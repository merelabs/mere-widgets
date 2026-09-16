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

    void setTitle(const QString &title);

protected:
    virtual void initCenterPanel(QWidget *container) override;

private:
    QString username() const;

private:
    QLabel *m_host;
    QLabel *m_title;
};

}
}
#endif // MERE_WIDGETS_WINDEFAULTHEADER_H
