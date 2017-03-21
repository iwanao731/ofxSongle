
#include "ofxSongle.h"

using namespace songle;

ofxSongle::ofxSongle()
	: mEnable(false)
{

}

ofxSongle::~ofxSongle()
{

}

void ofxSongle::load(const string &URL)
{
    mBasic.load(URL);
    mBeat.load(URL);
    mChord.load(URL);
    mMelody.load(URL);
    mChorus.load(URL);
    mEnable = true;
}

void ofxSongle::save(const string filename)
{
	// TBD
}

bool ofxSongle::isEnable()
{
	return mEnable;
}

ofxSongleBasic &ofxSongle::getBasic()
{
    return mBasic;
}

ofxSongleBeats &ofxSongle::getBeat()
{
    return mBeat;
}

ofxSongleChord &ofxSongle::getChord()
{
    return mChord;
}

ofxSongleMelody &ofxSongle::getMelody()
{
    return mMelody;
}

ofxSongleChorus &ofxSongle::getChorus()
{
    return mChorus;
}
