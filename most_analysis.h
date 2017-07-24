#ifndef MOST_ANALYSIS_H
#define MOST_ANALYSIS_H

#include <QWidget>

namespace Ui {
class most_analysis;
}

class most_analysis : public QWidget
{
    Q_OBJECT

public:
    explicit most_analysis(QWidget *parent = 0);
    ~most_analysis();

private:
    Ui::most_analysis *ui;
};

#endif // MOST_ANALYSIS_H
