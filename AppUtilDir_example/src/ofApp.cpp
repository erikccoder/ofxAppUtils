#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    string _path = "~/Downloads";
    vector<string> _files = getFilesFrom(_path);
    for (string _file : _files)
    {
        ofLog() << _file;
    }
    ofLog() << "all fles from " << _path;
    ofLog() << "-------------------------------------------------";
    

    vector<string> _exts;
    _exts.push_back("jpg");
    _exts.push_back("jpeg");
    _exts.push_back("png");
    _exts.push_back("tif");
    vector<string> _images = getFilesFrom(_path, _exts);
    for (string _file : _images)
    {
        ofLog() << _file;
    }
    ofLog() << "all image fles from " << _path;
    ofLog() << "-------------------------------------------------";
    
    vector<string> _pngs = getFilesFrom(_path, "png");
    for (string _file : _pngs)
    {
        ofLog() << _file;
    }
    ofLog() << "all png fles from " << _path;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapStringHighlight("look at console", 0, 14);
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
