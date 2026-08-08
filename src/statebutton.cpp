#include "statebutton.h"

namespace Mere::Widgets
{

StateButton::StateButton(QIcon defaultState, QIcon toggleState, QWidget *parent)
    : QPushButton(defaultState, "", parent)
    , m_toggled(false)
    , m_defaultState(defaultState)
    , m_toggleState(toggleState)
{
    connect(this, &QPushButton::clicked,
            this, &StateButton::onClicked);
}

void StateButton::onClicked(bool toggled)
{
    m_toggled = !m_toggled;
    setIcon(m_toggled ? m_toggleState : m_defaultState);
}

StateButton::State StateButton::state() const
{
    return m_toggled ? StateButton::State::Toggled : StateButton::State::Default;
}

void StateButton::setState(StateButton::State state)
{
    m_toggled = (state == StateButton::State::Toggled);
    setIcon(m_toggled ? m_toggleState : m_defaultState);
}

bool StateButton::isToggled() const
{
    return m_toggled;
}

}
