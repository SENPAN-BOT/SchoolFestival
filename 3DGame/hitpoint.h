//========================================================================================
//
// 体力処理 [hitpoint.h]
// Author : Seiya Takahashi
//
//========================================================================================
#ifndef _HITPOINT_H_
#define _HITPOINT_H_

//========================================================================================
// インクルードファイル
//========================================================================================
#include "main.h"

//=============================================================================
// 構造体の定義
//=============================================================================
typedef struct
{
	float fMaxHp;									//HPの最大値
	float fNowHp;									//現在のHP
	float fWidth;									//画像の幅の最大値
	float fMaxHpEnemy;								//HPの最大値
	float fNowHpEnemy;								//現在のHP
	float fWidthEnemy;								//画像の幅の最大値
} HITPOINT;

//========================================================================================
// プロトタイプ宣言
//========================================================================================
void InitHitPoint(void);
void UninitHitPoint(void);
void UpdateHitPoint(void);
void DrawHitPoint(void);
void SetVertexHitPoint(int index, D3DXVECTOR3 pos, D3DXCOLOR col, float fWidth, float fHeight);
void SetVertexHitPoint1(int index, D3DXVECTOR3 pos, D3DXCOLOR col, float fWidth, float fHeight);
HITPOINT *GetHitPoint(void);
#endif
