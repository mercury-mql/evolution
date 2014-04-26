#include "Globals.h"
#include <map>
using namespace std;

static map<int, Element*> s_map;

Element::Element(int r, int g, int b, const string& txt, const string& pic)
	: m_r(r), m_g(g), m_b(b), m_text(txt), m_pic(pic)
{

}

static void InitMap()
{
	if (s_map.size() <= 0)
	{
		s_map[0] = new Element(200, 190, 180, "", "bg.png");
		s_map[2] = new Element(97, 217, 61, "2", "1.png");
		s_map[4] = new Element(13, 126, 4, "4", "2.png");
		s_map[8] = new Element(246, 120, 8, "8", "3.png");
		s_map[16] = new Element(8, 53, 246, "16", "4.png");
		s_map[32] = new Element(120, 8, 246, "32", "5.png");
		s_map[64] = new Element(184, 25, 156, "64", "6.png");
		s_map[128] = new Element(250, 7, 7, "128", "7.png");
		s_map[256] = new Element(35, 250, 7, "256", "8.png");
		s_map[512] = new Element(213, 250, 7, "512", "9.png");
		s_map[1024] = new Element(75, 5, 135, "1024", "10.png");
		s_map[2048] = new Element(7, 131, 132, "4096", "11.png");
		s_map[4096] = new Element(244, 176, 13, "8192", "12.png");
	}
}

ccColor4B GetCardColor4B(int number)
{
	InitMap();
	map<int, Element*>::iterator it = s_map.find(number);
	if(it != s_map.end())
	{
		Element* element = it->second;
		return ccc4(element->m_r, element->m_g, element->m_b, 255);
	}
	return ccc4(0, 255, 0, 255);
}

ccColor3B GetCardColor3B(int number)
{
	InitMap();
	map<int, Element*>::iterator it = s_map.find(number);
	if(it != s_map.end())
	{
		Element* element = it->second;
		return ccc3(element->m_r, element->m_g, element->m_b);
	}
	return ccc3(0, 255, 0);
}

string GetCardText(int number)
{
	InitMap();
	map<int, Element*>::iterator it = s_map.find(number);
	if(it != s_map.end())
	{
		Element* element = it->second;
		return element->m_text;
	}
	return "";
}

string GetCardPic(int number)
{
	InitMap();
	map<int, Element*>::iterator it = s_map.find(number);
	if(it != s_map.end())
	{
		Element* element = it->second;
		return element->m_pic;
	}
	return "";
}

