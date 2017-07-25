#ifndef DATA_WIDGET_H
#define DATA_WIDGET_H

#include <QWidget>
#include <memory>
#include "model/json_model.h"
#include "pts/pts_model.h"
#include "pts/pts_delegate.h"

namespace Ui {
class data_widget;
}

class table_view;
class QStyledItemDelegate;

class data_widget : public QWidget
{
    Q_OBJECT
signals:
    void line_exists (bool yes_or_no);
    void std_time_sum(QString&);
public:
    explicit data_widget(QWidget *parent = 0);
    ~data_widget();

    void add_code (const QVariant& code);
    void set_unit (double unit);
    void next_code ();

    void set_row (int num);
//    bool task_content_check ();
    void clear();
private:
    void set_view ();
private:
    table_view* view_;
    std::unique_ptr<json_model> result_model_ = pts_model::make (PTS::result);
    std::unique_ptr<QStyledItemDelegate> result_delegate_ {new pts_delegate};
private:
    Ui::data_widget *ui;
};

#endif // DATA_WIDGET_H
