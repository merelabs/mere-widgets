#ifndef MERE_WIDGETS_ICONLABEL_H
#define MERE_WIDGETS_ICONLABEL_H

#include <QPixmap>
#include <QWidget>

namespace Mere::Widgets
{

class IconLabel : public QWidget
{
    Q_OBJECT
public:
    explicit IconLabel(QWidget *parent = nullptr);
    explicit IconLabel(const QPixmap &icon, const std::string &text, QWidget *parent = nullptr);
    explicit IconLabel(const std::string &icon, const std::string &text, QWidget *parent = nullptr);

    void initUI();
    void setIcon(const QPixmap &icon);
    void setIcon(const std::string &icon);
    void setText(const std::string &text);

private:
    QPixmap m_icon;
    std::string m_text;
};

}

#endif // MERE_WIDGETS_ICONLABEL_H
