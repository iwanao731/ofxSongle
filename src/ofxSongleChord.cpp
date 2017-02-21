//
//  ofxSongleChord.cpp
//  SongleExample
//
//  Created by NAOYA IWAMOTO on 2017/02/21.
//
//

#include "ofxSongleChord.hpp"


void ofxSongleChord::load(const string &url)
{
    std::string chord_url = "https://widget.songle.jp/api/v1/song/chord.json?url=" + url;
    
    ofxJSONElement data;
    
    if (!data.open(chord_url))
    {
        ofLogNotice("ofxSongleChord::load") << "Failed to parse JSON";
    }
    
    mChords.resize(data["chords"].size());
    
    for(int i=0; i<this->getNumChords(); i++)
    {
        // index
        mChords[i].setIndex(data["chords"][i]["index"].asInt());
        
        // start
        mChords[i].setStart(data["chords"][i]["start"].asInt());
        
        // duration
        mChords[i].setDuration(data["chords"][i]["duration"].asInt());
        
        // name
        mChords[i].setName(data["chords"][i]["name"].asString());
    }
}

string ofxSongleChord::getCurrentChord(float currentFloatTime)
{
    int currentIntTime = currentFloatTime * 1000.f;
    
    int i = 0;
    while(currentIntTime >= this->getChord(i).getStart())
    {
        i++;
    }
    
    int value = i - 1;    
    return this->getChord(value).getName();
}

int ofxSongleChord::getNumChords()
{
    return mChords.size();
}

Chord &ofxSongleChord::getChord(int index)
{
    return mChords[index];
}


void Chord::setIndex(int index)
{
    mIndex = index;
}

void Chord::setStart(int start)
{
    mStart = start;
}

void Chord::setDuration(int duration)
{
    mDuration = duration;
}

void Chord::setName(const string &name)
{
    mName = name;
}
    
int Chord::getIndex()
{
    return mIndex;
}

int Chord::getStart()
{
    return mStart;
}

int Chord::getDuration()
{
    return mDuration;
}

string &Chord::getName()
{
    return mName;
}
