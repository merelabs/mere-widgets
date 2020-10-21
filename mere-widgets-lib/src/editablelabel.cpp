#include "editablelabel.h"

#include <QEvent>
#include <QMouseEvent>
#include <QTextDocument>

Mere::Widgets::EditableLabel::EditableLabel(QWidget *parent)
    : QLabel(parent)
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

void Mere::Widgets::EditableLabel::makeEditable()
{
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
}

void Mere::Widgets::EditableLabel::updateDirtyText()
{
    QList<QTextDocument *> list = findChildren<QTextDocument *>();
    foreach(QTextDocument *document, list)
    {
        this->setText(document->toPlainText());
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
