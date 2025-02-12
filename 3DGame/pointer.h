//=============================================================================
//
// ポリゴン処理 [pointer.h]
// Author : masayasu wakita
//
//=============================================================================
#ifndef _POINTER_H_
#define _POINTER_H_

#define _CRT_SECURE_NO_WARNINGS

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"

//=============================================================================
// 構造体定義
//=============================================================================
typedef struct
{
	D3DXVECTOR3 pos;										//位置
	D3DXVECTOR3 move;										//移動量
	D3DXVECTOR3 rot;										//回転
	D3DXMATRIX	mtxWorld;									//ワールドマトリックス
	int nCounterAnim;										//アニメーションカウンター
	int nPatternAnim;										//アニメーションNo
	bool bUse;												//使用しているかどうか
} POINTER;

//=============================================================================
// プロトタイプ宣言
//=============================================================================
void InitPointer(void);
void UninitPointer(void);
void UpdatePointer(void);
void DrawPointer(void);
POINTER *GetPointer(void);

#endif