#pragma once
#include"Vector2.h"
#include "map.h"

class Player
{
public:
	Player(Vector2 pos);
	
	void Init();
	void Update(char* keys,char* preKeys);
	void Draw();
	void Move(const Vector2 velocity);
	Vector2 GetPos() { return pos_; }
	float GetSize() { return size_; }
	int GetPlayerX() { return playerX; }
	int GetPlayerY() { return playerY; }
	void SetMap(Map* map) {  map_ = map; }
	int preMap;
	bool mapChangeFlag;
private:
	int playerX=0;
	int playerY=0;
	Vector2 pos_;
	Vector2 initPos_;
	Vector2 speed_;
	float size_;
	Map* map_;
};

