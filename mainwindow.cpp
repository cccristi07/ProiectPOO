#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "monod.h"
#include "getdata.h"
#include <QFileDialog>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "moser.h"
#include "powel.h"
#include "dialog.h"
#include <QPrinter>
#include <oxigen.h>
#include "compare.h"
#include "tabel.h"


using namespace boost::numeric::ublas;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   // tab = new Tabel();
    m = new Monod();
    p = new Powel();
    ms = new Moser();
    o = new Oxigen();
    date = new Monod();
    help = new Dialog();
    this->setWindowState(Qt::WindowMaximized);
    ui->setupUi(this);
    cmp = new Compare();



    ui->plotData->addGraph();
    ui->plotData->addGraph();
    ui->plotData->plotLayout()->insertRow(0);

//    ui->monod->addGraph();
//    ui->monod->addGraph();
//    ui->moser->addGraph();
//    ui->moser->addGraph();
//    ui->powel->addGraph();
//    ui->powel->addGraph();

//    ui->powel->graph(0)->setName("Experimental Data");
//    ui->powel->graph(1)->setName("Andrews-Noack");

//    ui->monod->graph(0)->setName("Experimental Data");
//    ui->monod->graph(1)->setName("Monod");

//    ui->moser->graph(0)->setName("Experimental Data");
//    ui->moser->graph(1)->setName("Moser");

//    ui->monod->plotLayout()->insertRow(0);
//    ui->monod->plotLayout()->addElement(0, 0, new QCPPlotTitle(ui->monod, "Monod"));

//    ui->moser->plotLayout()->insertRow(0);
//    ui->moser->plotLayout()->addElement(0, 0, new QCPPlotTitle(ui->moser, "Moser"));

//    ui->powel->plotLayout()->insertRow(0);
//    ui->powel->plotLayout()->addElement(0, 0, new QCPPlotTitle(ui->powel, "Andrews - Noack"));


//    QApplication::setStyle(QStyleFactory::create("Fusion"));
//    QPalette p;
//    p = qApp->palette();
//    p.setColor(QPalette::Window, QColor(43,53,80));
//    p.setColor(QPalette::Button, QColor(70,53,53));
//    p.setColor(QPalette::Highlight, QColor(142,45,197));
//    p.setColor(QPalette::ButtonText, QColor(255,255,255));
//    qApp->setPalette(p);


//    QLinearGradient plotGradient;
//    plotGradient.setStart(0, 0);
//    plotGradient.setFinalStop(0, 350);
//    plotGradient.setColorAt(0, QColor(80, 80, 80));
//    plotGradient.setColorAt(1, QColor(50, 50, 50));
//    ui->monod->setBackground(plotGradient);
//    ui->moser->setBackground(plotGradient);
//    ui->powel->setBackground(plotGradient);
//    QLinearGradient axisRectGradient;
//    axisRectGradient.setStart(0, 0);
//    axisRectGradient.setFinalStop(0, 350);
//    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
//    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
//    ui->monod->axisRect()->setBackground(axisRectGradient);
//    ui->moser->axisRect()->setBackground(axisRectGradient);
//    ui->powel->axisRect()->setBackground(axisRectGradient);



//    ui->monod->xAxis->setBasePen(QPen(Qt::white, 1));
//    ui->monod->yAxis->setBasePen(QPen(Qt::white, 1));
//    ui->monod->xAxis->setTickPen(QPen(Qt::white, 1));
//    ui->monod->yAxis->setTickPen(QPen(Qt::white, 1));
//    ui->monod->xAxis->setSubTickPen(QPen(Qt::white, 1));
//    ui->monod->yAxis->setSubTickPen(QPen(Qt::white, 1));
//    ui->monod->xAxis->setTickLabelColor(Qt::white);
//    ui->monod->yAxis->setTickLabelColor(Qt::white);
//    ui->monod->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
//    ui->monod->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
//    ui->monod->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
//    ui->monod->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
//    ui->monod->xAxis->grid()->setSubGridVisible(true);
//    ui->monod->yAxis->grid()->setSubGridVisible(true);
//    ui->monod->xAxis->grid()->setZeroLinePen(Qt::NoPen);
//    ui->monod->yAxis->grid()->setZeroLinePen(Qt::NoPen);
//    ui->monod->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
//    ui->monod->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

