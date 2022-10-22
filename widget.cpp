#include "widget.h"
#include "ui_widget.h"
#include "stylehelper.h"
#include <QTabBar>
#include <QStyleOption>
#include <QDebug>
#include <QFontDatabase>
#include <QGridLayout>
#include <QStringList>
#include <time.h>

Widget::Widget(QWidget *parent):
      QWidget(parent),
      ui(new Ui::Widget)
{
    ui->setupUi(this);
    configurationTabWidget();
    setInterfaceStyle();
    addFonts();

    configurationGameAreaButtons();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::onComputerSlot);
}

Widget::~Widget()
{
    delete ui;
}

// применяем к widget правила qss
void Widget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

// назначаем правила qss для элементов интерфейса
void Widget::setInterfaceStyle()
{
    this->setStyleSheet(StyleHelper::getMainWidgetStyle());
    ui->startButton->setStyleSheet(StyleHelper::getStartButtonStyle());
    ui->aboutButton->setStyleSheet(StyleHelper::getStartButtonStyle());
    ui->leftButton->setStyleSheet(StyleHelper::getLeftButtonActiveStyle());
    ui->rightButton->setStyleSheet(StyleHelper::getRightButtonStyle());
    ui->tabWidget->setStyleSheet(StyleHelper::getTabWidgetStyle());
    ui->tab->setStyleSheet(StyleHelper::getTabStyle());

    ui->messageLabel->setStyleSheet(StyleHelper::getVictoryMessageStyle());
    ui->messageLabel->setText("the crosses are moving...");

    setGameAreaButtonStyle();
    ui->messageLabel->setText("");
    ui->messageLabel->setStyleSheet(StyleHelper::getNormalMessageStyle());
    ui->aboutTextLabel->setStyleSheet(StyleHelper::getAboutTextStyle());
}

// переключаем выбор крестики/нолики
void Widget::changeButtonStatus(int num)
{
    if(num == 1) {
        ui->leftButton->setStyleSheet(StyleHelper::getLeftButtonActiveStyle());
        ui->rightButton->setStyleSheet(StyleHelper::getRightButtonStyle());
    } else {
        ui->leftButton->setStyleSheet(StyleHelper::getLeftButtonStyle());
        ui->rightButton->setStyleSheet(StyleHelper::getRightButtonActiveStyle());
    }
}

// игрок выбрал крестики
void Widget::on_leftButton_clicked()
{
    changeButtonStatus(1);
    player = 'x';
}

// игрок выбрал нолики
void Widget::on_rightButton_clicked()
{
    changeButtonStatus(0);
    player = '0';
}

// скрываем заголовок и выбираем текущую вкладку для tabWidget
void Widget::configurationTabWidget()
{
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setCurrentIndex(0);
}

// добавление шрифтов
void Widget::addFonts()
{
    QFontDatabase::addApplicationFont(":/resourse/fonts/Roboto-Medium.ttf");
    QFontDatabase::addApplicationFont(":/resourse/fonts/Roboto-MediumItalic.ttf");
}

void Widget::changeButtonStyle(int row, int column, QString style)
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui->tab->layout());
    QPushButton *btn = qobject_cast <QPushButton*>(grid->itemAtPosition(row, column)->widget());
    btn->setStyleSheet(style);
}

void Widget::configurationGameAreaButtons()
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui->tab->layout());
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            QPushButton *btn = qobject_cast <QPushButton*>(grid->itemAtPosition(row, column)->widget());
            btn->setProperty("row", row);
            btn->setProperty("column", column);
            connect(btn, &QPushButton::clicked, this, &Widget::onGameAreaButtonClicked);
        }
    }
}

void Widget::setGameAreaButtonStyle()
{
    QString style = StyleHelper::getBlankButtonStyle();
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            changeButtonStyle(row, column, style);
        }
    }
}

// начало игры
void Widget::start()
{
    setGameAreaButtonStyle();
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            gameArea[row][column] = '-';
        }
    }
    progress = 0;
    gameStart = true;
    stop = false;

    if (player != 'x') {
        compurtInGame();
    }
}

void Widget::lockPlayer()
{
    if (player == 'x') {
        playerLocked = false;
    } else {
        playerLocked = true;
    }
}

// клик по кнопе play/give_up
void Widget::on_startButton_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
    if (gameStart) {
        playerLocked = false;
        ui->startButton->setText("play");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonStyle());
        ui->leftButton->setDisabled(false);
        ui->rightButton->setDisabled(false);
        gameStart = false;
        ui->messageLabel->setText("you lose...");
        ui->messageLabel->setStyleSheet(StyleHelper::getLostMessageStyle());
    } else {
        ui->messageLabel->setText("gooo...");
        ui->messageLabel->setStyleSheet(StyleHelper::getNormalMessageStyle());
        start();
        lockPlayer();
        ui->startButton->setText("i give up...");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonGameStyle());
        ui->leftButton->setDisabled(true);
        ui->rightButton->setDisabled(true);
    }
}

