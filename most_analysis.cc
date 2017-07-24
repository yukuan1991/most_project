#include "most_analysis.h"
#include "ui_most_analysis.h"

most_analysis::most_analysis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::most_analysis)
{
    ui->setupUi(this);
}

most_analysis::~most_analysis()
{
    delete ui;
}

