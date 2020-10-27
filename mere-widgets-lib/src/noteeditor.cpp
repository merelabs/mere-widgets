#include "noteeditor.h"

#include "mere/utils/stringutils.h"

#include <QHBoxLayout>

Mere::Widgets::NoteEditor::~NoteEditor()
{
    if (m_note)
    {
        delete m_note;
        m_note = nullptr;
    }

    if (m_panel)
    {
        delete m_panel;
        m_panel = nullptr;
    }
}

Mere::Widgets::NoteEditor::NoteEditor(QWidget *parent)
    : QWidget(parent),
      m_note(nullptr),
      m_panel(nullptr)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Base, Qt::transparent);
    pal.setColor(QPalette::Background, Qt::transparent);
    setAutoFillBackground(true);
    setPalette(pal);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->setContentsMargins(3, 3, 3, 3);
    layout->setSpacing(3);
    setLayout(layout);

    initUI();
}

void Mere::Widgets::NoteEditor::initUI()
{
    m_note = new TextEditor;
    m_note->setAutoFillBackground(true);
    m_note->setPalette(this->palette());

    layout()->addWidget(m_note);

    connect(m_note, SIGNAL(selectionChanged()), this, SLOT(contentSelected()));
}

void Mere::Widgets::NoteEditor::contentSelected()
{
    QTextCursor cursor = m_note->textCursor();
    if(!cursor.hasSelection())
    {
        hideEditPanel();
        return;
    }

    QString text = cursor.selectedText();
    if (Mere::Utils::StringUtils::isBlank(text))
    {
        hideEditPanel();
        return;
    }

    if (!m_panel)
    {
        m_panel = new NoteEditorPanel(*this);
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

        connect(m_note, SIGNAL(selectionChanged()), m_panel, SLOT(selectionChanged()));
    }

    showEditPanel();
}

void Mere::Widgets::NoteEditor::showEditPanel()
{
    if (!m_panel) return;
    updatePanelGeometry();
    m_panel->show();
}

void Mere::Widgets::NoteEditor::hideEditPanel()
{
    if (!m_panel) return;

    m_panel->hide();
}

void Mere::Widgets::NoteEditor::updatePanelGeometry()
{
    QRect rect = this->geometry();

    rect.setY(rect.height() - m_panel->height());
    rect.setHeight(m_panel->height());
    m_panel->setGeometry(rect);
}

void Mere::Widgets::NoteEditor::applyBold()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setFontWeight(isBold(cursor) ? QFont::Normal : QFont::Bold);
    cursor.mergeCharFormat(format);
}

void Mere::Widgets::NoteEditor::applyItalic()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setFontItalic(!isItalic(cursor));
    cursor.mergeCharFormat(format);
}

void Mere::Widgets::NoteEditor::applyUnderline()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setFontUnderline(true);
    cursor.mergeCharFormat(format);
}

void Mere::Widgets::NoteEditor::applyOverline()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setFontOverline(!isOverline(cursor));
    cursor.mergeCharFormat(format);
}

void Mere::Widgets::NoteEditor::applyStrikethrough()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setFontStrikeOut(!isStrikethrough(cursor));
    cursor.mergeCharFormat(format);
}

void Mere::Widgets::NoteEditor::applySuperscript()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setVerticalAlignment(!isSuperscript(cursor) ? QTextCharFormat::AlignSuperScript : QTextCharFormat::AlignNormal);
    cursor.mergeCharFormat(format);
}

void Mere::Widgets::NoteEditor::applySubscript()
{
    QTextCursor cursor = m_note->textCursor();

    QTextCharFormat format;
    format.setVerticalAlignment(!isSubscript(cursor) ? QTextCharFormat::AlignSubScript : QTextCharFormat::AlignNormal);
    cursor.mergeCharFormat(format);
}

void Mere::Widgets::NoteEditor::applyFont(const QFont &f)
{
    QTextCursor cursor = m_note->textCursor();
    QTextCharFormat format;
    format.setFont(f);
    cursor.mergeCharFormat(format);
}

int Mere::Widgets::NoteEditor::fontPointSize()
{
    QTextCursor cursor = m_note->textCursor();
    QTextCharFormat format = cursor.charFormat();

    // FIXME

    return format.fontPointSize();
}

void Mere::Widgets::NoteEditor::applyFontSize(int size)
{
    QTextCursor cursor = m_note->textCursor();
    QTextCharFormat format;
    format.setFontPointSize(size);
    cursor.mergeCharFormat(format);
}

QColor Mere::Widgets::NoteEditor::foregroundColor()
{
    QTextCursor cursor = m_note->textCursor();
    QTextCharFormat format = cursor.charFormat();

    // FIXME

    return format.foreground().color();
}

void Mere::Widgets::NoteEditor::applyColor(const QColor &color)
{
    QTextCursor cursor = m_note->textCursor();
    QTextCharFormat format;
    format.setForeground(QBrush(color));
    cursor.mergeCharFormat(format);
}

QColor Mere::Widgets::NoteEditor::backgroundColor()
{
    QTextCursor cursor = m_note->textCursor();
    QTextCharFormat format = cursor.charFormat();

    // FIXME

    return format.background().color();
}

void Mere::Widgets::NoteEditor::applyBackgroundColor(const QColor &color)
{
    QTextCursor cursor = m_note->textCursor();
    QTextCharFormat format;
    format.setBackground(QBrush(color));
    cursor.mergeCharFormat(format);
}

bool Mere::Widgets::NoteEditor::isBold()
{
    QTextCursor cursor = m_note->textCursor();
    return isBold(cursor);
}

