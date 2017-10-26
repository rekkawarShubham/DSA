#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>


int TTS = 0 ;    // Time to Send
const int CELL = 16 ;
class Revolver ;
class Bullet	 ;
class BALL ;
int ID = 0 ;
int scoreEx = 0 ;
int HIGH = 0 ;

int NOB = 0 ;  // no of balls


typedef BALL* PBALL ;

PBALL ballhead = NULL ;
PBALL balltail = NULL ;
//PBALL start    = NULL ;

BALL* CreateNewBall ( int , int ) ;
void DeleteBall ( int BallID ) ;
void PreLoad () ;
void PostLoad () ;
int GetYourOption () ;

//void Value ( int & , int & , Revolver ) ;

// All Class Declaration

class Player
{
	char Name[20] ;
	char Nick[20] ;
	char Password[20] ;
	int  TotalPlay ;
	int  TotalScore ;
	int  HighestScore ;
	int  TotalFire ;
	int  Performance ;

	public :
		Player ( char * , char * , char * ) ;
		Player () {}
		~Player () { }
		void Display () ;
		int operator == ( char * ) ;
		void UpdateStats ( int score , int fire ) ;
		int  CheckForMatch ( char * ) ;

} ;

int Player :: CheckForMatch ( char * passwd )
{
	if ( strcmp ( this->Password , passwd ) == 0 )
		return 1 ;
	else
		return 0 ;
}

void Player :: UpdateStats ( int score , int fire )
{
	Player tempPlayer , tempPlayer1 ;
	fstream file , file1 , highscoreFile ;

	this->TotalPlay += 1 ;
	this->TotalScore += score ;
	this->TotalFire += fire ;

	if ( score > this->HighestScore )
		this->HighestScore = score ;

	if ( TotalScore != 0 && TotalFire != 0 )
		this->Performance = ( this->TotalScore / this->TotalFire ) * 10 ;
	else
		this->Performance = 0 ;

	int H , G;

	tempPlayer = Player ( this->Name , this->Nick , this->Password ) ;
	tempPlayer.TotalPlay = this->TotalPlay ;
	tempPlayer.TotalScore = this->TotalScore ;
	tempPlayer.TotalFire  = this->TotalFire ;
	tempPlayer.HighestScore = this->HighestScore ;
	tempPlayer.Performance = this->Performance ;

	H = this->HighestScore ;

	highscoreFile.open ( "High.dat" , ios::in | ios::binary ) ;
	highscoreFile.read ( ( char * ) & G , sizeof ( int ) ) ;
	highscoreFile.close () ;

	if ( H > G )
	{
		HIGH = 1 ;
		highscoreFile.open ( "High.dat" , ios::out | ios::binary ) ;
		highscoreFile.write ( ( char * ) & H , sizeof ( int ) ) ;
		highscoreFile.close () ;
	}

	//tempPlayer.Display () ;

	file.open ( "Player.dat" , ios::binary | ios::in ) ;
	file1.open ( "Player1.dat" , ios::out | ios::binary | ios::trunc ) ;
	file.seekg ( 0 , ios::beg ) ;

	while ( file.read ( ( char * ) & tempPlayer1 , sizeof ( Player ) ) )
	{
		if ( !tempPlayer1.CheckForMatch ( this->Password ) )
		{
			file1.write ( ( char *) & tempPlayer1 , sizeof ( Player )) ;
		}
	}
	file1.write ( ( char *) & tempPlayer , sizeof ( Player )) ;

	file.close () ;
	file1.close () ;

	file.open ( "Player.dat" , ios::binary | ios::out | ios::trunc  ) ;
	file1.open ( "Player1.dat" , ios::binary | ios::in ) ;

	while ( file1.read ( ( char * ) & tempPlayer1 , sizeof ( Player ) ) )
	{
		file.write ( ( char *) & tempPlayer1 , sizeof ( Player )) ;
	}
	file1.close () ;
	file.close () ;
	return ;
}


//Operator Overloading
int Player :: operator == ( char * passwd )
{
	if ( strcmp ( this->Password , passwd ) == 0 )
		return 1 ;
	else
		return 0 ;
}

Player :: Player ( char *name , char *nick , char *passwd )
{
	strcpy ( this->Name , name ) ;
	strcpy ( this->Nick , nick ) ;
	strcpy ( this->Password , passwd ) ;
	this->TotalScore  = 0 ;
	this->TotalPlay   = 0 ;
	this->HighestScore = 0 ;
	this->TotalFire   = 0 ;
	this->Performance = 0 ;  // (*this).Performnce = 0 ;
}

