#include <Novice.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <corecrt_math.h>

bool isEnemy = true;
int timer = 0;

bool isBulletColliding(Bullet& bullet, Enemy& enemy) {
	int bulletX = bullet.bulletGetX() - enemy.getX();
	int bulletY = bullet.bulletGetY() - enemy.getY();
	int distance = (int)sqrt(bulletX * bulletX + bulletY * bulletY);

	return distance < 50;
}

bool isPlayerColliding(Player& player, Enemy& enemy) {
	int dx = player.playerGetX() - enemy.getX();
	int dy = player.playerGetY() - enemy.getY();
	int distance = (int)sqrt(dx * dx + dy * dy);

	return distance < 50;
}

enum Scene {
	title = 0,
	game = 1,
	over = 3,
};

int Scene = title;

const char kWindowTitle[] = "GC1C_09_タカハシ_ダン_Hit_The_Target";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	const int kWindowWidth = 1280; // ウィンドウの横幅
	const int kWindowHeight = 720; // ウィンドウの縦幅

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	int titleImages = Novice::LoadTexture("./images/gametitle.png");//タイトル
	int overImages = Novice::LoadTexture("./images/gameOver.png");//オーバー

	Player* player = new Player;
	Enemy* enemy = new Enemy;;
	Bullet* bullet = new Bullet;
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

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

		switch (Scene) {

		case title:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				Scene = game;
				player->Initialize();
				bullet->Initialize();
			}

			break;

		case game:

			player->move(keys);
			enemy->move();
			bullet->shot(keys, preKeys, player->playerGetX(), player->playerGetY());

			if (isBulletColliding(*bullet, *enemy)) {
				isEnemy = false;
				bullet->Initialize();
			}
			if (isEnemy == false) {
				timer++;
				if (timer == 60) {
					isEnemy = true;
					timer = 0;
				}
			}
			if (isPlayerColliding(*player, *enemy)) {
				Scene = over;
				bullet->Initialize();
			}

			break;


		case over:

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				Scene = title;
			}

			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから


		switch (Scene) {

		case title:
			Novice::DrawSprite(0, 0, titleImages, 1, 1, 0.0f, WHITE);

			break;

		case game:
			player->Draw();
			if (isEnemy == true) {
				enemy->Draw();
			}
			bullet->Draw();

			break;


		case over:
			Novice::DrawSprite(0, 0, overImages, 1, 1, 0.0f, WHITE);

			break;
		}



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

	delete bullet;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}