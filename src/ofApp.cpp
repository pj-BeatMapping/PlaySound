#include "ofApp.h"

int cnt = 0;
float x = 0.3;
PlaySound ps;
PlaySoundAuto psa1;
PlaySoundAuto psa2;
vector<string> soundNames;
float BPM = 80;
float margin = 0.2;

void ofApp::setup(){
    
    soundNames.push_back("BA_Modern_Fapping[GI].wav");
    soundNames.push_back("LD_Epic_Lead[AS].wav");
    soundNames.push_back("LD_Epic_Lead[AS]DS.wav");
    soundNames.push_back("SY_PopSuperSaw[GS]DS.wav");
    soundNames.push_back("SY_SAMsPissed[SD]DS.wav");
    soundNames.push_back("SY_Shot_Dirt_Stab[IM].wav");
    soundNames.push_back("SY_Space_Bach[SN].wav");
    soundNames.push_back("SY_Stereoid[SD].wav");
    
    //どの音を鳴らすかはsoundNamesの番号で指定
    ps = *new PlaySound(soundNames[0]); //人間の心拍
    //AIの心拍, (サウンドファイルの名前, 最初に鳴るまでの時間, 間欠カオスの初期値(0~1))
    psa1 = *new PlaySoundAuto(soundNames[2],BPM/60.0*1000 + (0.5 - x)*BPM*margin/60*1000, x);// AIの心拍1
    psa2 = *new PlaySoundAuto(soundNames[4],70/60.0*1000 + (0.5 - 0.7)*70*margin/60*1000, 0.7);// AIの心拍2
}



//--------------------------------------------------------------
void ofApp::update(){

    int mili = ofGetElapsedTimeMillis();
    
    //AI心拍1を鳴らす(今の時間, BPM, BPMを基準としたゆらぎの割合(BPM = 80, margin = 0.5なら60~100(=差がBPM*margin)の間で揺らぐ))
    psa1.autoPlay(mili,BPM,margin);
    
    //AI心拍2を鳴らす
    psa2.autoPlay(mili,70,margin);
}