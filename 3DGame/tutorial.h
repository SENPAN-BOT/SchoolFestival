//========================================================================================
//
// polygon基礎[bg.h]
//
// Author : masayasu wakita
// 07/18
//
//========================================================================================
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_
//========================================================================================
// インクルードファイル
//========================================================================================
#include "main.h"
#include "input.h"
#include "controller.h"

//========================================================================================
// 構造体定義
//========================================================================================

//========================================================================================
// プロトタイプ宣言
//========================================================================================
void InitTutorial(void);
void UninitTutorial(void);
void UpdateTutorial(void);
void DrawTutorial(void);
void SetVertexTutorial(int index, D3DXVECTOR3 pos, D3DXCOLOR col, float fWidth, float fHeight);
bool IsFinish(void);
void SetTutorial(void);
#endif