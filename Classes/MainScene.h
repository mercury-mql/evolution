#ifndef _MAIN_SCENE_H
#define _MAIN_SCENE_H

#include "cocos2d.h"
USING_NS_CC;

class MainScene : public CCLayer
{
public:
	MainScene();
	~MainScene();
	bool init();
	static CCScene* mainScene();
	CREATE_FUNC(MainScene);

private:
	CCSize m_winSize;
	CCSprite* m_bg;
};

#endif