#include "qhovercheckbox.h"

QHoverCheckBox::QHoverCheckBox(const QString &text, QWidget *parent)
    : QCheckBox(text, parent)
{
    this->setMouseTracking(true);
    this->setAttribute(Qt::WA_Hover);
}

void QHoverCheckBox::enterEvent(QEvent *e)
{
    emit mouseHover();

    QCheckBox::enterEvent(e);
}
