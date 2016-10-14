#include "common.h"

void Reset( int map[ MaxHei ][ MaxWid ], bool enemy[ MaxHei ][ MaxWid ] )
{
	if( MikanInput->GetKeyNum( K_R ) == 60 )
	{
		for( int i = 0; i < MaxHei; i ++ )
		{
			for( int j = 0; j < MaxWid; j ++ )
			{
				map[ i ][ j ] = -1;
				enemy[ i ][ j ] = false;
			}
		}
	}

	if( MikanInput->GetKeyNum( K_R ) >= 60 )
	{
		MikanDraw->DrawBox( 0, 0, 64 / 2 * 8, 64, 0xFFFFFFFF );
		MikanDraw->Printf( 1, 0, 0, "Reseted!" );
	}
}

void Save( int map[ MaxHei ][ MaxWid ], bool enemy[ MaxHei ][ MaxWid ] )
{
	if( MikanInput->GetKeyNum( K_S ) == 60 )
	{
		FILE *fp;

		//ステージ上のブロックの状態
		fp = fopen( "stage.csv", "w" );
		if( fp == NULL )
		{
			return;
		}

		for( int i = 0; i < MaxHei; i ++ )
		{
			for( int j = 0; j < MaxWid - 1; j ++ )
			{
				fprintf( fp, "%d,", map[ i ][ j ] );
			}
			fprintf( fp, "%d\n", map[ i ][ MaxWid - 1 ] );
		}

		fclose( fp );


		//ステージ上の敵の状態
		fp = fopen( "enemy.csv", "w" );
		if( fp == NULL )
		{
			return;
		}

		for( int i = 0; i < MaxHei; i ++ )
		{
			for( int j = 0; j < MaxWid - 1; j ++ )
			{
				fprintf( fp, "%d,", enemy[ i ][ j ] );
			}
			fprintf( fp, "%d\n", enemy[ i ][ MaxWid - 1 ] );
		}

		fclose( fp );
	}

	if( MikanInput->GetKeyNum( K_S ) >= 60 )
	{
		MikanDraw->DrawBox( 0, 0, 64 / 2 * 6, 64, 0xFFFFFFFF );
		MikanDraw->Printf( 1, 0, 0, "Saved!" );
	}
}

