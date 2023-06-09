#pragma once
#include"Vector2.h"
#include "map.h"
#include "Astar.h"
class Player;
class Enemy
{
public :
   
	Enemy(int EnemyX,int EnemyY);
	
	void Update();

	void Draw();

	void SetPlayer(Player* player) { player_ = player; }
	void SetMap(Map* map) {this-> map_ = map; }
private:
	
	int moveCount = 30;
	
	Player* player_;
	int enemyX_ ;
	int enemyY_ ;
	std::vector<Node*> path_;
	Map* map_;
private:
    
};


