#include "most_main.h"
#include "ui_most_main.h"
#include "interface_control/about_us_dlg.h"
#include <memory>
#include <QMdiSubWindow>

using namespace std;

most_main::most_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::most_main)
{
    ui->setupUi(this);
    ui->mdi->setViewMode (QMdiArea::TabbedView);
    init_conn();
    set_button_enabled();
}

most_main::~most_main()
{
    delete ui;
}

void most_main::init_conn()
{
    connect(ui->widget_ribbon, &ribbon_most::file_menu_triggered,
            [this] (const QString & s) { file_operations(s); });

    connect(ui->widget_ribbon, &ribbon_most::help, this, &most_main::help_advice);

    connect(ui->mdi, &QMdiArea::subWindowActivated, this, &most_main::set_button_enabled);

}

void most_main::set_button_enabled()
{
    const bool state = (active_window() != nullptr);
    ui->widget_ribbon->set_enabled(state);
}

void most_main::file_operations(const QString &s)
{
    if(s == "新建")
    {
        file_new();
    }
//    else if(s == "打开")
//    {
//        file_open();
//    }
//    else if(s == "保存")
//    {
//        file_save();
//    }
//    else if(s == "另存为")
//    {
//        file_save_as();
//    }
    else if(s == "退出")
    {
        close();
    }
}

void most_main::file_new()
{
    auto w = create_window ("未命名");
    w->set_task_count ();
}

void most_main::help_advice()
{
    const QString text = R"(<html><head/><body><p>如果您有任何需求与改进建议，</p><p>请随时联系IEToolkit君qq3350436646</p>
                         <p><span style=" font-weight:600; color:red">加好友请扫右边二维码---&gt;</span></p></body></html>)";
    const QString qr_code = R"( <a href = "www.shionto.com"> <img src="./png/about-us.png" width="300" height = "400"/></a>)";
    about_us_dlg::show_info(text, qr_code);
}

not_null<most_analysis *> most_main::create_window(const QString &title)
{
    auto most_win = make_unique<most_analysis> ();
    auto ptr_most_win = most_win.get();

    most_win->setAttribute (Qt::WA_DeleteOnClose);
    auto w = ui->mdi->addSubWindow (ptr_most_win);
    w->setWindowTitle (title);

    w->setWindowState (Qt::WindowMaximized);

    connect(ui->widget_ribbon, &ribbon_most::add_row, ptr_most_win, &most_analysis::add_row);
    //    connect(ui->widget_ribbon, &ribbon_most::copy, ptr_most_win, &most_analysis::copy);
    //    connect(ui->widget_ribbon, &ribbon_most::cut, ptr_most_win, &most_analysis::cut);
    //    connect(ui->widget_ribbon, &ribbon_most::paste, ptr_most_win, &most_analysis::paste);
    //    connect(ui->widget_ribbon, &ribbon_most::del, ptr_most_win, &most_analysis::del);

    return most_win.release ();
}

most_analysis *most_main::active_window()
{
    if(QMdiSubWindow* active_subwindow = ui->mdi->activeSubWindow())
    {
        most_analysis* w = dynamic_cast<most_analysis*>(active_subwindow->widget());
        return w;
    }
    else
    {
        return nullptr;
    }
}
