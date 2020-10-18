#include "keybinds.h"
#include "ui_keybinds.h"

static QString current_key;
static int     current_key_idx;

keybinds::keybinds(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keybinds)
{
    ui->setupUi(this);

    ui->enter1_lb->hide();
}

keybinds::~keybinds()
{
    delete ui;
}

void keybinds::on_assign_1_clicked()
{
    ui->enter1_lb->show();
    current_key_idx  = 1;

}

void keybinds::keyPressEvent(QKeyEvent *event)
{
   current_key = QString( QChar(event->key()));
   application_keybinds[1] = current_key;
   ui->enter1_lb->hide();
   ui->key1_lb->setText(current_key);
}

QString *keybinds::get_app_keybings()
{
    return application_keybinds;
}
void keybinds::on_ok_ob_clicked()
{
    emit this->save_keybinds();
    this->close();
}
