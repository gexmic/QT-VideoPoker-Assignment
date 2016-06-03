// /////////////////////////////////////////////////////////////////////
// File:  Jack or Bette Games
//
// Author: Michael Landry
// This assignment represents my own work and is in accordance with the College Academic Policy
//
// Copyright (c) 2016 All Right Reserved by Michael Landry
// Contributors:
// Description:  This is the game of poker Jack or Better, this programme simulate 5 card poker hand
// and the player is able to change any card for a redraw and have new card. the player win if I have a pair of jack or better
// all the card are old in the hand call like the real life.
//
// Date: juin 3 2016
// Revisions:
//
// ///////////////////////////////////////////////////////////////////

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

    // set the jack or better banner
    QPixmap banner(":/media/media/banner.png");
    auto lblBanner = new  QLabel;
    lblBanner->setMinimumSize(1000,250);
    lblBanner->setMaximumSize(1000,250);
    lblBanner->setPixmap( QPixmap( banner) );
    lblBanner->setScaledContents( true );
    lblBanner->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    vlPayTable->addWidget(lblBanner);

    // set the pay table banner
    QPixmap payTable(":/media/media/paysheet1.png");
    auto lblPayTable = new  QLabel;
    lblPayTable->setMinimumSize(1000,250);
    lblPayTable->setMaximumSize(1000,250);
    lblPayTable->setPixmap( QPixmap( payTable) );
    lblPayTable->setScaledContents( true );
    lblPayTable->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    vlPayTable->addWidget(lblPayTable);

    // set the card for the game
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

    // connect the card to the signal mapper
    connect(signalMapper,
            static_cast<void(QSignalMapper::*)(int)>(&QSignalMapper::mapped),
            this,
            &MainWindow::onButtonCardClick);

    vlPayTable->addLayout(hlFiveCard);

    auto hlbutton = new QHBoxLayout();

    // set the button draw or deal
    _btnDrawOrDeal = new QPushButton(this);
    _btnDrawOrDeal->setText("Deal");
    _btnDrawOrDeal->setObjectName("btnDrawAndDeal");
    _btnDrawOrDeal->setMinimumSize(75,75);
    _btnDrawOrDeal->setMaximumSize(75,75);
    _btnDrawOrDeal->setStyleSheet("background:rgb(160,160,160);");
    // connect the button draw or deal
    connect (_btnDrawOrDeal , &QPushButton::clicked, this, &MainWindow::onDrawOrDealClick);
    // set the play button
    _btnPlay = new QPushButton(this);
    _btnPlay->setText("Play");
    _btnPlay->setObjectName("btbPlay");
    _btnPlay->setMinimumSize(75,75);
    _btnPlay->setMaximumSize(75,75);
    _btnPlay->setStyleSheet("background:rgb(160,160,160);");
    connect (_btnPlay , &QPushButton::clicked, this, &MainWindow::onPlayClick);
    // set a lable to display what is the value of the hand
    _handResultText = new QLabel(this);
    _handResultText->setObjectName("lblHandResult");
    _handResultText->setMinimumSize(800,40);
    _handResultText->setMaximumSize(800,40);
    QFont phraseBtnFont( "Cooper Black", 15, QFont::Bold);
    _handResultText->setFont(phraseBtnFont);

    // add the button and the lable to a horozontal layout
    hlbutton->addWidget(_btnDrawOrDeal);
    hlbutton->addWidget(_btnPlay);
    hlbutton->addWidget(_handResultText);
    QSpacerItem *hSpacer = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum);
    hlbutton->addSpacerItem(hSpacer);
    vlPayTable->addLayout(hlbutton);

    vlMain->addLayout(vlPayTable);
    // set the card to face back at the start
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
    // go to each car and check the string to put in and the color and also if the card is hold or not
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
    // toggel hold at or not at the card click
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
    // if the game state is played hand it draw the next hand from wich card is hold or not and find the value of the hand
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

    //if the game state is a new hand change the draw button to deal and set the text to blank
    if(_pokerGame->isNewHand())
    {
        _btnDrawOrDeal->setText("Deal");
        _pokerGame->dealOrDraw();
        _handResultText->setText("");

    }
    // change the game state depend on what is the current game sate
    if(_pokerGame->isPlayedHand())
        _pokerGame->gameState(false);
    else
        _pokerGame->gameState(true);



    draw();

}

void MainWindow::onPlayClick()
{
    // change the card and the draw or deal button to be enable and disable the play button
    for(int i = 0 ; i < NUMBEROFCARD;++i)
    {
        _cardButton.at(i)->setEnabled(true);
    }

    _btnDrawOrDeal->setEnabled(true);
    _btnPlay->setEnabled(false);

    draw();

}
