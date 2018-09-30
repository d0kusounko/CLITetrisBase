//===========================================================================
//!
//!	@file		InputKey.cpp
//!	@brief		キー入力管理モジュール.
//!
//===========================================================================
#include <string.h>
#include "InputKey.h"

InputKey g_inputKey;

//! キー入力情報初期化.
void InputKeyInitialize(void)
{
	int i;
	for (i = 0; i < 0xFF; ++i)
	{
		g_inputKey.trigger[i]	= false;
		g_inputKey.press[i]		= false;
	}
}

// キー入力情報更新.
void UpdateKeyInput(void)
{
	int i;

	bool  oldPressKey[0xFF];
	memcpy(oldPressKey, g_inputKey.press, sizeof(bool) * 0xFF);

	for (i = 0; i < 0xFF; ++i)
	{
		SHORT state = GetAsyncKeyState(i);

		if (HIWORD(state))
		{
			g_inputKey.press[i] = true;
			g_inputKey.trigger[i] = oldPressKey[i] ? false : true;
		}
		else
		{
			g_inputKey.press[i] = false;
			g_inputKey.trigger[i] = false;
		}
	}
}
