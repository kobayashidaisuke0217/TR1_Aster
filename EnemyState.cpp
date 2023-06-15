#include "EnemyState.h"
#include"Novice.h"
EnemyStateChase::~EnemyStateChase()
{
}

void EnemyStateChase::Update()
{
	if (enemy_->enemyMapNum == map_->mapNum) {

		if (player_->GetPlayerX() != enemy_->enemyX_ || player_->GetPlayerY() != enemy_->enemyY_) {
			if (map_->mapNum == 0) {
				enemy_->path_ = findPath(map_->map, enemy_->enemyX_, enemy_->enemyY_, player_->GetPlayerX(), player_->GetPlayerY());
			}
			else if (map_->mapNum == 1) {
				enemy_->path_ = findPath(map_->map2, enemy_->enemyX_, enemy_->enemyY_, player_->GetPlayerX(), player_->GetPlayerY());

			}
			else if (map_->mapNum == 2) {
				enemy_->path_ = findPath(map_->map3, enemy_->enemyX_, enemy_->enemyY_, player_->GetPlayerX(), player_->GetPlayerY());
			}

			enemy_->moveCount--;
			// エネミーの移動
			if (enemy_->moveCount <= 0 && !enemy_->path_.empty()) {

				enemy_->enemyX_ = enemy_->path_[1]->x;
				enemy_->enemyY_ = enemy_->path_[1]->y;
				// パスを更新
				enemy_->path_.erase(enemy_->path_.begin(), enemy_->path_.begin() + 1);
				if (map_->mapNum == 0) {
					if (map_->map[enemy_->enemyY_][enemy_->enemyX_] == 100) {
						enemy_->moveCount = 20;
					}
					else if (map_->map[enemy_->enemyY_][enemy_->enemyX_] == 101) {
						enemy_->moveCount = 60;
					}
				}
				else if (map_->mapNum == 1) {
					if (map_->map2[enemy_->enemyY_][enemy_->enemyX_] == 100) {
						enemy_->moveCount = 20;
					}
					else if (map_->map2[enemy_->enemyY_][enemy_->enemyX_] == 101) {
						enemy_->moveCount = 60;
					}
				}
				else if (map_->mapNum == 2) {
					if (map_->map3[enemy_->enemyY_][enemy_->enemyX_] == 100) {
						enemy_->moveCount = 20;
					}
					else if (map_->map3[enemy_->enemyY_][enemy_->enemyX_] == 101) {
						enemy_->moveCount = 60;
					}
				}
			}

		}

	}

	if (enemy_->warpFlag == true) {
		enemy_->warpCount--;
		Novice::ScreenPrintf(100, 300, "%d", SwanpCount);
		Novice::ScreenPrintf(200, 300, "%d", floorCount);

		if (enemy_->warpCount < 0) {
			enemy_->enemyX_ = enemy_->warpPointX;
			enemy_->enemyY_ = enemy_->warpPointY;
			enemy_->warpCount = 0;
			floorCount = 0;
			SwanpCount = 0;
			enemy_->enemyMapNum = map_->mapNum;
			enemy_->warpFlag = false;
		}
	}
	if (player_->mapChangeFlag == true) {
		if (player_->preMap == enemy_->enemyMapNum) {


			for (const auto& node : enemy_->path_) {
				if (map_->mapNum == 0) {
					if (map_->map[node->y][node->x] == 101) {
						SwanpCount += 1;
					}
				}
				else if (map_->mapNum == 1) {
					if (map_->map2[node->y][node->x] == 101) {
						SwanpCount += 1;
					}
				}
				else if (map_->mapNum == 2) {
					if (map_->map3[node->y][node->x] == 101) {
						SwanpCount += 1;
					}
				}
			}

			floorCount = (int)enemy_->path_.size() - SwanpCount;
			enemy_->warpCount = floorCount * 20 + SwanpCount * 60;

			player_->mapChangeFlag = false;
			if (enemy_->chaseCount <= enemy_->warpCount) {
				enemy_->warpCount = 0;
				floorCount = 0;
				SwanpCount = 0;
				enemy_->ChangeEnemyState(new EnemyStateStandby);

			}
			else {
				enemy_->warpPointX = player_->GetPlayerX();
				enemy_->warpPointY = player_->GetPlayerY();
				enemy_->warpFlag = true;
			}
		}


		else {

			enemy_->warpCount = 1000;
			floorCount = 0;
			SwanpCount = 0;
			enemy_->warpFlag = false;
			

		}
	}

}

void EnemyStateChase::Init(Enemy* enemy, Player* player, Map* map)
{
	this->enemy_ = enemy;
	player_ = player;
	map_ = map;


}

EnemyStateStandby::~EnemyStateStandby()
{

}

void EnemyStateStandby::Update()
{
	if (enemy_->enemyMapNum == map_->mapNum) {
		enemy_->ChangeEnemyState(new EnemyStateChase);
	}
	Novice::ScreenPrintf(400, 400, "StandBy");
}

void EnemyStateStandby::Init(Enemy* enemy, Player* player, Map* map)
{
	this->enemy_ = enemy;
	player_ = player;
	map_ = map;
}

EnemyState::~EnemyState()
{
}
