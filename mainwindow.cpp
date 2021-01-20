#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_File_triggered()
{
    QFileDialog fileDialog;
    QString fileName = fileDialog.getOpenFileName(this);
    if(fileName!="")
        ui->lineEdit_FileName->setText(fileName);
}
