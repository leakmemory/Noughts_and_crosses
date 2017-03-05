#pragma once
#include "StartMenu.h"
class MenuEnd :	public StartMenu
{
public:
	MenuEnd();
	virtual void Draw(RenderWindow&, Vector2i&, Event&, bool&, bool&, std::list<Figure*>&);
	void setResult(String);
	~MenuEnd();
private:
	String m_Result;
};