void Player :: Display ()
{
	cout.width( 40 ) ;
	cout.setf ( ios::left , ios::adjustfield ) ;
	cout << endl << "Name: " << this->Name << endl ;
	cout.width( 40 ) ;
	cout << endl << "Nickname: " << this->Nick << endl ;
	cout.width( 40 ) ;
	cout << endl << "Password: " << this->Password << endl ;
	cout.width( 40 ) ;
	cout << endl << "Total Score You Did Till Today:  " << this->TotalScore << endl ;
	cout.width ( 40 ) ;
	cout << endl << "Total No. of Games Played: " << this->TotalPlay << endl ;
	cout.width ( 40 ) ;
	cout << endl << "Your Highest Score: " << this->HighestScore << endl ;
	cout.width ( 40 ) ;
	cout << endl << "Total No. of Bullets Fired " << this->TotalFire << endl ;
	cout.width ( 40 ) ;
	cout << endl << "Your Performance: " << this->Performance << endl ;
	return ;
}


class BorderRectangle                 // To Display The Border of Play Area
{
	int left , right , top , bottom ;
	public:
		BorderRectangle ( int , int , int , int ) ;
		void ShowBorder ( ) ;
		void PutMatrix  ( ) ;
};

// Constructor to Display The Border Play Area

BorderRectangle :: BorderRectangle ( int Left , int Top , int Right , int Bottom )
{
	left   = Left ;
	top    = Top ;
	right  = Right ;
	bottom = Bottom ;
}

// Function of Class to Display The Border of Play Area

void BorderRectangle :: ShowBorder ()
{
	rectangle ( left , top  , right , bottom ) ;
}

void BorderRectangle :: PutMatrix ()
{
	int row = CELL ;
	int col = CELL ;

	for( int i = top  ; i <= bottom ; i += row )
	{
		line ( left , i , right , i ) ;
	}

	for ( int j = left ; j <= right ; j += col )
	{
		line ( j , top , j , bottom ) ;
	}
}

class BALL
{
	int cx ;
	//int cy ;
	int xspeed , yspeed ;
	public :
		int cy ;
		BALL *next ;
		int  ID ;
		BALL () {}
		void GetValues ( int  , int ) ;
		BALL ( int , int ) ;
		void EraseBall () ;
		void DrawBall () ;
		void MoveBallUp () ;
		friend int GetCY ( int , int & , int & ) ;
};

int GetCY ( int cy , int & CX , int & CY )
{
	PBALL start = ballhead ;
	//cout << "CY is  " << cy << endl ;
	int ret ;
   //	cout << "1st ball is " << ballhead->cy << endl ;
	while ( start != NULL )
	{
		if ( ( start->cy - 1 ) == cy )
		{
	 //		cout << "GotIT" << endl ;
			CX = start->cx ;
			CY = start->cy ;
			return ( start->ID ) ;
		}
		start = start->next ;
	}
	return 0 ;
}


BALL :: BALL ( int a ,int b )
{
	cx = a ;
	cy = b ;
}

void BALL :: GetValues ( int a , int b )
{
	cx = a ;
	cy = b ;
}

void BALL :: DrawBall ()
{
	line ( 562 , 50 , 562 , 450 ) ;
	line ( 50 , 50 , 562 , 50 ) ;
	line ( 50 , 450 , 562 , 450 ) ;

	circle ( cx , cy , CELL/2 ) ;

	setfillstyle ( SOLID_FILL , GREEN ) ;

	floodfill ( cx , cy , WHITE ) ;
}

void BALL :: MoveBallUp ()
{
	 EraseBall () ;

	 if ( ( cy - 8 ) == 50 )
	 {
		cy = 450 - 8 ;
		DrawBall () ;
		return ;
	 }

	 cx += 0 ;
	 cy -= CELL ;
	 DrawBall () ;
}

void BALL :: EraseBall ()
{

	int erLeft , erRight , erTop , erBottom ; // er for erase
	erLeft   = cx - ( CELL / 2 ) ;
	erRight  = cx + ( CELL / 2 ) ;
	erTop    = cy - ( CELL / 2 ) ;
	erBottom = cy + ( CELL / 2 ) ;

	setcolor ( BLUE ) ;  // Setting Drawing Color to Black for invisible Painting
	rectangle ( erLeft , erTop , erRight , erBottom ) ; // Drawing Invisible Rectangle

	setfillstyle ( 0 , BLACK ) ;
	floodfill ( cx , cy , BLUE ) ;

	setcolor ( BLACK ) ;
	rectangle ( erLeft , erTop , erRight , erBottom ) ;

	setcolor ( WHITE ) ;
}

class Bullet
{
	int cx , cy ;
	public :
		Bullet ( Revolver ) ;
		void DrawBullet ( Revolver ) ;
		void MoveBulletLeft ( Revolver  ) ;
		void EraseBullet () ;
		void CheckForTouch ( ) ;
};

