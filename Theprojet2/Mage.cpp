#include "Mage.h"
#include <iostream>
#include "Vector2.h"
#include <conio.h> // Indispensable pour _kbhit() et _getch()
#include "Player.h"


void Mage::onUpdate() {

	if (_kbhit()) {
		char key = _getch(); // Utilisation de _getch() pour capturer la touche pressée

		Direction direction = InputToDirection(key);
		ApplyDirection(direction, position);
		// Implement Mage-specific update logic here
	}
}