#ifndef PIXELEDITORPANEL_H
#define PIXELEDITORPANEL_H

#include "panelview.h"

#include <QColor>
#include <QSlider>
#include <QPushButton>

namespace Mere {
namespace Widgets
{

class ScratchEditorPanel : public PanelView
{
    Q_OBJECT
public:
    ~ScratchEditorPanel();
    explicit ScratchEditorPanel(QWidget *parent = nullptr);

    void initUI();

private:
    QPushButton* addControl(const QIcon &icon);

signals:
    void selected(const int &width);
    void selected(const QColor &color);

private:
    int m_width;
    QSlider *m_sliderWidth;

    QColor m_color;
    QPushButton *m_btnColor;
};

}
}

#endif // PIXELEDITORPANEL_H
