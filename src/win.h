#ifndef MERE_WIDGETS_WIN_H
#define MERE_WIDGETS_WIN_H

#include "global.h"

#include <QWidget>

namespace Mere
{
namespace Widgets
{

class MERE_WIDGETS_LIBSPEC Win : public QWidget
{
    Q_OBJECT
public:
    virtual ~Win();
    explicit Win(QWidget *parent = nullptr);

    void initUI();

protected:
    virtual void initHeaderUI() = 0;
    virtual void initContentUI()= 0;
    virtual void initFooterUI() = 0;

    virtual void paintEvent(QPaintEvent *event) override;
};

}
}

#endif // MERE_WIDGETS_WIN_H
