#include "GoodbyeScene.h"

GoodbyeScene::GoodbyeScene()
	: m_bg(NULL)
{

}

GoodbyeScene::~GoodbyeScene()
{

}

bool GoodbyeScene::init()
{
	bool ret = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		m_winSize = CCDirector::sharedDirector()->getWinSize();
		m_bg = CCSprite::create();
		m_bg->setPosition(ccp(m_winSize.width/2, m_winSize.height/2));
		this->addChild(m_bg);
		ret = true;
	} while (0);
	return ret;
}

CCScene* GoodbyeScene::goodByeScene()
{
	CCScene* scene = CCScene::create();
	GoodbyeScene* goodByeLayer = GoodbyeScene::create();
	if (!scene || !goodByeLayer)
	{
		CC_SAFE_RELEASE(scene);
		CC_SAFE_RELEASE(goodByeLayer);
		return NULL;
	}
	return scene;
}