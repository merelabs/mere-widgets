#include "meresimpleeditpanel.h"

#include <QSpinBox>
#include <QColorDialog>
#include <QFontComboBox>
#include <QPushButton>
#include <QHBoxLayout>

MereSimpleEditPanel::MereSimpleEditPanel(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignLeft);
    layout->setContentsMargins(5, 5, 5, 5);
    layout->setSpacing(0);
    setLayout(layout);

    initUI();
}

void MereSimpleEditPanel::initUI()
{
    QSize size(16, 16);

    QPushButton *bold = new QPushButton("B");
    bold->setIcon(QIcon(":/widgets/icons/16x16/bold.png"));
    bold->setIconSize(size);
//    bold->setMaximumSize(size);
    bold->setFlat(true);
    layout()->addWidget(bold);

    QPushButton *italic = new QPushButton("I");
    italic->setMaximumSize(size);
    italic->setFlat(true);
    layout()->addWidget(italic);

    QPushButton *underline = new QPushButton("U");
    underline->setMaximumSize(size);
    underline->setFlat(true);
    layout()->addWidget(underline);

    QPushButton *overline = new QPushButton("O");
    overline->setMaximumSize(size);
    overline->setFlat(true);
    layout()->addWidget(overline);

    QPushButton *strikethrough = new QPushButton("S");
    strikethrough->setMaximumSize(size);
    strikethrough->setFlat(true);
    layout()->addWidget(strikethrough);

    QPushButton *superscript = new QPushButton("Sup");
    superscript->setMaximumSize(size);
    superscript->setFlat(true);
    layout()->addWidget(superscript);

    QPushButton *subscript = new QPushButton("Sub");
    subscript->setMaximumSize(size);
    subscript->setFlat(true);
    layout()->addWidget(subscript);

    QFontComboBox *font = new QFontComboBox();
    layout()->addWidget(font);

    QSpinBox *fintSize = new QSpinBox();

    layout()->addWidget(fintSize);

    QPushButton *color = new QPushButton("C");
    color->setMaximumSize(size);
    color->setFlat(true);
    layout()->addWidget(color);

    QPushButton *background = new QPushButton("B");
    background->setMaximumSize(size);
    background->setFlat(true);
    layout()->addWidget(background);

    connect(bold     , SIGNAL(clicked()), this, SIGNAL(applyBold()));
    connect(italic   , SIGNAL(clicked()), this, SIGNAL(applyItalic()));
    connect(underline, SIGNAL(clicked()), this, SIGNAL(applyUnderline()));
    connect(overline , SIGNAL(clicked()), this, SIGNAL(applyOverline()));
    connect(strikethrough , SIGNAL(clicked()), this, SIGNAL(applyStrikethrough()));
    connect(superscript , SIGNAL(clicked()), this, SIGNAL(applySuperscript()));
    connect(subscript , SIGNAL(clicked()), this, SIGNAL(applySubscript()));

    connect(font     , SIGNAL(currentFontChanged(const QFont &)), this, SIGNAL(applyFont(const QFont &)));
    connect(fintSize     , SIGNAL(valueChanged(int)), this, SIGNAL(applyFontSize(int)));

    connect(color , &QPushButton::clicked, this, [this]{
        QColor color = QColorDialog::getColor();
        emit applyColor(color);
    });

    connect(background , &QPushButton::clicked, this, [this]{
        QColor color = QColorDialog::getColor();
        emit applyBackgroundColor(color);
    });
}
