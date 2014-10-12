// -------------------------------------------------------------------------------
// 
// 		ＤＸライブラリ		Windows用データタイプ定義ヘッダファイル
// 
// 				Ver 3.12a
// 
// -------------------------------------------------------------------------------

#ifndef __DXDATATYPEWIN_H__
#define __DXDATATYPEWIN_H__

// インクルード ------------------------------------------------------------------
#include "DxCompileConfig.h"
#include <tchar.h>
#include <windows.h>
#include <commctrl.h>

namespace DxLib
{

// マクロ定義 --------------------------------------------------------------------

// 環境依存キーワードなど
#define FASTCALL	__fastcall

// DirectX型
#define DX_DIRECT3DDEVICE9					class D_IDirect3DDevice9
#define DX_DIRECT3DSURFACE9					class D_IDirect3DSurface9

// ＤｉｒｅｃｔＩｎｐｕｔのバージョン設定
#define DIRECTINPUT_VERSION 0x700

#ifndef DWORD_PTR
#ifdef _WIN64
#define DWORD_PTR	ULONGLONG
#else
#define DWORD_PTR	DWORD
#endif
#endif

#ifndef LONG_PTR
#ifdef _WIN64
#define LONG_PTR	__int64
#else
#define LONG_PTR	int
#endif
#endif

// 構造体定義 --------------------------------------------------------------------

// テーブル-----------------------------------------------------------------------

// 内部大域変数宣言 --------------------------------------------------------------

// 関数プロトタイプ宣言-----------------------------------------------------------

}

#endif // __DXDATATYPEWIN_H__
