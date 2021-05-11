#ifndef MERE_WIDGETS_HEADERVIEW_H
#define MERE_WIDGETS_HEADERVIEW_H

#include "global.h"
#include <QWidget>

namespace Mere
{

namespace Widgets
{

class MERE_WIDGETS_LIBSPEC HeaderView : public QWidget
{
    Q_OBJECT
public:
    virtual ~HeaderView();
    explicit HeaderView(QWidget *parent = nullptr);

protected:
    virtual void initLeftPanel() = 0;
    virtual void initCenterPanel() = 0;
    virtual void initRightPanel() = 0;

};

}
}


#endif // MERE_WIDGETS_HEADERVIEW_H
