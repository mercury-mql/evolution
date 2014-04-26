#ifndef _GLOBALS_H
#define _GLOBALS_H
/*
text    color    picture
*/
#include "cocos2d.h"
#include <string>
USING_NS_CC;
using namespace std;

struct Element
{
	int m_r;
	int m_g;
	int m_b;
	string m_text;
	string m_pic;

	Element(int r, int g, int b, const string& txt, const string& pic);
};

ccColor4B GetCardColor4B(int number);
ccColor3B GetCardColor3B(int number);
string GetCardText(int number);
string GetCardPic(int number);


#endif