#ifndef SCRATCHEDITORSCROLLER_H
#define SCRATCHEDITORSCROLLER_H

#include <QScrollArea>

namespace Mere
{
namespace Widgets
{

class ScratchEditor;

class ScratchEditorScroller : public QScrollArea
{
    Q_OBJECT
public:
    virtual ~ScratchEditorScroller();
    explicit ScratchEditorScroller(QWidget *parent = nullptr);

    void initUI();

    ScratchEditor* editor();

protected:
    void showEvent(QShowEvent *event);

signals:

private:
    ScratchEditor *m_editor;
};

}
}

#endif // SCRATCHEDITORSCROLLER_H
