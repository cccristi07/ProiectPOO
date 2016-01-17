#include "compare.h"
#include "ui_compare.h"
#include "monod.h"
#include "moser.h"
#include "powel.h"
#include "oxigen.h"
Compare::Compare(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Compare)
{
    ui->setupUi(this);
    ui->currentPlot->addGraph();
    ui->comparePlot1->addGraph();
    ui->comparePlot2->addGraph();
    ui->comparePlot3->addGraph();

    ui->currentPlot->addGraph();
    ui->comparePlot1->addGraph();
    ui->comparePlot2->addGraph();
    ui->comparePlot3->addGraph();



    ui->currentPlot->plotLayout()->insertRow(0);
    ui->comparePlot1->plotLayout()->insertRow(0);
    ui->comparePlot2->plotLayout()->insertRow(0);
    ui->comparePlot3->plotLayout()->insertRow(0);


}

Compare::~Compare()
{
    delete ui;
}

void Compare::plotCompare(Monod *m, Moser *ms, Powel *p, Oxigen *o)
{

    ui->currentPlot->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->currentPlot, "Monod"));
    ui->currentPlot->graph(0)->setData(m->getS(),m->getU());
    ui->currentPlot->graph(0)->setPen(QPen(Qt::red));
    ui->currentPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->currentPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle , 9));
    ui->currentPlot->graph(1)->setData(m->getX(),m->getY());
    //ui->currentPlot->graph(1)->setPen(QPen(QColor(120, 120, 120), 5));
    ui->currentPlot->update();
    ui->currentPlot->replot();
    ui->currentPlot->update();
    ui->currentPlot->xAxis->setLabel("S");
    ui->currentPlot->yAxis->setLabel("μ [1/h]");
    ui->currentPlot->xAxis->setRange(0,o->getS()[o->getS().size()-1]+1);
    ui->currentPlot->yAxis->setRange(0,1);
    ui->currentPlot->replot();


    ui->comparePlot1->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->comparePlot1,"Moser"));
    ui->comparePlot1->graph(0)->setData(ms->getS(),ms->getU());
    ui->comparePlot1->graph(0)->setPen(QPen(Qt::red));
    ui->comparePlot1->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->comparePlot1->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle , 9));
    ui->comparePlot1->graph(1)->setData(ms->getX(),ms->getY());
    //ui->comparePlot1->graph(1)->setPen(QPen(QColor(120, 120, 120), 5));
    ui->comparePlot1->update();
    ui->comparePlot1->replot();
    ui->comparePlot1->update();
    ui->comparePlot1->xAxis->setLabel("S");
    ui->comparePlot1->yAxis->setLabel("μ [1/h]");
    ui->comparePlot1->xAxis->setRange(0,o->getS()[o->getS().size()-1]+1);
    ui->comparePlot1->yAxis->setRange(0,1);
    ui->comparePlot1->replot();


    ui->comparePlot2->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->comparePlot2,"Andrews"));
    ui->comparePlot2->graph(0)->setData(p->getS(),p->getU());
    ui->comparePlot2->graph(0)->setPen(QPen(Qt::red));
    ui->comparePlot2->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->comparePlot2->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle , 9));
    ui->comparePlot2->graph(1)->setData(p->getX(),p->getY());
   // ui->comparePlot2->graph(1)->setPen(QPen(QColor(120, 120, 120), 5));
    ui->comparePlot2->update();
    ui->comparePlot2->replot();
    ui->comparePlot2->update();
    ui->comparePlot2->xAxis->setLabel("S");
    ui->comparePlot2->yAxis->setLabel("μ [1/h]");
    ui->comparePlot2->xAxis->setRange(0,o->getS()[o->getS().size()-1]+1);
    ui->comparePlot2->yAxis->setRange(0,1);
    ui->comparePlot2->replot();




    ui->comparePlot3->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->comparePlot3,"Olsson"));
    ui->comparePlot3->graph(0)->setData(o->getS(),o->getU());
    ui->comparePlot3->graph(0)->setPen(QPen(Qt::red));
    ui->comparePlot3->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->comparePlot3->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle , 9));
    ui->comparePlot3->graph(1)->setData(o->getX(),o->getY());
    //ui->comparePlot3->graph(1)->setPen(QPen(QColor(120, 120, 120), 3));
    ui->comparePlot3->update();
    ui->comparePlot3->replot();
    ui->comparePlot3->update();
    ui->comparePlot3->xAxis->setLabel("S");
    ui->comparePlot3->yAxis->setLabel("μ [1/h]");
    ui->comparePlot3->xAxis->setRange(0,o->getS()[o->getS().size()-1]+1);
    ui->comparePlot3->yAxis->setRange(0,1);
    ui->comparePlot3->replot();
}
