#include "CardSprite.h"

#define INVALID_VALUE -1

CardSprite::CardSprite()
	: m_bgColor(NULL), m_label(NULL), m_number(INVALID_VALUE)
{

}

CardSprite::~CardSprite()
{

}

bool CardSprite::init()
{
	return true;
}

bool CardSprite::init(int value, const CCPoint& pos, const CCSize& size)
{
	this->m_number = value;
	return true;
}

CardSprite* CardSprite::create(int value, const CCPoint& pos, const CCSize& size)
{
	CardSprite* cardSprite = new CardSprite();
	if (cardSprite && cardSprite->init(value, pos, size))
	{
		cardSprite->autorelease();
		return cardSprite;
	}
	CC_SAFE_DELETE(cardSprite);
	return NULL;
}

void CardSprite::resetValue()
{
	m_number = INVALID_VALUE;
}

