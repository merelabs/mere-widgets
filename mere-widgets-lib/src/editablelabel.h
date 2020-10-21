#ifndef MERE_WIDGETS_EDITABLELABEL_H
#define MERE_WIDGETS_EDITABLELABEL_H

#include <QLabel>
#include <QDebug>

namespace Mere
{

namespace  Widgets
{

class EditableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit EditableLabel(QWidget *parent = nullptr);
    void setEditable(bool flag = true);

protected:
    bool eventFilter(QObject* object, QEvent* event) override;

private:
    void makeEditable();
    void makeViewable();
    void updateDirtyText();

signals:
    void changed();
};

}
}
#endif // MERE_WIDGETS_EDITABLELABEL_H
