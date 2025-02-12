//========================================================================================
//
// 魔法処理 [magic.h]
// Author : Seiya Takahashi
//
//========================================================================================
#ifndef _MAGIC_H_
#define _MAGIC_H_

//========================================================================================
// インクルードファイル
//========================================================================================
#include "main.h"

//=============================================================================
// 構造体の定義
//=============================================================================
typedef struct
{
	float fMaxMagic;									//魔力の最大値
	float fNowMagic;									//現在の魔力
	float fWidth;										//画像の幅の最大値
} MAGIC;

//========================================================================================
// プロトタイプ宣言
//========================================================================================
void InitMagic(void);
void UninitMagic(void);
void UpdateMagic(void);
void DrawMagic(void);
void SetVertexMagic(int index, D3DXVECTOR3 pos, D3DXCOLOR col, float fWidth, float fHeight);
MAGIC *GetMagic(void);
#endif
