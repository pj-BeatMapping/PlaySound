#include "ofApp.h"

int nextTime;
int cnt = 0;
float x = 0.3;

void ofApp::setup(){
    mySound.loadSound("BA_Modern_Fapping[GI].wav"); //サウンドファイルの読込み
    nextTime = BPM/60.0*1000;
}



//--------------------------------------------------------------
void ofApp::update(){

    
    int mili = ofGetElapsedTimeMillis();
    if(nextTime<mili){
        printf("%d, %d, %f\n",mili,nextTime,x);
        int f_over_one = (0.5 - x)*BPM*margin/60*1000;
        nextTime += BPM/60.0*1000 + f_over_one;
        mySound.play(); //サウンド再生開始
        cnt++;
        intermittentChaos();
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
