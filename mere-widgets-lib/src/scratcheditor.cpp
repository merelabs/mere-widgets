#include "scratcheditor.h"
#include "resizer.h"

#include <QPen>
#include <QPixmap>
#include <QPainter>
#include <QFrame>
#include <QMouseEvent>

Mere::Widgets::ScratchEditor::~ScratchEditor()
{
    if (m_painter)
    {
        delete m_painter;
        m_painter = nullptr;
    }

    if (m_buffer)
    {
        delete m_buffer;
        m_buffer = nullptr;
    }

    if (m_resizer)
    {
        delete m_resizer;
        m_resizer = nullptr;
    }
}

Mere::Widgets::ScratchEditor::ScratchEditor(QWidget *parent)
    : QWidget(parent),
      m_lock(false),
//      m_pen(nullptr),
      m_buffer(nullptr),
      m_painter(nullptr)
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::Base, Qt::transparent);
    palette.setColor(QPalette::Window, Qt::transparent);
    setAutoFillBackground(true);
    setPalette(palette);

    m_penColor = Qt::black;
    m_penSize = 3;

    //m_pen = new QPen(m_penColor, m_penSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

//    m_pen.setColor(m_penColor);
//    m_pen.setWidth(m_penSize);
//    m_pen.setStyle(Qt::SolidLine);
    m_resizer = new Resizer(this);
}

void Mere::Widgets::ScratchEditor::setPenSize(const int &size)
{
    m_penSize = size;
    m_painter->setPen(QPen(m_penColor, m_penSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

void Mere::Widgets::ScratchEditor::setPenColor(const QColor &color)
{
    m_penColor = color;
    m_painter->setPen(QPen(m_penColor, m_penSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

void Mere::Widgets::ScratchEditor::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
        return;

    m_lock = true;
    m_point = event->pos();
}

void Mere::Widgets::ScratchEditor::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
        return;

    m_lock = false;
}

void Mere::Widgets::ScratchEditor::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_lock) return;

    m_painter->drawLine(m_point, event->pos());

    m_point = event->pos();

    this->update();
}

void Mere::Widgets::ScratchEditor::paintEvent(QPaintEvent *event)
{
    QPainter canvasPainter(this);
    canvasPainter.drawPixmap(this->rect(), *m_buffer, m_buffer->rect());
}

void Mere::Widgets::ScratchEditor::resizeEvent(QResizeEvent *event)
{
//    qDebug() << ">>>>>" << m_pen;
    if (m_painter)
    {
        delete m_painter;
        m_painter = nullptr;
    }

    QPixmap *copy = m_buffer;

    m_buffer = new QPixmap(this->size());
    m_buffer->fill(Qt::transparent);

    m_painter = new QPainter(m_buffer);
    m_painter->setPen(QPen(m_penColor, m_penSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    //m_painter->setPen(m_pen);

    if (copy)
    {
        m_painter->drawPixmap(copy->rect(), *copy, copy->rect());
        delete copy;
    }

    // MOVE IT TO INSIDE RESIZER
    m_resizer->move( event->size().width() - m_resizer->width(),
    event->size().height() - m_resizer->height() );
}
