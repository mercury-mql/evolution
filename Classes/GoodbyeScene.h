#ifndef _GOODBYE_SCENE_H
#define _GOODBYE_SCENE_H

#include "cocos2d.h"
USING_NS_CC;

class GoodbyeScene : public CCLayer
{
public:
	GoodbyeScene();
	~GoodbyeScene();
	bool init();
	static CCScene* goodByeScene();
	CREATE_FUNC(GoodbyeScene);

private:
	CCSize m_winSize;
	CCSprite* m_bg;
};

#endif