class Revolver
{
	int left , right ,top ,bottom ;
	public:
		Revolver( int , int , int  , int );
		void DrawRevolver () ;
		void MoveRevolverUp ();
		void MoveRevolverDown () ;
		void EraseRevolver () ;
		friend void Bullet :: DrawBullet ( Revolver ) ;
		friend Bullet :: Bullet ( Revolver ) ;
};

Bullet :: Bullet ( Revolver rev )
{
	 cx = rev.right + 8 ;
	 cy = rev.top   + 4 + 3 ;
}

void Bullet :: DrawBullet ( Revolver rev  )
{
	setcolor ( RED ) ;
	setfillstyle ( SOLID_FILL , RED ) ;
	ellipse ( cx , cy , 0 , 360 , 8 , 3 ) ;
	floodfill ( cx , cy , RED ) ;
	setcolor ( WHITE ) ;
		MoveBulletLeft ( rev ) ;
}

void Bullet :: MoveBulletLeft ( Revolver rev )
{
	EraseBullet () ;
	cx += 1 ;
	CheckForTouch ( ) ;
	if( cx <= 700 )
	{
		DrawBullet ( rev ) ;
	}
}

void Bullet :: EraseBullet ()
{
	int erbLeft , erbRight , erbTop , erbBottom ;  // erb stands for eraseBulletEx
	erbLeft   = cx - 9 ;
	erbTop    = cy - 4 ;
	erbRight  = cx + 9 ;
	erbBottom = cy + 4 ;

	setcolor ( RED ) ;  // Setting Drawing Color to Black for invisible Painting
	rectangle ( erbLeft , erbTop , erbRight , erbBottom ) ; // Drawing Invisible Rectangle

	setfillstyle ( SOLID_FILL , BLACK ) ;

	floodfill ( cx , cy , RED ) ;

	setcolor ( BLACK ) ;
	rectangle ( erbLeft , erbTop , erbRight , erbBottom ) ;


	setcolor ( WHITE ) ;

	line ( 562 , 50 , 562 , 450 ) ;
}

void Bullet :: CheckForTouch ()
{
	int ballid ;
	int xb , yb ;

	if ( ( getpixel ( cx + 12 , cy ) == GREEN ))
	{

		//cout << "CY is " << cy << endl ;
		ballid = GetCY ( cy , xb , yb ) ;
		scoreEx += 5 ;
		DeleteBall ( ballid ) ;

		setfillstyle ( SOLID_FILL , BLACK ) ;

		floodfill ( xb , yb , WHITE ) ;

		setcolor ( BLACK ) ;

		circle ( xb , yb , CELL/2 ) ;

	   //	cout << "1" ;


		//cx = cx + CELL*2 ;

		//EraseBullet () ;
	   //	getch() ;
	}
}


Revolver :: Revolver ( int a , int b , int c, int d )
{
	left = a ;
	top = b ;
	right = c ;
	bottom = d ;
}

void Revolver :: DrawRevolver ()
{
	int P[18] = { 55 , top + 4 , (( 7 * CELL ) + 50) - 8 , top + 4 , (( 7 * CELL ) + 50) - 8 , top + 12 , ( 1 * CELL ) + 50 + 8 , top + 12 , 58 + 8 , bottom - 2 , 52 + 8 , bottom - 2 , 55 + 8 , top + 12 , 52 , top + 12 , 55 , top + 4 } ;

	setcolor ( BLUE ) ;
	drawpoly ( 9 , P ) ;

	setfillstyle ( SOLID_FILL , BLUE ) ;

	floodfill ( 70 , top + 11 , BLUE ) ;

	//putpixel ( 70 , top + 11 , RED );

	setcolor ( WHITE ) ;
}

void Revolver :: EraseRevolver ()
{
	setcolor ( BLACK ) ;
	for ( int i = 0 ; i < 32 ; i++ )
	{
		line ( left , i + top , right , i + top ) ;
	}
	setcolor ( WHITE ) ;
	line ( left , top , left , bottom ) ;

	if ( top == 50 )
	{
		line ( left , top , ( CELL * 7 ) + 50 , top ) ;
	}
}

void Revolver :: MoveRevolverUp ()
{
	if ( top == 50 )
		return ;
	EraseRevolver () ;
	top -= 16 ;
	bottom -= 16 ;
	DrawRevolver () ;
}


void Revolver :: MoveRevolverDown ()
{
	if ( bottom == 450 )
		return ;
	EraseRevolver () ;
	top += 16 ;
	bottom += 16 ;
	DrawRevolver () ;
}

class StatOfPlayer  ;

class CurrentScoreBox ;

