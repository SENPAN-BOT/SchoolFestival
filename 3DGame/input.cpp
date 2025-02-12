//=============================================================================
//
// 入力処理 [input.cpp]
// Author : masayasu wakita
//
//=============================================================================
#include "input.h"
//#include <atlstr.h> 

//=============================================================================
// マクロ定義
//=============================================================================
#define	NUM_KEY_MAX			(256)	// キーの最大数

//=============================================================================
// グローバル変数
//=============================================================================
LPDIRECTINPUT8 g_pInput = NULL;				//DirectInputオブジェクトへのポインタ
LPDIRECTINPUTDEVICE8 g_pDevKeyboard = NULL;	//入力デバイス(キーボード)へのポインタ
BYTE g_aKeyState[NUM_KEY_MAX];				//キーボードの入力情報ワーク
BYTE g_akeyStateTrigger[NUM_KEY_MAX];		//弾の1発撃ち
BYTE g_akeyStateUp[NUM_KEY_MAX];		//弾の1発撃ち(離した)
//BYTE g_aXInputTrigger[NUM_KEY_MAX];			//コントローラーの1発撃ち
BYTE g_akeyStateRelese[NUM_KEY_MAX];		//弾の溜めうち
BYTE g_akeyStateRepeat[NUM_KEY_MAX];		//弾の再連射
//XINPUT_STATE g_pState;						//XInputコントローラー
//XINPUT_KEYSTROKE g_pKeystroke;

//=============================================================================
// キーボードの初期化
//=============================================================================
HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd)
{
	// DirectInputオブジェクトの作成
	if (FAILED(DirectInput8Create(hInstance,DIRECTINPUT_VERSION,IID_IDirectInput8,(void**)&g_pInput,NULL)))
	{
		return E_FAIL;
	}

	// 入力デバイス（キーボード）の作成
	if (FAILED(g_pInput->CreateDevice(GUID_SysKeyboard, &g_pDevKeyboard, NULL)))
	{
		return E_FAIL;
	}
	
	// データフォーマットを設定
	if (FAILED(g_pDevKeyboard->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	// 協調モードを設定（フォアグラウンド＆非排他モード）
	if (FAILED(g_pDevKeyboard->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	// キーボードへのアクセス権を獲得(入力制御開始)
	g_pDevKeyboard->Acquire();

	return S_OK;
}

//=============================================================================
// キーボードの終了処理
//=============================================================================
void UninitKeyboard(void)
{
	// 入力デバイス(キーボード)の開放
	if (g_pDevKeyboard != NULL)
	{
		g_pDevKeyboard->Unacquire();			//キーボードへのアクセス権を開放
		g_pDevKeyboard->Release();
		g_pDevKeyboard = NULL;
	}
	
	// DirectInputオブジェクトの開放
	if (g_pInput != NULL)
	{
		g_pInput->Release();
		g_pInput = NULL;
	}
}

//=============================================================================
// キーボードの更新処理
//=============================================================================
void UpdateKeyboard(void)
{
	BYTE aKeyState[NUM_KEY_MAX];				//キーボードの入力情報
	int nCntKey;

	// デバイスからデータを取得
	if (SUCCEEDED(g_pDevKeyboard->GetDeviceState(sizeof(aKeyState), aKeyState)))
	{
		for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			g_akeyStateTrigger[nCntKey] = (g_aKeyState[nCntKey] & aKeyState[nCntKey]) ^ aKeyState[nCntKey];
			g_akeyStateUp[nCntKey] = g_aKeyState[nCntKey] ^ (g_aKeyState[nCntKey] & aKeyState[nCntKey]);

			g_aKeyState[nCntKey] = aKeyState[nCntKey];	//キープレス情報保存
		}
	}
	else
	{
		g_pDevKeyboard->Acquire();				//キーボードへのアクセス権を取得
	}
}

//=============================================================================
// キーボードのトリガー状態を取得
//=============================================================================
bool GetTriggerKeyboard(int nKey)
{
	return(g_akeyStateTrigger[nKey] & 0x80) ? true : false;
}

//=============================================================================
// キーボードのトリガー状態を取得
//=============================================================================
bool GetUpKeyboard(int nKey)
{
	return(g_akeyStateUp[nKey] & 0x80) ? true : false;
}

//=============================================================================
// キーボードのプレス状態を取得
//=============================================================================
bool GetKeyboardPress(int nKey)
{
	return(g_aKeyState[nKey] & 0x80) ? true : false;
}
