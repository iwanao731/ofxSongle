#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class Beat;
class Bar;

class ofxSongleBeats
{
public:
    ofxSongleBeats(){}
    ~ofxSongleBeats(){}
    
    void load(const string &url);
    int getNumBeats();
    int getNumBar();
    int getBeatPosition(float currentFloatTime);
    int calcBPM(float currentFloatTime);
    Beat &getBeat(int index);
    Bar &getBar(int index);

private:
    std::vector<Beat> mBeats;
    std::vector<Bar> mBars;
};

class Beat
{
public:
    void setIndex(int index);
    void setStart(int start);
    void setPosition(int position);
    
    int getIndex();
    int getStart();
    int getPosition();
    
private:
    int mIndex;
    int mStart;
    int mPosition;
};

class Bar
{
public:
    void setStart(int start);
    void setIndex(int index);
    void setNumBeats(int num);
    
    int getStart();
    int getIndex();
    int getNumBeats();
    Beat &getBeat(int index);
    
private:
    int mStart;
    int mIndex;
    std::vector<Beat> mBeats;
};