class StatOfPlayer               // class for All statistics
{
	int BulletExsFired ;
	int TotalBulletExs ;
	int score ;
	public :
		StatOfPlayer ( int  , int ) ;
		void Update( int ) ;
		void UpdateScore ( CurrentScoreBox ) ;
		void DisplayScore () ;
		int GameIsNotOver () ;
};

class CurrentScoreBox
{
	int left , right , top , bottom ;
	char Title[10] ;
	int sbScore ;  // sb show box
	public:
		CurrentScoreBox ( int  , int , int , int , char * , int ) ;
		void DrawCurScoreBox () ;
		void Update_cs_Score ( int ) ;
		friend void StatOfPlayer :: UpdateScore ( CurrentScoreBox ) ;

};

StatOfPlayer :: StatOfPlayer ( int BF , int  TB )
{
	BulletExsFired = BF ;
	TotalBulletExs = TB ;
}

void StatOfPlayer :: Update ( int Inc )
{
	BulletExsFired += Inc ;
	return ;

}

int StatOfPlayer :: GameIsNotOver ()
{
	if ( BulletExsFired != TotalBulletExs )
		return (1) ;
	else
		return (0) ;
}

void StatOfPlayer :: UpdateScore ( CurrentScoreBox csBox )
{
	score = scoreEx ;
	csBox.Update_cs_Score( score ) ;
}

void StatOfPlayer :: DisplayScore ()
{
	cout << endl << "Total Socre is " << score << endl ;
}

CurrentScoreBox :: CurrentScoreBox ( int left ,int top , int right , int bottom , char *title , int InitScore )
{
	this->left = left ;
	this->right = right ;
	this->top = top ;
	this->bottom = bottom ;
	strcpy ( this->Title , title ) ;
	this->sbScore = InitScore ;
}

void CurrentScoreBox :: DrawCurScoreBox ()
{
	char buffer[10] ;
	setcolor ( YELLOW ) ;
	rectangle ( left , top , right ,bottom ) ;
	setcolor ( RED ) ;
	settextstyle ( 1 , 0 , 3 ) ;
	outtextxy ( left + 5 , top + 5 , this->Title ) ;
	sprintf ( buffer , "%d" , sbScore ) ;
	settextstyle ( 1 , 0 , 3 ) ;
	setcolor ( YELLOW ) ;
	outtextxy ( left + 80 , top + 5 , buffer ) ;
	setcolor ( WHITE ) ;
}

void CurrentScoreBox :: Update_cs_Score ( int Score )
{
	char buffer[10] ;
	setcolor ( RED ) ;
	rectangle ( left + 78 , 3 , right - 2 , bottom - 2 ) ;
	setfillstyle ( SOLID_FILL , BLACK ) ;
	floodfill ( left + 90 , 5 , RED ) ;
	setcolor ( BLACK ) ;
	rectangle ( left + 78 , 3 , right - 2 , bottom - 2 ) ;
	sprintf ( buffer , "%d" , Score ) ;
	settextstyle ( 1 , 0 , 3 ) ;
	setcolor ( YELLOW ) ;
	outtextxy ( left + 80 , top + 5 , buffer ) ;
	setcolor ( WHITE ) ;
}

class TimeBox
{
	int left , right , bottom , top , TimeLeft ;
	char Title[10] ;

	public:
		TimeBox ( int , int , int , int , char * , int ) ;
		void DrawTimeBox () ;
		void UpdateTime () ;
		void Update  ( int ) ;
};

TimeBox :: TimeBox ( int left , int top , int right, int bottom , char * title , int timeLeft )
{
	this->left = left ;
	this->right = right ;
	this->top = top ;
	this->bottom = bottom ;
	strcpy ( this->Title , title ) ;
	this->TimeLeft = timeLeft ;
}

void TimeBox :: DrawTimeBox ()
{
	char buffer[10] ;
	setcolor ( YELLOW ) ;
	rectangle ( left , top , right ,bottom ) ;
	setcolor ( RED ) ;
	settextstyle ( 1 , 0 , 3 ) ;
	outtextxy ( left + 5 , top + 5 , this->Title ) ;
	sprintf ( buffer , "%d" , TimeLeft ) ;
	settextstyle ( 1 , 0 , 3 ) ;
	setcolor ( YELLOW ) ;
	outtextxy ( left + 75 , top + 5 , buffer ) ;
	setcolor ( WHITE ) ;
}

void TimeBox :: Update ( int Score )
{
	char buffer[10] ;
	setcolor ( RED ) ;
	rectangle ( left + 73 , 3 , right - 2 , bottom - 2 ) ;
	setfillstyle ( SOLID_FILL , BLACK ) ;
	floodfill ( left + 80 , 5 , RED ) ;
	setcolor ( BLACK ) ;
	rectangle ( left + 73 , 3 , right - 2 , bottom - 2 ) ;
	sprintf ( buffer , "%d" , Score ) ;
	settextstyle ( 1 , 0 , 3 ) ;
	setcolor ( YELLOW ) ;
	outtextxy ( left + 80 , top + 5 , buffer ) ;
	setcolor ( WHITE ) ;

}

