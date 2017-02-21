//
//  ofxSongleChord.hpp
//  SongleExample
//
//  Created by NAOYA IWAMOTO on 2017/02/21.
//
//

#ifndef ofxSongleChord_hpp
#define ofxSongleChord_hpp

#include <ofMain.h>
#include "ofxJSON.h"

namespace songle
{
	class Chord;

	class ofxSongleChord
	{
	public:
		ofxSongleChord() {}
		~ofxSongleChord() {}

		void load(const string &url);
		string getCurrentChord(float currentFloatTime);
		int getNumChords();
		Chord &getChord(int index);

	private:
		vector<Chord> mChords;
	};

	class Chord
	{
	public:
		void setIndex(int index);
		void setStart(int start);
		void setDuration(int duration);
		void setName(const string &name);

		int getIndex();
		int getStart();
		int getDuration();
		string &getName();

	private:
		int mIndex;
		int mStart;
		int mDuration;
		string mName;
	};

}
#endif /* ofxSongleChord_hpp */
