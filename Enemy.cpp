#include "Enemy.h"
#include"Player.h"
#include<Novice.h>
Enemy::Enemy(int EnemyX, int EnemyY)
{
	this->enemyX_ = EnemyX;
	this->enemyY_ = EnemyY;
	player_ = nullptr;
	map_ = nullptr;
	state_ = nullptr;
}
void Enemy::Init() {
	state_ = new EnemyStateChase();
	state_->Init(this, player_, map_);
}
void Enemy::Update()
{
	state_->Update();
}

void Enemy::Draw()
{
	Novice::ScreenPrintf(200, 100, "%d", warpCount);
	if (enemyMapNum == map_->mapNum) {
		for (const auto& node : path_) {
			Novice::DrawBox(node->x * 64, node->y * 64, 64, 64, 0, RED, kFillModeWireFrame);
			
		}
		
		Novice::DrawBox(enemyX_ * 64, enemyY_ * 64, 64, 64, 0, RED, kFillModeSolid);
	}
}

void Enemy::ChangeEnemyState(EnemyState* enemyState)
{
	delete state_;
	state_ = enemyState;
	state_->Init(this,player_,map_);
}
