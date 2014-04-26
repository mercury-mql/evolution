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
	memset(&m_numbers, 0x0, sizeof(m_numbers));
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


void MainScene::moveLeft()
{
	CCLOG("left");
	for (int row = 0; row < DIM_NUM; row++)
	{
		int prefixIndex = -1;
		int prefixValue = 0;
		int currentValue = 0;
		for (int col=0; col<DIM_NUM; col++)
		{
			currentValue = m_numbers[row][col];
			if (currentValue > 0)
			{
				if (prefixIndex < 0)
				{
					m_numbers[row][col] = 0;
					m_numbers[row][0] = currentValue;					
					prefixIndex = 0;
					prefixValue = currentValue;
					continue;
				}
				if (currentValue == prefixValue)
				{
					m_numbers[row][prefixIndex] <<= 1;
					m_numbers[row][col] = 0;
					prefixValue <<= 1;
				}
				else
				{
					m_numbers[row][prefixIndex+1] = currentValue;
					m_numbers[row][col] = 0;
					prefixIndex += 1;
					prefixValue = currentValue;
				}
			}
		}
	}
	updateCards();
}

void MainScene::moveRight()
{
	CCLOG("right");
	for (int row = 0; row < DIM_NUM; row++)
	{
		int prefixIndex = -1;
		int prefixValue = 0;
		int currentValue = 0;
		for (int col = DIM_NUM-1; col >= 0; col--)
		{
			currentValue = m_numbers[row][col];
			if (currentValue > 0)
			{
				if (prefixIndex < 0)
				{
					m_numbers[row][col] = 0;
					m_numbers[row][DIM_NUM-1] = currentValue;					
					prefixIndex = DIM_NUM-1;
					prefixValue = m_numbers[row][prefixIndex];
					continue;
				}
				if (currentValue == prefixValue)
				{
					m_numbers[row][prefixIndex] <<= 1;
					m_numbers[row][col] = 0;
					prefixValue <<= 1;
				}
				else
				{
					m_numbers[row][prefixIndex-1] = currentValue;
					m_numbers[row][col] = 0;
					prefixIndex -= 1;
					prefixValue = currentValue;
				}
			}
		}
	}
	updateCards();
}

void MainScene::moveUp()
{
	CCLOG("up");
	for (int col = 0; col < DIM_NUM; col++)
	{
		int prefixIndex = -1;
		int prefixValue = 0;
		int currentValue = 0;
		for (int row=0; row<DIM_NUM; row++)
		{
			currentValue = m_numbers[row][col];
			if (currentValue > 0)
			{
				if (prefixIndex < 0)
				{
					m_numbers[row][col] = 0;
					m_numbers[0][col] = currentValue;					
					prefixIndex = 0;
					prefixValue = currentValue;
					continue;
				}
				if (currentValue == prefixValue)
				{
					m_numbers[prefixIndex][col] <<= 1;
					m_numbers[row][col] = 0;
					prefixValue <<= 1;
				}
				else
				{
					m_numbers[prefixIndex+1][col] = currentValue;
					m_numbers[row][col] = 0;
					prefixIndex += 1;
					prefixValue = currentValue;
				}
			}
		}
	}
	updateCards();

}

void MainScene::moveDown()
{
	CCLOG("down");
	for (int col = 0; col < DIM_NUM; col++)
	{
		int prefixIndex = -1;
		int prefixValue = 0;
		int currentValue = 0;
		for (int row = DIM_NUM-1; row >= 0; row--)
		{
			currentValue = m_numbers[row][col];
			if (currentValue > 0)
			{
				if (prefixIndex < 0)
				{
					m_numbers[row][col] = 0;
					m_numbers[DIM_NUM-1][col] = currentValue;					
					prefixIndex = DIM_NUM-1;
					prefixValue = m_numbers[prefixIndex][col];
					continue;
				}
				if (currentValue == prefixValue)
				{
					m_numbers[prefixIndex][col] <<= 1;
					m_numbers[row][col] = 0;
					prefixValue <<= 1;
				}
				else
				{
					m_numbers[prefixIndex-1][col] = currentValue;
					m_numbers[row][col] = 0;
					prefixIndex -= 1;
					prefixValue = currentValue;
				}
			}
		}
	}
	updateCards();
}

void MainScene::updateCards()
{
	for (int i=0; i<DIM_NUM; i++)
	{
		for (int j=0; j<DIM_NUM; j++)
		{
			int number = m_numbers[i][j];
			m_cards[i][j]->setNumber(number);
			m_cards[i][j]->setContentVisible(number > 0);
		}
	}
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
			m_numbers[i][j] = 2;
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

