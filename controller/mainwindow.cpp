#include "controller/mainwindow.h"
#include "ui_mainwindow.h"
#include "../model/videopokergame.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QPushButton>
#include <QSignalMapper>
#include <QDebug>
#include <memory>
#include <QSpacerItem>


static const int NUMBEROFCARD = 5;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    _pokerGame = std::unique_ptr<videoPokerGame>(new videoPokerGame);

    _pokerGame->dealOrDraw();
    _pokerGame->fillVectorWithTrue();

    QSignalMapper * signalMapper = new QSignalMapper(this);

    auto vlMain = new QHBoxLayout(ui->centralWidget);

    ui->centralWidget->setStyleSheet("background:rgb(8,91,13);");

    auto vlPayTable = new QVBoxLayout();
    auto hlFiveCard = new QHBoxLayout();

    QPixmap banner(":/media/media/banner.png");
    auto lblBanner = new  QLabel;
    lblBanner->setMinimumSize(1000,250);
    lblBanner->setMaximumSize(1000,250);
    lblBanner->setPixmap( QPixmap( banner) );
    lblBanner->setScaledContents( true );
    lblBanner->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    vlPayTable->addWidget(lblBanner);


    QPixmap payTable(":/media/media/paysheet1.png");
    auto lblPayTable = new  QLabel;
    lblPayTable->setMinimumSize(1000,250);
    lblPayTable->setMaximumSize(1000,250);
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
            &MainWindow::onButtonCardClick);

    vlPayTable->addLayout(hlFiveCard);

    auto hlbutton = new QHBoxLayout();

    _btnDrawOrDeal = new QPushButton(this);
    _btnDrawOrDeal->setText("Deal");
    _btnDrawOrDeal->setObjectName("btnDrawAndDeal");
    _btnDrawOrDeal->setMinimumSize(75,75);
    _btnDrawOrDeal->setMaximumSize(75,75);
    _btnDrawOrDeal->setStyleSheet("background:rgb(160,160,160);");

    connect (_btnDrawOrDeal , &QPushButton::clicked, this, &MainWindow::onDrawOrDealClick);

    _btnPlay = new QPushButton(this);
    _btnPlay->setText("Play");
    _btnPlay->setObjectName("btbPlay");
    _btnPlay->setMinimumSize(75,75);
    _btnPlay->setMaximumSize(75,75);
    _btnPlay->setStyleSheet("background:rgb(160,160,160);");
    connect (_btnPlay , &QPushButton::clicked, this, &MainWindow::onPlayClick);

    _handResultText = new QLabel(this);
    _handResultText->setObjectName("lblHandResult");
    _handResultText->setMinimumSize(500,40);
    _handResultText->setMaximumSize(500,40);
    QFont phraseBtnFont( "Cooper Black", 15, QFont::Bold);
    _handResultText->setFont(phraseBtnFont);

    hlbutton->addWidget(_btnDrawOrDeal);
    hlbutton->addWidget(_btnPlay);
    hlbutton->addWidget(_handResultText);
    QSpacerItem *hSpacer = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum);
    hlbutton->addSpacerItem(hSpacer);
    vlPayTable->addLayout(hlbutton);

    vlMain->addLayout(vlPayTable);

    _btnDrawOrDeal->setEnabled(false);
    for(int i = 0 ; i < NUMBEROFCARD; ++i)
    {
        _cardButton.at(i)->setEnabled(false);

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw()
{
    for(int i = 0 ; i < NUMBEROFCARD;++i)
    {
        QString styleSheet = QString ("border-image:url(:/media/media/%1.png); color: %2;");

        QString cardString = QString::fromStdString(_pokerGame->cardToStringAtIdx(i));
        QString cardColor = "black";
        QString design = "cardfront";

        if(_pokerGame->cardColorAtIdx(i)== CardColor::Red)
            cardColor = "red";
        else
            cardColor = "black";

        if(_pokerGame->isCardHoldAtIdx(i))
            design = "cardfrontHold";
        else
            design = "cardfront";

        _cardButton.at(i)->setText(cardString);
        _cardButton.at(i)->setStyleSheet(styleSheet.arg(design).arg(cardColor));
    }
}

void MainWindow::onButtonCardClick(int idx)
{
    if(_pokerGame->isPlayedHand())
    {
    _pokerGame->toggelHoldAtIdx(idx);
    draw();
    }
    else
        return;

}

void MainWindow::onDrawOrDealClick()
{

    if (_pokerGame->isPlayedHand())
    {
        _pokerGame->drawSecoundHand();
        _pokerGame->dealOrDraw();
        _pokerGame->fillVectorWithTrue();
        _btnDrawOrDeal->setText("Draw");
        Rank rank = _pokerGame->findValueOftheHand();
        QString rankCard = QString::fromStdString(_pokerGame->_handRank.at(rank));
        QString rankPay = QString::fromStdString(_pokerGame->_handPay.at(rank));
        _handResultText->setText(rankCard+" it pays "+rankPay+" time your bet");
    }

    if(_pokerGame->isNewHand())
    {
        _btnDrawOrDeal->setText("Deal");
        _pokerGame->dealOrDraw();
        _handResultText->setText("");

    }
    if(_pokerGame->isPlayedHand())
        _pokerGame->gameState(false);
    else
        _pokerGame->gameState(true);



    draw();

}

void MainWindow::onPlayClick()
{
    for(int i = 0 ; i < NUMBEROFCARD;++i)
    {
        _cardButton.at(i)->setEnabled(true);
    }

    _btnDrawOrDeal->setEnabled(true);
    _btnPlay->setEnabled(false);

    draw();

}
