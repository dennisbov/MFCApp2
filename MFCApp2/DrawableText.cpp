#include "pch.h"
#include "DrawableText.h"

DrawableText::DrawableText(Color color, PointMath point, std::string text) : Drawable(color, 0)
{
	this->Text = text;
	this->point = point;
}

DrawableText::DrawableText() : Drawable::Drawable()
{
	Text = std::string();
}

void DrawableText::Draw(Graphics& graphics)
{
	SolidBrush brush(color);
	FontFamily fontFamily(L"Times New Roman");
	
	Gdiplus::Font defaultFont(&fontFamily, 24, FontStyleRegular, UnitPixel);
	PointF position(point.x, point.y);

	std::wstring widestr = std::wstring(Text.begin(), Text.end());

	graphics.DrawString(widestr.c_str(), -1, &defaultFont, position, &brush);
}
