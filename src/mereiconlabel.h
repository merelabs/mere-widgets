#ifndef MEREICONLABEL_H
#define MEREICONLABEL_H

#include <QPixmap>
#include <QWidget>

class MereIconLabel : public QWidget
{
    Q_OBJECT
public:
    explicit MereIconLabel(QWidget *parent = nullptr);
    explicit MereIconLabel(const QPixmap &icon, const std::string &text, QWidget *parent = nullptr);
    explicit MereIconLabel(const std::string &icon, const std::string &text, QWidget *parent = nullptr);

    void initUI();
    void setIcon(const QPixmap &icon);
    void setIcon(const std::string &icon);
    void setText(const std::string &text);

private:
    QPixmap m_icon;
    std::string m_text;
};

#endif // MEREICONLABEL_H
