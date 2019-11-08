#ifndef MERENOTEEDITOR_H
#define MERENOTEEDITOR_H

#include "meresimpleeditor.h"
#include "merefloateditpanel.h"

#include <QWidget>
#include <QDebug>

class MereNoteEditor : public QWidget
{
    Q_OBJECT
public:
    explicit MereNoteEditor(QWidget *parent = nullptr);

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

    bool isProperty(QTextCursor &cursor, QTextCharFormat::Property property, QVariant value);

signals:

public slots:
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
    MereSimpleEditor *m_note;
    MereFloatEditPanel *m_panel;
};

#endif // MERENOTEEDITOR_H
