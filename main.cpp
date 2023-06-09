#include <Novice.h>
#include "map.h"
#include "Player.h"
#include "Enemy.h"
const char kWindowTitle[] = "LE2B_12_コバヤシダイスケ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Map* map = new Map();
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	
	Player* player = new Player({64, 64});
	int playerX = (int)player->GetPos().x / 64;
	int playerY = (int)player->GetPos().y / 64;
	//Vector2 Enemypos = { (float)5*64,(float)5*64};
	Enemy* enemy = new Enemy(12, 10);
	enemy->SetMap(map);
	enemy->SetPlayer(player);
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
	
			
		
		
		player->Update(keys);
	
		
		
		enemy->Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		map->Draw();
		enemy->Draw();

		 Novice::ScreenPrintf(650, 20, "%d", playerX);
			 Novice::ScreenPrintf(650, 40, "%d", playerY);

			 Novice::ScreenPrintf(900, 20, "%d", map->map[playerY][playerX]);
			 Novice::ScreenPrintf(850, 40, "%d", map->map.size());
			 Novice::ScreenPrintf(850, 20, "%d", map->map[0].size());
		player->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete map;
	delete player;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
