

#include "ofMain.h"
#include "PlaySoundAuto.h"
#include "PlaySound.h"



class ofApp : public ofBaseApp {
    
    const float BPM = 80;
    const float margin = 0.2;
    
    vector<string> soundNames;

    
public:
    void setup();
    
    void update();
    void draw();
    
    void intermittentChaos();
    
    string getSoundName(int num);
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    //ofSoundPlayer mySound; //ofSoundクラスをインスタンス化
};