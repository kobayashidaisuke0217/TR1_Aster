#pragma once
#include <vector>
class Map
{
public:
	//void Initialize();
	
	void Draw();
	Map();
	void Update(char* keys, char* preKeys);

	std::vector<std::vector<int>>  map;
	std::vector<std::vector<int>>  map2;
	std::vector<std::vector<int>>  map3;
	bool changeFlag;
	 const int mapSize = 64;
	 int mapNum = 1;
	 int mapTP;
};

