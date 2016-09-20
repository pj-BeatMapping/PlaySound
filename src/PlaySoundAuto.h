//
//  PlaySoundAuto.h
//  PlaySound
//
//  Created by 秋元和久 on 2016/09/20.
//
//

#include "PlaySound.h"
#ifndef PlaySoundAuto_h
#define PlaySoundAuto_h

class PlaySoundAuto : public PlaySound {
    
public:
    void autoPlay(int mili, float BPM, float margin);
    PlaySoundAuto(){};
    PlaySoundAuto(string musicName, int nxt, float x){mySound.loadSound(musicName), flct = x, nextTime = nxt;};
private:
    int nextTime;
    float flct; //ゆらぎ
    void intermittentChaos(); //間欠カオス
};

#endif /* PlaySoundAuto_h */
