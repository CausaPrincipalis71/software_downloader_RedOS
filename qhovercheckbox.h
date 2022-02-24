#ifndef QHOVERCHECKBOX_H
#define QHOVERCHECKBOX_H

#include <QCheckBox>
#include <QEvent>
#include <QDebug>

class QHoverCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    QHoverCheckBox(const QString &text, QWidget *parent = nullptr);

signals:
    void mouseHover();

protected:
    void enterEvent(QEvent *e);
};

#endif // QHOVERCHECKBOX_H