class HighScoreBox
{
	int left , top , right , bottom , HighScore ;
	char Title[20] ;
	public:
		HighScoreBox ( int , int , int , int , char * , int ) ;
		void DrawHighScoreBox () ;
};

HighScoreBox :: HighScoreBox ( int left , int top , int right , int bottom , char * title , int highScore )
{
	this->left = left ;
	this->right = right ;
	this->top = top ;
	this->bottom = bottom ;
	strcpy ( this->Title , title ) ;
	this->HighScore = highScore ;
}

void HighScoreBox :: DrawHighScoreBox ()
{
	char buffer[10] ;
	setcolor ( YELLOW ) ;
	rectangle ( left , top , right ,bottom ) ;
	setcolor ( RED ) ;
	settextstyle ( 1 , 0 , 3 ) ;
	outtextxy ( left + 5 , top + 5 , this->Title ) ;
	sprintf ( buffer , "%d" , HighScore ) ;
	settextstyle ( 1 , 0 , 3 ) ;
	setcolor ( YELLOW ) ;
	outtextxy ( left + 130 , top + 5 , buffer ) ;
	setcolor ( WHITE ) ;
}

int main ()
{
	char buffer[100] ;
	int gd=DETECT , gm ;
	int PlayStart ;
	int keyPress = 0 ;
	int randValx ;
	initgraph(&gd ,&gm ,"") ;

	getch() ;

	PreLoad () ;

	int Status = 0 ;
	int times = 0 ;
	int option ;
	fstream file ;
	Player NewPlayer ;
	int Wait ;
	char ch ;

MainPage:

	cleardevice () ;
	setcolor ( BLUE ) ;

	rectangle ( 5 , 5 , 600 , 470 ) ;

	settextstyle ( 1 , 0 , 2 ) ;

	char ign[20] ;

	char c = 64 ;

	setcolor ( YELLOW ) ;

	setcolor  ( GREEN ) ;
	settextstyle ( 5 , 0 , 4 ) ;

	sprintf ( buffer , "Follow the Instruction and " ) ;
	outtextxy ( 100 , 20 , buffer ) ;

	sprintf ( buffer , "Press the Right Key to Play" ) ;
	outtextxy ( 100 , 50 , buffer ) ;

	setcolor ( BROWN ) ;
	settextstyle ( 3 , 0 , 2 ) ;

	sprintf ( buffer , "1:Sign Up ( New Players )" ) ;
	outtextxy ( 10, 100 + 50 , buffer ) ;

	sprintf ( buffer , "2:Sign In ( Existing Players)" ) ;
	outtextxy ( 10 , 130 + 50 , buffer ) ;

	sprintf ( buffer , "3:Details of Your Account" ) ;
	outtextxy ( 10 , 160 + 50 , buffer ) ;

	sprintf ( buffer , "4:Instructions How To Play" ) ;
	outtextxy ( 10 , 190 + 50 , buffer ) ;

	sprintf ( buffer , "5:About" ) ;
	outtextxy ( 10 , 210 + 50 , buffer ) ;

	sprintf ( buffer , "6:Acknowledgement" ) ;
	outtextxy ( 10 , 240 + 50 , buffer ) ;

	sprintf ( buffer , "7:Exit" ) ;
	outtextxy ( 10 , 270 + 50 , buffer ) ;

	sprintf ( buffer , " Enter Your Choice            : " ) ;
	outtextxy ( 10 , 300 + 42 , buffer ) ;

	setcolor ( WHITE ) ;

	gotoxy ( 45 , 23 ) ;
	cin >> option ;

	cleardevice () ;

	switch ( option )
	{
	char passwd[20] ;
	case 1:
			char name[20] ;
			char nick[20] ;
			char passwdVer[20] ;
			cout.width ( 25 ) ;
			cout.setf ( ios::left , ios::adjustfield ) ;

			//setcolor  ( YELLOW ) ;
			//settextstyle ( 3 , 0 , 2 ) ;

			gotoxy ( 20 , 2 ) ;
			cout << endl <<  "Enter Your Name : " ;
			cin.ignore () ;
			cin.getline ( name , 20 ) ;
			//gotoxy ( 40 , 2 ) ;
			//cin >> name ;
			cout.width ( 25 ) ;

			//sprintf ( buffer , "Enter Your Nickname" ) ;
			//outtextxy ( 10 , 40 , buffer ) ;
			cout << endl << "Enter Your Nickname : ";
			//fflush ( stdin ) ;
			//cin.ignore () ;
			cin.getline ( nick , 20 ) ;
			//gotoxy ( 40 , 4 ) ;
			//cin >> nick ;
			AgainPasswd:
			cout.width ( 25 ) ;
			//sprintf ( buffer , "Enter Password" ) ;
			//outtextxy ( 10 , 70 , buffer ) ;
			cout << endl << "Enter Password : " ;
			//gotoxy ( 40 , 6 ) ;
			//cin >> passwd ;
			cin.getline ( passwd , 20 ) ;
			cout.width ( 25 ) ;
			//sprintf ( buffer , "Enter Password Again" ) ;
			//outtextxy ( 10 , 100 , buffer ) ;
			cout << endl << "Enter Password Again : ";
			//gotoxy ( 40 , 8 ) ;
			//cin >> passwdVer ;
			cin.getline ( passwdVer , 20 ) ;
			if ( strcmp ( passwdVer , passwd ) != 0 )
			{
				times++ ;
				if ( times == 3 )
				{
					cout << endl << "Entered Maximum Times of Password Failure Sorry Please Retry " << endl ;
					getch () ;
					goto MainPage ;
				}
				cout << "Both The Passwords do not Match Try Again " << endl ;
				goto AgainPasswd ;
			}

			file.open ( "Player.dat" , ios::out | ios::binary | ios::app ) ;

			NewPlayer = Player ( name , nick , passwd ) ;

			file.write ( ( char *) & NewPlayer , sizeof ( Player ) ) ;

			file.close () ;

			break ;
	case 2:
		gotoxy ( 2 , 2 ) ;
		cout << endl << "Please Enter Your Password : " ;
		cin >> passwd ;

			file.open ( "Player.dat" , ios::in | ios::binary ) ;

			while ( file.read ( ( char *) & NewPlayer , sizeof ( Player ) ) )
			{
				if ( NewPlayer == passwd )
				{
					Status = 1 ;
					cout << endl ;
					NewPlayer.Display () ;
					cout << endl ;
					getch () ;
					goto PLAYTIME ;
				}
			}
			if ( Status == 0 )
			{
				cout << endl << "Sorry No Account " << endl ;
				cout << endl << "Create Your Account By Sign In ( Option 1 ) and Start Playing " << endl ;
				getch () ;
				file.close () ;
				goto MainPage ;
			}
			file.close () ;
			getch () ;
			break ;
	case 3:
			gotoxy ( 2 , 2 ) ;
			cout << "Enter Your Password : " ;
			cin >> passwd ;
			file.open ( "Player.dat" , ios::in | ios::binary ) ;

			while ( file.read ( ( char *) & NewPlayer , sizeof ( Player ) ) )
			{
				if ( NewPlayer == passwd )
				{
					NewPlayer.Display () ;
					break ;
				}
			}
			file.close () ;
			getch () ;
			break ;
	case 4:

		gotoxy ( 2 ,2 ) ;
		file.open ( "Project4.txt" , ios::in ) ;
		file.seekg ( 0 , ios::beg ) ;

		while ( !file.eof() )
		{
			file.get(ch);
			cout << ch  ;
		}
		file.close () ;
		getch () ;
		break ;
	case 5:
		gotoxy ( 2 , 2 ) ;
		file.open ( "Project5.txt" , ios::in ) ;
		file.seekg ( 0 , ios::beg ) ;

		while ( !file.eof() )
		{
			file.get(ch) ;
			cout << ch ;
		}
		file.close () ;
		getch () ;
		break ;
	case 6:
		gotoxy ( 2 , 2 ) ;
		file.open ( "Project6.txt" , ios::in ) ;
		file.seekg ( 0 , ios::beg ) ;

		while ( !file.eof() )
		{
			file.get(ch) ;
			cout << ch ;
		}
		file.close () ;
		getch () ;
		break ;

	case 7:
		getch () ;
		exit ( 0 ) ;

	}
	goto MainPage ;

	EXIT1:

	cout << c ;
	cleardevice () ;

	setcolor  ( GREEN ) ;
	settextstyle ( 1 , 0 , 2 ) ;

	PLAYTIME:

	int fire = 0 ;


	PlayStart = 100 ;

	cleardevice () ;

	randValx = ( rand () % 10 ) + 22 ;

	int valx = ( ( 16 * randValx ) - ( CELL / 2 ) ) + 50 ;
	int valy = ( ( 16 * 23 ) - ( CELL / 2 ) ) + 50 ;


	ballhead = CreateNewBall (valx , valy ) ; // new BALL( 200 , 200 ) ;

	BorderRectangle brdRect ( 50 , 50 , 562 , 450 ) ;

	int iRandN = rand () % 23 ;

	Revolver rev = Revolver ( 50 , ( iRandN * CELL ) + 50 , ( 7 * CELL ) + 50 , ( ( iRandN + 2 ) * CELL ) + 50 );

	brdRect.ShowBorder() ;

	CurrentScoreBox scoreBox = CurrentScoreBox ( 60 , 2 , 60 + 150 , 48 , "Score" , 0 ) ;
	scoreBox.DrawCurScoreBox () ;

	TimeBox timeBox = TimeBox ( 60 + 170 , 2 , 60 + 170 + 120 , 48 , "Bullet" , PlayStart ) ;
	timeBox.DrawTimeBox () ;

	int H = 0  ;

	fstream highscoreFile ;

	highscoreFile.open ( "High.dat" , ios::in | ios::binary ) ;
	highscoreFile.read ( ( char * ) & H , sizeof ( int ) ) ;
	highscoreFile.close () ;

	HighScoreBox highScoreBox = HighScoreBox ( 60 + 170 + 120 + 20 , 2 , 562 - 5 , 48 , "High Score" , H ) ;
	highScoreBox.DrawHighScoreBox () ;

	c = 3 ;

	brdRect.PutMatrix () ;
	PBALL start = NULL ;
	start = ballhead ;

	while ( start != NULL )
	{
		start->DrawBall () ;
		start = start->next ;
	}

	rev.DrawRevolver () ;

	StatOfPlayer stat ( 0 , PlayStart ) ;
	char IP ;     // Input variable

 //	int ia = ( 7 * CELL ) + 50 ;
  //	int ib = ( 2 * CELL ) + 50 ;

	int TTStarget , BulletRem = PlayStart ;

	while ( stat.GameIsNotOver () )
	{
		if( !kbhit () )
		{
			delay ( 300 ) ;
			start = ballhead ;

			start = ballhead ;
			while ( start != NULL )
			{
				//cout << "\t" << start->ID  ;
				start->MoveBallUp () ;
				start = start->next ;
			}
		}
		else
		{
			keyPress ++ ;

			if ( keyPress == TTS )
			{
				srand ( time( NULL ) );
				randValx = ( rand () % 10 ) + 22 ;
				valx = ( ( 16 * randValx ) - ( CELL / 2 ) ) + 50 ;

				ballhead = CreateNewBall ( valx , valy ) ;
				keyPress = 0 ;
			}

			IP = getch () ;

			switch ( IP )
			{
			case '8':
			case 'u':
			case 'w':
				rev.MoveRevolverUp () ;
				break ;
			case '2':
			case 'd':
			case 's':
				rev.MoveRevolverDown () ;
				break ;
			case '5':
				fire++ ;
				Bullet bullT ( rev ) ;
				bullT.DrawBullet ( rev ) ;
				bullT.EraseBullet () ;
				stat.Update(1) ;
				BulletRem -= 1 ;
				timeBox.Update ( BulletRem ) ;
				stat.UpdateScore ( scoreBox ) ;
				break ;
			case 'q':
				goto EXIT ;
			}
		}
	}

	EXIT:

	settextstyle ( 4 , 0 , 7 ) ;
	setcolor ( GREEN ) ;
	sprintf ( buffer , "%s" , "GAME OVER" ) ;
	outtextxy ( 70 , 100 , buffer ) ;

	sleep ( 2 ) ;

	cleardevice () ;


	NewPlayer.UpdateStats ( ::scoreEx , fire ) ;

	getch () ;

	PostLoad () ;

   /*	start = ballhead ;

	while ( start != NULL )
	{
		cout << endl << " ID " << start->ID << endl ;
		start = start->next ;

	}

	stat.DisplayScore () ;
	getch () ;  */

	return 0 ;
}

