//
//  appOsc.cpp
//  NetworkHandle
//
//  Created by erik on 7/5/15.
//
//

#include "AppUtilOsc.h"

AppUtilOsc::AppUtilOsc(){
    feedbackPort_ = 4300;
}

void AppUtilOsc::setup(string _serverIP, int _sendPort, int _receiverPort)
{
    sender.setup(_serverIP, _sendPort);
    receiver.setup(_receiverPort);
}

void AppUtilOsc::update()
{
    while( receiver.hasWaitingMessages() )
    {
        ofPtr<ofxOscMessage> m(new ofxOscMessage);
        receiver.getNextMessage( m.get() );
        
        string _add = m->getAddress();
        
        if( _add != "" )
        {
            string _key = m->getRemoteIp() + "|" + _add;
            oscMsgMap[_key] = m;
            
            if(_add == "/setSendFeedback" || _add == "/sendFeedback")
            {
                bool _flag = m->getArgType(0) == OFXOSC_TYPE_STRING ? ofToBool(m->getArgAsString(0)) : m->getArgAsInt32(0);
                setSendFeedback(_flag);
            }
            else if(_add == "/feedbackPort")
            {
                int _port = m->getArgType(0) == OFXOSC_TYPE_STRING ? ofToInt(m->getArgAsString(0)) : m->getArgAsInt32(0);
                setFeedbackPort(_port);
            }
            
            if(ofGetLogLevel() == OF_LOG_VERBOSE)
            {
                string msg_string;
                msg_string = m->getAddress();
                msg_string += ": ";
                for( int i=0; i<m->getNumArgs(); i++ ){
                    // get the argument type
                    msg_string += m->getArgTypeName( i );
                    msg_string += ":";
                    // display the argument - make sure we get the right type
                    if( m->getArgType( i ) == OFXOSC_TYPE_INT32 )
                        msg_string += ofToString( m->getArgAsInt32( i ) );
                    else if( m->getArgType( i ) == OFXOSC_TYPE_FLOAT )
                        msg_string += ofToString( m->getArgAsFloat( i ) );
                    else if( m->getArgType( i ) == OFXOSC_TYPE_STRING )
                        msg_string += m->getArgAsString( i );
                    else
                        msg_string += "unknown";
                    
                    ofLogVerbose() << m->getRemoteIp() << ":" << m->getRemotePort() << ' ' << msg_string;
                }
            }
            
            if(isSendFeedback() && _add != "/feedback")
            {
                sendFeedbackOscMsg("/feedback", "[" + _add +"] with [" + ofToString(m->getNumArgs())  + "] Args received.", m->getRemoteIp(), feedbackPort_);
            }
            
        }
    }
    if(oscMsgMap.size() > 20){
        oscMsgMap.erase(oscMsgMap.begin());
    }
}

void AppUtilOsc::setSendFeedback(bool _flag){
    bSendFeedback_ = true;
}
bool AppUtilOsc::isSendFeedback(){
    return bSendFeedback_;
}


void AppUtilOsc::sendOscMsg(string _add, string _msg)
{
    ofxOscMessage m;
    m.setAddress( _add );
    m.addStringArg(_msg);
    sender.sendMessage( m );
}

void AppUtilOsc::setFeedbackPort(int _p){
    if(_p)
        feedbackPort_ = _p;
}


void AppUtilOsc::sendFeedbackOscMsg(string _add, string _msg, string _ipAdd, int _port)
{
    ofxOscMessage m;
    m.setAddress( _add );
    m.addStringArg(_msg);
    m.setRemoteEndpoint(_ipAdd, _port);

    ofxOscSender s;
    s.setup(_ipAdd, _port);
    s.sendMessage(m);
}

void AppUtilOsc::clearAllMsg(){
    oscMsgMap.clear();
}
