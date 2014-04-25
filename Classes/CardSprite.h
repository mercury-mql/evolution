#ifndef _CARD_SPRITE_H
#define _CARD_SPRITE_H

#include "cocos2d.h"
USING_NS_CC;

class CardSprite : public CCLayer
{
public:
	CardSprite();
	~CardSprite();
	bool init();
	bool init(int value, const CCPoint& pos, const CCSize& size);
	static CardSprite* create(int value, const CCPoint& pos, const CCSize& size);
	CREATE_FUNC(CardSprite);

	CC_SYNTHESIZE(int, m_number, Number);
	void resetValue();

private:
	CCLayerColor* m_bgColor;
	CCLabelTTF* m_label;
};

#endif