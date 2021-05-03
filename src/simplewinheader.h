#ifndef MERE_WIDGETS_SIMPLEWINHEADER_H
#define MERE_WIDGETS_SIMPLEWINHEADER_H

#include "defaultwinheader.h"

#include <QLabel>

namespace Mere {

namespace Widgets {

class SimpleWinHeader : public DefaultWinHeader
{
    Q_OBJECT
public:
    virtual ~SimpleWinHeader();
    explicit SimpleWinHeader(QWidget *parent = nullptr);

    void setTitle(const QString &title);

protected:
    virtual void initLeftPanel() override;
    virtual void initCenterPanel() override;
//    virtual void initRightPanel() override;

private:
    QLabel *m_title;
};

}
}


#endif // MERE_WIDGETS_SIMPLEWINHEADER_H
