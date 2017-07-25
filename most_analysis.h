#ifndef MOST_ANALYSIS_H
#define MOST_ANALYSIS_H

#include <QWidget>
#include "Qt-Utils/json.hpp"

namespace Ui {
class most_analysis;
}

using nlohmann::json;

class most_analysis : public QWidget
{
    Q_OBJECT

public:
    explicit most_analysis(QWidget *parent = 0);
    ~most_analysis();

    void set_task_count ();
    void add_row();

private:
    void init();
    void init_conn();
private:
    Ui::most_analysis *ui;

    json current_file_data_;
};

#endif // MOST_ANALYSIS_H
