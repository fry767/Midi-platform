#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "keybinds.h"
#include <QtMultimedia/QMediaPlayer>

typedef struct music_player {
     QMediaPlayer *player;
     bool is_playing;
} music_player_t;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_browse_pb1_clicked();

    void on_play1_pb_clicked();

    void on_pushButton_clicked();

    void on_s1_cb_stateChanged(int arg1);

    void on_pushButton_2_clicked();

    void change_key();

    void on_volume_slider1_sliderMoved(int position);

    void on_stop1_pb_clicked();

    void on_vlc_play1_clicked();

    void on_url1_le_returnPressed();

private:
    Ui::MainWindow *ui;
    keybinds *kb_windows;
};

#endif // MAINWINDOW_H
