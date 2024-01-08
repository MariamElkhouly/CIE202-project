#include "Collectable.h"

collectable::collectable(point ul, int w, int h, game* pG) : collidable(ul, w, h, pG)
{
}
collectable::~collectable()
{
};

