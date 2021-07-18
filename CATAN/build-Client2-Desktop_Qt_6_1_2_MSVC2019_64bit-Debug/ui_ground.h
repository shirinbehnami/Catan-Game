/********************************************************************************
** Form generated from reading UI file 'ground.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUND_H
#define UI_GROUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <ground/hexagonal.h>

QT_BEGIN_NAMESPACE

class Ui_ground
{
public:
    QWidget *centralwidget;
    hexagonal *hex0;
    hexagonal *hex1;
    hexagonal *hex2;
    hexagonal *hex8;
    hexagonal *hex7;
    hexagonal *hex6;
    hexagonal *hex5;
    hexagonal *hex3;
    hexagonal *hex4;
    hexagonal *hex9;
    hexagonal *hex10;
    hexagonal *hex11;
    hexagonal *hex12;
    hexagonal *hex13;
    hexagonal *hex14;
    hexagonal *hex15;
    hexagonal *hex16;
    hexagonal *hex17;
    hexagonal *hex18;
    hexagonal *water11;
    hexagonal *water22;
    hexagonal *water23;
    hexagonal *water26;
    hexagonal *water27;
    hexagonal *water30;
    hexagonal *water31;
    hexagonal *water33;
    hexagonal *water34;
    hexagonal *water12;
    hexagonal *water13;
    hexagonal *water14;
    hexagonal *water17;
    hexagonal *water18;
    hexagonal *water36;
    hexagonal *water37;
    hexagonal *water38;
    hexagonal *water39;
    hexagonal *water40;
    hexagonal *water41;
    hexagonal *hex27;
    hexagonal *water35;
    hexagonal *hex26;
    hexagonal *water32;
    hexagonal *water28;
    hexagonal *water29;
    hexagonal *water21;
    hexagonal *hex25;
    hexagonal *water24;
    hexagonal *water25;
    hexagonal *water16;
    hexagonal *hex24;
    hexagonal *water19;
    hexagonal *water20;
    hexagonal *water10;
    hexagonal *hex22;
    hexagonal *hex23;
    hexagonal *water15;
    hexagonal *water6;
    hexagonal *hex19;
    hexagonal *hex20;
    hexagonal *water7;
    hexagonal *hex21;
    hexagonal *water8;
    hexagonal *water9;
    hexagonal *water0;
    hexagonal *water1;
    hexagonal *water3;
    hexagonal *water2;
    hexagonal *water5;
    hexagonal *water4;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ground)
    {
        if (ground->objectName().isEmpty())
            ground->setObjectName(QString::fromUtf8("ground"));
        ground->resize(1000, 1000);
        ground->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"    background-color: rgb(20, 20, 95);\n"
"}"));
        centralwidget = new QWidget(ground);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hex0 = new hexagonal(centralwidget);
        hex0->setObjectName(QString::fromUtf8("hex0"));
        hex0->setEnabled(true);
        hex0->setGeometry(QRect(250, 250, 100, 100));
        hex0->setMinimumSize(QSize(100, 100));
        hex0->setMaximumSize(QSize(100, 100));
        QFont font;
        font.setKerning(true);
        hex0->setFont(font);
        hex0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex0->setIconSize(QSize(100, 100));
        hex0->setFlat(true);
        hex1 = new hexagonal(centralwidget);
        hex1->setObjectName(QString::fromUtf8("hex1"));
        hex1->setEnabled(true);
        hex1->setGeometry(QRect(335, 250, 100, 100));
        hex1->setMinimumSize(QSize(100, 100));
        hex1->setMaximumSize(QSize(100, 100));
        hex1->setFont(font);
        hex1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex1->setIconSize(QSize(100, 100));
        hex1->setFlat(true);
        hex2 = new hexagonal(centralwidget);
        hex2->setObjectName(QString::fromUtf8("hex2"));
        hex2->setEnabled(true);
        hex2->setGeometry(QRect(420, 250, 100, 100));
        hex2->setMinimumSize(QSize(100, 100));
        hex2->setMaximumSize(QSize(100, 100));
        hex2->setFont(font);
        hex2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex2->setIconSize(QSize(100, 100));
        hex2->setFlat(true);
        hex8 = new hexagonal(centralwidget);
        hex8->setObjectName(QString::fromUtf8("hex8"));
        hex8->setEnabled(true);
        hex8->setGeometry(QRect(249, 394, 100, 100));
        hex8->setMinimumSize(QSize(100, 100));
        hex8->setMaximumSize(QSize(100, 100));
        hex8->setFont(font);
        hex8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex8->setIconSize(QSize(100, 100));
        hex8->setFlat(true);
        hex7 = new hexagonal(centralwidget);
        hex7->setObjectName(QString::fromUtf8("hex7"));
        hex7->setEnabled(true);
        hex7->setGeometry(QRect(164, 394, 100, 100));
        hex7->setMinimumSize(QSize(100, 100));
        hex7->setMaximumSize(QSize(100, 100));
        hex7->setFont(font);
        hex7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex7->setIconSize(QSize(100, 100));
        hex7->setFlat(true);
        hex6 = new hexagonal(centralwidget);
        hex6->setObjectName(QString::fromUtf8("hex6"));
        hex6->setEnabled(true);
        hex6->setGeometry(QRect(462, 322, 100, 100));
        hex6->setMinimumSize(QSize(100, 100));
        hex6->setMaximumSize(QSize(100, 100));
        hex6->setFont(font);
        hex6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex6->setIconSize(QSize(100, 100));
        hex6->setFlat(true);
        hex5 = new hexagonal(centralwidget);
        hex5->setObjectName(QString::fromUtf8("hex5"));
        hex5->setEnabled(true);
        hex5->setGeometry(QRect(377, 322, 100, 100));
        hex5->setMinimumSize(QSize(100, 100));
        hex5->setMaximumSize(QSize(100, 100));
        hex5->setFont(font);
        hex5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex5->setIconSize(QSize(100, 100));
        hex5->setFlat(true);
        hex3 = new hexagonal(centralwidget);
        hex3->setObjectName(QString::fromUtf8("hex3"));
        hex3->setEnabled(true);
        hex3->setGeometry(QRect(207, 322, 100, 100));
        hex3->setMinimumSize(QSize(100, 100));
        hex3->setMaximumSize(QSize(100, 100));
        hex3->setFont(font);
        hex3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex3->setIconSize(QSize(100, 100));
        hex3->setFlat(true);
        hex4 = new hexagonal(centralwidget);
        hex4->setObjectName(QString::fromUtf8("hex4"));
        hex4->setEnabled(true);
        hex4->setGeometry(QRect(292, 322, 100, 100));
        hex4->setMinimumSize(QSize(100, 100));
        hex4->setMaximumSize(QSize(100, 100));
        hex4->setFont(font);
        hex4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex4->setIconSize(QSize(100, 100));
        hex4->setFlat(true);
        hex9 = new hexagonal(centralwidget);
        hex9->setObjectName(QString::fromUtf8("hex9"));
        hex9->setEnabled(true);
        hex9->setGeometry(QRect(334, 394, 100, 100));
        hex9->setMinimumSize(QSize(100, 100));
        hex9->setMaximumSize(QSize(100, 100));
        hex9->setFont(font);
        hex9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex9->setIconSize(QSize(100, 100));
        hex9->setFlat(true);
        hex10 = new hexagonal(centralwidget);
        hex10->setObjectName(QString::fromUtf8("hex10"));
        hex10->setEnabled(true);
        hex10->setGeometry(QRect(419, 394, 100, 100));
        hex10->setMinimumSize(QSize(100, 100));
        hex10->setMaximumSize(QSize(100, 100));
        hex10->setFont(font);
        hex10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex10->setIconSize(QSize(100, 100));
        hex10->setFlat(true);
        hex11 = new hexagonal(centralwidget);
        hex11->setObjectName(QString::fromUtf8("hex11"));
        hex11->setEnabled(true);
        hex11->setGeometry(QRect(504, 394, 100, 100));
        hex11->setMinimumSize(QSize(100, 100));
        hex11->setMaximumSize(QSize(100, 100));
        hex11->setFont(font);
        hex11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex11->setIconSize(QSize(100, 100));
        hex11->setFlat(true);
        hex12 = new hexagonal(centralwidget);
        hex12->setObjectName(QString::fromUtf8("hex12"));
        hex12->setEnabled(true);
        hex12->setGeometry(QRect(207, 466, 100, 100));
        hex12->setMinimumSize(QSize(100, 100));
        hex12->setMaximumSize(QSize(100, 100));
        hex12->setFont(font);
        hex12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex12->setIconSize(QSize(100, 100));
        hex12->setFlat(true);
        hex13 = new hexagonal(centralwidget);
        hex13->setObjectName(QString::fromUtf8("hex13"));
        hex13->setEnabled(true);
        hex13->setGeometry(QRect(292, 466, 100, 100));
        hex13->setMinimumSize(QSize(100, 100));
        hex13->setMaximumSize(QSize(100, 100));
        hex13->setFont(font);
        hex13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex13->setIconSize(QSize(100, 100));
        hex13->setFlat(true);
        hex14 = new hexagonal(centralwidget);
        hex14->setObjectName(QString::fromUtf8("hex14"));
        hex14->setEnabled(true);
        hex14->setGeometry(QRect(377, 466, 100, 100));
        hex14->setMinimumSize(QSize(100, 100));
        hex14->setMaximumSize(QSize(100, 100));
        hex14->setFont(font);
        hex14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex14->setIconSize(QSize(100, 100));
        hex14->setFlat(true);
        hex15 = new hexagonal(centralwidget);
        hex15->setObjectName(QString::fromUtf8("hex15"));
        hex15->setEnabled(true);
        hex15->setGeometry(QRect(462, 466, 100, 100));
        hex15->setMinimumSize(QSize(100, 100));
        hex15->setMaximumSize(QSize(100, 100));
        hex15->setFont(font);
        hex15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex15->setIconSize(QSize(100, 100));
        hex15->setFlat(true);
        hex16 = new hexagonal(centralwidget);
        hex16->setObjectName(QString::fromUtf8("hex16"));
        hex16->setEnabled(true);
        hex16->setGeometry(QRect(250, 538, 100, 100));
        hex16->setMinimumSize(QSize(100, 100));
        hex16->setMaximumSize(QSize(100, 100));
        hex16->setFont(font);
        hex16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex16->setIconSize(QSize(100, 100));
        hex16->setFlat(true);
        hex17 = new hexagonal(centralwidget);
        hex17->setObjectName(QString::fromUtf8("hex17"));
        hex17->setEnabled(true);
        hex17->setGeometry(QRect(335, 538, 100, 100));
        hex17->setMinimumSize(QSize(100, 100));
        hex17->setMaximumSize(QSize(100, 100));
        hex17->setFont(font);
        hex17->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex17->setIconSize(QSize(100, 100));
        hex17->setFlat(true);
        hex18 = new hexagonal(centralwidget);
        hex18->setObjectName(QString::fromUtf8("hex18"));
        hex18->setEnabled(true);
        hex18->setGeometry(QRect(420, 538, 100, 100));
        hex18->setMinimumSize(QSize(100, 100));
        hex18->setMaximumSize(QSize(100, 100));
        hex18->setFont(font);
        hex18->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex18->setIconSize(QSize(100, 100));
        hex18->setFlat(true);
        water11 = new hexagonal(centralwidget);
        water11->setObjectName(QString::fromUtf8("water11"));
        water11->setEnabled(true);
        water11->setGeometry(QRect(207, 178, 100, 100));
        water11->setMinimumSize(QSize(100, 100));
        water11->setMaximumSize(QSize(100, 100));
        water11->setFont(font);
        water11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water11->setIconSize(QSize(100, 100));
        water11->setFlat(true);
        water22 = new hexagonal(centralwidget);
        water22->setObjectName(QString::fromUtf8("water22"));
        water22->setEnabled(true);
        water22->setGeometry(QRect(122, 322, 100, 100));
        water22->setMinimumSize(QSize(100, 100));
        water22->setMaximumSize(QSize(100, 100));
        water22->setFont(font);
        water22->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water22->setIconSize(QSize(100, 100));
        water22->setFlat(true);
        water23 = new hexagonal(centralwidget);
        water23->setObjectName(QString::fromUtf8("water23"));
        water23->setEnabled(true);
        water23->setGeometry(QRect(547, 322, 100, 100));
        water23->setMinimumSize(QSize(100, 100));
        water23->setMaximumSize(QSize(100, 100));
        water23->setFont(font);
        water23->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water23->setIconSize(QSize(100, 100));
        water23->setFlat(true);
        water26 = new hexagonal(centralwidget);
        water26->setObjectName(QString::fromUtf8("water26"));
        water26->setEnabled(true);
        water26->setGeometry(QRect(79, 394, 100, 100));
        water26->setMinimumSize(QSize(100, 100));
        water26->setMaximumSize(QSize(100, 100));
        water26->setFont(font);
        water26->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water26->setIconSize(QSize(100, 100));
        water26->setFlat(true);
        water27 = new hexagonal(centralwidget);
        water27->setObjectName(QString::fromUtf8("water27"));
        water27->setEnabled(true);
        water27->setGeometry(QRect(589, 394, 100, 100));
        water27->setMinimumSize(QSize(100, 100));
        water27->setMaximumSize(QSize(100, 100));
        water27->setFont(font);
        water27->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water27->setIconSize(QSize(100, 100));
        water27->setFlat(true);
        water30 = new hexagonal(centralwidget);
        water30->setObjectName(QString::fromUtf8("water30"));
        water30->setEnabled(true);
        water30->setGeometry(QRect(122, 466, 100, 100));
        water30->setMinimumSize(QSize(100, 100));
        water30->setMaximumSize(QSize(100, 100));
        water30->setFont(font);
        water30->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water30->setIconSize(QSize(100, 100));
        water30->setFlat(true);
        water31 = new hexagonal(centralwidget);
        water31->setObjectName(QString::fromUtf8("water31"));
        water31->setEnabled(true);
        water31->setGeometry(QRect(547, 466, 100, 100));
        water31->setMinimumSize(QSize(100, 100));
        water31->setMaximumSize(QSize(100, 100));
        water31->setFont(font);
        water31->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water31->setIconSize(QSize(100, 100));
        water31->setFlat(true);
        water33 = new hexagonal(centralwidget);
        water33->setObjectName(QString::fromUtf8("water33"));
        water33->setEnabled(true);
        water33->setGeometry(QRect(165, 538, 100, 100));
        water33->setMinimumSize(QSize(100, 100));
        water33->setMaximumSize(QSize(100, 100));
        water33->setFont(font);
        water33->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water33->setIconSize(QSize(100, 100));
        water33->setFlat(true);
        water34 = new hexagonal(centralwidget);
        water34->setObjectName(QString::fromUtf8("water34"));
        water34->setEnabled(true);
        water34->setGeometry(QRect(505, 538, 100, 100));
        water34->setMinimumSize(QSize(100, 100));
        water34->setMaximumSize(QSize(100, 100));
        water34->setFont(font);
        water34->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water34->setIconSize(QSize(100, 100));
        water34->setFlat(true);
        water12 = new hexagonal(centralwidget);
        water12->setObjectName(QString::fromUtf8("water12"));
        water12->setEnabled(true);
        water12->setGeometry(QRect(292, 178, 100, 100));
        water12->setMinimumSize(QSize(100, 100));
        water12->setMaximumSize(QSize(100, 100));
        water12->setFont(font);
        water12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water12->setIconSize(QSize(100, 100));
        water12->setFlat(true);
        water13 = new hexagonal(centralwidget);
        water13->setObjectName(QString::fromUtf8("water13"));
        water13->setEnabled(true);
        water13->setGeometry(QRect(377, 178, 100, 100));
        water13->setMinimumSize(QSize(100, 100));
        water13->setMaximumSize(QSize(100, 100));
        water13->setFont(font);
        water13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water13->setIconSize(QSize(100, 100));
        water13->setFlat(true);
        water14 = new hexagonal(centralwidget);
        water14->setObjectName(QString::fromUtf8("water14"));
        water14->setEnabled(true);
        water14->setGeometry(QRect(462, 178, 100, 100));
        water14->setMinimumSize(QSize(100, 100));
        water14->setMaximumSize(QSize(100, 100));
        water14->setFont(font);
        water14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water14->setIconSize(QSize(100, 100));
        water14->setFlat(true);
        water17 = new hexagonal(centralwidget);
        water17->setObjectName(QString::fromUtf8("water17"));
        water17->setEnabled(true);
        water17->setGeometry(QRect(165, 250, 100, 100));
        water17->setMinimumSize(QSize(100, 100));
        water17->setMaximumSize(QSize(100, 100));
        water17->setFont(font);
        water17->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water17->setIconSize(QSize(100, 100));
        water17->setFlat(true);
        water18 = new hexagonal(centralwidget);
        water18->setObjectName(QString::fromUtf8("water18"));
        water18->setEnabled(true);
        water18->setGeometry(QRect(505, 250, 100, 100));
        water18->setMinimumSize(QSize(100, 100));
        water18->setMaximumSize(QSize(100, 100));
        water18->setFont(font);
        water18->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water18->setIconSize(QSize(100, 100));
        water18->setFlat(true);
        water36 = new hexagonal(centralwidget);
        water36->setObjectName(QString::fromUtf8("water36"));
        water36->setEnabled(true);
        water36->setGeometry(QRect(207, 610, 100, 100));
        water36->setMinimumSize(QSize(100, 100));
        water36->setMaximumSize(QSize(100, 100));
        water36->setFont(font);
        water36->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water36->setIconSize(QSize(100, 100));
        water36->setFlat(true);
        water37 = new hexagonal(centralwidget);
        water37->setObjectName(QString::fromUtf8("water37"));
        water37->setEnabled(true);
        water37->setGeometry(QRect(292, 610, 100, 100));
        water37->setMinimumSize(QSize(100, 100));
        water37->setMaximumSize(QSize(100, 100));
        water37->setFont(font);
        water37->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water37->setIconSize(QSize(100, 100));
        water37->setFlat(true);
        water38 = new hexagonal(centralwidget);
        water38->setObjectName(QString::fromUtf8("water38"));
        water38->setEnabled(true);
        water38->setGeometry(QRect(377, 610, 100, 100));
        water38->setMinimumSize(QSize(100, 100));
        water38->setMaximumSize(QSize(100, 100));
        water38->setFont(font);
        water38->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water38->setIconSize(QSize(100, 100));
        water38->setFlat(true);
        water39 = new hexagonal(centralwidget);
        water39->setObjectName(QString::fromUtf8("water39"));
        water39->setEnabled(true);
        water39->setGeometry(QRect(462, 610, 100, 100));
        water39->setMinimumSize(QSize(100, 100));
        water39->setMaximumSize(QSize(100, 100));
        water39->setFont(font);
        water39->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water39->setIconSize(QSize(100, 100));
        water39->setFlat(true);
        water40 = new hexagonal(centralwidget);
        water40->setObjectName(QString::fromUtf8("water40"));
        water40->setEnabled(true);
        water40->setGeometry(QRect(547, 610, 100, 100));
        water40->setMinimumSize(QSize(100, 100));
        water40->setMaximumSize(QSize(100, 100));
        water40->setFont(font);
        water40->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water40->setIconSize(QSize(100, 100));
        water40->setFlat(true);
        water41 = new hexagonal(centralwidget);
        water41->setObjectName(QString::fromUtf8("water41"));
        water41->setEnabled(true);
        water41->setGeometry(QRect(632, 610, 100, 100));
        water41->setMinimumSize(QSize(100, 100));
        water41->setMaximumSize(QSize(100, 100));
        water41->setFont(font);
        water41->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water41->setIconSize(QSize(100, 100));
        water41->setFlat(true);
        hex27 = new hexagonal(centralwidget);
        hex27->setObjectName(QString::fromUtf8("hex27"));
        hex27->setEnabled(true);
        hex27->setGeometry(QRect(590, 538, 100, 100));
        hex27->setMinimumSize(QSize(100, 100));
        hex27->setMaximumSize(QSize(100, 100));
        hex27->setFont(font);
        hex27->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex27->setIconSize(QSize(100, 100));
        hex27->setFlat(true);
        water35 = new hexagonal(centralwidget);
        water35->setObjectName(QString::fromUtf8("water35"));
        water35->setEnabled(true);
        water35->setGeometry(QRect(675, 538, 100, 100));
        water35->setMinimumSize(QSize(100, 100));
        water35->setMaximumSize(QSize(100, 100));
        water35->setFont(font);
        water35->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water35->setIconSize(QSize(100, 100));
        water35->setFlat(true);
        hex26 = new hexagonal(centralwidget);
        hex26->setObjectName(QString::fromUtf8("hex26"));
        hex26->setEnabled(true);
        hex26->setGeometry(QRect(632, 466, 100, 100));
        hex26->setMinimumSize(QSize(100, 100));
        hex26->setMaximumSize(QSize(100, 100));
        hex26->setFont(font);
        hex26->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex26->setIconSize(QSize(100, 100));
        hex26->setFlat(true);
        water32 = new hexagonal(centralwidget);
        water32->setObjectName(QString::fromUtf8("water32"));
        water32->setEnabled(true);
        water32->setGeometry(QRect(717, 466, 100, 100));
        water32->setMinimumSize(QSize(100, 100));
        water32->setMaximumSize(QSize(100, 100));
        water32->setFont(font);
        water32->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water32->setIconSize(QSize(100, 100));
        water32->setFlat(true);
        water28 = new hexagonal(centralwidget);
        water28->setObjectName(QString::fromUtf8("water28"));
        water28->setEnabled(true);
        water28->setGeometry(QRect(674, 394, 100, 100));
        water28->setMinimumSize(QSize(100, 100));
        water28->setMaximumSize(QSize(100, 100));
        water28->setFont(font);
        water28->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water28->setIconSize(QSize(100, 100));
        water28->setFlat(true);
        water29 = new hexagonal(centralwidget);
        water29->setObjectName(QString::fromUtf8("water29"));
        water29->setEnabled(true);
        water29->setGeometry(QRect(759, 394, 100, 100));
        water29->setMinimumSize(QSize(100, 100));
        water29->setMaximumSize(QSize(100, 100));
        water29->setFont(font);
        water29->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water29->setIconSize(QSize(100, 100));
        water29->setFlat(true);
        water21 = new hexagonal(centralwidget);
        water21->setObjectName(QString::fromUtf8("water21"));
        water21->setEnabled(true);
        water21->setGeometry(QRect(37, 322, 100, 100));
        water21->setMinimumSize(QSize(100, 100));
        water21->setMaximumSize(QSize(100, 100));
        water21->setFont(font);
        water21->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water21->setIconSize(QSize(100, 100));
        water21->setFlat(true);
        hex25 = new hexagonal(centralwidget);
        hex25->setObjectName(QString::fromUtf8("hex25"));
        hex25->setEnabled(true);
        hex25->setGeometry(QRect(632, 322, 100, 100));
        hex25->setMinimumSize(QSize(100, 100));
        hex25->setMaximumSize(QSize(100, 100));
        hex25->setFont(font);
        hex25->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex25->setIconSize(QSize(100, 100));
        hex25->setFlat(true);
        water24 = new hexagonal(centralwidget);
        water24->setObjectName(QString::fromUtf8("water24"));
        water24->setEnabled(true);
        water24->setGeometry(QRect(717, 322, 100, 100));
        water24->setMinimumSize(QSize(100, 100));
        water24->setMaximumSize(QSize(100, 100));
        water24->setFont(font);
        water24->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water24->setIconSize(QSize(100, 100));
        water24->setFlat(true);
        water25 = new hexagonal(centralwidget);
        water25->setObjectName(QString::fromUtf8("water25"));
        water25->setEnabled(true);
        water25->setGeometry(QRect(802, 322, 100, 100));
        water25->setMinimumSize(QSize(100, 100));
        water25->setMaximumSize(QSize(100, 100));
        water25->setFont(font);
        water25->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water25->setIconSize(QSize(100, 100));
        water25->setFlat(true);
        water16 = new hexagonal(centralwidget);
        water16->setObjectName(QString::fromUtf8("water16"));
        water16->setEnabled(true);
        water16->setGeometry(QRect(80, 250, 100, 100));
        water16->setMinimumSize(QSize(100, 100));
        water16->setMaximumSize(QSize(100, 100));
        water16->setFont(font);
        water16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water16->setIconSize(QSize(100, 100));
        water16->setFlat(true);
        hex24 = new hexagonal(centralwidget);
        hex24->setObjectName(QString::fromUtf8("hex24"));
        hex24->setEnabled(true);
        hex24->setGeometry(QRect(590, 250, 100, 100));
        hex24->setMinimumSize(QSize(100, 100));
        hex24->setMaximumSize(QSize(100, 100));
        hex24->setFont(font);
        hex24->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex24->setIconSize(QSize(100, 100));
        hex24->setFlat(true);
        water19 = new hexagonal(centralwidget);
        water19->setObjectName(QString::fromUtf8("water19"));
        water19->setEnabled(true);
        water19->setGeometry(QRect(675, 250, 100, 100));
        water19->setMinimumSize(QSize(100, 100));
        water19->setMaximumSize(QSize(100, 100));
        water19->setFont(font);
        water19->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water19->setIconSize(QSize(100, 100));
        water19->setFlat(true);
        water20 = new hexagonal(centralwidget);
        water20->setObjectName(QString::fromUtf8("water20"));
        water20->setEnabled(true);
        water20->setGeometry(QRect(760, 250, 100, 100));
        water20->setMinimumSize(QSize(100, 100));
        water20->setMaximumSize(QSize(100, 100));
        water20->setFont(font);
        water20->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water20->setIconSize(QSize(100, 100));
        water20->setFlat(true);
        water10 = new hexagonal(centralwidget);
        water10->setObjectName(QString::fromUtf8("water10"));
        water10->setEnabled(true);
        water10->setGeometry(QRect(122, 178, 100, 100));
        water10->setMinimumSize(QSize(100, 100));
        water10->setMaximumSize(QSize(100, 100));
        water10->setFont(font);
        water10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water10->setIconSize(QSize(100, 100));
        water10->setFlat(true);
        hex22 = new hexagonal(centralwidget);
        hex22->setObjectName(QString::fromUtf8("hex22"));
        hex22->setEnabled(true);
        hex22->setGeometry(QRect(547, 178, 100, 100));
        hex22->setMinimumSize(QSize(100, 100));
        hex22->setMaximumSize(QSize(100, 100));
        hex22->setFont(font);
        hex22->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex22->setIconSize(QSize(100, 100));
        hex22->setFlat(true);
        hex23 = new hexagonal(centralwidget);
        hex23->setObjectName(QString::fromUtf8("hex23"));
        hex23->setEnabled(true);
        hex23->setGeometry(QRect(632, 178, 100, 100));
        hex23->setMinimumSize(QSize(100, 100));
        hex23->setMaximumSize(QSize(100, 100));
        hex23->setFont(font);
        hex23->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex23->setIconSize(QSize(100, 100));
        hex23->setFlat(true);
        water15 = new hexagonal(centralwidget);
        water15->setObjectName(QString::fromUtf8("water15"));
        water15->setEnabled(true);
        water15->setGeometry(QRect(717, 178, 100, 100));
        water15->setMinimumSize(QSize(100, 100));
        water15->setMaximumSize(QSize(100, 100));
        water15->setFont(font);
        water15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water15->setIconSize(QSize(100, 100));
        water15->setFlat(true);
        water6 = new hexagonal(centralwidget);
        water6->setObjectName(QString::fromUtf8("water6"));
        water6->setEnabled(true);
        water6->setGeometry(QRect(165, 106, 100, 100));
        water6->setMinimumSize(QSize(100, 100));
        water6->setMaximumSize(QSize(100, 100));
        water6->setFont(font);
        water6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water6->setIconSize(QSize(100, 100));
        water6->setFlat(true);
        hex19 = new hexagonal(centralwidget);
        hex19->setObjectName(QString::fromUtf8("hex19"));
        hex19->setEnabled(true);
        hex19->setGeometry(QRect(250, 106, 100, 100));
        hex19->setMinimumSize(QSize(100, 100));
        hex19->setMaximumSize(QSize(100, 100));
        hex19->setFont(font);
        hex19->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex19->setIconSize(QSize(100, 100));
        hex19->setFlat(true);
        hex20 = new hexagonal(centralwidget);
        hex20->setObjectName(QString::fromUtf8("hex20"));
        hex20->setEnabled(true);
        hex20->setGeometry(QRect(335, 106, 100, 100));
        hex20->setMinimumSize(QSize(100, 100));
        hex20->setMaximumSize(QSize(100, 100));
        hex20->setFont(font);
        hex20->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex20->setIconSize(QSize(100, 100));
        hex20->setFlat(true);
        water7 = new hexagonal(centralwidget);
        water7->setObjectName(QString::fromUtf8("water7"));
        water7->setEnabled(true);
        water7->setGeometry(QRect(420, 106, 100, 100));
        water7->setMinimumSize(QSize(100, 100));
        water7->setMaximumSize(QSize(100, 100));
        water7->setFont(font);
        water7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water7->setIconSize(QSize(100, 100));
        water7->setFlat(true);
        hex21 = new hexagonal(centralwidget);
        hex21->setObjectName(QString::fromUtf8("hex21"));
        hex21->setEnabled(true);
        hex21->setGeometry(QRect(505, 106, 100, 100));
        hex21->setMinimumSize(QSize(100, 100));
        hex21->setMaximumSize(QSize(100, 100));
        hex21->setFont(font);
        hex21->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hex21->setIconSize(QSize(100, 100));
        hex21->setFlat(true);
        water8 = new hexagonal(centralwidget);
        water8->setObjectName(QString::fromUtf8("water8"));
        water8->setEnabled(true);
        water8->setGeometry(QRect(590, 106, 100, 100));
        water8->setMinimumSize(QSize(100, 100));
        water8->setMaximumSize(QSize(100, 100));
        water8->setFont(font);
        water8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water8->setIconSize(QSize(100, 100));
        water8->setFlat(true);
        water9 = new hexagonal(centralwidget);
        water9->setObjectName(QString::fromUtf8("water9"));
        water9->setEnabled(true);
        water9->setGeometry(QRect(675, 106, 100, 100));
        water9->setMinimumSize(QSize(100, 100));
        water9->setMaximumSize(QSize(100, 100));
        water9->setFont(font);
        water9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water9->setIconSize(QSize(100, 100));
        water9->setFlat(true);
        water0 = new hexagonal(centralwidget);
        water0->setObjectName(QString::fromUtf8("water0"));
        water0->setEnabled(true);
        water0->setGeometry(QRect(207, 34, 100, 100));
        water0->setMinimumSize(QSize(100, 100));
        water0->setMaximumSize(QSize(100, 100));
        water0->setFont(font);
        water0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water0->setIconSize(QSize(100, 100));
        water0->setFlat(true);
        water1 = new hexagonal(centralwidget);
        water1->setObjectName(QString::fromUtf8("water1"));
        water1->setEnabled(true);
        water1->setGeometry(QRect(292, 34, 100, 100));
        water1->setMinimumSize(QSize(100, 100));
        water1->setMaximumSize(QSize(100, 100));
        water1->setFont(font);
        water1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water1->setIconSize(QSize(100, 100));
        water1->setFlat(true);
        water3 = new hexagonal(centralwidget);
        water3->setObjectName(QString::fromUtf8("water3"));
        water3->setEnabled(true);
        water3->setGeometry(QRect(462, 34, 100, 100));
        water3->setMinimumSize(QSize(100, 100));
        water3->setMaximumSize(QSize(100, 100));
        water3->setFont(font);
        water3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water3->setIconSize(QSize(100, 100));
        water3->setFlat(true);
        water2 = new hexagonal(centralwidget);
        water2->setObjectName(QString::fromUtf8("water2"));
        water2->setEnabled(true);
        water2->setGeometry(QRect(377, 34, 100, 100));
        water2->setMinimumSize(QSize(100, 100));
        water2->setMaximumSize(QSize(100, 100));
        water2->setFont(font);
        water2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water2->setIconSize(QSize(100, 100));
        water2->setFlat(true);
        water5 = new hexagonal(centralwidget);
        water5->setObjectName(QString::fromUtf8("water5"));
        water5->setEnabled(true);
        water5->setGeometry(QRect(632, 34, 100, 100));
        water5->setMinimumSize(QSize(100, 100));
        water5->setMaximumSize(QSize(100, 100));
        water5->setFont(font);
        water5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water5->setIconSize(QSize(100, 100));
        water5->setFlat(true);
        water4 = new hexagonal(centralwidget);
        water4->setObjectName(QString::fromUtf8("water4"));
        water4->setEnabled(true);
        water4->setGeometry(QRect(547, 34, 100, 100));
        water4->setMinimumSize(QSize(100, 100));
        water4->setMaximumSize(QSize(100, 100));
        water4->setFont(font);
        water4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        water4->setIconSize(QSize(100, 100));
        water4->setFlat(true);
        ground->setCentralWidget(centralwidget);
        toolBar = new QToolBar(ground);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        ground->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(ground);

        QMetaObject::connectSlotsByName(ground);
    } // setupUi

    void retranslateUi(QMainWindow *ground)
    {
        ground->setWindowTitle(QCoreApplication::translate("ground", "ground", nullptr));
        hex0->setText(QString());
        hex1->setText(QString());
        hex2->setText(QString());
        hex8->setText(QString());
        hex7->setText(QString());
        hex6->setText(QString());
        hex5->setText(QString());
        hex3->setText(QString());
        hex4->setText(QString());
        hex9->setText(QString());
        hex10->setText(QString());
        hex11->setText(QString());
        hex12->setText(QString());
        hex13->setText(QString());
        hex14->setText(QString());
        hex15->setText(QString());
        hex16->setText(QString());
        hex17->setText(QString());
        hex18->setText(QString());
        water11->setText(QString());
        water22->setText(QString());
        water23->setText(QString());
        water26->setText(QString());
        water27->setText(QString());
        water30->setText(QString());
        water31->setText(QString());
        water33->setText(QString());
        water34->setText(QString());
        water12->setText(QString());
        water13->setText(QString());
        water14->setText(QString());
        water17->setText(QString());
        water18->setText(QString());
        water36->setText(QString());
        water37->setText(QString());
        water38->setText(QString());
        water39->setText(QString());
        water40->setText(QString());
        water41->setText(QString());
        hex27->setText(QString());
        water35->setText(QString());
        hex26->setText(QString());
        water32->setText(QString());
        water28->setText(QString());
        water29->setText(QString());
        water21->setText(QString());
        hex25->setText(QString());
        water24->setText(QString());
        water25->setText(QString());
        water16->setText(QString());
        hex24->setText(QString());
        water19->setText(QString());
        water20->setText(QString());
        water10->setText(QString());
        hex22->setText(QString());
        hex23->setText(QString());
        water15->setText(QString());
        water6->setText(QString());
        hex19->setText(QString());
        hex20->setText(QString());
        water7->setText(QString());
        hex21->setText(QString());
        water8->setText(QString());
        water9->setText(QString());
        water0->setText(QString());
        water1->setText(QString());
        water3->setText(QString());
        water2->setText(QString());
        water5->setText(QString());
        water4->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("ground", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ground: public Ui_ground {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUND_H
