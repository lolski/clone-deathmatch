#include <irrlicht.h>
#include "debug.h"

int main() {
	irr::core::vector3df a(0, 0, 1);
	irr::core::vector3df b(0, 0, -1);
	pVec3d(a.getHorizontalAngle());
	pVec3d(b.getHorizontalAngle());
	return 0;
}
