#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "voyageur.h"
#include "arduino.h"
#include <QMainWindow>
#include <QMainWindow>
#include <QPrinter>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextDocument>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     QSortFilterProxyModel *proxy;
    void show_tables();

private slots:
    void on_Ajouterbutton_clicked();

    void on_Supprimerbutton_clicked();

    //void on_combosupp_activated(const QString &arg1);

    void on_Modifierbutton_clicked();

    void on_tableview_activated(const QModelIndex &index);

    void on_sortid_clicked();

    void on_pushButton_clicked();

    void on_sortid_2_clicked();

    void on_rechercher_clicked();

    void on_ajoutstat_clicked();

private:
    Ui::MainWindow *ui;
    voyageur vtemp;
    QByteArray data; // variable contenant les données reçues
    arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
