#ifndef MERESIMPLEWINHEADER_H
#define MERESIMPLEWINHEADER_H

#include "merewinheader.h"

class MereSimpleWinHeader : public MereWinHeader
{
    Q_OBJECT
public:
    explicit MereSimpleWinHeader(QWidget *parent = nullptr);

protected:
    virtual void initLeftPanel() override;
    virtual void initCenterPanel() override;
    virtual void initRightPanel() override;

signals:

public slots:
};

#endif // MERESIMPLEWINHEADER_H
