#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <vector>
#include<memory>

// forward declaration
class videoPokerGame;
class Hand;
class Deck;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void draw();

public slots:
    void onButtonCardClick(int);
public slots:
    void onDrawOrDealClick();
public slots:
    void onPlayClick();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<videoPokerGame> _pokerGame;
    QPushButton * _btnPlay;
    QPushButton * _btnDrawOrDeal;
    QLabel * _handResultText;
    std::unique_ptr<Hand> _hand;
    std::unique_ptr<Deck> _deck;
    std::vector<QPushButton *> _cardButton;
};

#endif // MAINWINDOW_H
