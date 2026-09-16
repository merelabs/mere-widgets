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
    virtual void initLeftPanel(QWidget *container) override;
    virtual void initCenterPanel(QWidget *container) override;
//    virtual void initRightPanel(QWidget *container) override;

private:
    QLabel *m_title;
};

}
}


#endif // MERE_WIDGETS_SIMPLEWINHEADER_H
