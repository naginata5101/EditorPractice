#include "common.h"

void PutChip( int map[ MaxHei ][ MaxWid ], bool enemy[ MaxHei ][ MaxWid ], int scr, int selL, int selR )
{
	int x = MikanInput->GetMousePosX() / SIZE;
	int y = MikanInput->GetMousePosY() / SIZE;

	if( MikanInput->GetMouseNum( 0 ) > 0 )
	{
		if( selL != 100 && selL != -100 )
		{
			map[ y ][ x + scr ] = selL;
		}
		else if( selL == 100 )
		{
			enemy[ y ][ x + scr ] = true;
		}
		else
		{
			enemy[ y ][ x + scr ] = false;
		}
	}
	else if( MikanInput->GetMouseNum( 1 ) > 0 )
	{
		if( selR != 100 && selR != -100 )
		{
			map[ y ][ x + scr ] = selR;
		}
		else if( selR == 100 )
		{
			enemy[ y ][ x + scr ] = true;
		}
		else
		{
			enemy[ y ][ x + scr ] = false;
		}
	}
}

bool DidClickPalette( int *cliX, int *cliY )
{
	const int FrameSize = SIZE + 5 * 2;
	int x = MikanInput->GetMousePosX();
	int y = MikanInput->GetMousePosY();

	if( MikanInput->GetMouseNum( 0 ) == 1 ||
		MikanInput->GetMouseNum( 1 ) == 1 )
	{
		*cliX = x;
		*cliY = y;
	}

	if( ( WIDTH * SIZE - FrameSize * 2 <= *cliX &&
		  *cliX < WIDTH * SIZE &&
		  0 <= *cliY &&
		  *cliY <  FrameSize * ( ( MaxColor + 2 ) / 2 + 1 ) ) ||
		( 0 <= *cliX &&
		  *cliX < 32 / 2 * 9 &&
		  0 <= *cliY &&
		  *cliY < 32 ) )
	{
		return true;
	}

	return false;
}

void SelectChip( int *sel, int PudNum )
{
	const int FrameSize = SIZE + 5 * 2;
	int x = MikanInput->GetMousePosX();
	int y = MikanInput->GetMousePosY();

	if( MikanInput->GetMouseNum( PudNum ) == 1 )
	{
		for( int i = 0; i < MaxColor + 3; i ++ )
		{
			if( WIDTH * SIZE - FrameSize * ( 2 - i % 2 ) <= x &&
				x < WIDTH * SIZE - FrameSize * ( 1 - i % 2 ) &&
				FrameSize * ( i / 2 ) <= y &&
				y < FrameSize * ( i / 2 + 1 ) )
			{
				if( i < MaxColor )
				{
					*sel = i;
				}
				else if( i == MaxColor )
				{
					*sel = 100;
				}
				else if( i == MaxColor + 1 )
				{
					*sel = -100;
				}
				else
				{
					*sel = -1;
				}
			}
		}
	}
}

void MouseScroll( int *scr, int *stX )
{
	int x = MikanInput->GetMousePosX();
	int y = MikanInput->GetMousePosY();

	if( 0 <= x &&
		x < WIDTH * SIZE &&
		0 <= y &&
		y < HEIGHT * SIZE )
	{
		if( MikanInput->GetMouseNum( 2 ) == 1 )
		{
			*stX = x;
		}
		else if( x != *stX &&
			MikanInput->GetMouseNum( 2 ) > 1 &&
			MikanInput->GetMouseNum( 2 ) % ( WIDTH - abs( x - *stX ) / SIZE ) == 0 )
		{
			if( x < *stX )
			{
				*scr -= 1;
			}
			else
			{
				*scr += 1;
			}
		}
		else if( MikanInput->GetMouseNum( 2 ) == -1 )
		{
			*stX = -10;
		}
	}
}

void KeyScroll( int *scr )
{
	if( MikanInput->GetKeyNum( K_RIGHT ) % 5 == 1 )
	{
		*scr += 1;
	}
	if( MikanInput->GetKeyNum( K_LEFT ) % 5 == 1 )
	{
		*scr -= 1;
	}

	if( MikanInput->GetKeyNum( K_A ) % 5 == 1 )
	{
		*scr = 0;
	}
	if( MikanInput->GetKeyNum( K_Z ) % 5 == 1 )
	{
		*scr = MaxWid - WIDTH;
	}
}

//画面外に出た際のスクロール位置の修正
void ReviseScroll( int *scr )
{
	if( *scr < 0 )
	{
		*scr = 0;
	}
	else if( *scr > MaxWid - WIDTH )
	{
		*scr = MaxWid - WIDTH;
	}
}


void Move( int map[ MaxHei ][ MaxWid ], bool enemy[ MaxHei ][ MaxWid ], int *scroll, int *startX, int *cliX, int *cliY, int *selectL, int *selectR )
{
	if( DidClickPalette( cliX, cliY ) == true )
	{
		SelectChip( selectL, 0 );
		SelectChip( selectR, 1 );
	}
	else
	{
		PutChip( map, enemy, *scroll, *selectL, *selectR );
	}

	MouseScroll( scroll, startX );
	KeyScroll( scroll );
	ReviseScroll( scroll );
}