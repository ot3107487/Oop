/********************************************************************************
** Form generated from reading UI file 'biblioteca.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBLIOTECA_H
#define UI_BIBLIOTECA_H

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

class Ui_BibliotecaClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BibliotecaClass)
    {
        if (BibliotecaClass->objectName().isEmpty())
            BibliotecaClass->setObjectName(QStringLiteral("BibliotecaClass"));
        BibliotecaClass->resize(600, 400);
        menuBar = new QMenuBar(BibliotecaClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        BibliotecaClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BibliotecaClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BibliotecaClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(BibliotecaClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        BibliotecaClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BibliotecaClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BibliotecaClass->setStatusBar(statusBar);

        retranslateUi(BibliotecaClass);

        QMetaObject::connectSlotsByName(BibliotecaClass);
    } // setupUi

    void retranslateUi(QMainWindow *BibliotecaClass)
    {
        BibliotecaClass->setWindowTitle(QApplication::translate("BibliotecaClass", "Biblioteca", 0));
    } // retranslateUi

};

namespace Ui {
    class BibliotecaClass: public Ui_BibliotecaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBLIOTECA_H
