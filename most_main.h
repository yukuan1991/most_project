#ifndef MOST_MAIN_H
#define MOST_MAIN_H

#include <QWidget>

namespace Ui {
class most_main;
}

class most_main : public QWidget
{
    Q_OBJECT

public:
    explicit most_main(QWidget *parent = 0);
    ~most_main();

private:
    Ui::most_main *ui;
};

#endif // MOST_MAIN_H
