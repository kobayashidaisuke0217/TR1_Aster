#include "map.h"
#include "Novice.h"

void Map::Draw()
{
	if (mapNum == 0) {
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[i].size(); j++) {
				if (map[i][j] == 99) {
					Novice::DrawBox(j * 64, i * 64, 64, 64, 0, BLACK, kFillModeSolid);
				}
				else if (map[i][j] == 101) {
					Novice::DrawBox(j * 64, i * 64, 64, 64, 0, BLACK, kFillModeWireFrame);
					Novice::DrawLine(j * 64, i * 64, j * 64 + 64, i * 64 + 64, BLACK);
				}
			}
		}
	}
	else if (mapNum == 1) {
		for (int i = 0; i < map2.size(); i++) {
			for (int j = 0; j < map2[i].size(); j++) {
				if (map2[i][j] == 99) {
					Novice::DrawBox(j * 64, i * 64, 64, 64, 0, BLACK, kFillModeSolid);
				}
				else if (map2[i][j] == 101) {
					Novice::DrawBox(j * 64, i * 64, 64, 64, 0, BLACK, kFillModeWireFrame);
					Novice::DrawLine(j * 64, i * 64, j * 64 + 64, i * 64 + 64, BLACK);
				}
			}
		}
	}
	else if (mapNum == 2) {
		for (int i = 0; i < map3.size(); i++) {
			for (int j = 0; j < map3[i].size(); j++) {
				if (map3[i][j] == 99) {
					Novice::DrawBox(j * 64, i * 64, 64, 64, 0, BLACK, kFillModeSolid);
				}
				else if (map3[i][j] == 101) {
					Novice::DrawBox(j * 64, i * 64, 64, 64, 0, BLACK, kFillModeWireFrame);
					Novice::DrawLine(j * 64, i * 64, j * 64 + 64, i * 64 + 64, BLACK);
				}
			}
		}
	}
}

Map::Map()
{
  map = {
		{99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99},
		{99,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,1},
		{99,100,100,100,100,100,100,100,99,100,100,99,100,100,100,100,100,100,100,99},
		{99,100,100,100,100,100,100,101,101,101,101,101,100,100,100,100,100,100,100,99},
		{99,100,100,100,100,100,100,101,101,99,101,101,100,100,100,100,100,100,100,99},
		{99,100,100,100,100,100,101,101,101,101,101,101,100,100,100,100,100,100,100,99},
		{99,100,100,100,100,100,101,101,101,99,101,101,100,100,100,100,100,100,100,99},
		{99,100,100,100,100,99,100,99,99,99,99,99,100,100,100,100,100,100,100,99},
		{99,100,100,99,99,100,100,100,100,100,100,100,100,100,100,100,100,100,99,99},
		{99,100,100,100,100,100,100,99,100,100,100,100,100,100,100,100,100,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99},
  };
  
  map2 = {
	   {99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99},
	   {0,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99},
	   {99,100,100,100,100,100,100,100,99,100,100,99,100,100,100,100,100,100,100,99},
	   {99,100,100,100,100,100,100,99,99,99,99,99,100,100,100,100,100,100,100,99},
	   {99,100,100,100,100,100,100,99,99,99,99,99,100,100,100,100,100,100,100,99},
	   {99,100,100,100,100,100,101,101,101,101,99,99,100,100,100,100,100,100,100,99},
	   {99,100,100,100,100,100,99,99,99,99,99,99,100,100,100,100,100,100,100,99},
	   {99,100,100,100,100,99,100,99,99,99,99,99,100,100,100,100,100,100,100,99},
	   {99,100,100,99,99,100,100,100,100,100,100,100,100,100,100,100,100,100,99,99},
	   {99,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,99,99},
	   {99,99,99,99,99,99,99,2,99,99,99,99,99,99,99,99,99,99,99,99},
  };
  map3 = {
	   {99,99,99,99,99,99,99,1,99,99,99,99,99,99,99,99,99,99,99,99},
	   {99,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99},
	   {99,100,100,100,100,100,100,100,99,100,100,99,100,100,100,100,100,100,100,99},
	   {99,100,100,100,100,100,100,99,99,99,99,99,100,100,100,100,100,100,100,99},
	   {99,100,100,100,100,100,100,99,99,99,99,99,100,100,100,100,100,100,100,99},
	   {99,100,100,100,100,100,100,101,100,99,99,99,100,100,100,100,100,100,100,99},
	   {99,100,100,100,100,100,99,99,99,99,99,99,100,100,100,100,100,100,100,99},
	   {99,100,100,100,100,99,100,99,99,99,99,99,100,100,100,100,100,100,100,99},
	   {99,100,100,99,99,100,100,100,100,99,100,100,100,100,100,100,100,100,99,99},
	   {99,100,100,100,100,100,100,99,100,99,99,99,99,99,99,100,100,99,99,99},
	   {99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99},
  };
  
  
}

void Map::Update(char*keys,char* preKeys)
{
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		/*if (mapNum == 0) {
			mapNum = 1;
		}
		else if (mapNum == 1) {
			mapNum = 0;
		}*/
	}
}
