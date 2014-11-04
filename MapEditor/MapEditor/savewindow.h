#ifndef SAVEWINDOW_H
#define SAVEWINDOW_H

#include <QDialog>

namespace Ui {
class SaveWindow;
}

class SaveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SaveWindow(QList<QList<QString> >, QList<QList<QString> >,QWidget *parent = 0);
    ~SaveWindow();

private:
    QList<QList<QString> > data;
    QList<QList<QString> > elemData;
    Ui::SaveWindow *ui;
    void save();
};

#endif // SAVEWINDOW_H
