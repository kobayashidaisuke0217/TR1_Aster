#include "Player.h"
#include <Novice.h>
Player::Player(Vector2 pos)
{
	initPos_ = pos;
	pos_ = pos;
	size_ = 64;
	speed_ = { 0,0 };
}
void Player::Init() {
	pos_ = initPos_;
	size_ = 64;
	speed_ = { 0,0 };

}

void Player::Update(char* keys,Map* map)
{

	
	float playerLeftTopX = pos_.x / 64;
	float playerLeftTopY = pos_.y / 64;
	float playerRightTopX = (pos_.x + size_ - 1) / 64;
	float playerRightTopY = pos_.y  / 64;
	float playerLeftBotommX = pos_.x / 64;
	float playerLeftBotommY = (pos_.y + size_ - 1) / 64;
	float playerRightBotommX = (pos_.x + size_- 1) / 64;
	float playerRightBotommY = (pos_.y + size_ - 1) / 64;
	if (keys[DIK_W]) {
			if (map->map[(int)playerLeftTopY][(int)playerLeftTopX] == 1 && map->map[(int)playerRightTopY][(int)playerRightTopX] == 1) {
			speed_.y = -4;
		}
	}
	else if (keys[DIK_S]) {
			if (map->map[(int)playerLeftBotommY][(int)playerLeftBotommX] == 1 && map->map[(int)playerRightBotommY][(int)playerRightBotommX] == 1) {
			speed_.y = 4;
		}
	}
	else if (keys[DIK_A]) {
			if (map->map[(int)playerLeftTopY][(int)playerLeftTopX] == 1 && map->map[(int)playerLeftBotommY][(int)playerLeftBotommX] == 1) {
			speed_.x =- 4;
		}
	}
	else if (keys[DIK_D]) {
			if (map->map[(int)playerRightTopY][(int)playerRightTopX] == 1 && map->map[(int)playerRightBotommY][(int)playerRightBotommX] == 1) {
			speed_.x = 4;
		}
	}
	pos_.x += speed_.x;
	pos_.y += speed_.y;
	speed_ = { 0,0 };
	/*if (keys[DIK_W] ) {
		Move({0,-4});
	}
	else if (keys[DIK_S] ) {
		Move({0,4});
	}
	else if (keys[DIK_A] ) {
		Move({-4,0});
	}
	else if (keys[DIK_D] ) {
		Move({4,0});
	}*/
}

void Player::Draw()
{
	Novice::DrawBox((int)pos_.x,(int) pos_.y, (int)size_, (int)size_, 0.0f, RED, kFillModeSolid);
}

void Player::Move(const Vector2 velocity)
{
	pos_.x += velocity.x;
	pos_.y += velocity.y;
}
