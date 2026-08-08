#ifndef MERE_WIDGETS_STATEBUTTON_H
#define MERE_WIDGETS_STATEBUTTON_H

#include <QIcon>
#include <QPushButton>

namespace Mere::Widgets
{

class StateButton : public QPushButton
{
    Q_OBJECT
public:
    explicit StateButton(QIcon defaultState, QIcon toggleState, QWidget* parent = nullptr);

    enum State
    {
        Default,
        Toggled
    };

    State state() const;
    void setState(State state);

    bool isToggled() const;

private slots:
    void onClicked(bool toggled);

private:
    bool m_toggled;
    QIcon m_defaultState;
    QIcon m_toggleState;
};

}
#endif // MERE_WIDGETS_STATEBUTTON_H
