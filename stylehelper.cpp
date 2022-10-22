#include "stylehelper.h"


QString StyleHelper::getMainWidgetStyle()
{
    return "QWidget {"
           "    background: url(:/resourse/images/bg.png);"
           "}";
}

QString StyleHelper::getStartButtonStyle()
{
    return "QPushButton {"
           "    color: #fff;"
           "    background: none;"
           "    border: none;"
           "    border-radius: 15px;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(89, 156, 208, 255), stop:1 rgba(65, 118, 184, 255));"
           "    font-family: 'Roboto Medium';"
           "    font-size: 15px"
           "}"
           "QPushButton::hover {"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(93, 163, 218, 255), stop:1 rgba(80, 146, 227, 255));"
           "}"
           "QPushButton::pressed {"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(89, 156, 208, 255), stop:1 rgba(65, 118, 184, 255));"
           "}";
}

QString StyleHelper::getLeftButtonStyle()
{
    return "QPushButton {"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(88, 100, 112, 255), stop:1 rgba(56, 68, 80, 255));"
           "    background-image: url(:/resourse/images/cross_small.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    border: 1px solid #333;"
           "    border-top-left-radius: 5px;"
           "    border-bottom-left-radius: 5px;"
           "}";
}

QString StyleHelper::getRightButtonStyle()
{
    return "QPushButton {"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(88, 100, 112, 255), stop:1 rgba(56, 68, 80, 255));"
           "    background-image: url(:/resourse/images/zero_small.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    border: 1px solid #333;"
           "    border-left: none;"
           "    border-top-right-radius: 5px;"
           "    border-bottom-right-radius: 5px;"
           "}";
}

QString StyleHelper::getLeftButtonActiveStyle()
{
    return "QPushButton {"
           "    background-color: #2d313b;"
           "    background-image: url(:/resourse/images/cross_small.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    border: 1px solid #333;"
           "    border-top-left-radius: 5px;"
           "    border-bottom-left-radius: 5px;"
           "}";
}

QString StyleHelper::getRightButtonActiveStyle()
{
    return "QPushButton {"
           "    background-color: #2d313b;"
           "    background-image: url(:/resourse/images/zero_small.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    border: 1px solid #333;"
           "    border-left: none;"
           "    border-top-right-radius: 5px;"
           "    border-bottom-right-radius: 5px;"
           "}";
}

QString StyleHelper::getTabWidgetStyle()
{
    return "QTabWidget {"
            "border: none;"
        "}"

        "QTabWidget::pane {"
            "border: 1px solid #222;"
            "border-radius: 3px;"
        "}";
}

QString StyleHelper::getTabStyle()
{
    return "QWidget#tab {"
           "    background: rgb(33, 40, 50);"
           "}";
}

QString StyleHelper::getStartButtonGameStyle()
{
    return "QPushButton {"
           "    color: #fff;"
           "    background: none;"
           "    border: none;"
           "    border-radius: 15px;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 137, 124, 255), stop:0.982955 rgba(215, 51, 97, 255), stop:1 rgba(255, 255, 255, 255));"
           "    font-family: 'Roboto Medium';"
           "    font-size: 15px"
           "}";
}

QString StyleHelper::getBlankButtonStyle()
{
    return "QPushButton {"
           "    border: none;"
           "    background: #272D39;"
           "}"
           "QPushButton::hover {"
           "    background: #373D49;"
           "}";
}

QString StyleHelper::getCrossNormalStyle()
{
    return "QPushButton {"
           "    border: none;"
           "    background: #272D39 url(:/resourse/images/cross_large.png) no-repeat;"
           "    background-position: center center;"
           "}"
           "QPushButton::hover {"
           "    background-color: #373D49;"
           "}";
}

QString StyleHelper::getCrossVictoryStyle()
{
    return "QPushButton {"
           "    border: none;"
           "    background-color: #20401b;"
           "    background-image: url(:/resourse/images/cross_large.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "}";
}

QString StyleHelper::getCrossLostStyle()
{
    return "QPushButton {"
           "    border: none;"
           "    background-color: #7f1f8c;"
           "    background-image: url(:/resourse/images/cross_large.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "}";
}

QString StyleHelper::getZeroNormalStyle()
{
    return "QPushButton {"
           "    border: none;"
           "    background: #272D39 url(:/resourse/images/zero_large.png) no-repeat;"
           "    background-position: center center;"
           "}"
           "QPushButton::hover {"
           "    background-color: #373D49;"
           "}";
}

QString StyleHelper::getZeroVictoryStyle()
{
    return "QPushButton {"
           "    border: none;"
           "    background-color: #20401b;"
           "    background-image: url(:/resourse/images/zero_large.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "}";
}

QString StyleHelper::getZeroLostStyle()
{
    return "QPushButton {"
           "    border: none;"
           "    background-color: #7f1f8c;"
           "    background-image: url(:/resourse/images/zero_large.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "}";
}

QString StyleHelper::getNormalMessageStyle()
{
    return "QLabel {"
           "    font-family: 'Roboto Medium';"
           "    font-size: 12px;"
           "    background: none;"
           "    color: #ffffff;"
           "}";
}

QString StyleHelper::getVictoryMessageStyle()
{
    return "QLabel {"
           "    font-family: 'Roboto Medium';"
           "    font-size: 12px;"
           "    background: #055902;"
           "    border: 1px solid #1c7c32;"
           "    color: #ffffff;"
           "}";
}

QString StyleHelper::getLostMessageStyle()
{
    return "QLabel {"
           "    font-family: 'Roboto Medium';"
           "    font-size: 12px;"
           "    background: #961f99;"
           "    border: 1px solid #e237f5;"
           "    color: #ffffff;"
           "}";
}

QString StyleHelper::getAboutTextStyle()
{
    return "QLabel {"
           "    font-family: 'Roboto Medium';"
           "    font-size: 12px;"
           "    color: #ffffff;"
           "    font-style: italic;"
           "}";
}
