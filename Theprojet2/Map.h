#pragma once
#include "Vector2.h"
#include <vector>

enum class Tile
{
    Ground,
    Water,
    Mountain,
    Exit
};

class Map
{
public:
    static const int WIDTH = 20;
    static const int HEIGHT = 10;
    static const int LEVEL_COUNT = 2;

    Map();

    void Load(int levelIndex);

    bool IsInside(Vector2 pos) const;
    Tile GetTile(Vector2 pos) const;
    bool CanEnter(Vector2 pos, bool CanSwim = false) const;
    bool IsExit(Vector2 pos) const;
    char GetTileChar(Vector2 pos) const;

    Vector2 GetPlayerStart() const;
    const std::vector<Vector2> &GetEnemySpawns() const;

private:
    Tile Tiles[HEIGHT][WIDTH]{};
    Vector2 playerStart;
    Vector2 exitPos;
    std::vector<Vector2> EnemySpawns;
};
