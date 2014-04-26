#include "CardSprite.h"
#include "Globals.h"
#include <string>
using namespace std;

#define INVALID_VALUE 0

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
	m_number = value <= 0 ? INVALID_VALUE : value;
	string text = GetCardText(m_number);
	m_bgColor = CCLayerColor::create(GetCardColor4B(m_number), size.width-15, size.height-15);
	m_label = CCLabelTTF::create(text.c_str(), "Arial", 20);
	CCSize cxtSize = m_bgColor->getContentSize();
	m_label->setPosition(ccp(cxtSize.width/2, cxtSize.height/2));
	this->addChild(m_label, 1);
	this->addChild(m_bgColor, 0);
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



void CardSprite::setNumber(int number)
{
	m_number = number <= 0 ? INVALID_VALUE : number;
	string text = GetCardText(m_number).c_str();
	m_bgColor->setColor(GetCardColor3B(m_number));
	m_label->setString(text.c_str());
	m_label->setColor(ccc3(0,0,0));
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