#include "ofApp.h"

int nextTime;
int cnt = 0;
float x = 0.3;
PlaySound ps;
PlaySoundAuto psa1;
PlaySoundAuto psa2;

void ofApp::setup(){
    //mySound.loadSound("BA_Modern_Fapping[GI].wav"); //サウンドファイルの読込み
    nextTime = BPM/60.0*1000;
    
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
    psa1 = *new PlaySoundAuto(soundNames[3],BPM/60.0*1000 + (0.5 - x)*BPM*margin/60*1000, x);// AIの心拍1
    psa2 = *new PlaySoundAuto(soundNames[6],70/60.0*1000 + (0.5 - 0.7)*70*margin/60*1000, 0.7);// AIの心拍2
}



//--------------------------------------------------------------
void ofApp::update(){

    int mili = ofGetElapsedTimeMillis();
    
    //ここを増やせば良い
    if(psa1.nextTime<mili){
        
        int f_over_one = (0.5 - psa1.flct)*BPM*margin/60*1000;
        psa1.nextTime += BPM/60.0*1000 + f_over_one;
        cnt++;
        psa1.intermittentChaos();
        psa1.play();
        
        printf("1 %d, %d, %f, %f\n",mili,psa1.nextTime,(1+margin*(psa2.flct-0.5))*BPM,psa1.flct);
    }
    
    if(psa2.nextTime<mili){
        
        int f_over_one = (0.5 - psa2.flct)*BPM*margin/60*1000;
        psa2.nextTime += BPM/60.0*1000 + f_over_one;
        cnt++;
        psa2.intermittentChaos();
        psa2.play();
        
        printf("2 %d, %d, %f, %f\n",mili,psa2.nextTime,(1+margin*(psa2.flct-0.5))*70, psa2.flct);
    }
}



//--------------------------------------------------------------
void ofApp::draw(){

}


void ofApp::intermittentChaos(){ //間欠カオス
    //本来の間欠カオス,0と1に張り付きやすい
    /*
    if(x < 0.5) x = x + 2*x*x;
    else x = x - 2*(1-x)*(1-x);
    */
    
    //改良版,なんだかループしてしまっている
    //http://broadbeans.blog.so-net.ne.jp/2011-07-26
    if(x == 0) x = 0.51;
    else if(x < 0.1) x = x + ofRandom(0.3, 0.8);
    else if(x < 0.5) x = x + 2*x*x;
    else if(x >= 0.9)x = x - ofRandom(0.3, 0.8);
    else if(x >= 0.5) x = x + 2*(1-x)*(1-x);
    
    
}

string ofApp::getSoundName(int num){
    return soundNames[num];
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}
