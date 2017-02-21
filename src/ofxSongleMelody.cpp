//
//  ofxSongleMelody.cpp
//  SongleExample
//
//  Created by NAOYA IWAMOTO on 2017/02/21.
//
//

#include "ofxSongleMelody.hpp"

void ofxSongleMelody::load(const string &url)
{
    std::string melody_url = "https://widget.songle.jp/api/v1/song/melody.json?url=" + url;

    ofxJSONElement data;
    
    if (!data.open(melody_url))
    {
        ofLogNotice("ofxSongleMelody::load") << "Failed to parse JSON";
    }
    
    mNotes.resize(data["notes"].size());
    
    for(int i=0; i<this->getNumNotes(); i++)
    {
        // start
        mNotes[i].setStart(data["notes"][i]["start"].asInt());
        
        // duration
        mNotes[i].setDuration(data["notes"][i]["duration"].asInt());
        
        // pitch
        mNotes[i].setPitch(data["notes"][i]["pitch"].asFloat());
        
        // number
        mNotes[i].setNumber(data["notes"][i]["number"].asInt());
        
        // index
        mNotes[i].setIndex(data["notes"][i]["index"].asInt());
    }
}

int ofxSongleMelody::getNumNotes()
{
    return mNotes.size();
}

Note &ofxSongleMelody::getNote(int index)
{
    return mNotes[index];
}

void Note::setStart(int start)
{
    mStart = start;
}

void Note::setDuration(int duration)
{
    mDuration = duration;
}

void Note::setPitch(float pitch)
{
    mPitch = pitch;
}

void Note::setNumber(int number)
{
    mNumber = number;
}

void Note::setIndex(int index)
{
    mIndex = index;
}
