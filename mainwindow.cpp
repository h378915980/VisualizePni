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
    QString filePath = fileDialog.getOpenFileName(this);
    qDebug()<<filePath;

    QStringList qsList = filePath.split("/");
    QString fileName = qsList[qsList.size()-1];
    qDebug()<<fileName;
    QString deviceType= qsList[qsList.size()-2];
    qDebug()<<deviceType;

    if(fileName.compare(QString::fromLocal8Bit("scanner.ini"))==0)
    {
        ui->lineEdit_filePath->setText(filePath);
    }
    else
    {
        QMessageBox::information(this,"notice","file type is error, needed scanner.ini!");
        return;
    }

    ui->lineEdit_deviceType->setText(deviceType);

    showAllSetting();
}


void MainWindow::on_pushButton_applyChange_clicked()
{
    if(ui->lineEdit_filePath->text()=="")
    {
        QMessageBox::information(this,"notice","please open file first!");
        return;
    }
    inifile::IniFile iniScanner;
    iniScanner.Load(ui->lineEdit_filePath->text().toStdString());
    iniScanner.SetIntValue("scanner_PET","crystal_num_X",ui->spinBox_crystalNumX->value());
    iniScanner.SetIntValue("scanner_PET","crystal_num_Y",ui->spinBox_crystalNumY->value());
    iniScanner.SetIntValue("scanner_PET","crystal_num_Z",ui->spinBox_crystalNumZ->value());
    iniScanner.Save();

    showAllSetting();
}

void MainWindow::showAllSetting()
{
    //config file example
    inifile::IniFile iniScanner;
    iniScanner.Load(ui->lineEdit_filePath->text().toStdString());
    iniScanner.GetIntValue("scanner_PET","crystal_num_X",&crystalNumX);
    iniScanner.GetIntValue("scanner_PET","crystal_num_Y",&crystalNumY);
    iniScanner.GetIntValue("scanner_PET","crystal_num_Z",&crystalNumZ);

    ui->spinBox_crystalNumX->setValue(crystalNumX);
    ui->spinBox_crystalNumY->setValue(crystalNumY);
    ui->spinBox_crystalNumZ->setValue(crystalNumZ);
}
