#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

namespace songle
{
	class Beat;
	class Bar;

	class ofxSongleBeats
	{
	public:
		ofxSongleBeats() {}
		~ofxSongleBeats() {}

		void load(const string &url);
		void loadFile(const string &filename);
		int getNumBeats();
		int getNumBar();
		int getBeatPosition(float currentFloatTime);
		int getBeatStart(float currentFloatTime);
		int getBeatIndex(float currentFloatTime);
		int getBarPosition(const float currentFloatTime);
		int getBarStart(const float currentFloatTime);
		int getBarIndex(const float currentFloatTime);
		int calcBPM(float currentFloatTime);
		Beat &getBeat(int index);
		Bar &getBar(int index);
		void clear();

	private:
		std::vector<Beat> mBeats;
		std::vector<Bar> mBars;
	};

	class Beat
	{
	public:
		void setIndex(int index);
		void setStart(int start);
		void setPosition(int position);

		int getIndex();
		int getStart();
		int getPosition();

	private:
		int mIndex;
		int mStart;
		int mPosition;
	};

	class Bar
	{
	public:
		void setStart(int start);
		void setIndex(int index);
		void setNumBeats(int num);

		int getStart();
		int getIndex();
		int getNumBeats();
		Beat &getBeat(int index);

	private:
		int mStart;
		int mIndex;
		std::vector<Beat> mBeats;
	};
}
