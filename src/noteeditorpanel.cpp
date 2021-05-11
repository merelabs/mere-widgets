#include "noteeditorpanel.h"
#include "noteeditor.h"

#include <QSpinBox>
#include <QColorDialog>
#include <QFontComboBox>
#include <QPushButton>
#include <QHBoxLayout>

Mere::Widgets::NoteEditorPanel::NoteEditorPanel(NoteEditor &editor)
    : PanelView(&editor),
      m_editor(editor)
{
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignLeft);
    layout->setContentsMargins(5, 5, 5, 5);
    layout->setSpacing(7);
    setLayout(layout);

    initUI();
}

void Mere::Widgets::NoteEditorPanel::initUI()
{
    m_bold      = addControl(QIcon(":/widgets/icons/bold.svg"));
    m_italic    = addControl(QIcon(":/widgets/icons/italic.svg"));
    m_underline = addControl(QIcon(":/widgets/icons/underline.svg"));
//    m_overline  = addControl(QIcon(":/widgets/icons/overline.svg"));

    m_strikethrough = addControl(QIcon(":/widgets/icons/strikethrough.svg"));
    m_superscript   = addControl(QIcon(":/widgets/icons/superscript.svg"));
    m_subscript     = addControl(QIcon(":/widgets/icons/subscript.svg"));

    QFontComboBox *font = new QFontComboBox();
    layout()->addWidget(font);

    m_fintSize = new QSpinBox();

    layout()->addWidget(m_fintSize);

    m_foreground = addControl(QIcon(":/widgets/icons/palette.svg"));
    m_foreground->setCheckable(false);

    m_background = addControl(QIcon(":/widgets/icons/paint-roller.svg"));
    m_background->setCheckable(false);

    connect(m_bold         , SIGNAL(clicked()), this, SIGNAL(applyBold()));
    connect(m_italic       , SIGNAL(clicked()), this, SIGNAL(applyItalic()));
    connect(m_underline    , SIGNAL(clicked()), this, SIGNAL(applyUnderline()));
    //connect(overline     , SIGNAL(clicked()), this, SIGNAL(applyOverline()));
    connect(m_strikethrough, SIGNAL(clicked()), this, SIGNAL(applyStrikethrough()));
    connect(m_superscript  , SIGNAL(clicked()), this, SIGNAL(applySuperscript()));
    connect(m_subscript    , SIGNAL(clicked()), this, SIGNAL(applySubscript()));

    connect(font         , SIGNAL(currentFontChanged(const QFont &)), this, SIGNAL(applyFont(const QFont &)));
    connect(m_fintSize     , SIGNAL(valueChanged(int)), this, SIGNAL(applyFontSize(int)));

    connect(m_foreground , &QPushButton::clicked, this, [this]{
        QColor color = QColorDialog::getColor(m_editor.foregroundColor(), this);
        if (!color.isValid()) return;
        emit applyColor(color);
    });

    connect(m_background , &QPushButton::clicked, this, [this]{
        QColor color = QColorDialog::getColor(m_editor.backgroundColor(), this);
        if (!color.isValid()) return;
        emit applyBackgroundColor(color);
    });
}

QPushButton* Mere::Widgets::NoteEditorPanel::addControl(const QIcon &icon)
{
    QPushButton *button = new QPushButton(this);
    button->setIcon(icon);
    button->setIconSize(QSize(16, 16));
    button->setMaximumSize(QSize(24, 24));
    button->setCheckable(true);
    button->setFlat(true);
    layout()->addWidget(button);

    return button;
}

void Mere::Widgets::NoteEditorPanel::selectionChanged()
{
    m_bold->setChecked(m_editor.isBold());
    m_italic->setChecked(m_editor.isItalic());
    m_underline->setChecked(m_editor.isUnderline());
    m_strikethrough->setChecked(m_editor.isStrikethrough());
    m_superscript->setChecked(m_editor.isSuperscript());
    m_subscript->setChecked(m_editor.isSubscript());
//    m_foreground->setChecked(m_editor.is;
//    m_background->setBa

    qDebug() << "POINT SIZE:" << m_editor.fontPointSize();
//    m_fintSize->setValue(m_editor.fontPointSize());
}
