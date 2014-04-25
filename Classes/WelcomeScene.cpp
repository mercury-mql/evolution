#include "WelcomeScene.h"

WelcomeScene::WelcomeScene()
	: m_bg(NULL)
{

}

WelcomeScene::~WelcomeScene()
{

}

bool WelcomeScene::init()
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

CCScene* WelcomeScene::welcomeScene()
{
	CCScene* scene = CCScene::create();
	WelcomeScene* welcomeLayer = WelcomeScene::create();
	if (!scene || !welcomeLayer)
	{
		CC_SAFE_RELEASE(scene);
		CC_SAFE_RELEASE(welcomeLayer);
		return NULL;
	}
	return scene;
}