#include "common.h"

void DrawMap( int map[ MaxHei ][ MaxWid ], int scroll )
{
	for( int i = scroll; i < scroll + WIDTH; i ++ )
	{
		for( int j = 0; j < HEIGHT; j ++ )
		{
			if( map[ j ][ i ] != -1 )
			{
				MikanDraw->DrawTexture( 1, ( i - scroll ) * SIZE,
					j * SIZE, map[ j ][ i ] * SIZE, 0 * SIZE, SIZE, SIZE );
			}
		}
	}
}

void DrawEnemy( bool enemy[ MaxHei ][ MaxWid ], int scroll )
{
	for( int i = scroll; i < scroll + WIDTH; i ++ )
	{
		for( int j = 0; j < HEIGHT; j ++ )
		{
			if( enemy[ j ][ i ] == true )
			{
				MikanDraw->DrawTexture( 0, ( i - scroll ) * SIZE + 5,
					j * SIZE + 5, 42, 0, SIZE - 10, SIZE - 10 );
			}
		}
	}
}

void DrawGrid()
{
	//ècê¸
	for( int i = 1; i < WIDTH; i ++ )
	{
		MikanDraw->DrawLine( i * SIZE - 1, 0, i * SIZE - 1, HEIGHT * SIZE, 0xFF9400D3, ( 2, 0 ) );
	}
	//â°ê¸
	for( int i = 1; i < HEIGHT; i ++ )
	{
		MikanDraw->DrawLine( 0, i * SIZE - 1, WIDTH * SIZE, i * SIZE - 1, 0xFF9400D3, ( 0, 2 ) );
	}
}

void DrawStartX( int stX )
{
	MikanDraw->DrawLine( stX, 0, stX, HEIGHT * SIZE, 0xFFFFFF00 );
}

void DrawChoiced( int selL, int color )
{
	const int FrameSize = SIZE + 5 * 2;

	for( int i = 0; i < MaxColor + 3; i ++ )
	{
		if( i < MaxColor )
		{
			if( selL == i )
			{
				MikanDraw->DrawBox( WIDTH * SIZE - FrameSize * ( 2 - i % 2 ),
					FrameSize * ( i / 2 ), FrameSize, FrameSize, color );
				return;
			}
		}
		else
		{
			if( selL == 100 )
			{
				MikanDraw->DrawBox( WIDTH * SIZE - FrameSize * ( 2 - ( MaxColor + 0 ) % 2 ),
					FrameSize * ( ( MaxColor + 0 ) / 2 ), FrameSize, FrameSize, color );
				return;
			}
			else if( selL == -100 )
			{
				MikanDraw->DrawBox( WIDTH * SIZE - FrameSize * ( 2 - ( MaxColor + 1 ) % 2 ),
					FrameSize * ( ( MaxColor + 1 ) / 2 ), FrameSize, FrameSize, color );
				return;
			}
			else if( selL == -1 )
			{
				MikanDraw->DrawBox( WIDTH * SIZE - FrameSize * ( 2 - ( MaxColor + 2 ) % 2 ),
					FrameSize * ( ( MaxColor + 2 ) / 2 ), FrameSize, FrameSize, color );
				return;
			}
		}
	}
}
void DrawPalette( int selL, int selR )
{
	const int FrameSize = SIZE + 5 * 2;

	MikanDraw->DrawBox( WIDTH * SIZE - FrameSize * 2, 0,
		FrameSize * 2, FrameSize * ( ( MaxColor + 2 ) / 2 + 1 ), 0x770000FF );

	for( int i = 0; i < MaxColor + 3; i ++ )
	{
		MikanDraw->DrawTexture( 0, WIDTH * SIZE - FrameSize * ( 2 - i % 2 ),
			FrameSize * ( i / 2 ), 0, 0, SIZE + 5 * 2, SIZE + 5 * 2 );
	}

	DrawChoiced( selL, 0x77FF0000 );
	DrawChoiced( selR, 0x7700FF00 );


	for( int i = 0; i < MaxColor + 3; i ++ )
	{
		if( i < MaxColor )
		{
			MikanDraw->DrawTexture( 1, WIDTH * SIZE - FrameSize * ( 2 - i % 2 ) + 5,
				FrameSize * ( i / 2 ) + 5, i * SIZE, 0 * SIZE, SIZE, SIZE );
		}
		else
		{
			MikanDraw->DrawBox( WIDTH * SIZE - FrameSize * ( 2 - i % 2 ) + 5,
				FrameSize * ( i / 2 ) + 5, SIZE, SIZE, 0xFF000000 );

			if( i != MaxColor + 2 )
			{
				MikanDraw->DrawTexture( 0, WIDTH * SIZE - FrameSize * ( 2 - i % 2 ) + 5 + 5,
					FrameSize * ( i / 2 ) + 5 + 5, 42, 0, SIZE - 10, SIZE - 10 );

				if( i == MaxColor + 1 )
				{
					MikanDraw->DrawTexture( 0, WIDTH * SIZE - FrameSize * ( 2 - i % 2 ) + 5 + 5,
						FrameSize * ( i / 2 ) + 5 + 5, 42, 22, SIZE - 10, SIZE - 10 );
				}
			}
		}
	}
}

void DrawCoordinates( int scr )
{
	int x = MikanInput->GetMousePosX();
	int y = MikanInput->GetMousePosY();

	MikanDraw->DrawBox( 0, 0, 32 / 2 * 9, 32, 0xFFFFFFFF );
	MikanDraw->DrawBox( 1, 1, 32 / 2 * 9 - 2, 32 - 2, 0xFF000000 );

	if( 0 <= x &&
		x < WIDTH * SIZE &&
		0 <= y &&
		y < HEIGHT * SIZE )
	{
		MikanDraw->Printf( 0, 0, 0, "(%3d,%2d )", x / SIZE + scr + 1, y / SIZE + 1 );
	}
}


void Draw( int map[ MaxHei ][ MaxWid ], bool enemy[ MaxHei ][ MaxWid ], int scroll, int startX, int selectL, int selectR )
{
	DrawMap( map, scroll );
	DrawEnemy( enemy, scroll );
	DrawGrid();
	DrawStartX( startX );

	DrawCoordinates( scroll );
	DrawPalette( selectL, selectR );
}