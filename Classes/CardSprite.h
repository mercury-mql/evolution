#ifndef _CARD_SPRITE_H
#define _CARD_SPRITE_H

#include "cocos2d.h"
USING_NS_CC;

class CardSprite : public CCNode
{
public:
	CardSprite();
	~CardSprite();
	bool init();
	bool init(int value, const CCSize& size);
	static CardSprite* create(int value, const CCSize& size);
	CREATE_FUNC(CardSprite);

	int getNumber() {return m_number;}
	void setNumber(int number);
	void resetValue();

	void setContentVisible(bool visible);
	bool isContentVisible();

private:
	CCLayerColor* m_bgColor;
	CCLabelTTF* m_label;
	int m_number;
};

#endif