void Load( int map[ MaxHei ][ MaxWid ], bool enemy[ MaxHei ][ MaxWid ] )
{
	if( MikanInput->GetKeyNum( K_L ) == 60 )
	{
		FILE *fp;

		fp = fopen( "stage.csv", "r" );
		if( fp == NULL )
		{
			return;
		}

		for( int i = 0; i < MaxHei; i ++ )
		{
			fscanf( fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
				&map[ i ][ 0 ],	&map[ i ][ 1 ],	&map[ i ][ 2 ],	&map[ i ][ 3 ],	&map[ i ][ 4 ],	&map[ i ][ 5 ],	&map[ i ][ 6 ],	&map[ i ][ 7 ],	&map[ i ][ 8 ],	&map[ i ][ 9 ],	&map[ i ][ 10 ],	&map[ i ][ 11 ],	&map[ i ][ 12 ],	&map[ i ][ 13 ],	&map[ i ][ 14 ],	&map[ i ][ 15 ],	&map[ i ][ 16 ],	&map[ i ][ 17 ],	&map[ i ][ 18 ],	&map[ i ][ 19 ],	&map[ i ][ 20 ],	&map[ i ][ 21 ],	&map[ i ][ 22 ],	&map[ i ][ 23 ],	&map[ i ][ 24 ],	&map[ i ][ 25 ],	&map[ i ][ 26 ],	&map[ i ][ 27 ],	&map[ i ][ 28 ],	&map[ i ][ 29 ],	&map[ i ][ 30 ],	&map[ i ][ 31 ],	&map[ i ][ 32 ],	&map[ i ][ 33 ],	&map[ i ][ 34 ],	&map[ i ][ 35 ],	&map[ i ][ 36 ],	&map[ i ][ 37 ],	&map[ i ][ 38 ],	&map[ i ][ 39 ],	&map[ i ][ 40 ],	&map[ i ][ 41 ],	&map[ i ][ 42 ],	&map[ i ][ 43 ],	&map[ i ][ 44 ],	&map[ i ][ 45 ],	&map[ i ][ 46 ],	&map[ i ][ 47 ],	&map[ i ][ 48 ],	&map[ i ][ 49 ],	&map[ i ][ 50 ],	&map[ i ][ 51 ],	&map[ i ][ 52 ],	&map[ i ][ 53 ],	&map[ i ][ 54 ],	&map[ i ][ 55 ],	&map[ i ][ 56 ],	&map[ i ][ 57 ],	&map[ i ][ 58 ],	&map[ i ][ 59 ],	&map[ i ][ 60 ],	&map[ i ][ 61 ],	&map[ i ][ 62 ],	&map[ i ][ 63 ],	&map[ i ][ 64 ],	&map[ i ][ 65 ],	&map[ i ][ 66 ],	&map[ i ][ 67 ],	&map[ i ][ 68 ],	&map[ i ][ 69 ],	&map[ i ][ 70 ],	&map[ i ][ 71 ],	&map[ i ][ 72 ],	&map[ i ][ 73 ],	&map[ i ][ 74 ],	&map[ i ][ 75 ],	&map[ i ][ 76 ],	&map[ i ][ 77 ],	&map[ i ][ 78 ],	&map[ i ][ 79 ],	&map[ i ][ 80 ],	&map[ i ][ 81 ],	&map[ i ][ 82 ],	&map[ i ][ 83 ],	&map[ i ][ 84 ],	&map[ i ][ 85 ],	&map[ i ][ 86 ],	&map[ i ][ 87 ],	&map[ i ][ 88 ],	&map[ i ][ 89 ],	&map[ i ][ 90 ],	&map[ i ][ 91 ],	&map[ i ][ 92 ],	&map[ i ][ 93 ],	&map[ i ][ 94 ],	&map[ i ][ 95 ],	&map[ i ][ 96 ],	&map[ i ][ 97 ],	&map[ i ][ 98 ],	&map[ i ][ 99 ] );
		}

		fclose( fp );


		fp = fopen( "enemy.csv", "r" );
		if( fp == NULL )
		{
			return;
		}

		for( int i = 0; i < MaxHei; i ++ )
		{
			fscanf( fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
				&enemy[ i ][ 0 ],	&enemy[ i ][ 1 ],	&enemy[ i ][ 2 ],	&enemy[ i ][ 3 ],	&enemy[ i ][ 4 ],	&enemy[ i ][ 5 ],	&enemy[ i ][ 6 ],	&enemy[ i ][ 7 ],	&enemy[ i ][ 8 ],	&enemy[ i ][ 9 ],	&enemy[ i ][ 10 ],	&enemy[ i ][ 11 ],	&enemy[ i ][ 12 ],	&enemy[ i ][ 13 ],	&enemy[ i ][ 14 ],	&enemy[ i ][ 15 ],	&enemy[ i ][ 16 ],	&enemy[ i ][ 17 ],	&enemy[ i ][ 18 ],	&enemy[ i ][ 19 ],	&enemy[ i ][ 20 ],	&enemy[ i ][ 21 ],	&enemy[ i ][ 22 ],	&enemy[ i ][ 23 ],	&enemy[ i ][ 24 ],	&enemy[ i ][ 25 ],	&enemy[ i ][ 26 ],	&enemy[ i ][ 27 ],	&enemy[ i ][ 28 ],	&enemy[ i ][ 29 ],	&enemy[ i ][ 30 ],	&enemy[ i ][ 31 ],	&enemy[ i ][ 32 ],	&enemy[ i ][ 33 ],	&enemy[ i ][ 34 ],	&enemy[ i ][ 35 ],	&enemy[ i ][ 36 ],	&enemy[ i ][ 37 ],	&enemy[ i ][ 38 ],	&enemy[ i ][ 39 ],	&enemy[ i ][ 40 ],	&enemy[ i ][ 41 ],	&enemy[ i ][ 42 ],	&enemy[ i ][ 43 ],	&enemy[ i ][ 44 ],	&enemy[ i ][ 45 ],	&enemy[ i ][ 46 ],	&enemy[ i ][ 47 ],	&enemy[ i ][ 48 ],	&enemy[ i ][ 49 ],	&enemy[ i ][ 50 ],	&enemy[ i ][ 51 ],	&enemy[ i ][ 52 ],	&enemy[ i ][ 53 ],	&enemy[ i ][ 54 ],	&enemy[ i ][ 55 ],	&enemy[ i ][ 56 ],	&enemy[ i ][ 57 ],	&enemy[ i ][ 58 ],	&enemy[ i ][ 59 ],	&enemy[ i ][ 60 ],	&enemy[ i ][ 61 ],	&enemy[ i ][ 62 ],	&enemy[ i ][ 63 ],	&enemy[ i ][ 64 ],	&enemy[ i ][ 65 ],	&enemy[ i ][ 66 ],	&enemy[ i ][ 67 ],	&enemy[ i ][ 68 ],	&enemy[ i ][ 69 ],	&enemy[ i ][ 70 ],	&enemy[ i ][ 71 ],	&enemy[ i ][ 72 ],	&enemy[ i ][ 73 ],	&enemy[ i ][ 74 ],	&enemy[ i ][ 75 ],	&enemy[ i ][ 76 ],	&enemy[ i ][ 77 ],	&enemy[ i ][ 78 ],	&enemy[ i ][ 79 ],	&enemy[ i ][ 80 ],	&enemy[ i ][ 81 ],	&enemy[ i ][ 82 ],	&enemy[ i ][ 83 ],	&enemy[ i ][ 84 ],	&enemy[ i ][ 85 ],	&enemy[ i ][ 86 ],	&enemy[ i ][ 87 ],	&enemy[ i ][ 88 ],	&enemy[ i ][ 89 ],	&enemy[ i ][ 90 ],	&enemy[ i ][ 91 ],	&enemy[ i ][ 92 ],	&enemy[ i ][ 93 ],	&enemy[ i ][ 94 ],	&enemy[ i ][ 95 ],	&enemy[ i ][ 96 ],	&enemy[ i ][ 97 ],	&enemy[ i ][ 98 ],	&enemy[ i ][ 99 ] );
		}

		fclose( fp );
	}

	if( MikanInput->GetKeyNum( K_L ) >= 60 )
	{
		MikanDraw->DrawBox( 0, 0, 64 / 2 * 7, 64, 0xFFFFFFFF );
		MikanDraw->Printf( 1, 0, 0, "Loaded!" );
	}
}


void Menu( int map[ MaxHei ][ MaxWid ], bool enemy[ MaxHei ][ MaxWid ] )
{
	Reset( map, enemy );
	Save( map, enemy );
	Load( map, enemy );
}