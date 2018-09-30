//===========================================================================
//!
//!	@file		Game.cpp
//!	@brief		ゲームメイン.
//!
//===========================================================================
#include "Game.h"
#include "Console.h"
#include "InputKey.h"

// サンプル.
static int	testX		= 5;
static int	testY		= 5;
static bool testBlack	= true;

//! ゲーム更新.
bool UpdateGame( void )
{
	// TODO: テトリスを制御するプログラムを書こう.
	//
	// ゲームは1秒間約30フレームで動作するよ.

	// サンプル.
	if (g_inputKey.press[VK_LEFT])
	{
		testX--;
	}
	if (g_inputKey.press[VK_RIGHT])
	{
		testX++;
	}
	if (g_inputKey.press[VK_UP])
	{
		testY--;
	}
	if (g_inputKey.press[VK_DOWN])
	{
		testY++;
	}
	if (g_inputKey.trigger[VK_SPACE])
	{
		testBlack = !testBlack;
	}

	if (testX < 0) testX = 0;
	if (testY < 0) testY = 0;

	return false;

	// return true;	// ゲーム終了時はTrueを返却.
}

//! ゲーム画面描画.
void DrawGame( void )
{
	// TODO: テトリスの画面を描画するプログラムを書こう.
	//
	// ConsoleOut()関数で指定位置に文字が出せるよ.

	// サンプル.
	int i;
	for (i = 0; i < 10; ++i)
	{
		ConsoleOut( i * 2, 0, "□" );
	}

	ConsoleOut(testX * 2, testY + 1, "%s", testBlack ? "■" : "□");
}
