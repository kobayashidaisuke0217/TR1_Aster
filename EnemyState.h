#pragma once
#include "Enemy.h"
#include "Player.h"	
class Enemy;
class Player;
class EnemyState
{
public :
	virtual ~EnemyState();
	virtual void Update() = 0;
	virtual void Init(Enemy* enemy,Player* player, Map* map) = 0;
protected:
	Enemy * enemy_;
	Player* player_;
	Map* map_;

};
class EnemyStateChase : public EnemyState {
	~EnemyStateChase();
	void Update();
	void Init(Enemy* enemy,Player*player,Map*map);
private:
	int SwanpCount = 0;
	int floorCount = 0;
	static std::thread t1;
};
class EnemyStateStandby :public EnemyState {
	~EnemyStateStandby();
	void Update();
	void Init(Enemy* enemy, Player* player, Map* map);
};


