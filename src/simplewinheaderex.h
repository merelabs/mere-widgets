#ifndef MERE_WIDGETS_WINDEFAULTHEADER_H
#define MERE_WIDGETS_WINDEFAULTHEADER_H

#include "simplewinheader.h"

namespace Mere
{

namespace Widgets
{

class SimpleWinHeaderEx : public SimpleWinHeader
{
    Q_OBJECT
public:
    virtual ~SimpleWinHeaderEx();
    explicit SimpleWinHeaderEx(QWidget *parent = nullptr);

protected:
    virtual void initCenterPanel() override;
};

}
}
#endif // MERE_WIDGETS_WINDEFAULTHEADER_H
