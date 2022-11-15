#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>

using namespace std;

namespace Ui {
class qr;
}

class qr : public QDialog
{
    Q_OBJECT

public:
    explicit qr(QWidget *parent = nullptr);


    ~statistique();

private:
    Ui::statistique *ui;
private slots :
};

#endif // STATISTIQUE_H

