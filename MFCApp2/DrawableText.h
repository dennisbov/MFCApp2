#pragma once
#include "Drawable.h"
#include <string>
#include "PointMath.h"


class DrawableText :
    public Drawable
{
public:
    std::string Text;
    PointMath point;
    DrawableText(Color color, PointMath point, std::string text);
    DrawableText();
    void Draw(Graphics& graphics) override;
private:
    FontFamily fontFamily;
};

