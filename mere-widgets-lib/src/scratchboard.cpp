#include "scratchboard.h"
#include "scratcheditor.h"
#include "scratcheditorpanel.h"
#include "scratcheditorscroller.h"

#include <QResizeEvent>
#include <QScrollArea>
#include <QHBoxLayout>

Mere::Widgets::ScratchBoard::~ScratchBoard()
{
    if (m_panel)
    {
        delete m_panel;
        m_panel = nullptr;
    }

//    if (m_editor)
//    {
//        delete m_editor;
//        m_editor = nullptr;
//    }
}

Mere::Widgets::ScratchBoard::ScratchBoard(QWidget *parent)
    : QWidget(parent),
      m_panel(nullptr)
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::Base, Qt::transparent);
    palette.setColor(QPalette::Window, Qt::transparent);
    setAutoFillBackground(true);
    setPalette(palette);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(3, 3, 3, 3);
    layout->setSpacing(3);

    initUI();
}

void Mere::Widgets::ScratchBoard::initUI()
{
    m_panel = new ScratchEditorPanel(this);
    m_panel->setMinimumWidth(40);
    m_panel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout()->addWidget(m_panel);

    m_scroller = new ScratchEditorScroller(this);
    m_scroller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout()->addWidget(m_scroller);

    connect(m_panel, SIGNAL(selected(const QColor &)), m_scroller->editor(), SLOT(setPenColor(const QColor &)));
    connect(m_panel, SIGNAL(selected(const int &)), m_scroller->editor(), SLOT(setPenSize(const int &)));
}
