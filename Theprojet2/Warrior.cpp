#include "Warrior.h"
#include <iostream>
#include <conio.h> // Indispensable pour _kbhit() et _getch()
#include "Vector2.h"
#include "Player.h"


void Warrior::onUpdate() {

	if (_kbhit()) {
		char key = _getch(); // Utilisation de _getch() pour capturer la touche pressée

		Direction direction = InputToDirection(key);
		ApplyDirection(direction, position);
		// Implement Warrior-specific update logic here
	}
}
