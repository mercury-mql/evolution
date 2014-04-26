#include "MainScene.h"
#include "CardSprite.h"
#include <stdlib.h>
#include <time.h>

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
		m_bg = CCLayerColor::create(ccc4(180, 170, 160, 255), m_winSize.width, m_winSize.height);
		this->addChild(m_bg);

		createCardSprites();
		//showRandom();
		//showRandom();

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

void MainScene::moveSpanLeft(int row, int emptyCol)
{
	int col = emptyCol;
	while(col+1 < DIM_NUM)
	{

		m_cards[row][col+1]->setContentVisible(false);
		m_cards[row][col]->setNumber(m_cards[row][col+1]->getNumber());
		m_cards[row][col]->setContentVisible(true);
		col++;
	}
}

void MainScene::moveSpanRight(int row, int startCol)
{

}

void MainScene::moveSpanUp(int startRow, int col)
{

}

void MainScene::moveSpanDown(int startRow, int col)
{

}

void MainScene::moveLeft()
{
	CCLOG("left");
	for (int row = 0; row < DIM_NUM; row++)
	{
		int emptyCol = -1;
		int validCol = -1;
		for (int col=DIM_NUM-1; col >0; col--)
		{
			if (m_cards[row][col]->isContentVisible())
			{
				if (!m_cards[row][col-1]->isContentVisible())
				{
					moveSpanLeft(row, col-1);
				}
			}

		}
	}
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
			//card->setNumber(i*4+j);
            m_cards[i][j] = card;
			
			card->setPosition(ccp(unitSize*j+105, (m_winSize.height -56)-(unitSize*i+20) ));
			addChild(card, 2);
			card->setContentVisible(true);
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
	card->setContentVisible(true);
}

void MainScene::hideCard(int xOrder, int yOrder)
{
	if (xOrder < 0 || xOrder >= DIM_NUM || yOrder < 0 || yOrder >= DIM_NUM)
	{
		return;
	}
	m_cards[xOrder][yOrder]->setContentVisible(false);
}

void MainScene::showRandom()
{
	srand(time(0));
	int xOrder = rand() % 4;
	srand(time(0));
	int yOrder = rand() % 4;
	srand(time(0));
	int number = rand() % 4;
	while(m_cards[xOrder][yOrder]->isContentVisible())
	{
		srand(time(0));
		xOrder = rand() % 4;
		srand(time(0));
		yOrder = rand() % 4;
	}
	showCard(number, xOrder, yOrder);
}

