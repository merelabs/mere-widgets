#ifndef MERE_WIDGETS_EDITORPANEL_H
#define MERE_WIDGETS_EDITORPANEL_H

#include "panelview.h"

#include <QFont>
#include <QColor>
#include <QSpinBox>
#include <QPushButton>
#include <QDebug>

namespace Mere
{

namespace Widgets
{

class NoteEditor;
class NoteEditorPanel : public PanelView
{
    Q_OBJECT
public:
    explicit NoteEditorPanel(NoteEditor &editor);
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

private:
    QPushButton* addControl(const QIcon &icon);

private slots:
    void selectionChanged();

private:
    NoteEditor &m_editor;

    QPushButton *m_bold;
    QPushButton *m_italic;
    QPushButton *m_underline;

    QPushButton *m_strikethrough;
    QPushButton *m_superscript;
    QPushButton *m_subscript;

    QSpinBox *m_fintSize;

    QPushButton *m_foreground;
    QPushButton *m_background;
};

}
}

#endif // MERE_WIDGETS_EDITORPANEL_H
