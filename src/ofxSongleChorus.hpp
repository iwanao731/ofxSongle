//
//  ofxSongleChorus.hpp
//  SongleExample
//
//  Created by NAOYA IWAMOTO on 2017/02/21.
//
//

#ifndef ofxSongleChorus_hpp
#define ofxSongleChorus_hpp

#include <ofMain.h>
#include "ofxJSON.h"

class Repeat;
class Segment;

class ofxSongleChorus
{
public:
    ofxSongleChorus(){}
    ~ofxSongleChorus(){}
    
    void load(const string &url);
    
    Segment &getChorusSegment(int index);
    Segment &getRepeatSegment(int index);
    
    int getNumChorusSegments();
    int getNumRepeatSegments();
    
private:
    std::vector<Segment> mChorusSegments;
    std::vector<Segment> mRepeatSegments;
};

class Repeat
{
public:
    void setStart(int start);
    void setDuration(int duration);
    void setIndex(int index);
    
    int getStart();
    int getDuration();
    int getindex();
    
private:
    int mStart;
    int mDuration;
    int mIndex;
};

class Segment
{
public:
    void setIndex(int index);
    void setIsChorus(bool flag);
    void setDuration(int duration);
    void setNumRepeats(int num);
    
    int getNumRepeats();
    int getIndex();
    bool getIsChorus();
    Repeat &getRepeat(int index);
    
private:
    int mIndex;
    bool mIsChorus;
    int mDuration;
    std::vector<Repeat> mRepeats;
};


#endif /* ofxSongleChorus_hpp */
