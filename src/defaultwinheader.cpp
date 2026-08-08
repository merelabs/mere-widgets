#include "defaultwinheader.h"
#include "statebutton.h"

#include <QLayout>
#include <QPushButton>

Mere::Widgets::DefaultWinHeader::~DefaultWinHeader()
{

}

Mere::Widgets::DefaultWinHeader::DefaultWinHeader(QWidget *parent)
    : WinHeader(parent)
{
}

void Mere::Widgets::DefaultWinHeader::initRightPanel()
{
    QMargins margins = layout()->contentsMargins();
    margins.setRight(margins.right() + 5);
    layout()->setContentsMargins(margins);

    auto state = new StateButton(QIcon(":/widgets/icons/maximize.svg"), QIcon(":/widgets/icons/minimize.svg"), this);
    state->setObjectName("DefaultWinHeaderStateButton");
    state->setIconSize(QSize(20, 20));
    state->setMaximumSize(QSize(20, 20));
    state->setFlat(true);
    state->setFocusPolicy(Qt::NoFocus);
    connect(state, &StateButton::clicked, this, [state, this]() {
        state->isToggled() ? emit maximize() : emit restore();
    });
    layout()->addWidget(state);


    auto close = new QPushButton(QIcon(":/widgets/icons/times-circle.svg"),"", this);
    close->setObjectName("DefaultWinHeaderCloseButton");
    close->setStyleSheet("QPushButton#DefaultWinHeaderCloseButton:hover:pressed{border: none;}");
    close->setIconSize(QSize(20, 20));
    close->setMaximumSize(QSize(20, 20));
    close->setFlat(true);
    close->setFocusPolicy(Qt::NoFocus);

    layout()->addWidget(close);

    connect(close, SIGNAL(clicked(bool)), this, SIGNAL(closed()));
}
