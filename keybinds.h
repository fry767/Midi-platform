#ifndef KEYBINDS_H
#define KEYBINDS_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class keybinds;
}

class keybinds : public QDialog
{
    Q_OBJECT

public:
    explicit keybinds(QWidget *parent = nullptr);
    ~keybinds();

    QString application_keybinds[25];

    QString *get_app_keybings();
private slots:
    void on_assign_1_clicked();

    void on_ok_ob_clicked();

private:
    Ui::keybinds *ui;

protected:
    void keyPressEvent(QKeyEvent *event);

signals:
    void save_keybinds();
};

#endif // KEYBINDS_H
