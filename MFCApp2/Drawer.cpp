#include "pch.h"
#include "Drawer.h"


Drawer::Drawer() {
	drawables = std::vector<Drawable*>(10000, nullptr);
	lastElementIndex = 0;
	}  
void Drawer::AddDrawable(Drawable* drawable)
	{
		drawables[lastElementIndex] = drawable;
		lastElementIndex++;
	}
void Drawer::UpdateDrawer(Graphics& graphics)
	{
	for (int i = 0; i < lastElementIndex; i++)
		{
			drawables[i]->Draw(graphics);
		}
	}
void Drawer::RemoveDrawable(Drawable* drawable) {
	int shift = 0;
	bool flag = false;
	for (int i = 0; i < lastElementIndex; i++)
	{
		if (drawables[i] == drawable) {
			shift++;
			flag = true;
		}
		drawables[i] = drawables[i + shift];
	}
	if (flag) {
		lastElementIndex--;
	}
}