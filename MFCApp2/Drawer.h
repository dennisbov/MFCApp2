#pragma once
#include <vector>
#include "Drawable.h"

class Drawer
{
private:
	std::vector<Drawable*> drawables;
	int lastElementIndex = 0;
public:
	Drawer();
	void AddDrawable(Drawable* drawable);
	void RemoveDrawable(Drawable* drawable);
	void UpdateDrawer(Graphics& graphics);
};

