#include "controller/mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QPushButton>
#include <QSignalMapper>
#include <QDebug>



static const int NUMBEROFCARD = 5;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     QSignalMapper * signalMapper = new QSignalMapper(this);

    auto vlMain = new QHBoxLayout(ui->centralWidget);

    ui->centralWidget->setStyleSheet("background:rgb(8,91,13);");

    auto vlPayTable = new QVBoxLayout();
    auto hlFiveCard = new QHBoxLayout();

    QPixmap banner(":/media/media/banner.png");
    auto lblBanner = new  QLabel;
    lblBanner->setPixmap( QPixmap( banner) );
    lblBanner->setScaledContents( true );
    lblBanner->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    vlPayTable->addWidget(lblBanner);


    QPixmap payTable(":/media/media/paysheet1.png");
    auto lblPayTable = new  QLabel;
    lblPayTable->setPixmap( QPixmap( payTable) );
    lblPayTable->setScaledContents( true );
    lblPayTable->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    //lblPayTable->setMinimumSize(600,150);
   // lblPayTable->setMaximumSize(600,150);
    vlPayTable->addWidget(lblPayTable);

    for (int i = 0; i<NUMBEROFCARD;++i)
    {
       auto btnCard = new QPushButton(this);
        btnCard->setObjectName("btnCard");
        btnCard->setMinimumSize(150,250);
        btnCard->setMaximumSize(150,250);
        btnCard->setFlat( true );
        btnCard->setCheckable( true );
        QFont cardFont( "Times New Roman", 15, QFont::Bold);
        btnCard->setFont(cardFont);
        btnCard->setStyleSheet("border-image:url(:/media/media/cardback)");
        hlFiveCard->addWidget(btnCard);

        _cardButton.push_back(btnCard);

        connect(btnCard,
                &QPushButton::clicked,
                signalMapper,
                static_cast<void(QSignalMapper:: *)()>(&QSignalMapper::map));

        signalMapper->setMapping(btnCard,i);

    }


    connect(signalMapper,
            static_cast<void(QSignalMapper::*)(int)>(&QSignalMapper::mapped),
            this,
            &MainWindow::onButtonClick);

    vlPayTable->addLayout(hlFiveCard);

    auto btnDrawAndDeal = new QPushButton();
    btnDrawAndDeal->setText("Draw");
    btnDrawAndDeal->setObjectName("btnDrawAndDeal");
    btnDrawAndDeal->setMinimumSize(75,75);
    btnDrawAndDeal->setMaximumSize(75,75);
    btnDrawAndDeal->setStyleSheet("background:rgb(160,160,160);");

    connect (btnDrawAndDeal , &QPushButton::clicked, this, &MainWindow::onDrawOrDealClick);

    vlPayTable->addWidget(btnDrawAndDeal);
    vlMain->addLayout(vlPayTable);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClick()
{

}

void MainWindow::onDrawOrDealClick()
{

}
