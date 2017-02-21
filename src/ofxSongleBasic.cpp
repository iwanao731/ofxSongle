//
//  ofxSongleBasic.cpp
//  SongleExample
//
//  Created by NAOYA IWAMOTO on 2017/02/21.
//
//

#include "ofxSongleBasic.hpp"

void ofxSongleBasic::load(const string &url)
{
    std::string basic_url = "https://widget.songle.jp/api/v1/song.json?url=" + url;
    
    ofxJSONElement data;
    
    if (!data.open(basic_url))
    {
        ofLogNotice("ofxSongleBasic::load") << "Failed to parse JSON";
    }

    // url
    mURL = data["url"].asString();
    
    // artist
    mArtist.setID(data["artist"]["id"].asInt());
    mArtist.setName(data["artist"]["name"].asString());
    
    // duration
    mDuration = data["duration"].asFloat();
    
    // permalink
    mPermalink = data["permalink"].asString();
    
    // code
    mCode = data["code"].asString();
    
    // rmsAmplitude
    mRmsAmplitude = data["rmsAmplitude"].asFloat();
    
    // createdAt
    mCreatedAt = data["createdAt"].asString();
    
    // updatedAt
    mUpdatedAt = data["updatedAt"].asString();
    
    // recognizedAt
    mRecognizedAt = data["recognizedAt"].asString();
    
    // title
    mTitle = data["title"].asString();
}

float ofxSongleBasic::getDuration()
{
    return mDuration;
}

string &ofxSongleBasic::getTitle()
{
    return mTitle;
}

Artist &ofxSongleBasic::getArtist()
{
    return mArtist;
}

void Artist::setName(const string &name)
{
    mName = name;
}

int Artist::getID()
{
    return mId;
}

string &Artist::getName()
{
    return mName;
}

