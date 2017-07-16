/********************************************************************************
** Form generated from reading UI file 'magazin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGAZIN_H
#define UI_MAGAZIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_magazinClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *magazinClass)
    {
        if (magazinClass->objectName().isEmpty())
            magazinClass->setObjectName(QStringLiteral("magazinClass"));
        magazinClass->resize(600, 400);
        menuBar = new QMenuBar(magazinClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        magazinClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(magazinClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        magazinClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(magazinClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        magazinClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(magazinClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        magazinClass->setStatusBar(statusBar);

        retranslateUi(magazinClass);

        QMetaObject::connectSlotsByName(magazinClass);
    } // setupUi

    void retranslateUi(QMainWindow *magazinClass)
    {
        magazinClass->setWindowTitle(QApplication::translate("magazinClass", "magazin", 0));
    } // retranslateUi

};

namespace Ui {
    class magazinClass: public Ui_magazinClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGAZIN_H
