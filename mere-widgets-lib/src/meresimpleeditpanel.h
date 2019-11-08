#ifndef MERESIMPLEEDITPANEL_H
#define MERESIMPLEEDITPANEL_H

#include <QFont>
#include <QColor>
#include <QWidget>

class MereSimpleEditPanel : public QWidget
{
    Q_OBJECT
public:
    explicit MereSimpleEditPanel(QWidget *parent = nullptr);
    void initUI();

signals:
    void applyBold();
    void applyItalic();
    void applyUnderline();
    void applyOverline();
    void applyStrikethrough();
    void applySuperscript();
    void applySubscript();
    void applyFont(const QFont &font);
    void applyFontSize(int size);
    void applyColor(const QColor &color);
    void applyBackgroundColor(const QColor &color);

public slots:
};

#endif // MERESIMPLEEDITPANEL_H
