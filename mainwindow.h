#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include "./source/tool/inifile.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_File_triggered();

    void on_pushButton_applyChange_clicked();

private:
    Ui::MainWindow *ui;

    int crystalNumX;
    int crystalNumY;
    int crystalNumZ;

    void showAllSetting();
};
#endif // MAINWINDOW_H