void Widget::onGameAreaButtonClicked()
{
    if (!playerLocked) {
        QPushButton *btn = qobject_cast <QPushButton*> (sender());
        int row = btn->property("row").toInt();
        int column = btn->property("column").toInt();
        QString style;
        if (player == 'x') {
            style = StyleHelper::getCrossNormalStyle();
            gameArea[row][column] = 'x';
        } else {
            style = StyleHelper::getZeroNormalStyle();
            gameArea[row][column] = '0';
        }
        changeButtonStyle(row, column, style);
        playerLocked = true;
        progress++;
        chekGameStop();
        endGame();
        compurtInGame();
    }
}

void Widget::compurtInGame()
{
    if (stop) {
        return;
    }
    srand(time(0));
    int index = rand()%6;;
    QStringList list = {"my move!", "i should think...", "Hmm... difficult...", "ooo...", "o my god!", "help me :("};
    ui->messageLabel->setText(list.at(index));
    timer->start(2000);
}

void Widget::onComputerSlot()
{
    char comp;
    QString style;
    if (player == 'x') {
        comp = '0';
        style = StyleHelper::getZeroNormalStyle();
    } else {
        comp = 'x';
        style = StyleHelper::getCrossNormalStyle();
    }
    timer->stop();
    while (true) {
        int row = rand()%3;
        int column = rand()%3;
        if (gameArea[row][column] == '-') {
            gameArea[row][column] = comp;
            changeButtonStyle(row, column, style);
            ui->messageLabel->setText("your move!");
            progress++;
            chekGameStop();
            endGame();
            playerLocked = false;
            break;
        }
    }
}

void Widget::changeButtonRowColumnStyle(QString &style)
{
    if (winner == player) {
        if (player == 'x') {
            style = StyleHelper::getCrossVictoryStyle();
        } else {
            style = StyleHelper::getZeroVictoryStyle();
        }
    } else {
        if (player == 'x') {
            style = StyleHelper::getCrossLostStyle();
        } else {
            style = StyleHelper::getZeroLostStyle();
        }
    }
}

void Widget::chekGameStop()
{
    winner = '-';
    QString style;

    char symbols[2] = {'x', '0'};
    for (int i = 0; i < 2; i++) {

        for (int row = 0; row < 3; row++) {
            if ((gameArea[row][0] == symbols[i]) and (gameArea[row][1] == symbols[i]) and (gameArea[row][2] == symbols[i])) {
                stop = true;
                winner = symbols[i];

                changeButtonRowColumnStyle(style);
                changeButtonStyle(row, 0, style);
                changeButtonStyle(row, 1, style);
                changeButtonStyle(row, 2, style);

                return;
            }
        }

        for (int column = 0; column < 3; column++) {
            if ((gameArea[0][column] == symbols[i]) and (gameArea[1][column] == symbols[i]) and (gameArea[2][column] == symbols[i])) {
                stop = true;
                winner = symbols[i];

                changeButtonRowColumnStyle(style);
                changeButtonStyle(0, column, style);
                changeButtonStyle(1, column, style);
                changeButtonStyle(2, column, style);

                return;
            }
        }

        if ((gameArea[0][0] == symbols[i]) and (gameArea[1][1] == symbols[i]) and (gameArea[2][2] == symbols[i])) {
            stop = true;
            winner = symbols[i];

            changeButtonRowColumnStyle(style);
            changeButtonStyle(0, 0, style);
            changeButtonStyle(1, 1, style);
            changeButtonStyle(2, 2, style);

            return;
        }

        if ((gameArea[0][2] == symbols[i]) and (gameArea[1][1] == symbols[i]) and (gameArea[2][0] == symbols[i])) {
            stop = true;
            winner = symbols[i];

            changeButtonRowColumnStyle(style);
            changeButtonStyle(0, 2, style);
            changeButtonStyle(1, 1, style);
            changeButtonStyle(2, 0, style);

            return;
        }
    }

    if (progress == 9) {
        stop = true;
    }
}

void Widget::endGame()
{
    if (stop) {

        if (winner == player) {
            ui->messageLabel->setText("wiiiiin!");
            ui->messageLabel->setStyleSheet(StyleHelper::getVictoryMessageStyle());
        } else if (winner == '-') {
            ui->messageLabel->setText("draw");
        } else {
            ui->messageLabel->setText("defeat :(");
            ui->messageLabel->setStyleSheet(StyleHelper::getLostMessageStyle());
        }
        playerLocked = true;

        ui->startButton->setText("play");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonStyle());
        ui->leftButton->setDisabled(false);
        ui->rightButton->setDisabled(false);
        gameStart = false;
    }
}


void Widget::on_aboutButton_clicked()
{
    if (swich != 0) {
        ui->aboutButton->setText("to the game");
        ui->aboutButton->setStyleSheet(StyleHelper::getStartButtonGameStyle());
    } else {
        ui->aboutButton->setText("about game");
        ui->aboutButton->setStyleSheet(StyleHelper::getStartButtonStyle());
    }
    ui->tabWidget->setCurrentIndex(swich);
    swich = (swich + 1)%2;
}

