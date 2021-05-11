#ifndef MERESIMPLEEDITOR_H
#define MERESIMPLEEDITOR_H

#include <QTextEdit>

namespace Mere
{

namespace Widgets
{

class TextEditor : public QTextEdit
{
    Q_OBJECT
public:
    explicit TextEditor(QWidget *parent = nullptr);
};

}
}

#endif // MERESIMPLEEDITOR_H