//    ui->moser->xAxis->setBasePen(QPen(Qt::white, 1));
//    ui->moser->yAxis->setBasePen(QPen(Qt::white, 1));
//    ui->moser->xAxis->setTickPen(QPen(Qt::white, 1));
//    ui->moser->yAxis->setTickPen(QPen(Qt::white, 1));
//    ui->moser->xAxis->setSubTickPen(QPen(Qt::white, 1));
//    ui->moser->yAxis->setSubTickPen(QPen(Qt::white, 1));
//    ui->moser->xAxis->setTickLabelColor(Qt::white);
//    ui->moser->yAxis->setTickLabelColor(Qt::white);
//    ui->moser->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
//    ui->moser->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
//    ui->moser->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
//    ui->moser->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
//    ui->moser->xAxis->grid()->setSubGridVisible(true);
//    ui->moser->yAxis->grid()->setSubGridVisible(true);
//    ui->moser->xAxis->grid()->setZeroLinePen(Qt::NoPen);
//    ui->moser->yAxis->grid()->setZeroLinePen(Qt::NoPen);
//    ui->moser->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
//    ui->moser->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

//    ui->powel->xAxis->setBasePen(QPen(Qt::white, 1));
//    ui->powel->yAxis->setBasePen(QPen(Qt::white, 1));
//    ui->powel->xAxis->setTickPen(QPen(Qt::white, 1));
//    ui->powel->yAxis->setTickPen(QPen(Qt::white, 1));
//    ui->powel->xAxis->setSubTickPen(QPen(Qt::white, 1));
//    ui->powel->yAxis->setSubTickPen(QPen(Qt::white, 1));
//    ui->powel->xAxis->setTickLabelColor(Qt::white);
//    ui->powel->yAxis->setTickLabelColor(Qt::white);
//    ui->powel->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
//    ui->powel->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
//    ui->powel->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
//    ui->powel->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
//    ui->powel->xAxis->grid()->setSubGridVisible(true);
//    ui->powel->yAxis->grid()->setSubGridVisible(true);
//    ui->powel->xAxis->grid()->setZeroLinePen(Qt::NoPen);
//    ui->powel->yAxis->grid()->setZeroLinePen(Qt::NoPen);
//    ui->powel->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
//    ui->powel->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);







}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{




}

void MainWindow::on_pushButton_clicked()
{

    if( filename == NULL )
    {

        QMessageBox::information(this,"Info","Selectati un set de date");
        return;

    }

//    ui->monod->legend->setVisible(true);
//    ui->powel->legend->setVisible(true);
//    ui->moser->legend->setVisible(true);


//   ui->monod->graph(0)->setData(m->getS(),m->getU());
//   ui->monod->graph(0)->setPen(QPen(Qt::red));
//   ui->monod->graph(0)->setLineStyle(QCPGraph::lsNone);
//   ui->monod->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle , 9));
//   ui->monod->graph(1)->setData(m->getX(),m->getY());
//   ui->monod->graph(1)->setPen(QPen(QColor(120, 120, 120), 5));
//   ui->monod->update();
//   ui->monod->replot();
//   ui->monod->update();
//   ui->monod->xAxis->setLabel("S");
//   ui->monod->yAxis->setLabel("μ [1/h]");
//   ui->monod->xAxis->setRange(0,o->getS()[o->getS().size()-1]+1);
//   ui->monod->yAxis->setRange(0,1);
//   ui->monod->replot();

    /*ui->moser->graph(0)->setData(ms->getS(),ms->getU());
    ui->moser->graph(0)->setPen(QPen(Qt::red));
    ui->moser->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->moser->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle , 4));
    ui->moser->graph(1)->setData(ms->getX(),ms->getY());
    ui->moser->replot();
    ui->moser->update();
    ui->moser->rescaleAxes();*/



//   ui->moser->graph(0)->setData(ms->getS(),ms->getU());
//   ui->moser->graph(0)->setPen(QPen(Qt::red));
//   ui->moser->graph(0)->setLineStyle(QCPGraph::lsNone);
//   ui->moser->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle , 9));
//   ui->moser->graph(1)->setData(ms->getX(),ms->getY());
//   ui->moser->graph(1)->setPen(QPen(QColor(120, 120, 120), 5));
//   ui->moser->update();
//   ui->moser->replot();
//   ui->moser->update();
//   ui->moser->xAxis->setLabel("S");
//   ui->moser->yAxis->setLabel("μ[1/h]");
//   ui->moser->xAxis->setRange(0,ms->getS()[ms->getS().size()-1]+1);
//   ui->moser->yAxis->setRange(0,1);
//   ui->moser->replot();



//    ui->powel->graph(0)->setData(p->getS(),p->getU());
//    ui->powel->graph(0)->setPen(QPen(Qt::red));
//    ui->powel->graph(0)->setLineStyle(QCPGraph::lsNone);
//    ui->powel->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle , 9));
//    ui->powel->graph(1)->setData(p->getX(),p->getY());
//    ui->powel->graph(1)->setPen(QPen(QColor(120, 120, 120), 5));
//    ui->powel->update();
//    ui->powel->replot();
//    ui->powel->update();
//    ui->powel->xAxis->setLabel("S");
//    ui->powel->yAxis->setLabel("μ[1/h]");
//    ui->powel->xAxis->setRange(0,o->getS()[o->getS().size()-1]+1);
//    ui->powel->yAxis->setRange(0,1);
//    ui->powel->replot();





}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_actionManual_F1_triggered()
{
    help->show();
}

