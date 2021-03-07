#ifndef MEREWINDEFAULTHEADER_H
#define MEREWINDEFAULTHEADER_H

#include "simplewinheader.h"

namespace Mere {

namespace Widgets {

class SimpleWinHeaderEx : public SimpleWinHeader
{
    Q_OBJECT
public:
    ~SimpleWinHeaderEx();
    explicit SimpleWinHeaderEx(QWidget *parent = nullptr);

    void setTitle(const QString &title);

protected:
    virtual void initCenterPanel() override;

private:
    QLabel *m_title;
};

}
}
#endif // MEREWINDEFAULTHEADER_H
