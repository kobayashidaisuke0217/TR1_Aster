#include <Novice.h>
#include "map.h"
#include "Player.h"
const char kWindowTitle[] = "LE2B_12_コバヤシダイスケ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	Map* map = new Map();
	Player* player = new Player({64, 64});
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
		player->Update(keys,map);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		map->Draw();
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
