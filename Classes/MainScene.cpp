#include "MainScene.h"
#include "CardSprite.h"

#define DIM_NUM 4

MainScene::MainScene()
	: m_bg(NULL), 
	m_glOrgX(0), m_glOrgY(0), m_glDstX(0), m_glDstY(0)
{
	memset(&m_cards, 0x0, sizeof(m_cards));
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

		createCardSprites();
		showRandom();
		showRandom();

		this->setTouchEnabled(true);

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
	scene->addChild(mainLayer);
	return scene;
}

void MainScene::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool MainScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint glPos = pTouch->getLocationInView();
	m_glOrgX = glPos.x;
	m_glOrgY = glPos.y;

	return true;
}

void MainScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{

}

void MainScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint glPos = pTouch->getLocationInView();
	m_glDstX = glPos.x;
	m_glDstY = glPos.y;
    
	float deltaX = m_glDstX - m_glOrgX;
	float deltaY = m_glDstY - m_glOrgY;

	if (abs(deltaY) > abs(deltaX))
	{
		if (deltaY<0)
		{
			moveUp();
		}
		else
		{
			moveDown();
		}
	}
	else
	{
		if (deltaX > 0)
		{
			moveRight();
		}
		else
		{
			moveLeft();
		}
	}
}

void MainScene::moveLeft()
{
	CCLOG("left");
}

void MainScene::moveRight()
{
	CCLOG("right");
}

void MainScene::moveUp()
{
	CCLOG("up");
}

void MainScene::moveDown()
{
	CCLOG("down");
}

void MainScene::createCardSprites()
{
	int unitSize = (m_winSize.height - 28)/4;
	for (int i=0; i<DIM_NUM; i++)
	{
		for (int j=0; j<DIM_NUM; j++)
		{
			CardSprite* card = CardSprite::create(2, ccp(unitSize, unitSize));
            m_cards[i][j] = card;
			card->setPosition(ccp(unitSize*i+140, unitSize*j+20));
			addChild(card);
			card->setVisible(false);
		}
	}
}

void MainScene::showCard(int number, int xOrder, int yOrder)
{
	if (number < 0 || xOrder < 0 || xOrder >= DIM_NUM || yOrder < 0 || yOrder >= DIM_NUM)
	{
		return;
	}
	CardSprite* card = m_cards[xOrder][yOrder];
	card->setNumber(number);
	card->setVisible(true);
}

void MainScene::hideCard(int xOrder, int yOrder)
{
	if (xOrder < 0 || xOrder >= DIM_NUM || yOrder < 0 || yOrder >= DIM_NUM)
	{
		return;
	}
	m_cards[xOrder][yOrder]->setVisible(true);
}

void MainScene::showRandom()
{
	int xOrder = CCRANDOM_0_1() * 4;
	int yOrder = CCRANDOM_0_1() * 4;
	int number = (CCRANDOM_0_1()*10 < 5) ? 2 : 4;
	while(m_cards[xOrder][yOrder]->isVisible())
	{
		xOrder = CCRANDOM_0_1() * 4;
		yOrder = CCRANDOM_0_1() * 4;
	}
	showCard(number, xOrder, yOrder);
}

