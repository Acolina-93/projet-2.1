#include "Map.h"
#include "Player.h"
#include "Entity.h"
namespace
{
    const char* const LEVELS[Map::LEVEL_COUNT][Map::HEIGHT] = {
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
}

Map::Map() : PlayerStart(0, 0), ExitPos(0, 0) {}

void Map::Load(int levelIndex)
{
    EnemySpawns.clear();

    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            Tiles[y][x] = Tile::Ground;

            switch (LEVELS[levelIndex][y][x])
            {
            case '~': Tiles[y][x] = Tile::Water; break;
            case 'A': Tiles[y][x] = Tile::Mountain; break;
            case 'E':
                Tiles[y][x] = Tile::Exit;
                ExitPos = Vector2(x, y);
                break;
            case 'H': PlayerStart = Vector2(x, y); break;
            case 'X': EnemySpawns.push_back(Vector2(x, y)); break;
            default: break;
            }
        }
    }
}

bool Map::IsInside(Vector2 pos) const
{
    return pos.x >= 0 && pos.x < WIDTH && pos.y >= 0 && pos.y < HEIGHT;
}

Tile Map::GetTile(Vector2 pos) const
{
    return Tiles[pos.y][pos.x]; 
}

bool Map::CanEnter(Vector2 pos, bool canSwim) const
{
    if (!IsInside(pos)) return false;

    Tile t = GetTile(pos);
    if (t == Tile::Mountain) return false;
    if (t == Tile::Water) return canSwim;
    return true;
}

bool Map::IsExit(Vector2 pos) const
{
    return IsInside(pos) && GetTile(pos) == Tile::Exit;
}

bool Map::GetTileChar(Vector2 pos) const
{
    switch (GetTile(pos))
    {
    case Tile::Ground:   return '.';
    case Tile::Water:    return '~';
    case Tile::Mountain: return 'A';
    case Tile::Exit:     return 'E';
    }
    return '?';
}

Vector2 Map::GetPlayerStart() const
{
    return PlayerStart;
}

const std::vector<Vector2>& Map::GetEnemySpawns() const
{
    return EnemySpawns;
}