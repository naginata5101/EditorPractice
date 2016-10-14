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


//�v���O�����N������1�x�������s
//�V�X�e���ݒ�Ȃǂ��s��
void SystemInit( void )
{
	MikanWindow->SetWindowName( "Editor" );
	MikanWindow->SetWindowIcon( "GAME_ICON" );
}

//MainLoop�J�n�O��1�x�������s
//�e�N�X�`���̓ǂݍ��݂Ȃǂ̃Q�[���J�n�O�̏������s��
void UserInit( void )
{
	MikanDraw->CreateFont( 0, "�l�r �S�V�b�N", 32, 0xFFFFFF00 );
	MikanDraw->CreateFont( 1, "�l�r �S�V�b�N", 64, 0xFF00EE00 );
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

//1�b�Ԃ�60����s
//0��Ԃ��Ă���Ԃ͉��x�ł����s�����
int MainLoop( void )
{
	//��ʂ̏�����
	MikanDraw->ClearScreen();

	Move( map, enemy, &scroll, &startX, &clickX, &clickY, &selectL, &selectR );
	Draw( map, enemy, scroll, startX, selectL, selectR );
	Menu( map, enemy );

	return Escape();
}

//MainLoop�I�����1�x�������s
//��Еt���Ȃǂ��s��
void CleanUp( void )
{
}