#include "most_widget.h"
#include "ui_most_widget.h"

most_widget::most_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::most_widget)
{
    ui->setupUi(this);
}

most_widget::~most_widget()
{
    delete ui;
}
