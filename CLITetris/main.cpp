//===========================================================================
//!
//!	@file		main.cpp
//!	@brief		アプリケーションメイン.
//!
//===========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <conmanip.h>
#include <thread>

#include "InputKey.h"
#include "Game.h"

void InitializeApp(void);

int main()
{
	InitializeApp();

	// ゲームループ.
	while (true)
	{
		// 画面クリア.
		system("cls");

		// キー入力情報更新.
		UpdateKeyInput();

		// ゲーム更新.
		if (UpdateGame())
		{
			break;	// ゲーム終了.
		}

		// ゲーム画面表示.
		DrawGame();

		// 疑似30FPS.
		std::this_thread::sleep_for(std::chrono::microseconds(33333));
	}

	return 0;
}

// アプリケーション初期化.
void InitializeApp(void)
{
	// ゲームタイトル設定.
	conmanip::console_out_context ctxout;
	conmanip::console_out conout(ctxout);
	conout.settitle("Tetris");

	// キャレット非表示.
	HANDLE hOut;
	CONSOLE_CURSOR_INFO cci;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cci);

	// キー入力情報初期化.
	InputKeyInitialize();
}