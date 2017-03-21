//
//  ofxSongleChorus.cpp
//  SongleExample
//
//  Created by NAOYA IWAMOTO on 2017/02/21.
//
//

#include "ofxSongleChorus.hpp"

using namespace songle;

void ofxSongleChorus::load(const string &url)
{
    std::string chorus_url = "https://widget.songle.jp/api/v1/song/chorus.json?url=" + url;

    ofxJSONElement data;
    
    if (!data.open(chorus_url))
    {
        ofLogNotice("ofxSongleChorus::load") << "Failed to parse JSON";
    }
    
    // Chorus Segments
    mChorusSegments.resize(data["chorusSegments"].size());
    
    for(int i=0; i<mChorusSegments.size(); i++)
    {
        // index
        mChorusSegments[i].setIndex(data["chorusSegments"][i]["index"].asInt());
        
        // isChorus
        if(data["chorusSegments"][i]["isChorus"].asString() == "true")
            mChorusSegments[i].setIsChorus(true);
        else
            mChorusSegments[i].setIsChorus(false);
        
        // duration
        mChorusSegments[i].setIndex(data["chorusSegments"][i]["duration"].asInt());

        // repeats
        mChorusSegments[i].setNumRepeats(data["chorusSegments"][i]["repeats"].size());
        
        for(int j=0; j< mChorusSegments[i].getNumRepeats(); j++)
        {
            mChorusSegments[i].getRepeat(j).setStart(data["chorusSegments"][i]["repeats"][j]["start"].asInt());
            mChorusSegments[i].getRepeat(j).setDuration(data["chorusSegments"][i]["repeats"][j]["duration"].asInt());
            mChorusSegments[i].getRepeat(j).setIndex(data["chorusSegments"][i]["repeats"][j]["index"].asInt());
        }
    }
    
    // Repeat Segments
    mRepeatSegments.resize(data["repeatSegments"].size());
    
    for(int i=0; i<mRepeatSegments.size(); i++)
    {
        // index
        mRepeatSegments[i].setIndex(data["repeatSegments"][i]["index"].asInt());
        
        // isChorus
        if(data["repeatSegments"][i]["isChorus"].asString() == "true")
            mRepeatSegments[i].setIsChorus(true);
        else
            mRepeatSegments[i].setIsChorus(false);
        
        // duration
        mRepeatSegments[i].setIndex(data["repeatSegments"][i]["duration"].asInt());
        
        // repeats
        mRepeatSegments[i].setNumRepeats(data["repeatSegments"][i]["repeats"].size());
        
        for(int j=0; j< mRepeatSegments[i].getNumRepeats(); j++)
        {
            mRepeatSegments[i].getRepeat(j).setStart(data["repeatSegments"][i]["repeats"][j]["start"].asInt());
            mRepeatSegments[i].getRepeat(j).setDuration(data["repeatSegments"][i]["repeats"][j]["duration"].asInt());
            mRepeatSegments[i].getRepeat(j).setIndex(data["repeatSegments"][i]["repeats"][j]["index"].asInt());
        }
    }
}

void ofxSongleChorus::draw(ofPoint &p, float width, float height, float allDuration, float currentTime, float speed)
{
	ofPushMatrix();

	ofSetLineWidth(2.0);

	ofFill();
	float scale = width / allDuration;
	float eachHeight = height / this->getNumRepeatSegments();

	for (int k = 0; k < 2; k++)
	{
		if (k == 0)
			ofFill();
		else
			ofNoFill();

		for (int i = 0; i < this->getNumRepeatSegments(); i++)
		{
			int numRepeats = this->getRepeatSegment(i).getNumRepeats();
			for (int j = 0; j < numRepeats; j++)
			{
				float start = (float) this->getRepeatSegment(i).getRepeat(j).getStart() * scale;
				float duration = (float) this->getRepeatSegment(i).getRepeat(j).getDuration() * scale;

				if (this->getRepeatSegment(i).getIsChorus()) {
					ofSetColor(255, 140, 0);
				}
				else if(k!=1){
					ofSetColor(30, 30, 255);
				}else{
					ofSetColor(0);
				}
				ofDrawRectangle(ofPoint(p.x + start, p.y + eachHeight * i), duration, eachHeight);
			}
		}
	}

	ofSetColor(255, 0, 0);
	float x = currentTime * 1000.f * scale * speed;
	ofDrawLine(p.x + x, p.y, p.x + x, p.y + height);
	ofSetColor(255);

	ofPopMatrix();
}

int ofxSongleChorus::getNumChorusSegments()
{
    return mChorusSegments.size();
}

int ofxSongleChorus::getNumRepeatSegments()
{
    return mRepeatSegments.size();
}

Segment &ofxSongleChorus::getChorusSegment(int index)
{
    return mChorusSegments[index];
}

Segment &ofxSongleChorus::getRepeatSegment(int index)
{
    return mRepeatSegments[index];
}


// Segment
void Segment::setIndex(int index)
{
    mIndex = index;
}

void Segment::setIsChorus(bool flag)
{
    mIsChorus = flag;
}

void Segment::setDuration(int duration)
{
    mDuration = duration;
}

void Segment::setNumRepeats(int num)
{
    mRepeats.resize(num);
}

int Segment::getNumRepeats()
{
    return mRepeats.size();
}

int Segment::getIndex()
{
    return mIndex;
}

bool Segment::getIsChorus()
{
    return mIsChorus;
}

Repeat &Segment::getRepeat(int index)
{
    if(mRepeats.size() <= index)
        ofLogNotice("Segment::getRepeat") << "Over the index value";
    
    return mRepeats[index];
}

// Repeat
void Repeat::setStart(int start)
{
    mStart = start;
}

void Repeat::setDuration(int duration)
{
    mDuration = duration;
}

void Repeat::setIndex(int index)
{
    mIndex = index;
}

int Repeat::getStart()
{
    return mStart;
}

int Repeat::getDuration()
{
    return mDuration;
}

int Repeat::getindex()
{
    return mIndex;
}
