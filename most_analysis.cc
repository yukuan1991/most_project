﻿#include "most_analysis.h"
#include "ui_most_analysis.h"
#include <QInputDialog>

most_analysis::most_analysis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::most_analysis)
{
    ui->setupUi(this);
    init();
    init_conn();
}

most_analysis::~most_analysis()
{
    delete ui;
}

void most_analysis::set_task_count()
{
    QInputDialog dlg;
    dlg.setWindowTitle ("调整步数");
    dlg.setLabelText ("请输入工作步数");
    dlg.setOkButtonText ("确 定");
    dlg.setCancelButtonText ("取 消");
    dlg.setInputMode (QInputDialog::IntInput);
    dlg.setIntRange (0, 10000);

    if (dlg.exec () == QDialog::Accepted)
    {
        auto row = dlg.intValue ();
        ui->widget_data->clear ();
        ui->widget_data->set_row (row);

        current_file_data_.clear ();
    }
}

void most_analysis::add_row()
{
    QInputDialog dlg;
    dlg.setWindowTitle ("调整步数");
    dlg.setLabelText ("请输入工作步数");
    dlg.setOkButtonText ("确 定");
    dlg.setCancelButtonText ("取 消");
    dlg.setInputMode (QInputDialog::IntInput);
    dlg.setIntRange (0, 10000);

    if (dlg.exec () == QDialog::Accepted)
    {
        auto row = dlg.intValue ();
        ui->widget_data->set_row (row);
    }
}

void most_analysis::init()
{
    ui->widget_data->set_unit(0.036);
}

void most_analysis::init_conn()
{
    connect (ui->widget_most, &most_widget::code_changed,
             ui->widget_data, &data_widget::add_code);

    connect (ui->widget_most, &most_widget::code_changed,
             [] (const QVariant& code) { qDebug() << code; });

    connect (ui->widget_most, &most_widget::return_pressed,
             ui->widget_data, &data_widget::next_code);
}

