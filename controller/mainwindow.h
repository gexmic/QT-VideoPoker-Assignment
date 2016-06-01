#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void onButtonClick();
public slots:
    void onDrawOrDealClick();

private:
    Ui::MainWindow *ui;

   std::vector<QPushButton *> _cardButton;
};

#endif // MAINWINDOW_H
