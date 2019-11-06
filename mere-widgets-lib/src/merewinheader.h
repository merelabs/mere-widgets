#ifndef MEREWINHEADER_H
#define MEREWINHEADER_H

#include <QHBoxLayout>

#include <QMouseEvent>
#include <QLabel>
#include <QWidget>
#include <QDebug>

class MereWinHeader : public QWidget
{
    Q_OBJECT
public:
    enum MereHeaderStyle
    {
        MereHeaderStyleSingleLiner,
        MereHeaderStyleDoubleLiner
    };

    explicit MereWinHeader(QWidget *parent = nullptr);

    void initUI();
    void setTitle(const QString title);

protected:
//    virtual void setHeaderStyle(MereHeaderStyle style) = 0;
    virtual void initLeftPanel() = 0;
    virtual void initCenterPanel() = 0;
    virtual void initRightPanel() = 0;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:

signals:

public slots:
private slots:
    void close();

protected:
    QLabel *m_title;

private:
    bool m_lock;
    QPoint m_point;
};

#endif // MEREWINHEADER_H
