#include "merenoteeditor.h"
#include "mere/utils/merestringutils.h"

#include <QHBoxLayout>
MereNoteEditor::MereNoteEditor(QWidget *parent)
    : QWidget(parent),
      m_note(nullptr),
      m_panel(nullptr)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0, 46, 99, 25));
    setAutoFillBackground(true);
    setPalette(pal);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->setContentsMargins(3, 3, 3, 3);
    setLayout(layout);

    initUI();
}

void MereNoteEditor::initUI()
{
    m_note = new MereSimpleEditor;

    layout()->addWidget(m_note);

    connect(m_note, SIGNAL(selectionChanged()), this, SLOT(contentSelected()));
}

void MereNoteEditor::contentSelected()
{
    QTextCursor cursor = m_note->textCursor();
    if(!cursor.hasSelection())
    {
        hideEditPanel();
        return;
    }

    QString text = cursor.selectedText();
    if (MereStringUtils::isBlank(text))
    {
        hideEditPanel();
        return;
    }

    if (!m_panel)
    {
        m_panel = new MereFloatEditPanel(this);
        connect(m_panel, SIGNAL(applyBold()), this, SLOT(applyBold()));
        connect(m_panel, SIGNAL(applyItalic()), this, SLOT(applyItalic()));
        connect(m_panel, SIGNAL(applyUnderline()), this, SLOT(applyUnderline()));
        connect(m_panel, SIGNAL(applyOverline()), this, SLOT(applyOverline()));

        connect(m_panel, SIGNAL(applyStrikethrough()), this, SLOT(applyStrikethrough()));
        connect(m_panel, SIGNAL(applySuperscript()), this, SLOT(applySuperscript()));
        connect(m_panel, SIGNAL(applySubscript()), this, SLOT(applySubscript()));

        connect(m_panel, SIGNAL(applyFont(const QFont &)), this, SLOT(applyFont(const QFont &)));
        connect(m_panel, SIGNAL(applyFontSize(int)), this, SLOT(applyFontSize(int)));
        connect(m_panel, SIGNAL(applyColor(const QColor &)), this, SLOT(applyColor(const QColor &)));
        connect(m_panel, SIGNAL(applyBackgroundColor(const QColor &)), this, SLOT(applyBackgroundColor(const QColor &)));
    }
    showEditPanel();
}

void MereNoteEditor::showEditPanel()
{
    if (!m_panel) return;
    updatePanelGeometry();
    m_panel->show();
}

void MereNoteEditor::hideEditPanel()
{
    if (!m_panel) return;

    m_panel->hide();
}

void MereNoteEditor::updatePanelGeometry()
{
    QRect rect = this->geometry();

    rect.setY(rect.height() - m_panel->height());
    rect.setHeight(m_panel->height());
    m_panel->setGeometry(rect);
}

void MereNoteEditor::applyBold()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setFontWeight(isBold(cursor) ? QFont::Normal : QFont::Bold);
    cursor.mergeCharFormat(format);
}

void MereNoteEditor::applyItalic()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setFontItalic(!isItalic(cursor));
    cursor.mergeCharFormat(format);
}

void MereNoteEditor::applyUnderline()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setFontUnderline(true);
    cursor.mergeCharFormat(format);
}

void MereNoteEditor::applyOverline()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setFontOverline(!isOverline(cursor));
    cursor.mergeCharFormat(format);
}

void MereNoteEditor::applyStrikethrough()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setFontStrikeOut(!isStrikethrough(cursor));
    cursor.mergeCharFormat(format);
}

void MereNoteEditor::applySuperscript()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setVerticalAlignment(!isSuperscript(cursor) ? QTextCharFormat::AlignSuperScript : QTextCharFormat::AlignNormal);
    cursor.mergeCharFormat(format);
}

void MereNoteEditor::applySubscript()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setVerticalAlignment(!isSubscript(cursor) ? QTextCharFormat::AlignSubScript : QTextCharFormat::AlignNormal);
    cursor.mergeCharFormat(format);
}

void MereNoteEditor::applyFont(const QFont &f)
{
    QTextCursor cursor = m_note->textCursor();
    QTextCharFormat format;
    format.setFont(f);
    cursor.mergeCharFormat(format);
}

void MereNoteEditor::applyFontSize(int size)
{
    QTextCursor cursor = m_note->textCursor();
    QTextCharFormat format;
    format.setFontPointSize(size);
    cursor.mergeCharFormat(format);
}

void MereNoteEditor::applyColor(const QColor &color)
{
    QTextCursor cursor = m_note->textCursor();
    QTextCharFormat format;
    format.setForeground(QBrush(color));
    cursor.mergeCharFormat(format);
}

void MereNoteEditor::applyBackgroundColor(const QColor &color)
{
    QTextCursor cursor = m_note->textCursor();
    QTextCharFormat format;
    format.setBackground(QBrush(color));
    cursor.mergeCharFormat(format);
}

bool MereNoteEditor::isBold(QTextCursor &cursor)
{
    return isProperty(cursor, QTextFormat::FontWeight, QVariant(QFont::Bold));
}

bool MereNoteEditor::isItalic(QTextCursor &cursor)
{
    return isProperty(cursor, QTextFormat::FontItalic, QVariant(true));
}

bool MereNoteEditor::isUnderline(QTextCursor &cursor)
{
    return isProperty(cursor, QTextFormat::FontUnderline, QVariant(true));
}

bool MereNoteEditor::isOverline(QTextCursor &cursor)
{
    return isProperty(cursor, QTextFormat::FontOverline, QVariant(true));
}

bool MereNoteEditor::isStrikethrough(QTextCursor &cursor)
{
    return isProperty(cursor, QTextFormat::FontStrikeOut, QVariant(true));
}

bool MereNoteEditor::isSuperscript(QTextCursor &cursor)
{
    return isProperty(cursor, QTextFormat::TextVerticalAlignment, QVariant(QTextCharFormat::AlignSuperScript));
}

bool MereNoteEditor::isSubscript(QTextCursor &cursor)
{
    return isProperty(cursor, QTextFormat::TextVerticalAlignment, QVariant(QTextCharFormat::AlignSubScript));
}

bool MereNoteEditor::isProperty(QTextCursor &cursor, QTextCharFormat::Property property, QVariant value)
{
    bool set = true;

    int anchor   = cursor.anchor();
    int position = cursor.position();

    int offset = anchor < position ? anchor : position;
    int length = cursor.selectedText().length();

    for(int i = 1; i <= length; i++)
    {
        cursor.setPosition(offset + i);

        QTextCharFormat format = cursor.charFormat();

        if(!format.hasProperty(property) || format.property(property) != value)
        {
            set = false;
            break;
        }
    }

    cursor.setPosition(anchor, QTextCursor::MoveAnchor);
    cursor.setPosition(position, QTextCursor::KeepAnchor);

    return set;
}

void MereNoteEditor::resizeEvent(QResizeEvent *event)
{
    if (!m_panel || m_panel->isHidden())
        return;

    updatePanelGeometry();
}
