#ifndef MOST_WIDGET_H
#define MOST_WIDGET_H

#include <QWidget>

namespace Ui {
class most_widget;
}

class most_widget : public QWidget
{
    Q_OBJECT

public:
    explicit most_widget(QWidget *parent = 0);
    ~most_widget();

private:
    Ui::most_widget *ui;
};

#endif // MOST_WIDGET_H