void MainWindow::on_browse_clicked()
{
    delete m;
    delete ms;
    delete p;
    delete o;
    delete date;
    filename =  QFileDialog::getOpenFileName(this,tr("Open text File"), "", tr("Text Files (*.txt)"));



    if ( filename == NULL )
        return;
    else
    {
        m = new Monod(filename);
        ms = new Moser(filename);
        p = new Powel(filename);
        o = new Oxigen(filename);
        date = new Monod(filename);
    }

}

void MainWindow::on_saveas_clicked()
{
    QString savefile = QFileDialog::getSaveFileName(this,"SaveGraph","",tr("Image ( *.jpg )"));

    ui->plotData->saveJpg(savefile+".jpg",0,0,1.0,-1);


}

void MainWindow::on_plot_clicked()
{
    if( filename == NULL )
    {

        QMessageBox::information(this,"Info","Selectati un set de date");
        return;

    }

    ui->eroare_moser->setText("ε :" + QString::number(ms->getErr(2)));
    ui->eroare_monod->setText("ε :" + QString::number(m->getErr(2)));
    ui->eroare_andrews->setText("ε :" +QString::number(p->getErr(2)));
    ui->eroare_olsson->setText("ε :" +QString::number(o->getErr(2)));

    ui->umax->setText("------");
    ui->kc->setText("------");
    ui->ks->setText("------");
    ui->ki->setText("------");
    if(ui->monodButton->isChecked())
    {
        ui->plotData->plotLayout()->removeAt(0);
        ui->plotData->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->plotData, "Monod"));
        ui->plotData->graph(0)->setData(m->getS(),m->getU());
        ui->plotData->graph(0)->setPen(QPen(Qt::red));
        ui->plotData->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->plotData->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle , 9));
        ui->plotData->graph(1)->setData(m->getX(),m->getY());
        //ui->plotData->graph(1)->setPen(QPen(QColor(120, 120, 120), 5));
        ui->plotData->update();
        ui->plotData->replot();
        ui->plotData->update();
        ui->plotData->xAxis->setLabel("S");
        ui->plotData->yAxis->setLabel("μ [1/h]");
        ui->plotData->xAxis->setRange(0,o->getS()[o->getS().size()-1]+1);
        ui->plotData->yAxis->setRange(0,1);
        ui->plotData->replot();
        ui->ks->setText(QString::number(m->getKs()));
        ui->umax->setText(QString::number(m->getUMax()));

    }
    else if ( ui->moserButton->isChecked() )
    {
        ui->plotData->plotLayout()->removeAt(0);
        ui->plotData->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->plotData,"Moser"));
        ui->plotData->graph(0)->setData(ms->getS(),ms->getU());
        ui->plotData->graph(0)->setPen(QPen(Qt::red));
        ui->plotData->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->plotData->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle , 9));
        ui->plotData->graph(1)->setData(ms->getX(),ms->getY());
        //ui->plotData->graph(1)->setPen(QPen(QColor(120, 120, 120), 5));
        ui->plotData->update();
        ui->plotData->replot();
        ui->plotData->update();
        ui->plotData->xAxis->setLabel("S");
        ui->plotData->yAxis->setLabel("μ [1/h]");
        ui->plotData->xAxis->setRange(0,o->getS()[o->getS().size()-1]+1);
        ui->plotData->yAxis->setRange(0,1);
        ui->plotData->replot();
        ui->ks->setText(QString::number(ms->getKs()));
        ui->umax->setText(QString::number(ms->getUMax()));


    }
    else if ( ui->andrewsButton->isChecked() )
    {

        ui->plotData->plotLayout()->removeAt(0);
        ui->plotData->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->plotData,"Andrews"));
        ui->plotData->graph(0)->setData(p->getS(),p->getU());
        ui->plotData->graph(0)->setPen(QPen(Qt::red));
        ui->plotData->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->plotData->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle , 9));
        ui->plotData->graph(1)->setData(p->getX(),p->getY());
       // ui->plotData->graph(1)->setPen(QPen(QColor(120, 120, 120), 5));
        ui->plotData->update();
        ui->plotData->replot();
        ui->plotData->update();
        ui->plotData->xAxis->setLabel("S");
        ui->plotData->yAxis->setLabel("μ [1/h]");
        ui->plotData->xAxis->setRange(0,o->getS()[o->getS().size()-1]+1);
        ui->plotData->yAxis->setRange(0,1);
        ui->plotData->replot();
        ui->ks->setText(QString::number(p->getKs()));
        ui->ki->setText(QString::number(p->getKi()));

    }
    else if( ui->olssonButton->isChecked() )
    {

        ui->plotData->plotLayout()->removeAt(0);
        ui->plotData->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->plotData,"Olsson"));
        ui->plotData->graph(0)->setData(o->getS(),o->getU());
        ui->plotData->graph(0)->setPen(QPen(Qt::red));
        ui->plotData->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->plotData->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle , 9));
        ui->plotData->graph(1)->setData(o->getX(),o->getY());
        //ui->plotData->graph(1)->setPen(QPen(QColor(120, 120, 120), 3));
        ui->plotData->update();
        ui->plotData->replot();
        ui->plotData->update();
        ui->plotData->xAxis->setLabel("S");
        ui->plotData->yAxis->setLabel("μ [1/h]");
        ui->plotData->xAxis->setRange(0,o->getS()[o->getS().size()-1]+1);
        ui->plotData->yAxis->setRange(0,1);
        ui->plotData->replot();
        ui->ks->setText(QString::number(o->getKs()));
        ui->umax->setText(QString::number(o->getUMax()));
        ui->kc->setText(QString::number(o->getKc()));


    }
    else{


        QMessageBox::information(this,"Info","Selectati un model");
        return;
    }
}

