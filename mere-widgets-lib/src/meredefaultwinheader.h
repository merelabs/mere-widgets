#ifndef MEREDEFAULTWINHEADER_H
#define MEREDEFAULTWINHEADER_H

#include "merewinheader.h"

class MereDefaultWinHeader : public MereWinHeader
{
    Q_OBJECT
public:
    explicit MereDefaultWinHeader(QWidget *parent = nullptr);
    void setHeaderStyle(MereHeaderStyle style);

protected:
    virtual void initLeftPanel() override;
    virtual void initCenterPanel() override;
    virtual void initRightPanel() override;

signals:

public slots:

private:
    MereHeaderStyle m_style;
};

#endif // MEREDEFAULTWINHEADER_H
