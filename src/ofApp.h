#pragma once

#include "ofMain.h"

#ifdef TARGET_RASPBERRY_PI
#include "ofxOMXVideoGrabber.h"
#endif

//#include "ofxPoco.h"
#include "ofxVideoRecorder.h"

class ofApp : public ofBaseApp{

public:

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void appendBufferPixels();
    void appendRecorderFrame();
    void setupPiCam();
    void setupRecorder();
    void recordingComplete(ofxVideoRecorderOutputFileCompleteEventArgs& args);
    void exit();

#ifdef TARGET_RASPBERRY_PI
    ofxOMXVideoGrabber vidGrabber;
#else
    ofVideoGrabber vidGrabber;
#endif
    ofxVideoRecorder recorder;
    
    ofTexture videoTexture;
    int camWidth;
    int camHeight;
    
    
    vector<ofPixels> frames;
    bool isRecording;
    float speed;
    float frameIndex;
    float maxSeconds;
    
    float frameRate;
    int resizeW, resizeH;
    float resize;
    
    float timeStamp, memoryTimestamp, measureTimestamp;
    
    bool bufferOrMpeg;
    
    
    ofSoundStream soundStream;
};