bool Mere::Widgets::NoteEditor::isBold(QTextCursor &cursor)
{
    return isPropertyEnabled(cursor, QTextFormat::FontWeight, QVariant(QFont::Bold));
}

bool Mere::Widgets::NoteEditor::isItalic()
{
    QTextCursor cursor = m_note->textCursor();
    return isItalic(cursor);
}

bool Mere::Widgets::NoteEditor::isItalic(QTextCursor &cursor)
{
    return isPropertyEnabled(cursor, QTextFormat::FontItalic, QVariant(true));
}

bool Mere::Widgets::NoteEditor::isUnderline()
{
    QTextCursor cursor = m_note->textCursor();
    return isUnderline(cursor);
}

bool Mere::Widgets::NoteEditor::isUnderline(QTextCursor &cursor)
{
    return isPropertyEnabled(cursor, QTextFormat::FontUnderline, QVariant(true));
}

bool Mere::Widgets::NoteEditor::isOverline()
{
    QTextCursor cursor = m_note->textCursor();
    return isOverline(cursor);
}

bool Mere::Widgets::NoteEditor::isOverline(QTextCursor &cursor)
{
    return isPropertyEnabled(cursor, QTextFormat::FontOverline, QVariant(true));
}

bool Mere::Widgets::NoteEditor::isStrikethrough()
{
    QTextCursor cursor = m_note->textCursor();
    return isStrikethrough(cursor);
}

bool Mere::Widgets::NoteEditor::isStrikethrough(QTextCursor &cursor)
{
    return isPropertyEnabled(cursor, QTextFormat::FontStrikeOut, QVariant(true));
}

bool Mere::Widgets::NoteEditor::isSuperscript()
{
    QTextCursor cursor = m_note->textCursor();
    return isSuperscript(cursor);
}

bool Mere::Widgets::NoteEditor::isSuperscript(QTextCursor &cursor)
{
    return isPropertyEnabled(cursor, QTextFormat::TextVerticalAlignment, QVariant(QTextCharFormat::AlignSuperScript));
}

bool Mere::Widgets::NoteEditor::isSubscript()
{
    QTextCursor cursor = m_note->textCursor();
    return isSubscript(cursor);
}

bool Mere::Widgets::NoteEditor::isSubscript(QTextCursor &cursor)
{
    return isPropertyEnabled(cursor, QTextFormat::TextVerticalAlignment, QVariant(QTextCharFormat::AlignSubScript));
}

bool Mere::Widgets::NoteEditor::isPropertyEnabled(QTextCursor &cursor, QTextCharFormat::Property property, QVariant value)
{
    bool enable = true;

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
            enable = false;
            break;
        }
    }

    cursor.setPosition(anchor, QTextCursor::MoveAnchor);
    cursor.setPosition(position, QTextCursor::KeepAnchor);

    return enable;
}

bool Mere::Widgets::NoteEditor::changeFontSize(int by)
{
    QTextCursor cursor = m_note->textCursor();

    bool enable = true;

    int anchor   = cursor.anchor();
    int position = cursor.position();

    int offset = anchor < position ? anchor : position;
    int length = cursor.selectedText().length();

    for(int i = 1; i <= length; i++)
    {
        cursor.setPosition(offset + i);
        QTextCharFormat format = cursor.charFormat();
        qDebug() << "1..." << format.fontPointSize();
        format.setFontPointSize(format.fontPointSize() + by);
        cursor.mergeCharFormat(format);
    }

    cursor.setPosition(anchor, QTextCursor::MoveAnchor);
    cursor.setPosition(position, QTextCursor::KeepAnchor);

    return enable;
}

void Mere::Widgets::NoteEditor::resizeEvent(QResizeEvent *event)
{
    if (!m_panel || m_panel->isHidden())
        return;

    updatePanelGeometry();
}

QString Mere::Widgets::NoteEditor::content() const
{
    return m_note->toHtml();
}

void Mere::Widgets::NoteEditor::setContent(const QString &content)
{
    m_note->setHtml(content);
}

void Mere::Widgets::NoteEditor::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_B  && (e->modifiers() & Qt::ControlModifier))
    {
        applyBold();
        e->accept(); // set as 'handled here'
        return;
    }
    else if (e->key() == Qt::Key_I  && (e->modifiers() & Qt::ControlModifier))
    {
        applyItalic();
        e->accept(); // set as 'handled here'
        return;
    }
    else if (e->key() == Qt::Key_U  && (e->modifiers() & Qt::ControlModifier))
    {
        applyUnderline();
        e->accept(); // set as 'handled here'
        return;
    }
    else if (e->key() == Qt::Key_O  && (e->modifiers() & Qt::ControlModifier))
    {
        applyOverline();
        e->accept(); // set as 'handled here'
        return;
    }
    else if (e->key() == Qt::Key_Up  && (e->modifiers() & Qt::ControlModifier))
    {
        if (isSubscript())
            applySubscript();
        else
            applySuperscript();
        e->accept(); // set as 'handled here'
        return;
    }
    else if (e->key() == Qt::Key_Down  && (e->modifiers() & Qt::ControlModifier))
    {
        if (isSuperscript())
            applySuperscript();
        else
            applySubscript();
        e->accept(); // set as 'handled here'
        return;
    }
    else if (e->key() == Qt::Key_Minus && (e->modifiers() & Qt::ControlModifier))
    {
        changeFontSize(-1);
        e->accept(); // set as 'handled here'
        return;
    }
    else if (e->key() == Qt::Key_Plus  && (e->modifiers() & Qt::ControlModifier))
    {
        changeFontSize(1);
        e->accept(); // set as 'handled here'
        return;
    }

    e->ignore(); // set as 'not handled here'
}
