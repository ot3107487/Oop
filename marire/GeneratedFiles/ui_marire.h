/********************************************************************************
** Form generated from reading UI file 'marire.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARIRE_H
#define UI_MARIRE_H

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

class Ui_marireClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *marireClass)
    {
        if (marireClass->objectName().isEmpty())
            marireClass->setObjectName(QStringLiteral("marireClass"));
        marireClass->resize(600, 400);
        menuBar = new QMenuBar(marireClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        marireClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(marireClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        marireClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(marireClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        marireClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(marireClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        marireClass->setStatusBar(statusBar);

        retranslateUi(marireClass);

        QMetaObject::connectSlotsByName(marireClass);
    } // setupUi

    void retranslateUi(QMainWindow *marireClass)
    {
        marireClass->setWindowTitle(QApplication::translate("marireClass", "marire", 0));
    } // retranslateUi

};

namespace Ui {
    class marireClass: public Ui_marireClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARIRE_H
