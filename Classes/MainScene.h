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

	void registerWithTouchDispatcher();
	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

private:
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void createCardSprites();

private:
	CCSize m_winSize;
	CCSprite* m_bg;
	CCArray* m_usedCard;
	CCArray* m_unusedCard;
	float m_glOrgX, m_glOrgY, m_glDstX, m_glDstY;
};

#endif