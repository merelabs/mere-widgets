#ifndef SCRATCHBOARD_H
#define SCRATCHBOARD_H

#include <QWidget>

namespace Mere
{

namespace Widgets
{

class ScratchEditorPanel;
class ScratchEditorScroller;

class ScratchBoard : public QWidget
{
    Q_OBJECT
public:
    ~ScratchBoard();
    explicit ScratchBoard(QWidget *parent = nullptr);
    void initUI();

private:
    ScratchEditorPanel *m_panel;
    ScratchEditorScroller *m_scroller;
};

}
}

#endif // SCRATCHBOARD_H
