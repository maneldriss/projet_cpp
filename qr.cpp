#include "qr.h"
#include "ui_mainwindow.h"
#include<iostream>
#include "mainwindow.h"
#include "bagage.h"


    qr::qr(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::statistique)
    {
        ui->setupUi(this);
    }

    qr::~qr()
    {
        delete ui;
    }
qr::qr()
{ ui->setupUi(this);
    ui->tabfac->setModel(f.afficher());//refresh
       ui->prix_ach->setValidator(new QIntValidator (0,999999,this));


       QString data = "text to be encoded";
       QImage barcode = QZXing::encodeData(data);

       QGraphicsScene *graphic = new QGraphicsScene(this);
       graphic->addPixmap( QPixmap::fromImage(barcode));
       ui->graphicsView->setScene(graphic);
}
