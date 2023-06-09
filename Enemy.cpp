#include "Enemy.h"
#include"Player.h"
#include<Novice.h>
Enemy::Enemy(int EnemyX, int EnemyY)
{
	this->enemyX_ = EnemyX;
	this->enemyY_ = EnemyY;
}

void Enemy::Update()
{
	if (player_->GetPlayerX() != enemyX_ || player_->GetPlayerY() != enemyY_) {

		path_ = findPath(map_->map, enemyX_, enemyY_, player_->GetPlayerX(),player_->GetPlayerY() );
		moveCount--;
		// プレイヤーの移動
		if (moveCount <= 0 && !path_.empty()) {

			enemyX_ = path_[1]->x;
			enemyY_ = path_[1]->y;
			// パスを更新
			path_.erase(path_.begin(), path_.begin() + 1);
			if (map_->map[enemyY_][enemyX_] == 1) {
				moveCount = 30;
			}
			else if (map_->map[enemyY_][enemyX_] == 2) {
				moveCount = 90;
			}
		}

	}
}

void Enemy::Draw()
{
	for (const auto& node : path_) {
		Novice::DrawBox(node->x * 64, node->y * 64, 64, 64, 0, RED, kFillModeWireFrame);
	}
	Novice::DrawBox(enemyX_ * 64, enemyY_ * 64, 64, 64, 0, RED, kFillModeSolid);
}
