//
//  PlaySound.h
//  PlaySound
//
//  Created by 秋元和久 on 2016/09/20.
//
//

#ifndef PlaySound_h
#define PlaySound_h


#include "ofMain.h"

class PlaySound {

public:
    ofSoundPlayer mySound; //ofSoundクラスをインスタンス化
    PlaySound(){};
    PlaySound(string musicName){mySound.loadSound(musicName);};
    void play();
private:
    

};
#endif /* PlaySound_h */
