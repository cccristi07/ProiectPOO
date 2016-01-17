#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>
#include "monod.h"
#include "moser.h"
#include "powel.h"
#include "dialog.h"
#include "oxigen.h"
#include "compare.h"
#include "tabel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_actionManual_F1_triggered();

    void on_browse_clicked();

    void on_saveas_clicked();

    void on_plot_clicked();

    void on_compare_clicked();


    void on_actionData_Table_triggered();

private:
    Ui::MainWindow *ui;
    QString filename;
    Monod *m, *date;
    Moser *ms;
    Powel *p;
    Dialog *help;
    Oxigen *o;
    Compare *cmp;
    Tabel *tab;
};

#endif // MAINWINDOW_H
