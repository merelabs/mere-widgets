#ifndef MERENOTEEDITOR_H
#define MERENOTEEDITOR_H

#include "texteditor.h"
#include "editorpanel.h"

#include <QWidget>

namespace Mere
{

namespace  Widgets
{

class NoteEditor : public QWidget
{
    Q_OBJECT
public:
    virtual ~NoteEditor();
    explicit NoteEditor(QWidget *parent = nullptr);

    QString content() const;
    void setContent(const QString &content);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void initUI();
    void showEditPanel();
    void hideEditPanel();

    void updatePanelGeometry();

    bool isBold(QTextCursor &cursor);
    bool isItalic(QTextCursor &cursor);
    bool isUnderline(QTextCursor &cursor);
    bool isOverline(QTextCursor &cursor);

    bool isStrikethrough(QTextCursor &cursor);
    bool isSuperscript(QTextCursor &cursor);
    bool isSubscript(QTextCursor &cursor);

    bool isPropertyEnabled(QTextCursor &cursor, QTextCharFormat::Property property, QVariant value);

private slots:
    void contentSelected();
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
    TextEditor *m_note;
    EditorPanel *m_panel;
};

}
}
#endif // MERENOTEEDITOR_H