void MainWindow::on_compare_clicked()
{
    cmp->setWindowState(Qt::WindowMaximized);
    cmp->plotCompare(m,ms,p,o);
    cmp->exec();

}


void MainWindow::on_actionData_Table_triggered()
{
    QTableWidget *table = new QTableWidget;
    QStringList table_header;
    QVector<double> t = date->getTime();
    QVector<double> DO = date->get_DO();
    QVector<double> pH = date->get_PH();
    QVector<double> S = date->get_S();
    QVector<double> O2 = date->get_O2();
   // tab->show();
   table->setRowCount(t.size());
   table->setColumnCount(5);
    table_header << "Timp" << "D.O." << "pH" << "NNH2" << "Oxigen dizolvat";
   table->setHorizontalHeaderLabels(table_header);
    for(int i = 0; i < t.size(); i++)
    {
        table->setItem(i, 0, new QTableWidgetItem(QString::number((t[i]))));
        table->setItem(i, 1, new QTableWidgetItem(QString::number(DO[i])));
        table->setItem(i, 2, new QTableWidgetItem(QString::number(pH[i])));
        table->setItem(i, 3, new QTableWidgetItem(QString::number(S[t.size() - 1 - i]+date->delay)));
        table->setItem(i, 4, new QTableWidgetItem(QString::number(O2[i])));


    }
    table->setShowGrid(true);
    table->show();



}
