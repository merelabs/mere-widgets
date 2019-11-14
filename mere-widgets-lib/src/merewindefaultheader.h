#ifndef MEREWINDEFAULTHEADER_H
#define MEREWINDEFAULTHEADER_H

#include "merewinheader.h"

class MereWinDefaultHeader : public MereWinHeader
{
    Q_OBJECT
public:
    explicit MereWinDefaultHeader(QWidget *parent = nullptr);
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

#endif // MEREWINDEFAULTHEADER_H
