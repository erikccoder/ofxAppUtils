//
//  ofxFboHistory.h
//  undo
//
//  Created by erikccoder on 8/5/15.
//
//

#ifndef undo_ofxFboHistory_h
#define undo_ofxFboHistory_h

#include "ofMain.h"

class FboHistory
{
private:
    deque<ofPtr<ofFbo> > history_;
    deque<ofPtr<ofFbo> > empty_;
    
    ofPtr<ofFbo> current_;
    
public:
    
    void setup(int sumSteps, int w, int h)
    {
        empty_.assign(history_.begin(), history_.end());
        history_.resize(0);
        empty_.push_back(current_);
        empty_.resize(sumSteps);
        for (int i=0; i<sumSteps; i++)
        {
            if(!empty_[i])
            {
                empty_[i] = ofPtr<ofFbo>(new ofFbo);
                empty_[i]->allocate(w, h);
            }
            empty_[i]->begin();
            ofClear(0);
            empty_[i]->end();
        }
        current_ = empty_.back();
        empty_.pop_back();
    }
    
    ofPtr<ofFbo>& getCurFbo(){
        return current_;
    }
    
    void saveHistory()
    {
        ofPtr<ofFbo> _item;
        if(empty_.size())
        {
            _item = empty_.back();
            empty_.pop_back();
        }
        else
        {
            _item = history_.front();
            history_.pop_front();
        }
        
        _item->begin();
        ofClear(0);
        current_->draw(0,0);
        _item->end();
        
        history_.push_back(_item);
    }
    
    void undo()
    {
        if(history_.size())
        {
            ofPtr<ofFbo> _item = history_.back();
            history_.pop_back();
            
            current_->begin();
            ofClear(0);
            _item->draw(0,0);
            current_->end();
            
            empty_.push_back(_item);
        }
    }
    
    void begin(){
        current_->begin();
    }
    
    void end(){
        current_->end();
    }
    
    void draw(int x, int y)
    {
        current_->draw(x, y);
    }
    void draw(ofVec2f _p)
    {
        current_->draw(_p);
    }
    
    
    
};

#endif
