//
//  ofxSongle.hpp
//  SongleExample
//
//  Created by NAOYA IWAMOTO on 2017/02/21.
//
//

#ifndef ofxSongle_h
#define ofxSongle_h

#include <ofMain.h>
#include "ofxJSON.h"
#include "ofxSongleBasic.hpp"
#include "ofxSongleBeats.hpp"
#include "ofxSongleChord.hpp"
#include "ofxSongleMelody.hpp"
#include "ofxSongleChorus.hpp"

namespace songle
{
	class ofxSongle
	{
	public:
		ofxSongle();
		~ofxSongle();

		void load(const string &URL);
		bool isEnable();

		ofxSongleBasic &getBasic();
		ofxSongleBeats &getBeat();
		ofxSongleChord &getChord();
		ofxSongleMelody &getMelody();
		ofxSongleChorus &getChorus();

	private:
		bool mEnable;
		ofxSongleBasic mBasic;
		ofxSongleBeats mBeat;
		ofxSongleChord mChord;
		ofxSongleMelody mMelody;
		ofxSongleChorus mChorus;
	};
}

#endif /* ofxSongle_h */
