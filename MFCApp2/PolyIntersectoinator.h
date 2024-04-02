#pragma once
#include "Drawer.h"
#include "CommandConstructor.h"
#include "TriangleAssembler.h"

class PolyIntersectoinator
{
public:
	PolyIntersectoinator();
	Drawer drawer;
	CommandConstructor commandConstructor;
	TriangleAssembler triangleAssembler;
};