BALL* CreateNewBall ( int valx , int valy )
{
	/*NOB = NOB + 1 ;
	if ( NOB >= 5 )
	{
		return ( ballhead ) ;
	}            */
	ID = ID + 1 ;

	TTS = ( rand () % 20 ) + 1 ;
	//cout << "TTS is " << TTS << endl ;

	BALL *newB ;
	newB = new BALL ;
	newB->GetValues ( valx , valy ) ;

	if ( ballhead == NULL )
	{
	   //	cout << "GUY "   ;
		ballhead = balltail = newB ;
	}

	else
	{
	   //	cout << "Boy " ;
		balltail->next = newB ;
		balltail = newB ;
	}

	balltail->next = NULL ;
	balltail->ID = ID ;
	return ( ballhead ) ;
}


void DeleteBall ( int BallID )
{
	NOB-- ;

	PBALL start  = ballhead ;
	PBALL delM = NULL ;

	if  ( ballhead == NULL )
		return ;

	if ( start->ID  == BallID )
	{
		if ( start == balltail )
			balltail = NULL ;
		delM = start ;
		start = start->next ;
		delete delM ;
		ballhead = start ;
		return ;
	}

	while ( start->next != NULL )
	{
		if ( start->next->ID != BallID )
		{
			start = start->next ;
		}
		else
			break ;
	}

	if ( start != balltail )
	{
		delM = start->next ;
		if ( delM->next == NULL )
			balltail = start ;
		start->next = delM->next ;
		delete delM ;
		return ;
	}

	return ;

}

