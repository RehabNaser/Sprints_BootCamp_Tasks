/*
 * File Name: XO_GAME.h
 * Creation Date: 03/07/2021
 * Author: Rehab
 * Description: Header File for X-O Game....
 */ 
 
#ifndef XO_GAME_H_
#define XO_GAME_H_

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "STD_TYPES.h"

#define GRID_SIZE 9
#define ROWS_NUMBER 3
#define COLUMNS_NUMBER 3


#define PLAYER1  1
#define PLAYER2  2

typedef enum GameState
{
	GameWin 		= 0,
	GameDraw		= 1,
	GameContinue	= 2
}GameState_t;

void GridDraw(void);
void XOGame(void);
void PlayerGetPosition(uint8_t WhichPlayer);
GameState_t GameCheckState(void);

#endif