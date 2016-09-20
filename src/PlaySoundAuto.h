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
    int nextTime;
    float flct; //ゆらぎ
    void intermittentChaos(); //間欠カオス
    PlaySoundAuto(){};
    PlaySoundAuto(string musicName, int nxt, float x){mySound.loadSound(musicName), isOn = true; flct = x, nextTime = nxt;};
private:
    
    
};

#endif /* PlaySoundAuto_h */
