#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    fboHist.setup(3, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fboHist.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if(key == OF_KEY_LEFT)
    {
        fboHist.undo();
    }
    else if(key == ' ')
        setup();
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    fboHist.begin();
    ofCircle(x, y, 20);
    fboHist.end();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    fboHist.saveHistory();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
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
