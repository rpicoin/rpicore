/********************************************************************************
** Form generated from reading UI file 'overviewpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERVIEWPAGE_H
#define UI_OVERVIEWPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OverviewPage
{
public:
    QVBoxLayout *topLayout;
    QLabel *labelAlerts;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *labelWalletStatus;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QLabel *labelImmatureText;
    QLabel *label_6;
    QLabel *label;
    QLabel *labelStake;
    QLabel *labelUnconfirmed;
    QLabel *labelBalance;
    QLabel *label_3;
    QLabel *labelImmature;
    QLabel *labelTotalText;
    QLabel *labelTotal;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *labelTransactionsStatus;
    QSpacerItem *horizontalSpacer;
    QListView *listTransactions;

    void setupUi(QWidget *OverviewPage)
    {
        if (OverviewPage->objectName().isEmpty())
            OverviewPage->setObjectName(QStringLiteral("OverviewPage"));
        OverviewPage->resize(573, 342);
        topLayout = new QVBoxLayout(OverviewPage);
        topLayout->setObjectName(QStringLiteral("topLayout"));
        labelAlerts = new QLabel(OverviewPage);
        labelAlerts->setObjectName(QStringLiteral("labelAlerts"));
        labelAlerts->setVisible(false);
        labelAlerts->setStyleSheet(QLatin1String("background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop:0 #F0D0A0, stop:1 #F8D488);  color:#000000\n"
""));
        labelAlerts->setWordWrap(true);
        labelAlerts->setMargin(3);

        topLayout->addWidget(labelAlerts);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new QWidget(OverviewPage);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setFamily(QStringLiteral("Noto Mono"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        labelWalletStatus = new QLabel(widget);
        labelWalletStatus->setObjectName(QStringLiteral("labelWalletStatus"));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Mono"));
        font1.setPointSize(10);
        labelWalletStatus->setFont(font1);
        labelWalletStatus->setStyleSheet(QStringLiteral("QLabel { color: #2ebb89; }"));
        labelWalletStatus->setText(QStringLiteral("(out of sync)"));
        labelWalletStatus->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(labelWalletStatus);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(widget);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(12);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelImmatureText = new QLabel(OverviewPage);
        labelImmatureText->setObjectName(QStringLiteral("labelImmatureText"));
        labelImmatureText->setFont(font1);

        gridLayout->addWidget(labelImmatureText, 6, 0, 1, 1);

        label_6 = new QLabel(OverviewPage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        gridLayout->addWidget(label_6, 0, 1, 1, 1);

        label = new QLabel(OverviewPage);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        labelStake = new QLabel(OverviewPage);
        labelStake->setObjectName(QStringLiteral("labelStake"));
        QFont font2;
        font2.setFamily(QStringLiteral("Noto Mono"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        labelStake->setFont(font2);
        labelStake->setCursor(QCursor(Qt::IBeamCursor));
        labelStake->setText(QStringLiteral("0 RPI"));
        labelStake->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelStake->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(labelStake, 1, 1, 1, 1);

        labelUnconfirmed = new QLabel(OverviewPage);
        labelUnconfirmed->setObjectName(QStringLiteral("labelUnconfirmed"));
        QFont font3;
        font3.setFamily(QStringLiteral("Noto Mono"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        labelUnconfirmed->setFont(font3);
        labelUnconfirmed->setCursor(QCursor(Qt::IBeamCursor));
        labelUnconfirmed->setText(QStringLiteral("0 RPI"));
        labelUnconfirmed->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelUnconfirmed->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(labelUnconfirmed, 3, 0, 1, 1);

        labelBalance = new QLabel(OverviewPage);
        labelBalance->setObjectName(QStringLiteral("labelBalance"));
        labelBalance->setFont(font2);
        labelBalance->setCursor(QCursor(Qt::IBeamCursor));
        labelBalance->setText(QStringLiteral("0 RPI"));
        labelBalance->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelBalance->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(labelBalance, 1, 0, 1, 1);

        label_3 = new QLabel(OverviewPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        labelImmature = new QLabel(OverviewPage);
        labelImmature->setObjectName(QStringLiteral("labelImmature"));
        labelImmature->setFont(font3);
        labelImmature->setText(QStringLiteral("0 RPI"));
        labelImmature->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelImmature->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(labelImmature, 7, 0, 1, 1);

        labelTotalText = new QLabel(OverviewPage);
        labelTotalText->setObjectName(QStringLiteral("labelTotalText"));
        labelTotalText->setFont(font1);

        gridLayout->addWidget(labelTotalText, 2, 1, 1, 1);

        labelTotal = new QLabel(OverviewPage);
        labelTotal->setObjectName(QStringLiteral("labelTotal"));
        labelTotal->setFont(font3);
        labelTotal->setCursor(QCursor(Qt::IBeamCursor));
        labelTotal->setText(QStringLiteral("0 RPI"));
        labelTotal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelTotal->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(labelTotal, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_2 = new QWidget(OverviewPage);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        labelTransactionsStatus = new QLabel(widget_2);
        labelTransactionsStatus->setObjectName(QStringLiteral("labelTransactionsStatus"));
        labelTransactionsStatus->setStyleSheet(QStringLiteral("QLabel { color: #2ebb89; }"));
        labelTransactionsStatus->setText(QStringLiteral("(out of sync)"));
        labelTransactionsStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelTransactionsStatus);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        listTransactions = new QListView(widget_2);
        listTransactions->setObjectName(QStringLiteral("listTransactions"));
        listTransactions->setStyleSheet(QStringLiteral("QListView { background: transparent; }"));
        listTransactions->setFrameShape(QFrame::NoFrame);
        listTransactions->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listTransactions->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listTransactions->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(listTransactions);


        verticalLayout_3->addWidget(widget_2);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        topLayout->addLayout(horizontalLayout);


        retranslateUi(OverviewPage);

        QMetaObject::connectSlotsByName(OverviewPage);
    } // setupUi

    void retranslateUi(QWidget *OverviewPage)
    {
        OverviewPage->setWindowTitle(QApplication::translate("OverviewPage", "Form", Q_NULLPTR));
        label_5->setText(QApplication::translate("OverviewPage", "Wallet", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        labelWalletStatus->setToolTip(QApplication::translate("OverviewPage", "The displayed information may be out of date. Your wallet automatically synchronizes with the Rpicoin network after a connection is established, but this process has not completed yet.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        labelImmatureText->setText(QApplication::translate("OverviewPage", "Immature", Q_NULLPTR));
        label_6->setText(QApplication::translate("OverviewPage", "Staking", Q_NULLPTR));
        label->setText(QApplication::translate("OverviewPage", "Available", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        labelStake->setToolTip(QApplication::translate("OverviewPage", "Total of coins that was staked, and do not yet count toward the current balance", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelUnconfirmed->setToolTip(QApplication::translate("OverviewPage", "Total of transactions that have yet to be confirmed, and do not yet count toward the current balance", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelBalance->setToolTip(QApplication::translate("OverviewPage", "Your current spendable balance", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("OverviewPage", "Unconfirmed", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        labelImmature->setToolTip(QApplication::translate("OverviewPage", "Mined balance that has not yet matured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        labelTotalText->setText(QApplication::translate("OverviewPage", "Total", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        labelTotal->setToolTip(QApplication::translate("OverviewPage", "Your current total balance", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("OverviewPage", "<b>Recent transactions</b>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        labelTransactionsStatus->setToolTip(QApplication::translate("OverviewPage", "The displayed information may be out of date. Your wallet automatically synchronizes with the Rpicoin network after a connection is established, but this process has not completed yet.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class OverviewPage: public Ui_OverviewPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERVIEWPAGE_H
