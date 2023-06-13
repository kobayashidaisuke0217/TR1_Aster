#include "Player.h"
#include <Novice.h>
Player::Player(Vector2 pos)
{
	initPos_ = pos;
	pos_ = pos;
	size_ = 32;
	speed_ = { 0,0 };
	playerX = 0;
	playerY = 0;
}
void Player::Init() {
	pos_ = initPos_;
	
	speed_ = { 0,0 };
	preMap = map_->mapNum;
}

void Player::Update(char* keys)
{

	if (keys[DIK_W]&& pos_.y >= 0) {
		
			speed_.y = -4;
		
	}
	else if (keys[DIK_S]&& pos_.y <= 688) {
		
			speed_.y = 4;
		
	}
	else if (keys[DIK_A]&&pos_.x >= 0) {
		
			speed_.x =- 4;
		
	}

	else if (keys[DIK_D]&& pos_.x <= 1248) {
		
			speed_.x = 4;
		
	}
	
	pos_.x += speed_.x;
	pos_.y += speed_.y;
	speed_ = { 0,0 };
	playerX = (int)pos_.x / 64;
	playerY = (int)pos_.y / 64;
	if (map_->mapNum == 0) {
		if (map_->map[playerY][playerX] != 99 && map_->map[playerY][playerX] != 100 && map_->map[playerY][playerX] != 101) {
			
			mapChangeFlag = true;
			preMap = map_->mapNum;
			map_->mapNum = map_->map[playerY][playerX];
			pos_ = { 70,70 };
		}
	}
	else if (map_->mapNum == 1) {
		if (map_->map2[playerY][playerX] != 99 && map_->map2[playerY][playerX] != 100 && map_->map2[playerY][playerX] != 101) {
			mapChangeFlag = true;
			preMap = map_->mapNum;
			map_->mapNum = map_->map2[playerY][playerX];
			
			pos_ = { 70,70 };
		}
	}
	else if (map_->mapNum == 2) {
		if (map_->map3[playerY][playerX] != 99 && map_->map3[playerY][playerX] != 100 && map_->map3[playerY][playerX] != 101) {
			mapChangeFlag = true;
			preMap = map_->mapNum;
			map_->mapNum = map_->map3[playerY][playerX];
			
			pos_ = { 70,70 };
		}
	}
	
}

void Player::Draw()
{
	Novice::DrawBox((int)pos_.x,(int) pos_.y, (int)size_, (int)size_, 0.0f, WHITE, kFillModeSolid);
	Novice::ScreenPrintf(300, 100, "%d", preMap);
}

void Player::Move(const Vector2 velocity)
{
	pos_.x += velocity.x;
	pos_.y += velocity.y;
}
