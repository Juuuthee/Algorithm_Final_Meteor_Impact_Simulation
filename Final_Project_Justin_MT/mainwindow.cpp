#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QMessageBox>
#include <iostream>
#include <cmath>
#include <QDebug>
#include <QString>
#include <QLabel>
#include <ui_mainwindow.h>



    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));
    }


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    vimpact = ui -> doubleSpinBox -> value ();
    mdensity = ui -> doubleSpinBox_2 -> value ();
    timeprimary = ui -> doubleSpinBox_4 -> value ();
    radiusm = ui -> doubleSpinBox_3 -> value ();

    const double PI = 3.14;
    volume = (1.33333333*PI*(radiusm)*(radiusm)*(radiusm));
    mass = (mdensity*volume);
    previousFaverage = faverage;
    faverage = ((mass*(0-vimpact))/(timeprimary));

    ui -> lcdNumber -> display(faverage);


    if (radiusm <= 0 || mdensity <= 0 || timeprimary <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter valid positive values for radius of the meteor, meteor density, and time primary impact lasted.");

        return;
    }




}

void MainWindow::resetValues()
{
    ui->doubleSpinBox->setValue(0.0);
    ui->doubleSpinBox_2->setValue(0.0);
    ui->doubleSpinBox_3->setValue(0.0);
    ui->doubleSpinBox_4->setValue(0.0);
    ui->lcdNumber->display(0.0);
}




void MainWindow::on_pushButton_2_clicked()
{
    resetValues();
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Justin's Final Algorithm Project");
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setText("This is my algorithm for final algorithm project :<br />In This Algorithm Users Are Able To Calculate Force Average For The Questions Shown In The Qt UI, In Mainwindow.cpp it is shown the code calculation to calculate volume, mass for then used to find average force. The value of average force is then shown in the lcdNumber. It Also shows the code for if the value of (Meteor Density, Time Primary Impact Lasted And Radius Of The Meteor) is equal or less than 0 it will pop out a qmessagebox and tell the users that the input is invalid. Below That shows a code (Reset Values), it is used to reset the values so that users will be able to reset the values back to zero after using it. The code below is added to help users see the previous f average value at the lcdNumber. This Code Is An Original Code Made By Me (Justin Theodore)");
    msgBox.exec();
}


void MainWindow::on_pushButton_4_clicked()
{

    resetValues();
    ui->lcdNumber->display(previousFaverage);
}


