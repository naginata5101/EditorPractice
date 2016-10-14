#include "common.h"

int map[ MaxHei ][ MaxWid ];
bool enemy[ MaxHei ][ MaxWid ];
int scroll = 0, startX = -10;
int clickX, clickY;

//put enemy == 100
//remove enemy == -100
int selectL = 0, selectR = -1;

void Move( int map[ MaxHei ][ MaxWid ], bool enemy[ MaxHei ][ MaxWid ], int *scroll, int *startX, int *cliX, int *cliY, int *selectL, int *selectR );
void Draw( int map[ MaxHei ][ MaxWid ], bool enemy[ MaxHei ][ MaxWid ], int scroll, int startX, int selectL, int selectR );
void Menu( int map[ MaxHei ][ MaxWid ], bool enemy[ MaxHei ][ MaxWid ] );


int Escape()
{
	if( MikanInput->GetKeyNum( K_ESC ) > 0 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//プログラム起動時に1度だけ実行
//システム設定などを行う
void SystemInit( void )
{
	MikanWindow->SetWindowName( "Editor" );
	MikanWindow->SetWindowIcon( "GAME_ICON" );
}

//MainLoop開始前に1度だけ実行
//テクスチャの読み込みなどのゲーム開始前の準備を行う
void UserInit( void )
{
	MikanDraw->CreateFont( 0, "ＭＳ ゴシック", 32, 0xFFFFFF00 );
	MikanDraw->CreateFont( 1, "ＭＳ ゴシック", 64, 0xFF00EE00 );
	MikanDraw->CreateTexture( 0, "frame.png", 0xFFFFFFFF );
	MikanDraw->CreateTexture( 1, "map.png", TRC_ZERO );

	for( int i = 0; i < MaxHei; i ++ )
	{
		for( int j = 0; j < MaxWid; j ++ )
		{
			map[ i ][ j ] = -1;
			enemy[ i ][ j ] = false;
		}
	}
}

//1秒間に60回実行
//0を返している間は何度でも実行される
int MainLoop( void )
{
	//画面の初期化
	MikanDraw->ClearScreen();

	Move( map, enemy, &scroll, &startX, &clickX, &clickY, &selectL, &selectR );
	Draw( map, enemy, scroll, startX, selectL, selectR );
	Menu( map, enemy );

	return Escape();
}

//MainLoop終了後に1度だけ実行
//後片付けなどを行う
void CleanUp( void )
{
}