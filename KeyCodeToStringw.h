#ifndef KEYCODETOSTRINGW_H
#define KEYCODETOSTRINGW_H

#include <irrlicht.h>
#include <string>

using namespace irr;
using namespace irr::core;
using namespace std;

wstring keyCodeToStringw(EKEY_CODE e) {
   if (e == KEY_LBUTTON)      return wstring(L"KEY_LBUTTON");
   if (e == KEY_RBUTTON)      return wstring(L"KEY_RBUTTON");
   if (e == KEY_CANCEL)      return wstring(L"KEY_CANCEL");
   if (e == KEY_MBUTTON)      return wstring(L"KEY_MBUTTON");
   if (e == KEY_XBUTTON1)      return wstring(L"KEY_XBUTTON1");
   if (e == KEY_XBUTTON2)      return wstring(L"KEY_XBUTTON2");
   if (e == KEY_BACK)         return wstring(L"KEY_BACK");
   if (e == KEY_TAB)         return wstring(L"KEY_TAB");
   if (e == KEY_CLEAR)         return wstring(L"KEY_CLEAR");
   if (e == KEY_RETURN)      return wstring(L"KEY_RETURN");
   if (e == KEY_SHIFT)         return wstring(L"KEY_SHIFT");
   if (e == KEY_CONTROL)      return wstring(L"KEY_CONTROL");
   if (e == KEY_MENU)         return wstring(L"KEY_MENU");
   if (e == KEY_PAUSE)         return wstring(L"KEY_PAUSE");
   if (e == KEY_CAPITAL)      return wstring(L"KEY_CAPITAL");
   if (e == KEY_KANA)         return wstring(L"KEY_KANA");
   if (e == KEY_HANGUEL)      return wstring(L"KEY_HANGUEL");
   if (e == KEY_HANGUL)      return wstring(L"KEY_HANGUL");
   if (e == KEY_JUNJA)         return wstring(L"KEY_JUNJA");
   if (e == KEY_FINAL)         return wstring(L"KEY_FINAL");
   if (e == KEY_HANJA)         return wstring(L"KEY_HANJA");
   if (e == KEY_KANJI)         return wstring(L"KEY_KANJI");
   if (e == KEY_ESCAPE)      return wstring(L"KEY_ESCAPE");
   if (e == KEY_CONVERT)      return wstring(L"KEY_CONVERT");
   if (e == KEY_NONCONVERT)   return wstring(L"KEY_NONCONVERT");
   if (e == KEY_ACCEPT)      return wstring(L"KEY_ACCEPT");
   if (e == KEY_MODECHANGE)   return wstring(L"KEY_MODECHANGE");
   if (e == KEY_SPACE)         return wstring(L"KEY_SPACE");
   if (e == KEY_PRIOR)         return wstring(L"KEY_PRIOR");
   if (e == KEY_NEXT)         return wstring(L"KEY_NEXT");
   if (e == KEY_END)         return wstring(L"KEY_END");
   if (e == KEY_HOME)         return wstring(L"KEY_HOME");
   if (e == KEY_LEFT)         return wstring(L"KEY_LEFT");
   if (e == KEY_UP)         return wstring(L"KEY_UP");
   if (e == KEY_RIGHT)         return wstring(L"KEY_RIGHT");
   if (e == KEY_DOWN)         return wstring(L"KEY_DOWN");
   if (e == KEY_SELECT)      return wstring(L"KEY_SELECT");
   if (e == KEY_PRINT)         return wstring(L"KEY_PRINT");
   if (e == KEY_EXECUT)      return wstring(L"KEY_EXECUT");
   if (e == KEY_SNAPSHOT)      return wstring(L"KEY_SNAPSHOT");
   if (e == KEY_INSERT)      return wstring(L"KEY_INSERT");
   if (e == KEY_DELETE)      return wstring(L"KEY_DELETE");
   if (e == KEY_HELP)         return wstring(L"KEY_HELP");
   if (e == KEY_KEY_0)         return wstring(L"KEY_KEY_0");
   if (e == KEY_KEY_1)         return wstring(L"KEY_KEY_1");
   if (e == KEY_KEY_2)         return wstring(L"KEY_KEY_2");
   if (e == KEY_KEY_3)         return wstring(L"KEY_KEY_3");
   if (e == KEY_KEY_4)         return wstring(L"KEY_KEY_4");
   if (e == KEY_KEY_5)         return wstring(L"KEY_KEY_5");
   if (e == KEY_KEY_6)         return wstring(L"KEY_KEY_6");
   if (e == KEY_KEY_7)         return wstring(L"KEY_KEY_7");
   if (e == KEY_KEY_8)         return wstring(L"KEY_KEY_8");
   if (e == KEY_KEY_9)         return wstring(L"KEY_KEY_9");
   if (e == KEY_KEY_A)         return wstring(L"KEY_KEY_A");
   if (e == KEY_KEY_B)         return wstring(L"KEY_KEY_B");
   if (e == KEY_KEY_C)         return wstring(L"KEY_KEY_C");
   if (e == KEY_KEY_D)         return wstring(L"KEY_KEY_D");
   if (e == KEY_KEY_E)         return wstring(L"KEY_KEY_E");
   if (e == KEY_KEY_F)         return wstring(L"KEY_KEY_F");
   if (e == KEY_KEY_G)         return wstring(L"KEY_KEY_G");
   if (e == KEY_KEY_H)         return wstring(L"KEY_KEY_H");
   if (e == KEY_KEY_I)         return wstring(L"KEY_KEY_I");
   if (e == KEY_KEY_J)         return wstring(L"KEY_KEY_J");
   if (e == KEY_KEY_K)         return wstring(L"KEY_KEY_K");
   if (e == KEY_KEY_L)         return wstring(L"KEY_KEY_L");
   if (e == KEY_KEY_M)         return wstring(L"KEY_KEY_M");
   if (e == KEY_KEY_N)         return wstring(L"KEY_KEY_N");
   if (e == KEY_KEY_O)         return wstring(L"KEY_KEY_O");
   if (e == KEY_KEY_P)         return wstring(L"KEY_KEY_P");
   if (e == KEY_KEY_Q)         return wstring(L"KEY_KEY_Q");
   if (e == KEY_KEY_R)         return wstring(L"KEY_KEY_R");
   if (e == KEY_KEY_S)         return wstring(L"KEY_KEY_S");
   if (e == KEY_KEY_T)         return wstring(L"KEY_KEY_T");
   if (e == KEY_KEY_U)         return wstring(L"KEY_KEY_U");
   if (e == KEY_KEY_V)         return wstring(L"KEY_KEY_V");
   if (e == KEY_KEY_W)         return wstring(L"KEY_KEY_W");
   if (e == KEY_KEY_X)         return wstring(L"KEY_KEY_X");
   if (e == KEY_KEY_Y)         return wstring(L"KEY_KEY_Y");
   if (e == KEY_KEY_Z)         return wstring(L"KEY_KEY_Z");
   if (e == KEY_LWIN)         return wstring(L"KEY_LWIN");
   if (e == KEY_RWIN)         return wstring(L"KEY_RWIN");
   if (e == KEY_APPS)         return wstring(L"KEY_APPS");
   if (e == KEY_SLEEP)         return wstring(L"KEY_SLEEP");
   if (e == KEY_NUMPAD0)      return wstring(L"KEY_NUMPAD0");
   if (e == KEY_NUMPAD1)      return wstring(L"KEY_NUMPAD1");
   if (e == KEY_NUMPAD2)      return wstring(L"KEY_NUMPAD2");
   if (e == KEY_NUMPAD3)      return wstring(L"KEY_NUMPAD3");
   if (e == KEY_NUMPAD4)      return wstring(L"KEY_NUMPAD4");
   if (e == KEY_NUMPAD5)      return wstring(L"KEY_NUMPAD5");
   if (e == KEY_NUMPAD6)      return wstring(L"KEY_NUMPAD6");
   if (e == KEY_NUMPAD7)      return wstring(L"KEY_NUMPAD7");
   if (e == KEY_NUMPAD8)      return wstring(L"KEY_NUMPAD8");
   if (e == KEY_NUMPAD9)      return wstring(L"KEY_NUMPAD9");
   if (e == KEY_MULTIPLY)      return wstring(L"KEY_MULTIPLY");
   if (e == KEY_ADD)         return wstring(L"KEY_ADD");
   if (e == KEY_SEPARATOR)      return wstring(L"KEY_SEPARATOR");
   if (e == KEY_SUBTRACT)      return wstring(L"KEY_SUBTRACT");
   if (e == KEY_DECIMAL)      return wstring(L"KEY_DECIMAL");
   if (e == KEY_DIVIDE)      return wstring(L"KEY_DIVIDE");
   if (e == KEY_F1)         return wstring(L"KEY_F1");
   if (e == KEY_F2)         return wstring(L"KEY_F2");
   if (e == KEY_F3)         return wstring(L"KEY_F3");
   if (e == KEY_F4)         return wstring(L"KEY_F4");
   if (e == KEY_F5)         return wstring(L"KEY_F5");
   if (e == KEY_F6)         return wstring(L"KEY_F6");
   if (e == KEY_F7)         return wstring(L"KEY_F7");
   if (e == KEY_F8)         return wstring(L"KEY_F8");
   if (e == KEY_F9)         return wstring(L"KEY_F9");
   if (e == KEY_F10)         return wstring(L"KEY_F10");
   if (e == KEY_F11)         return wstring(L"KEY_F11");
   if (e == KEY_F12)         return wstring(L"KEY_F12");
   if (e == KEY_F13)         return wstring(L"KEY_F13");
   if (e == KEY_F14)         return wstring(L"KEY_F14");
   if (e == KEY_F15)         return wstring(L"KEY_F15");
   if (e == KEY_F16)         return wstring(L"KEY_F16");
   if (e == KEY_F17)         return wstring(L"KEY_F17");
   if (e == KEY_F18)         return wstring(L"KEY_F18");
   if (e == KEY_F19)         return wstring(L"KEY_F19");
   if (e == KEY_F20)         return wstring(L"KEY_F20");
   if (e == KEY_F21)         return wstring(L"KEY_F21");
   if (e == KEY_F22)         return wstring(L"KEY_F22");
   if (e == KEY_F23)         return wstring(L"KEY_F23");
   if (e == KEY_F24)         return wstring(L"KEY_F24");
   if (e == KEY_NUMLOCK)      return wstring(L"KEY_NUMLOCK");
   if (e == KEY_SCROLL)      return wstring(L"KEY_SCROLL");
   if (e == KEY_LSHIFT)      return wstring(L"KEY_LSHIFT");
   if (e == KEY_RSHIFT)      return wstring(L"KEY_RSHIFT");
   if (e == KEY_LCONTROL)      return wstring(L"KEY_LCONTROL");
   if (e == KEY_RCONTROL)      return wstring(L"KEY_RCONTROL");
   if (e == KEY_LMENU)         return wstring(L"KEY_LMENU");
   if (e == KEY_RMENU)         return wstring(L"KEY_RMENU");
   if (e == KEY_PLUS)         return wstring(L"KEY_PLUS");
   if (e == KEY_COMMA)         return wstring(L"KEY_COMMA");
   if (e == KEY_MINUS)         return wstring(L"KEY_MINUS");
   if (e == KEY_PERIOD)      return wstring(L"KEY_PERIOD");
   if (e == KEY_ATTN)         return wstring(L"KEY_ATTN");
   if (e == KEY_CRSEL)         return wstring(L"KEY_CRSEL");
   if (e == KEY_EXSEL)         return wstring(L"KEY_EXSEL");
   if (e == KEY_EREOF)         return wstring(L"KEY_EREOF");
   if (e == KEY_PLAY)         return wstring(L"KEY_PLAY");
   if (e == KEY_ZOOM)         return wstring(L"KEY_ZOOM");
   if (e == KEY_PA1)         return wstring(L"KEY_PA1");
   if (e == KEY_OEM_CLEAR)      return wstring(L"KEY_OEM_CLEAR");
   return wstring(L"UNKNOWN");
}

#endif