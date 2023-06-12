#include "EnemyState.h"

EnemyStateChase::~EnemyStateChase()
{
}

void EnemyStateChase::Update()
{
	if (enemy_->enemyMapNum ==enemy_-> map_->mapNum) {
		if ( player_->GetPlayerX()!=enemy_->enemyX_ || player_->GetPlayerY() !=enemy_->enemyY_) {
			if (map_->mapNum == 0) {
				enemy_->path_ = findPath(map_->map, enemy_-> enemyX_, enemy_-> enemyY_, player_->GetPlayerX(), player_->GetPlayerY());
			}
			else if (map_->mapNum == 1) {
				enemy_->path_ = findPath(map_->map2, enemy_->enemyX_, enemy_->enemyY_, player_->GetPlayerX(), player_->GetPlayerY());

			}
			enemy_->moveCount--;
			// プレイヤーの移動
			if (enemy_->moveCount <= 0 && !enemy_->path_.empty()) {

				enemy_->enemyX_ = enemy_->path_[1]->x;
				enemy_->enemyY_ = enemy_->path_[1]->y;
				// パスを更新
				enemy_->path_.erase(enemy_->path_.begin(), enemy_->path_.begin() + 1);
				if (map_->map[enemy_->enemyY_][enemy_->enemyX_] == 1) {
					enemy_->moveCount = 30;
				}
				else if (map_->map[enemy_->enemyY_][enemy_->enemyX_] == 2) {
					enemy_->moveCount = 80;
				}
			}

		}
	}
}

void EnemyStateChase::Init(Enemy* enemy,Player*player,Map*map)
{
	this->enemy_ = enemy;
	player_ = player;
		map_ = map;


}

//EnemyStateStandby::~EnemyStateStandby()
//{
//}
//
//void EnemyStateStandby::Update()
//{
//}
//
//void EnemyStateStandby::Init(Enemy* enemy_, Player* player, Map* map)
//{
//}

EnemyState::~EnemyState()
{
}