void PreLoad ()
{
	srand (time(NULL)) ;

	cleardevice () ;

	setcolor ( BLUE ) ;

	rectangle ( 5 , 5 , 600 , 470 ) ;

	settextstyle ( 1 , 0 , 2 ) ;

	char buffer[100] ;

	char c = 64 ;

	setcolor ( YELLOW ) ;

	sprintf ( buffer ," %c  %s" , c , " Mr.Suryaa" ) ;
	outtextxy ( 8 , 2 , buffer ) ;

	sprintf ( buffer , "%s" , "Version 0.7" ) ;
	outtextxy ( 470 , 2  , buffer ) ;

	settextstyle ( 4 , 0 , 7 ) ;
	setcolor ( GREEN ) ;
	sprintf ( buffer , "%s" , "Gun - Ball Battle" ) ;
	outtextxy ( 70 , 100 , buffer ) ;

	settextstyle ( 1 , 0 , 3 ) ;
	sprintf ( buffer , "%s" , "With Love For MS" ) ;
	outtextxy ( 200 , 200 , buffer ) ;

	settextstyle ( 1 , 0 , 1 ) ;
	setcolor ( YELLOW ) ;
	outtextxy ( 8 , 300 , "Press Any Key" ) ;
	outtextxy ( 8 , 340 , "To Start The Game... ") ;

	getch () ;

	setcolor ( RED ) ;
	outtextxy ( 250 , 370 , "Loading..." ) ;
	setcolor ( YELLOW ) ;
	rectangle ( 200 , 400 , 400 , 410 ) ;

	int max = ( rand () % 200 ) + 200 ;
	for ( int i = 200 ; i < max; i++ )
	{
		line ( i , 400 , i , 410 ) ;
	}
	delay ( 300 ) ;
	for ( i = max ; i < 400 ; i++ )
	{
		line ( i , 400 , i , 410 ) ;
	}

	delay ( 300 ) ;

	setcolor ( WHITE ) ;
	cleardevice () ;

	return ;
}

