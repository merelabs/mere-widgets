#ifndef MERE_WIDGETS_DEFAULTWINHEADER_H
#define MERE_WIDGETS_DEFAULTWINHEADER_H

#include "winheader.h"

namespace Mere::Widgets
{

class DefaultWinHeader : public WinHeader
{
    Q_OBJECT
public:
    virtual ~DefaultWinHeader();
    explicit DefaultWinHeader(QWidget *parent = nullptr);

protected:
    virtual void initRightPanel() override;

signals:
    void closed();
};

}



#endif // MERE_WIDGETS_DEFAULTWINHEADER_H
