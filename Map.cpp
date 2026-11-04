#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

struct hero {
	int hp = 1;
	char body = 'H';
};

struct ennemi {
	int x;
	int y;
	char body = 'X';
	bool vivant = true;
};

struct Terrain {
	int cases[10][20];
};

enum Case { SOL = 0, EAU = 1, MONTAGNE = 2, SORTIE = 3 };

struct Niveau {
	Terrain terrain;
	int heroX = 0;
	int heroY = 0;
	int sortieX = 0;
	int sortieY = 0;
	std::vector<ennemi> ennemis;
};

const int NB_NIVEAUX = 2;

const char* const NIVEAUX[NB_NIVEAUX][10] = {
	{   // niveau 1
		"...X................",
		".....~~~~...........",
		".....~~~~...AAA.....",
		"..........X.........",
		"H...................",
		"..............X.....",
		"..AAA...........~~..",
		"...............X....",
		".....X..............",
		".................E.."
	},
	{   // niveau 2
		"H...................",
		".AAAAAAAA..~~~~~....",
		"....................",
		"..~~~..........X....",
		"..~~~......AAA......",
		"........X...........",
		"..........X.........",
		".AAA........X.......",
		"..........~~........",
		"..X..............E.."
	}
};


Niveau chargerNiveau(int index) {
	Niveau niveau;

	for (int ligne = 0; ligne < 10; ++ligne) {
		for (int colonne = 0; colonne < 20; ++colonne) {
			char c = NIVEAUX[index][ligne][colonne];
			niveau.terrain.cases[ligne][colonne] = SOL;

			switch (c) {
			case '~': niveau.terrain.cases[ligne][colonne] = EAU; break;
			case 'A': niveau.terrain.cases[ligne][colonne] = MONTAGNE; break;
			case 'E':
				niveau.terrain.cases[ligne][colonne] = SORTIE;
				niveau.sortieX = colonne;
				niveau.sortieY = ligne;
				break;
			case 'H':
				niveau.heroX = colonne;
				niveau.heroY = ligne;
				break;
			case 'X': {
				ennemi e;
				e.x = colonne;
				e.y = ligne;
				niveau.ennemis.push_back(e);
				break;
			}
			default: break;
			}
		}
	}
	return niveau;
}

void GererDeplacement(char touche, int& heroX, int& heroY, const Terrain& grille) {

	int futurX = heroX;
	int futurY = heroY;


	switch (touche) {
	case 'z':
		if (futurY > 0) futurY--;
		break;
	case 's':
		if (futurY < 9) futurY++;
		break;
	case 'q':
		if (futurX > 0) futurX--;
		break;
	case 'd':
		if (futurX < 19) futurX++;
		break;
	default:
		return;
	}

	int typeTerrain = grille.cases[futurY][futurX];

	if (typeTerrain == EAU || typeTerrain == MONTAGNE) {

		return;
	}

	heroX = futurX;
	heroY = futurY;
}

void verifierCollisionsEnnemis(int heroX, int heroY, hero& joueur, std::vector<ennemi>& listeEnnemis) {
	if (joueur.hp <= 0) return;   // déjà mort : les PV ne passent jamais sous 0

	for (auto& ennemi : listeEnnemis) {
		if (ennemi.vivant && ennemi.x == heroX && ennemi.y == heroY) {
			joueur.hp--;
			ennemi.vivant = false;
			break;
		}
	}
}

void DeplacerEnnemisAleatoirement(std::vector<ennemi>& listeEnnemis, const Terrain& grille) {
	for (auto& ennemi : listeEnnemis) {
		if (!ennemi.vivant) continue;


		int direction = rand() % 5;

		int futurX = ennemi.x;
		int futurY = ennemi.y;

		switch (direction) {
		case 1: futurY--; break;
		case 2: futurY++; break;
		case 3: futurX--; break;
		case 4: futurX++; break;
		default: break;
		}


		if (futurX >= 0 && futurX < 20 && futurY >= 0 && futurY < 10) {

			if (grille.cases[futurY][futurX] == SOL) {
				ennemi.x = futurX;
				ennemi.y = futurY;
			}
		}
	}
}


void afficherGrille(const Terrain& grille, hero joueur, int heroX, int heroY, const std::vector<ennemi>& listeEnnemis) {
	for (int ligne = 0; ligne < 10; ++ligne) {
		for (int colonne = 0; colonne < 20; ++colonne) {


			if (ligne == heroY && colonne == heroX) {
				std::cout << joueur.body;
			}

			else {
				bool ennemiTrouve = false;
				for (const auto& ennemi : listeEnnemis) {
					if (ennemi.vivant && ennemi.y == ligne && ennemi.x == colonne) {
						std::cout << ennemi.body;
						ennemiTrouve = true;
						break;
					}
				}
				if (!ennemiTrouve) {
					switch (grille.cases[ligne][colonne]) {
					case SOL: std::cout << '.'; break;
					case EAU: std::cout << '~'; break;
					case MONTAGNE: std::cout << 'A'; break;
					case SORTIE: std::cout << 'E'; break;
					default: std::cout << '?'; break;
					}
				}
			}

		}
		std::cout << '\n';
	}
}

int main() {
	srand(time(0));

	int numeroNiveau = 0;
	Niveau niveau = chargerNiveau(numeroNiveau);
	hero joueur;
	char touche = ' ';
	bool victoire = false;

	while (touche != 'a' && touche != 'A' && joueur.hp > 0 && !victoire) {
		system("cls");
		std::cout << "Niveau " << numeroNiveau + 1 << " | HP : " << joueur.hp
			<< " | 'a' pour quitter\n\n";
		afficherGrille(niveau.terrain, joueur, niveau.heroX, niveau.heroY, niveau.ennemis);

		std::cin >> touche;

		GererDeplacement(touche, niveau.heroX, niveau.heroY, niveau.terrain);
		verifierCollisionsEnnemis(niveau.heroX, niveau.heroY, joueur, niveau.ennemis);
		if (joueur.hp <= 0) break;

		// sortie atteinte : niveau suivant
		if (niveau.terrain.cases[niveau.heroY][niveau.heroX] == SORTIE) {
			numeroNiveau++;
			if (numeroNiveau >= NB_NIVEAUX)
				victoire = true;
			else
				niveau = chargerNiveau(numeroNiveau);
			continue;
		}

		if (touche == 'z' || touche == 'q' || touche == 's' || touche == 'd') {
			DeplacerEnnemisAleatoirement(niveau.ennemis, niveau.terrain);
			verifierCollisionsEnnemis(niveau.heroX, niveau.heroY, joueur, niveau.ennemis);
			if (joueur.hp <= 0) break;
		}
	}   // <- le while se ferme ici

	system("cls");
	if (joueur.hp <= 0)  std::cout << "GAME OVER\n";
	else if (victoire)   std::cout << "Bravo, tu as fini tous les niveaux !\n";
	else                 std::cout << "merci d'avoir jouer !\n";

	system("pause");
	return 0;
}