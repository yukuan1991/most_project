﻿#ifndef MOST_WIDGET_H
#define MOST_WIDGET_H

#include <QWidget>

namespace Ui {
class most_widget;
}

class QComboBox;

class most_widget : public QWidget
{
    Q_OBJECT
signals:
    void code_changed (const QVariant&);
    void return_pressed ();
public:
    explicit most_widget(QWidget *parent = 0);
    ~most_widget();

private:
    void on_button_gms_reset_clicked();

    void on_button_cms_reset_clicked();

    void on_button_tus_reset_clicked();

    void on_button_most_backspace_clicked();
    void on_button_most_confirm_return_clicked();
private:
    void init_most ();
    void on_most_highlighted (const QString& highlight);
    void on_most_dot_dot_dot_selected (const QString&);

private:
    Ui::most_widget *ui;

    std::vector<QComboBox*> cms_;
    std::vector<QComboBox*> gms_;
    std::vector<QComboBox*> tus_;
    std::map<std::string, std::vector<std::pair<std::string, bool>>> most_data_;

    static std::map<std::string, int> kv_tmu_;
};

#endif // MOST_WIDGET_H
