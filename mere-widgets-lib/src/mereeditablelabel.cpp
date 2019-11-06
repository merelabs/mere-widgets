#include "mereeditablelabel.h"

#include <QEvent>
#include <QMouseEvent>
#include <QTextDocument>

MereEditableLabel::MereEditableLabel(QWidget *parent)
    : QLabel(parent),
      m_flag(true)
{
    installEventFilter(this);
}

void MereEditableLabel::setEditable(bool flag)
{
    m_flag = flag;

    if (flag)
        makeEditable();
    else
        makeViewable();
}

void MereEditableLabel::makeEditable()
{
    setTextInteractionFlags(Qt::TextEditable |
                            Qt::TextSelectableByKeyboard |
                            Qt::TextSelectableByMouse);
    setSelection(0, this->text().size());
    setMouseTracking(true);
    setCursor(Qt::IBeamCursor);
    setFocus();
}

void MereEditableLabel::makeViewable()
{
    updateDirtyText();
    setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    setSelection(0, 0);
    setCursor(Qt::ArrowCursor);
}

void MereEditableLabel::updateDirtyText()
{
    QList<QTextDocument *> list = findChildren<QTextDocument *>();
    foreach(QTextDocument *document, list)
    {
        this->setText(document->toPlainText());
        break;
    }
}

bool MereEditableLabel::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        //QMouseEvent *mouse = static_cast<QMouseEvent *>(event);
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
