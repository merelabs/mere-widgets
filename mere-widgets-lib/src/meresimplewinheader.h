#ifndef MERESIMPLEWINHEADER_H
#define MERESIMPLEWINHEADER_H

#include "merewinheader.h"

class MereSimpleWinHeader : public MereWinHeader
{
    Q_OBJECT
public:
    ~MereSimpleWinHeader();
    explicit MereSimpleWinHeader(QWidget *parent = nullptr);

    void setTitle(const QString &title);

protected:
    virtual void initLeftPanel() override;
    virtual void initCenterPanel() override;
    virtual void initRightPanel() override;

private:
    QLabel *m_title;
};

#endif // MERESIMPLEWINHEADER_H
