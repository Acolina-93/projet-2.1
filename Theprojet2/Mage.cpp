#include "Mage.h"

void Mage::onCollision(Entity *)
{
    applyDamage(1);
}