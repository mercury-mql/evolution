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
};

ccColor4B GetColor(int number);
string GetText(int number);
string GetPic(int number);


#endif