#include "map.h"
#include "Novice.h"
void Map::Initialize()
{
	
}

void Map::Draw()
{
	for (int i = 0; i <= 11; i++) {
		for (int j = 0; j <= 20; j++) {
			if (map[i][j] == 0) {
				Novice::DrawBox(j * mapSize, i * mapSize,mapSize,mapSize,0, WHITE,kFillModeSolid);
			}
		}
	}
}


