/********************************************************************************
** Form generated from reading UI file 'FigureSampleQt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGURESAMPLEQT_H
#define UI_FIGURESAMPLEQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FigureSampleQtClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FigureSampleQtClass)
    {
        if (FigureSampleQtClass->objectName().isEmpty())
            FigureSampleQtClass->setObjectName(QString::fromUtf8("FigureSampleQtClass"));
        FigureSampleQtClass->resize(600, 400);
        centralWidget = new QWidget(FigureSampleQtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        FigureSampleQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FigureSampleQtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        FigureSampleQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FigureSampleQtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        FigureSampleQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FigureSampleQtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FigureSampleQtClass->setStatusBar(statusBar);

        retranslateUi(FigureSampleQtClass);

        QMetaObject::connectSlotsByName(FigureSampleQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *FigureSampleQtClass)
    {
        FigureSampleQtClass->setWindowTitle(QApplication::translate("FigureSampleQtClass", "FigureSampleQt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FigureSampleQtClass: public Ui_FigureSampleQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGURESAMPLEQT_H
