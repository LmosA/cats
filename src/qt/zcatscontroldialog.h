// Copyright (c) 2017-2019 The CATSCOIN developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZCATSCONTROLDIALOG_H
#define ZCATSCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zcats/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZCatsControlDialog;
}

class CZCatsControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZCatsControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZCatsControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZCatsControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZCatsControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZCatsControlDialog(QWidget *parent);
    ~ZCatsControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZCatsControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZCatsControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZCATSCONTROLDIALOG_H
