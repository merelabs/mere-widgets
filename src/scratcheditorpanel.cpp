#include "scratcheditorpanel.h"

#include <QColorDialog>
#include <QVBoxLayout>

Mere::Widgets::ScratchEditorPanel::~ScratchEditorPanel()
{

}

Mere::Widgets::ScratchEditorPanel::ScratchEditorPanel(QWidget *parent)
    : PanelView(parent),
      m_sliderWidth(nullptr),
      m_btnColor(nullptr)
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::Base, QColor(0, 0, 0, 50));
    palette.setColor(QPalette::Window, QColor(0, 0, 0, 50));
    setAutoFillBackground(true);
    setPalette(palette);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    layout->setContentsMargins(5, 5, 5, 5);
    layout->setSpacing(7);
    setLayout(layout);

    initUI();
}

void Mere::Widgets::ScratchEditorPanel::initUI()
{
    m_sliderWidth = new QSlider(Qt::Vertical);
    m_sliderWidth->setTickInterval(1);
    m_sliderWidth->setMaximum(50);
    m_sliderWidth->setTickPosition(QSlider::TicksBothSides);

    layout()->addWidget(m_sliderWidth);

    connect(m_sliderWidth , &QSlider::valueChanged, this, [this]{
        m_width = m_sliderWidth->value();
        emit selected(m_width);
    });

    m_btnColor = addControl(QIcon(":/widgets/icons/palette.svg"));

    connect(m_btnColor , &QPushButton::clicked, this, [this]{
        QColor color = QColorDialog::getColor(m_color, this);
        if (!color.isValid()) return;
        m_color = color;
        emit selected(color);
    });
}

QPushButton* Mere::Widgets::ScratchEditorPanel::addControl(const QIcon &icon)
{
    QPushButton *button = new QPushButton(this);
    button->setIcon(icon);
    button->setIconSize(QSize(16, 16));
    button->setMaximumSize(QSize(24, 24));
    button->setCheckable(false);
    button->setFlat(true);
    layout()->addWidget(button);

    return button;
}
