//===========================================================================
//!
//!	@file		Console.cpp
//!	@brief		コンソール制御モジュール.
//!
//===========================================================================
#include <conmanip.h>
#include "Console.h"

//! 指定座標にコンソール文字出力.
void ConsoleOut(int x, int y, const char* format, ...)
{
	va_list	vastr;
	static char	temp[1024];

	va_start(vastr, format);
	vsprintf_s(temp, format, vastr);
	va_end(vastr);

	std::cout << conmanip::setposx(x) << conmanip::setposy(y) << temp;
}
