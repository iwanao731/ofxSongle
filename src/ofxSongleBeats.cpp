
#include "ofxSongleBeats.hpp"

using namespace songle;

void ofxSongleBeats::load(const string &url)
{
    std::string beat_url = "https://widget.songle.jp/api/v1/song/beat.json?url=" + url;

    ofxJSONElement data;
    
    if (!data.open(beat_url))
    {
        ofLogNotice("ofxSongleBeats::load") << "Failed to parse JSON";
    }
    
    // Beats
    mBeats.resize(data["beats"].size());
    
    for(int i=0; i<this->getNumBeats(); i++)
    {
        mBeats[i].setIndex(data["beats"][i]["index"].asInt());
        mBeats[i].setStart(data["beats"][i]["start"].asInt());
        mBeats[i].setPosition(data["beats"][i]["position"].asInt());
    }
    
    // Bars
    mBars.resize(data["bars"].size());
    
    for(int i=0; i<this->getNumBar(); i++)
    {
        // start
        mBars[i].setStart(data["bars"][i]["start"].asInt());
        
        // beats
        mBars[i].setNumBeats(data["bars"][i]["beats"].size());
        
        for(int j=0; j<mBars[i].getNumBeats(); j++)
        {
            mBars[i].getBeat(j).setIndex(data["bars"][i]["beats"][j]["index"].asInt());
            mBars[i].getBeat(j).setStart(data["bars"][i]["beats"][j]["start"].asInt());
            mBars[i].getBeat(j).setPosition(data["bars"][i]["beats"][j]["position"].asInt());
        }
        
        mBars[i].setIndex(data["bars"][i]["index"].asInt());
    }   
}

int ofxSongleBeats::getNumBeats()
{
    return mBeats.size();
}

int ofxSongleBeats::getNumBar()
{
    return mBars.size();
}

int ofxSongleBeats::getBeatPosition(float currentFloatTime)
{
    int i=0;
    int currentIntTime = currentFloatTime * 1000.f;
    while(currentIntTime >= this->getBeat(i).getStart())
    {
        i++;
    }
    
    int value = i - 1;
    if(value==-1)
        return 0;
    else{
        return this->getBeat(value).getPosition();
    }
}

int ofxSongleBeats::getBeatStart(float currentFloatTime)
{
	int i = 0;
	int currentIntTime = currentFloatTime * 1000.f;
	while (currentIntTime >= this->getBeat(i).getStart())
	{
		i++;
	}

	int value = i - 1;
	if (value == -1)
		return 0;
	else {
		return this->getBeat(value).getStart();
	}
}

int ofxSongleBeats::getBeatIndex(float currentFloatTime)
{
	int i = 0;
	int currentIntTime = currentFloatTime * 1000.f;
	while (currentIntTime >= this->getBeat(i).getStart())
	{
		i++;
	}

	int value = i - 1;
	if (value == -1)
		return 0;
	else {
		return value;
	}
}

Beat &ofxSongleBeats::getBeat(int index)
{
	if (index < 0)
		ofLogError("ofxSongleBeats::getBeat : index < 0");
	else if(mBeats.size() < index)
		ofLogError("ofxSongleBeats::getBeat : oversize");

    return mBeats[index];
}

Bar &ofxSongleBeats::getBar(int index)
{
    return mBars[index];
}

int ofxSongleBeats::calcBPM(float currentFloatTime)
{
    int i=0;
    int currentIntTime = currentFloatTime * 1000.f;
    while(currentIntTime >= this->getBeat(i).getStart())
    {
        i++;
    }
    
    float duration = (this->getBeat(i).getStart() - this->getBeat(i-1).getStart()) / 1000.f;
    int bpm = 60.0f / duration;
    return bpm;
}

// Beat
void Beat::setIndex(int index)
{
    mIndex = index;
}

void Beat::setStart(int start)
{
    mStart = start;
}

void Beat::setPosition(int position)
{
    mPosition = position;
}

int Beat::getIndex()
{
    return mIndex;
}

int Beat::getStart()
{
    return mStart;
}

int Beat::getPosition()
{
    return mPosition;
}

// Bar
void Bar::setStart(int start)
{
    mStart = start;
}

void Bar::setIndex(int index)
{
    mIndex = index;
}

void Bar::setNumBeats(int num)
{
    mBeats.resize(num);
}
    
int Bar::getStart()
{
    return mStart;
}

int Bar::getIndex()
{
    return mIndex;
}

int Bar::getNumBeats()
{
    return mBeats.size();
}

Beat &Bar::getBeat(int index)
{
    return mBeats[index];
}
