#include "pch.h"
#include "PolyIntersectoinator.h"

PolyIntersectoinator::PolyIntersectoinator()
{
	triangleAssembler = TriangleAssembler(&drawer);
	commandConstructor = CommandConstructor(&triangleAssembler);
}
