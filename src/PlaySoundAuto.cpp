//
//  PlaySoundAuto.cpp
//  PlaySound
//
//  Created by 秋元和久 on 2016/09/20.
//
//

#include "PlaySoundAuto.h"
#include "PlaySound.h"

void PlaySoundAuto::intermittentChaos(){ //間欠カオス
    //本来の間欠カオス,0と1に張り付きやすい
    /*
     if(x < 0.5) x = x + 2*x*x;
     else x = x - 2*(1-x)*(1-x);
     */
    
    //改良版,なんだかループしてしまっている
    //http://broadbeans.blog.so-net.ne.jp/2011-07-26
    if(flct == 0) flct = 0.51;
    else if(flct < 0.1) flct = flct + ofRandom(0.3, 0.8);
    else if(flct < 0.5) flct = flct + 2*flct*flct;
    else if(flct >= 0.9)flct = flct - ofRandom(0.3, 0.8);
    else if(flct >= 0.5) flct = flct + 2*(1-flct)*(1-flct);
    
    
}

void PlaySoundAuto::autoPlay(int mili, float BPM, float margin){
    if(nextTime<mili){
        
        int f_over_one = (0.5 - flct)*BPM*margin/60*1000;
        nextTime += BPM/60.0*1000 + f_over_one;
        intermittentChaos();
        play();
        
        printf("1 %d, %d, %f, %f\n",mili,nextTime,(1+margin*(flct-0.5))*BPM,flct);
    }
}