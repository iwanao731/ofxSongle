//
//  ofxSongleBasic.hpp
//  SongleExample
//
//  Created by NAOYA IWAMOTO on 2017/02/21.
//
//

#ifndef ofxSongleBasic_hpp
#define ofxSongleBasic_hpp

#include <ofMain.h>
#include "ofxJSON.h"

namespace songle
{
	class Artist
	{
	public:
		void setID(int id) { mId = id; }
		void setName(const string &name);

		int getID();
		string &getName();

	private:
		int mId;
		string mName;
	};

	class ofxSongleBasic
	{
	public:
		ofxSongleBasic() {}
		~ofxSongleBasic() {}

		void load(const string &url);

		float getDuration();
		string &getTitle();
		Artist &getArtist();

	private:
		string mURL;
		int mId;
		float mDuration;
		float mRmsAmplitude;
		string mPermalink;
		string mCode;
		string mCreatedAt;
		string mUpdatedAt;
		string mRecognizedAt;
		string mTitle;
		Artist mArtist;
	};
}

#endif /* ofxSongleBasic_hpp */
