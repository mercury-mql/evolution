#include "MainScene.h"

MainScene::MainScene()
	: m_bg(NULL)
{

}

MainScene::~MainScene()
{

}

bool MainScene::init()
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

CCScene* MainScene::mainScene()
{
	CCScene* scene = CCScene::create();
	MainScene* mainLayer = MainScene::create();
	if (!scene || !mainLayer)
	{
		CC_SAFE_RELEASE(scene);
		CC_SAFE_RELEASE(mainLayer);
		return NULL;
	}
	return scene;
}