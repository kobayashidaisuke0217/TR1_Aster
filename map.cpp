#include "map.h"
#include "Novice.h"
//void Map::Initialize()
//{
//	
//}
//
void Map::Draw()
{
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 0) {
				Novice::DrawBox(j * 64, i * 64,64,64,0, BLACK,kFillModeSolid);
			}
			if (map[i][j] == 2) {
				Novice::DrawBox(j * 64, i * 64, 64, 64, 0, BLACK, kFillModeWireFrame);
				Novice::DrawLine(j *64, i * 64, j * 64 + 64, i * 64 + 64, BLACK);
			}
		}
	}
}

Map::Map()
{
  map = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,2,2,0,2,2,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,2,2,2,0,2,2,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0},
		{0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  };
}
