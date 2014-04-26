#ifndef _MAIN_SCENE_H
#define _MAIN_SCENE_H

#include "cocos2d.h"
#include "CardSprite.h"
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
	void showCard(int number, int xOrder, int yOrder);
	void hideCard(int xOrder, int yOrder);

	void AddOneRandom();
	void AddTowRandom();
	void AddRandom(int number);
	bool canAddOne();
	bool isOver();
	void checkCards();

	void updateCards();
private:
	CCSize m_winSize;
	CCLayerColor* m_bg;
	CardSprite* m_cards[4][4];
	int m_numbers[4][4];
	float m_glOrgX, m_glOrgY, m_glDstX, m_glDstY;
};

#endif