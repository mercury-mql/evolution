#ifndef _WELCOME_SCENE_H
#define _WELCOME_SCENE_H

#include "cocos2d.h"
USING_NS_CC;

class WelcomeScene : public CCLayer
{
public:
	WelcomeScene();
	~WelcomeScene();
	bool init();

	static CCScene* welcomeScene();
	CREATE_FUNC(WelcomeScene)

private:
	CCSize m_winSize;
	CCSprite* m_bg;
};

#endif