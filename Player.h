#pragma once
#include"Vector2.h"
#include "map.h"
class Map;
class Player
{
public:
	Player(Vector2 pos);
	
	void Init();
	void Update(char* keys, Map* map);
	void Draw();
	void Move(const Vector2 velocity);
private:

	Vector2 pos_;
	Vector2 initPos_;
	Vector2 speed_;
	float size_;
};

