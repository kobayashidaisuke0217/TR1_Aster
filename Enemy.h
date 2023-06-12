#pragma once
#include"Vector2.h"
#include "map.h"
#include "Astar.h"
#include<thread>
#include"EnemyState.h"
class Player;
class EnemyState;
class Enemy
{
public :
   
	Enemy(int EnemyX,int EnemyY);
	void Init();
	void Update();

	void Draw();

	void SetPlayer(Player* player) { player_ = player; }
	void SetMap(Map* map) {this-> map_ = map; }
	void ChangeEnemyState(EnemyState* enemyState);


	int moveCount = 30;
	
	Player* player_=nullptr;
	int enemyX_ ;
	int enemyY_ ;
	std::vector<Node*> path_;
	Map* map_=nullptr;
	int enemyMapNum = 1;
	EnemyState* state_;
    
};


