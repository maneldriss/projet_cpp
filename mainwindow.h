#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<avion.h>
#include <QMainWindow>
#include<QRegExp>

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
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_afficher_clicked();
    void on_pb_modifier_clicked();

    void on_pb_tri_clicked();
    void on_pb_rech_mod_clicked();

   void on_pdf_clicked();
     void on_pb_tri_desc_clicked();

private:
    Ui::MainWindow *ui;
    Avion a;
};

#endif // MAINWINDOW_H
