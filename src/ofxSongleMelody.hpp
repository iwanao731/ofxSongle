//
//  ofxSongleMelody.hpp
//  SongleExample
//
//  Created by NAOYA IWAMOTO on 2017/02/21.
//
//

#ifndef ofxSongleMelody_hpp
#define ofxSongleMelody_hpp

#include <ofMain.h>
#include "ofxJSON.h"

namespace songle
{
	class Note;

	class ofxSongleMelody
	{
	public:
		ofxSongleMelody() {}
		~ofxSongleMelody() {}

		void load(const string &url);
		int getNumNotes();
		Note &getNote(int index);

	private:
		vector<Note> mNotes;
	};

	class Note
	{
	public:
		void setStart(int start);
		void setDuration(int duration);
		void setPitch(float pitch);
		void setNumber(int number);
		void setIndex(int index);

	private:
		int mStart;
		int mDuration;
		float mPitch;
		int mNumber;
		int mIndex;
	};
}

#endif /* ofxSongleMelody_hpp */
