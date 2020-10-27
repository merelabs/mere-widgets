#ifndef PANELVIEW_H
#define PANELVIEW_H

#include <QWidget>

namespace Mere
{

namespace Widgets
{

class PanelView : public QWidget
{
    Q_OBJECT
public:
    ~PanelView();
    explicit PanelView(QWidget *parent = nullptr);

signals:

};

}
}
#endif // PANELVIEW_H
