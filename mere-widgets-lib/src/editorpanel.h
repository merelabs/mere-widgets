#ifndef MERE_WIDGETS_EDITORPANEL_H
#define MERE_WIDGETS_EDITORPANEL_H

#include <QFont>
#include <QColor>
#include <QWidget>

namespace Mere
{

namespace Widgets
{

class EditorPanel : public QWidget
{
    Q_OBJECT
public:
    explicit EditorPanel(QWidget *parent = nullptr);
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

}
}

#endif // MERE_WIDGETS_EDITORPANEL_H
