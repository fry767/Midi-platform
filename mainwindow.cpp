
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QShortcut"
#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>

static music_player_t mp[20];
static QMediaPlayer *player = new QMediaPlayer;
static VlcInstance *test_vlc_inst;
static VlcMediaPlayer *test_vlc_player;
static QString vlc_url;
static QShortcut    *shortcutList[10];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    kb_windows = new keybinds;

    /* Init player */
    mp[0].player = new QMediaPlayer;
    mp[0].is_playing = false;

    mp[0].player->setVolume(50);
    ui->volume_slider1->setSliderPosition(50);

    /* Test VLC Player */
    test_vlc_inst = new VlcInstance(VlcCommon::args(), this);
    test_vlc_player = new VlcMediaPlayer(test_vlc_inst);

    /* Set shortcut callback */
    shortcutList[1] = new QShortcut(QKeySequence("1"), this);

    /* Connect keybinds save signals */
    QObject::connect(kb_windows, SIGNAL(save_keybinds()), this, SLOT(change_key()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browse_pb1_clicked()
{
    QStringList file_names = QFileDialog::getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("Sound Files (*.*)"));
    for(const QString & filename: file_names){
         mp[0].player->setMedia(QMediaContent(QUrl::fromLocalFile(filename)));
    }
    ui->s1_cb->setChecked(true);
}

void MainWindow::on_play1_pb_clicked()
{
    if(mp[0].is_playing == false) {
         mp[0].is_playing = true;
         mp[0].player->play();
    } else {
        mp[0].player->stop();
        mp[0].is_playing = true;
        mp[0].player->play();
    }

}

void MainWindow::on_pushButton_clicked()
{
     mp[0].player->stop();
     mp[0].is_playing = false;
}

void MainWindow::on_s1_cb_stateChanged(int arg1)
{
    if (ui->s1_cb->isChecked()) {
        QObject::connect(shortcutList[1], SIGNAL(activated()), this, SLOT(on_play1_pb_clicked()));
    } else {
        QObject::disconnect(shortcutList[1], SIGNAL(activated()), this, SLOT(on_play1_pb_clicked()));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    kb_windows->show();
}

void MainWindow::change_key()
{
    QString *keybinds = kb_windows->get_app_keybings();
    ui->usr_kb1_lb->setText(keybinds[1]);
    shortcutList[1]->setKey(QKeySequence(keybinds[1]));
    this->on_s1_cb_stateChanged(0);
}

void MainWindow::on_volume_slider1_sliderMoved(int position)
{
    mp[0].player->setVolume(position);
}

void MainWindow::on_stop1_pb_clicked()
{
    mp[0].player->stop();
    mp[0].is_playing = false;
}

void MainWindow::on_vlc_play1_clicked()
{
    /*QString url =
            QInputDialog::getText(this, tr("Open Url"), tr("Enter the URL you want to play"));

    if (url.isEmpty())
        return;

    _media = new VlcMedia(url, _instance);

    _player->open(_media);*/
}

void MainWindow::on_url1_le_returnPressed()
{

}
