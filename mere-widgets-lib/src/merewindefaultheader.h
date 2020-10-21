#ifndef MEREWINDEFAULTHEADER_H
#define MEREWINDEFAULTHEADER_H

#include "merewinheader.h"

class MereWinDefaultHeader : public MereWinHeader
{
    Q_OBJECT
public:
    ~MereWinDefaultHeader();
    explicit MereWinDefaultHeader(QWidget *parent = nullptr);
    void setHeaderStyle(MereHeaderStyle style);

    void setTitle(const QString &title);

protected:
    virtual void initLeftPanel() override;
    virtual void initCenterPanel() override;
    virtual void initRightPanel() override;

private:
    QLabel *m_title;
    MereHeaderStyle m_style;
};

#endif // MEREWINDEFAULTHEADER_H
