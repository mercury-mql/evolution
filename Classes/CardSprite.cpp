#include "CardSprite.h"

#define INVALID_VALUE -1

CardSprite::CardSprite()
	: m_bgColor(NULL), m_label(NULL), m_number(INVALID_VALUE)
{
	setAnchorPoint(ccp(0.5, 0.5));
	ignoreAnchorPointForPosition(false);
}

CardSprite::~CardSprite()
{

}

bool CardSprite::init()
{
	if (!CCNode::init())
	{
		return false;
	}
	return true;
}

bool CardSprite::init(int value, const CCSize& size)
{
	m_number = value < 0 ? INVALID_VALUE : value;
	const char* text = value < 0 ? "" : CCString::createWithFormat("%d", value)->getCString();
	m_bgColor = CCLayerColor::create(ccc4(200, 190, 180, 255), size.width-15, size.height-15);
	m_label = CCLabelTTF::create(text, "Arial", 20);
	CCSize cxtSize = m_bgColor->getContentSize();
	m_label->setPosition(ccp(cxtSize.width/2, cxtSize.height/2));
	m_bgColor->addChild(m_label);
	this->addChild(m_bgColor);
	return true;
}

CardSprite* CardSprite::create(int value, const CCSize& size)
{
	CardSprite* cardSprite = new CardSprite();
	if (cardSprite && cardSprite->init(value, size))
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

void CardSprite::setNumber(int number)
{
	m_number = number < 0 ? INVALID_VALUE : number;
	const char* text = number < 0 ? "" : CCString::createWithFormat("%d", number)->getCString();
	m_label->setString(text);
}

void CardSprite::setContentVisible(bool visible)
{
	m_label->setVisible(visible);
	if (!visible)
	{
		m_number = INVALID_VALUE;
	}
}

bool CardSprite::isContentVisible()
{
	return m_label->isVisible();
}