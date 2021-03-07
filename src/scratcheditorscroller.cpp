#include "scratcheditorscroller.h"
#include "scratcheditor.h"

Mere::Widgets::ScratchEditorScroller::~ScratchEditorScroller()
{
    if (m_editor)
    {
        delete m_editor;
        m_editor = nullptr;
    }
}

Mere::Widgets::ScratchEditorScroller::ScratchEditorScroller(QWidget *parent)
    : QScrollArea(parent)
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::Base, Qt::transparent);
    palette.setColor(QPalette::Window, Qt::transparent);
    setAutoFillBackground(true);
    setPalette(palette);

    initUI();
}

void Mere::Widgets::ScratchEditorScroller::initUI()
{
    m_editor = new ScratchEditor(this);
    setWidget(m_editor);
}

Mere::Widgets::ScratchEditor* Mere::Widgets::ScratchEditorScroller::editor()
{
    return m_editor;
}

void Mere::Widgets::ScratchEditorScroller::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    m_editor->resize(contentsRect().size());
}
