#include "XO_GAME.h"

static uint8_t Grid[ROWS_NUMBER][COLUMNS_NUMBER]={	'1','2','3',
													'4','5','6',
													'7','8','9' };

void GridDraw(void)
{
		system("cls");
    printf("\n\n\t\t\t\t     X-O Game\n\n");

    printf("\t\t\t  Player 1 (X)  Vs  Player 2 (O)\n\n\n");


    printf("\t\t\t\t      |     |     \n");
    printf("\t\t\t\t   %c  |  %c  |  %c \n", Grid[0][0] , Grid[0][1] , Grid[0][2]);

    printf("\t\t\t\t _____|_____|_____\n");
	
    printf("\t\t\t\t      |     |     \n");
    printf("\t\t\t\t   %c  |  %c  |  %c \n", Grid[1][0] , Grid[1][1] , Grid[1][2]);

    printf("\t\t\t\t _____|_____|_____\n");
	
    printf("\t\t\t\t      |     |     \n");
    printf("\t\t\t\t   %c  |  %c  |  %c \n", Grid[2][0] , Grid[2][1] , Grid[2][2]);

    printf("\t\t\t\t      |     |     \n\n");
}

GameState_t GameCheckState(void)
{
	uint8_t AvailablePlacesCounter=0;
	uint8_t GridData = '1';
	
	if(	(Grid[0][0]==Grid[1][1])&&(Grid[0][0]==Grid[2][2]) ||
		(Grid[0][2]==Grid[1][1])&&(Grid[0][2]==Grid[2][0])	)
	{
		return GameWin;
	}
	
	for(uint8_t Row=0;Row<ROWS_NUMBER;Row++)
	{
		if((Grid[Row][0]==Grid[Row][1])&&(Grid[Row][0]==Grid[Row][2]))
		{
			return GameWin;
		}
		for(uint8_t Col=0;Col<COLUMNS_NUMBER;Col++)
		{
			if((Grid[0][Col]==Grid[1][Col])&&(Grid[0][Col]==Grid[2][Col]))
			{
				return GameWin;
			}
			
			if(Grid[Row][Col] == GridData)
			{
				AvailablePlacesCounter++;
			}
			GridData++;
		}
	}
	
	if(AvailablePlacesCounter == 0)
	{
		return GameDraw;
	}
	else
	{
		return GameContinue;
	}
}

void PlayerGetPosition(uint8_t WhichPlayer)
{
	uint8_t PlayerPosition;
	while(1)
	{
		printf("Plz enter your game position from (1 To 9): ");
		scanf("%d",&PlayerPosition);
		getchar();

		if((PlayerPosition<1)||(PlayerPosition>9))
		{
			printf("This Position isn't valid, Plz Enter a number from (1 To 9)\n");
		}
		else 
		{
			PlayerPosition--;
			if ((Grid[PlayerPosition/3][PlayerPosition%3]=='O')||(Grid[PlayerPosition/3][PlayerPosition%3]=='X'))
			{
				printf("This Position is chosen before, Plz Choose another position\n");
			}
			else if(WhichPlayer == PLAYER1)
			{
				Grid[PlayerPosition/3][PlayerPosition%3]='X';
				break;
			}
			else
			{
				Grid[PlayerPosition/3][PlayerPosition%3]='O';
				break;
			}
		}		
	}

}

void XOGame(void)
{
	GameState_t GameState;
	uint8_t WhichPlayer = 0;
	do
	{
		GridDraw();
		WhichPlayer=(WhichPlayer==1)?(PLAYER2):(PLAYER1);
		printf("\n\n\tPlayer%d turn\n\n",WhichPlayer);
		PlayerGetPosition(WhichPlayer);
		GameState =GameCheckState();
		
		
	}while(GameState==GameContinue);
	
	GridDraw();
	switch(GameState)
	{
		case GameWin:
			printf("\n\n\t\t\t\tPlayer%d is the Winner\n\n",WhichPlayer);
		break;
		case GameDraw:
			printf("\n\n\t\t\t\tA Game Draw\n\n");
		break;
		default:
		break;		
	}
	
}