void PostLoad ()
{
	char buffer[100] ;
	char c = 64 ;
	setcolor ( BLUE ) ;

	rectangle ( 5 , 5 , 600 , 470 ) ;

	settextstyle ( 1 , 0 , 2 ) ;

	setcolor ( YELLOW ) ;

	sprintf ( buffer ," %c  %s" , c , " Mr.Suryaa" ) ;
	outtextxy ( 8 , 2 , buffer ) ;

	sprintf ( buffer , "%s" , "Version 0.7" ) ;
	outtextxy ( 470 , 2  , buffer ) ;

	if ( HIGH == 1 )
	{
		settextstyle ( 3 , 0 , 2 ) ;
		setcolor ( RED ) ;
		sprintf ( buffer , "%s" , "Congratulationns You Have Beaten The High Score" ) ;
		outtextxy ( 10 , 40 , buffer ) ;
	}

	settextstyle ( 4 , 0 , 7 ) ;
	setcolor ( GREEN ) ;
	sprintf ( buffer , "%s" , "GAME OVER" ) ;
	outtextxy ( 70 , 100 , buffer ) ;

	settextstyle ( 1 , 0 , 3 ) ;
	sprintf ( buffer , "%s" , "With Love For MS" ) ;
	outtextxy ( 200 , 200 , buffer ) ;

	setcolor ( RED ) ;
	outtextxy ( 250 , 300 , "Exiting..." ) ;
	setcolor ( YELLOW ) ;
	rectangle ( 200 , 340 , 400 , 350 ) ;

	int max = ( rand () % 200 ) + 200 ;
	for ( int i = 200 ; i < max; i++ )
	{
		line ( i , 340 , i , 350 ) ;
	}
	delay ( 300 ) ;
	for ( i = max ; i < 400 ; i++ )
	{
		line ( i , 340 , i , 350 ) ;
	}

	delay ( 300 ) ;

	settextstyle ( 1 , 0 , 1 ) ;
	setcolor ( YELLOW ) ;
	outtextxy ( 8 , 380 , "Thanks For Playing" ) ;
	outtextxy ( 8 , 400 , " Press Any To EXIT ") ;

	getch () ;

	setcolor ( WHITE ) ;
	cleardevice () ;

}
