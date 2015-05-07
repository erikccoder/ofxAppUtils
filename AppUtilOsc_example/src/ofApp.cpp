#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    AppUtilOsc::setup("localhost", 12345, 23456) // serverIP, sendPort, receiverPort
    

}

//--------------------------------------------------------------
void ofApp::update(){
    AppUtilOsc::update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    stringstream ss;
    
    ss << "oscMsg.size: " << oscMsgMap.size() << "\n";
    
    for (auto& m : oscMsgMap)
    {
        if(m.first.find("/test") != string::npos)
            ofLog() << "do sth with " << m.first;
    }
    
    AppUtilOsc::clearAllMsg();
    ofDrawBitmapStringHighlight(ss.str(), 100,100);
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
