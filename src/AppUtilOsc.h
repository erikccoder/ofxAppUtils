//
//  appOsc.h
//  NetworkHandle
//
//  Created by erik on 7/5/15.
//
//

#ifndef __NetworkHandle__appOsc__
#define __NetworkHandle__appOsc__

#include "ofMain.h"
#include "ofxOsc.h"

class AppUtilOsc
{
    
private:
    int feedbackPort_;
    bool bSendFeedback_;
protected:
    
    ofxOscSender sender;
    ofxOscReceiver receiver;
    
    map<string, ofPtr<ofxOscMessage> > oscMsgMap;
    
public:
    
    AppUtilOsc();
    
    void setup(string _serverIP, int _sendPort=4300, int _receivePort = 4300);
    void update();
    
    void sendOscMsg(string _add, string _msg);
    void sendFeedbackOscMsg(string _add, string _msg, string _ipAdd, int _port=4300);
    void clearAllMsg();
    
    void setSendFeedback(bool _flag);
    bool isSendFeedback();
    void setFeedbackPort(int _p);
};

#endif /* defined(__NetworkHandle__appOsc__) */
