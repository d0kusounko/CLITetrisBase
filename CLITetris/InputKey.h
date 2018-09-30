//===========================================================================
//!
//!	@file		InputKey.h
//!	@brief		キー入力管理モジュール.
//!
//===========================================================================
#ifndef __INPUT_KEY_H__
#define __INPUT_KEY_H__

#include <windows.h>	//!< VK_???? キーアクセス用.

typedef struct tagInputKey
{
	bool trigger[256];	//!< 押した瞬間.
	bool press[256];	//!< 押している間.

} InputKey;

extern InputKey g_inputKey;

void InputKeyInitialize( void );
void UpdateKeyInput(void);

#endif // __INPUT_KEY_H__
