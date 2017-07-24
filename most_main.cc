#include "most_main.h"
#include "ui_most_main.h"

most_main::most_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::most_main)
{
    ui->setupUi(this);
}

most_main::~most_main()
{
    delete ui;
}
