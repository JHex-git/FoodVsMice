#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include "qaudiooutput.h"
class MusicPlayer
{
public:
    MusicPlayer(QString music_url_string);
    ~MusicPlayer();

    void play();
    void stop();
    void set_loop(bool flag);
    void set_volumn(float volume);

protected:
    QMediaPlayer* music_ptr;
    QAudioOutput* music_audio_output;


    bool end = false;
    bool loop = false;

};


#endif // MUSICPLAYER_H
