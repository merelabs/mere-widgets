#include "editablelabel.h"
#include "mere/utils/stringutils.h"

#include <QEvent>
#include <QMouseEvent>
#include <QTextDocument>

Mere::Widgets::EditableLabel::EditableLabel(QWidget *parent)
    : QLabel(parent),
      m_placeholderMark(false)
{
    installEventFilter(this);
}

void Mere::Widgets::EditableLabel::setEditable(bool flag)
{
    if (flag)
        makeEditable();
    else
        makeViewable();
}

void Mere::Widgets::EditableLabel::setPlaceholder(const QString &placeholder)
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::WindowText, Qt::gray);
    setPalette(palette);

    m_placeholderText = placeholder;
    m_placeholderMark = true;

    QLabel::setText(m_placeholderText);
}

void Mere::Widgets::EditableLabel::resetPlaceholder()
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::WindowText, Qt::gray);
    setPalette(palette);

    m_placeholderMark = true;
    QLabel::setText(m_placeholderText);
}

void Mere::Widgets::EditableLabel::clearPlaceholder()
{
    if (!m_placeholderMark) return;

    QPalette palette = this->palette();
    palette.setColor(QPalette::WindowText, Qt::black);
    setPalette(palette);
    QLabel::setText("");
    m_placeholderMark = false;
}

QString Mere::Widgets::EditableLabel::text() const
{
    if (m_placeholderMark)
        return QString("");

    return QLabel::text();
}

void Mere::Widgets::EditableLabel::setText(const QString &text)
{
    if (Mere::Utils::StringUtils::isBlank(text))
    {
        resetPlaceholder();
    }
    else
    {
        clearPlaceholder();
        QLabel::setText(text);
    }
}

void Mere::Widgets::EditableLabel::makeEditable()
{
    clearPlaceholder();
    setTextInteractionFlags(Qt::TextEditable |
                            Qt::TextSelectableByKeyboard |
                            Qt::TextSelectableByMouse);
    setSelection(0, this->text().size());
    setMouseTracking(true);
    setCursor(Qt::IBeamCursor);
    setFocus();
}

void Mere::Widgets::EditableLabel::makeViewable()
{
    updateDirtyText();
    setSelection(0, 0);
    setCursor(Qt::ArrowCursor);
    setTextInteractionFlags(Qt::LinksAccessibleByMouse);

    if(Mere::Utils::StringUtils::isBlank(this->text()))
    {
        resetPlaceholder();
    }
}

void Mere::Widgets::EditableLabel::updateDirtyText()
{
    QList<QTextDocument *> list = findChildren<QTextDocument *>();
    foreach(QTextDocument *document, list)
    {
        QLabel::setText(document->toPlainText());
        emit changed();
        break;
    }
}

bool Mere::Widgets::EditableLabel::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        setEditable(true);
        return true;
    }
    else if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *key = static_cast<QKeyEvent *> (event);
        if ( key->key()==Qt::Key_Enter || key->key()==Qt::Key_Return ||
             key->key()==Qt::Key_Tab || key->key()==Qt::Key_Escape )
        {
            setEditable(false);
            return true;
        }
    }
    else if (event->type() == QEvent::FocusOut)
    {
        setEditable(false);
        return true;
    }

    return QObject::eventFilter(object, event);
}
