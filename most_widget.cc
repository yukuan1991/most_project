#include "most_widget.h"
#include "ui_most_widget.h"
#include <boost/regex.hpp>
#include "Qt-Utils/tinyxml2.h"
#include "arithmetic_resource.hpp"

std::map<std::string, int> most_widget::kv_tmu_;

most_widget::most_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::most_widget)
{
    ui->setupUi(this);
    init_most();
    std::tie (kv_tmu_, most_data_) = read_tmu_data ();

}

most_widget::~most_widget()
{
    delete ui;
}

void most_widget::init_most()
{
    auto list_children = children ();

    for (auto & iter : list_children)
    {
        auto obj = dynamic_cast<QComboBox*> (*(&iter));
        if (obj)
        {
            using highlight_fptr = void (QComboBox::*) (const QString&);
            highlight_fptr signal_hightlight = &QComboBox::highlighted;
            connect (obj, signal_hightlight, this, &most_widget::on_most_highlighted);
            using index_change_fptr = void (QComboBox::*) (const QString&);
            index_change_fptr signal_index_change = &QComboBox::currentTextChanged;
            connect (obj, signal_index_change, this, &most_widget::on_most_dot_dot_dot_selected);
        }
    }

    for (auto & iter : list_children)
    {
        if (iter->objectName ().length () != 13)
        {
            continue;
        }

        auto obj = dynamic_cast<QComboBox*> (&(*iter));

        if (obj)
        {
            if (boost::regex_search (obj->objectName ().toStdString (), boost::regex {"cms"}))
            {
                cms_.emplace_back (obj);
            }
            else if (boost::regex_search (obj->objectName ().toStdString (), boost::regex {"gms"}))
            {
                gms_.emplace_back (obj);
            }
            else if (boost::regex_search (obj->objectName ().toStdString (), boost::regex {"tus"}))
            {
                tus_.emplace_back (obj);
            }
        }
    }
}

void most_widget::on_most_highlighted(const QString &highlight)
{
    auto combo = dynamic_cast<QComboBox*>(sender ());
    assert (combo);
    if (combo->objectName ().length () > 13)
    {
        return;
    }
    assert (combo->objectName ().length () == 13);

    std::string capital_prefix;
    if (combo->objectName ().toStdString ().substr (10, 1) == "u")
    {
        capital_prefix =  ui->combo_tus_u_categories->currentText ().toStdString ();
    }
    else
    {
        capital_prefix = combo->objectName ().toUpper ().toStdString ().substr (10, 1);
    }

    if (highlight == "……")
    {
        ui->text_area_most_description->setText (R"(<img src="icon/greater.png" />)");
        return;
    }

    auto str_key = capital_prefix + highlight.toStdString ();


    auto iter = most_data_.find (str_key);
    if (iter == most_data_.end ())
    {
        return;
    }

    tinyxml2::XMLDocument doc;
    QString qstr_rich_text;

    auto p = doc.NewElement ("p"); assert (p);
    auto span = doc.NewElement ("span"); assert (span);
    p->InsertEndChild (span);
    doc.InsertEndChild (p);

    for (auto &iter_ : iter->second)
    {
        if (iter_.second)
        {
            span->SetAttribute ("style", " font-size:11pt; font-weight:600;");
        }
        else
        {
            span->SetAttribute ("style", "font-size:11pt;");
        }

        span->SetText (iter_.first.data ());
        tinyxml2::XMLPrinter prt;
        doc.Print (&prt); assert (prt.CStr ());
        qstr_rich_text += prt.CStr ();
    }

    ui->text_area_most_description->setText (qstr_rich_text);
}

void most_widget::on_most_dot_dot_dot_selected(const QString &)
{

}
