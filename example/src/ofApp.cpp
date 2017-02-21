#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    mTimecode.setFPS(30);
    currentTime = 0.0f;
    countNumberOfBeat = 0;
    
    string filename = "Redial.mp4";
    video.load(filename);
    video.play();
    
    std::string youtube_url = "www.youtube.com/watch?v=243vPl8HdVk";
    songle.load(youtube_url);
}

//--------------------------------------------------------------
void ofApp::update(){
    currentTime += ofGetLastFrameTime();
    video.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    ofBackground(0);
    
    ofSetColor(255);
    video.draw(200, 200, video.getWidth()/2, video.getHeight()/2);
    ofSetColor(255);
    
    ofDrawBitmapString(songle.getBasic().getTitle(), 20, 20);
    string all_time = mTimecode.timecodeForSeconds(songle.getBasic().getDuration() / 1000.f);
    ofDrawBitmapString(mTimecode.timecodeForSeconds(currentTime) + " / " + all_time, 20, 40);
    
    string beatText;
    int value = songle.getBeat().getBeatPosition(currentTime);
    switch(value)
    {
        case 1:
            beatText = "x - - -";
            break;
        case 2:
            beatText = "- x - -";
            break;
        case 3:
            beatText = "- - x -";
            break;
        case 4:
            beatText = "- - - x";
            break;
        default:
            beatText = "- - - -";
            break;
    }
    int bpm = songle.getBeat().calcBPM(currentTime);
    ofDrawBitmapString("beat : " + beatText + "   bpm : " + ofToString(bpm), 20, 60);
    
    
    // melody
    string chord = songle.getChord().getCurrentChord(currentTime);
    ofDrawBitmapString("chord : " + chord, 20, 80);
    
    ofSetColor(255, 0, 0);
    ofDrawLine(currentTime*3, ofGetHeight(), currentTime*3, 0);
    
    // chorus
    for (int i = 0; i < songle.getChorus().getNumRepeatSegments(); i++)
    {
        int numRepeats = songle.getChorus().getRepeatSegment(i).getNumRepeats();
        for(int j=0; j<numRepeats; j++)
        {
            float start = (float)songle.getChorus().getRepeatSegment(i).getRepeat(j).getStart() / 333.f;
            float duration = (float)songle.getChorus().getRepeatSegment(i).getRepeat(j).getDuration() / 333.f;
            
            if(songle.getChorus().getRepeatSegment(i).getIsChorus()){
                ofSetColor(255, 140, 0);
            }else{
                ofSetColor(30,30,255);
            }
            ofDrawRectangle(ofPoint(start, (ofGetHeight()-100)+10*(i+1)), duration, 10);
        }
    }
    
    float nextTime = (float)songle.getBeat().getBeat(countNumberOfBeat).getStart() / 1000.f;
    
    if (currentTime >= nextTime) {
        countNumberOfBeat++;
        ofBackground(255);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
    }
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
