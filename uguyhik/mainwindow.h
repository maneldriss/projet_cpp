#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QRegExp>
#include <QMainWindow>
#include"employe.h"
#include"login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pb_supp_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_ch_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_tri_2_clicked();

    void on_pushButton_tri_3_clicked();

private:
    Ui::MainWindow *ui;
    MainWindow *Page;
    Employe e;
};

#endif // MAINWINDOW_H
