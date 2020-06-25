// Copyright (c) 2019 The CATSCOIN developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLCATSWIDGET_H
#define COINCONTROLCATSWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlCatsWidget;
}

class CoinControlCatsWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlCatsWidget(QWidget *parent = nullptr);
    ~CoinControlCatsWidget();

private:
    Ui::CoinControlCatsWidget *ui;
};

#endif // COINCONTROLCATSWIDGET_H
