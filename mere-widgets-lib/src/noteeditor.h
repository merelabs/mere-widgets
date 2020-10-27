#ifndef MERENOTEEDITOR_H
#define MERENOTEEDITOR_H

#include "texteditor.h"
#include "noteeditorpanel.h"

#include <QKeyEvent>
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

    bool isBold();
    bool isItalic();
    bool isUnderline();
    bool isOverline();
    bool isStrikethrough();
    bool isSuperscript();
    bool isSubscript();
    QColor foregroundColor();
    QColor backgroundColor();

    int fontPointSize();

protected:
    void keyPressEvent(QKeyEvent *e) override;
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

    bool changeFontSize(int by);

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
    NoteEditorPanel *m_panel;
};

}
}
#endif // MERENOTEEDITOR_H
