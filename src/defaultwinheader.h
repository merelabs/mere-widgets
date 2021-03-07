#ifndef DEFAULTWINHEADER_H
#define DEFAULTWINHEADER_H

#include "winheader.h"

namespace Mere {

namespace Widgets {

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

private slots:
    void close();

};

}
}


#endif // DEFAULTWINHEADER_H
