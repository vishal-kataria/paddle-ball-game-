#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <bios.h>
#include <stdlib.h>
#define RT 19712
#define LT 19200
#define UP 18432
#define DN 20480
#define A 7745
#define a 7777
#define D 8260
#define d 8292
#define ESC 283
void loading();
void start();
void end();
void main()
{
//char player1[10],player2[10];
int score1=0,score2=0;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	loading();
	closegraph();

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	clearviewport();

	start();
	clearviewport();
	setcolor(CYAN);
	settextstyle(TRIPLEX_FONT,0,5);
	outtextxy(100,100,"PADDLE BALL GAME!!");

	setcolor(MAGENTA);
	line(100,150,510,150);
	line(100,155,510,155);


int x=200,y=200,dx=1,dy=1;
int b=0;
int key=0,key1=0;
int dec;
{


//outer main square
int array1[]={2,2,627,2,627,457,2,457,2,2};
setcolor(CYAN);
setfillstyle(SOLID_FILL,BROWN);
fillpoly(5,array1);

//inner main square
int array2[]={10,10,620,10,620,450,10,450,10,10};
setfillstyle(SOLID_FILL,0);
fillpoly(5,array2);



//introduction

	clearviewport();
	rectangle(1,1,638,478);
	setcolor(14);
	settextstyle(8,0,1);
	setusercharsize(55,30,50,30);
	outtextxy(110,30,"INSTRUCTIONS");
	line(90,115,550,115);
	setbkcolor(0);
	setcolor(11);
	settextstyle(7,0,1);
	setusercharsize(40,70,20,20);
	outtextxy(10,150,"1. This Game can be played by TWO Players.");
	outtextxy(10,190,"2. First Player can move the paddle with RIGHT and LEFT Arrow.");
	outtextxy(10,230,"3. Second Player can move the paddle with A and D key.");
	outtextxy(10,270,"4. You score 5 points every time you hit the paddle.");
	setcolor(14);
	settextstyle(7,0,1);
	setusercharsize(40,30,40,30);
	outtextxy(100,320," ENJOY PLAYING!");
	setcolor(15);
	settextstyle(7,0,1);
	outtextxy(150,430,"PRESS ANY KEY TO CONITINUE");

	getch();
	clearviewport();
	setcolor(YELLOW);
	//triangle on upper side
for(dec=5;dec<=586;dec+=13)
{
	int t1=10+dec,t2=10;
	int tri1[]={t1,t2,t1+26,t2,t1+13,t2+26,t1,t2};
	setfillstyle(SOLID_FILL,128);
	fillpoly(4,tri1);
}
//triangle on lower side
for(dec=5;dec<=586;dec+=13)
{
	int t1=10+dec,t2=450;
	int tri1[]={t1,t2,t1+26,t2,t1+13,t2-26,t1,t2};
	setfillstyle(SOLID_FILL,128);
	fillpoly(4,tri1);
}

		    //paddle  1

	int ux=250,uy=390;
	setfillstyle(CLOSE_DOT_FILL,BROWN);
	bar(ux,uy,ux+100,uy+20);
	rectangle(ux,uy,ux+100,uy+20);

	//paddle 2

	int lx=250,ly=50;
	setfillstyle(CLOSE_DOT_FILL,CYAN);
	bar(lx,ly,lx+100,ly+20);
	rectangle(lx,ly,lx+100,ly+20);
 //	loading();

	//GET
	setcolor(YELLOW);
	settextstyle(7,0,10);
	outtextxy(200,150,"GET");
	delay(1000);
	setcolor(0);
	outtextxy(200,150,"GET");

	//SET
	setcolor(YELLOW);
	settextstyle(7,0,10);
	outtextxy(200,150,"SET");
	delay(1000);
	setcolor(0);
	outtextxy(200,150,"SET");

	//GO
	setcolor(YELLOW);
	settextstyle(7,0,10);
	outtextxy(200,150," GO...");
	delay(1000);
	setcolor(0);
	outtextxy(200,150," GO...");

while(key!=ESC)
{
    //key
    key1=bioskey(1);
    if(key1>0)
    {
      key = bioskey(0);
    }


	//KEYS for paddle 1
	    if(key==LT)
		ux-=2;
	    else if (key==RT)
		ux+=2;

	     if(ux>500)
		ux=500;
	     if(ux<20)
		ux=20;
	//KEYS for paddle 2
	       if(key==A || key==a)
		lx-=2;
	    else if (key==D || key==d)
		lx+=2;

	     if(lx>500)
		lx=500;
	     if(lx<20)
		lx=20;


	//PADDLE MOVEMENT 1
	setcolor(13);
	setfillstyle(CLOSE_DOT_FILL,BROWN);
	bar(ux,uy,ux+100,uy+20);
	rectangle(ux,uy,ux+100,uy+20);
	delay(2);
	setcolor(BLACK);
	setfillstyle(CLOSE_DOT_FILL,BLACK);
	bar(ux,uy,ux+100,uy+20);
	rectangle(ux,uy,ux+100,uy+20);

	//paddle movement 2
	setcolor(14);
	setfillstyle(CLOSE_DOT_FILL,BROWN);
	bar(lx,ly,lx+100,ly+20);
	rectangle(lx,ly,lx+100,ly+20);
	delay(2);
	setcolor(BLACK);
	setfillstyle(CLOSE_DOT_FILL,BLACK);
	bar(lx,ly,lx+100,ly+20);
	rectangle(lx,ly,lx+100,ly+20);

	//bouncing ball
	setcolor(RED);
	setfillstyle(1,YELLOW);
	fillellipse(x,y,10,10);
	delay(1);
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	fillellipse(x,y,10,10);

	if(x<615)
		x=x+dx;
	if(x>605 || x<25)
		dx=-dx;
	if(y>435 || y<25)
		dy=-dy;
	if(y<445)
		y+=dy;

	// if ball touches the paddle 1
	if( y==377 )
	{
		if(x>=(ux-20) && x<=(ux+120) )
		{
			dy=-dy;
			score1++;
		}
	}
	// if ball touches the paddle 2
	if( y==83 )
	{
		if(x>=(lx-20) && x<=(lx+120) )
		{
			dy=-dy;
			score2++;
		}
	}




	// if ball goes n touches the ground and top
	for( int i=10; i<=630; i++ )
	{
		if( ( x==i && y==435 ) || ( x==i && y==33 ) )
		{

	       /*	setcolor(RED);
		setlinestyle(DASHED_LINE,0,THICK_WIDTH);
		rectangle(10,10,620,450);
		setfillstyle(SOLID_FILL,RED);
		fillpoly(5,array1);
		setfillstyle(SOLID_FILL,0);
		fillpoly(5,array2);
	       */	b=1;
		break;
		}
	}
	if(b==1)
	 {

		setcolor(CYAN);
		settextstyle(1,0,1);
		cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<(score1*5);
		cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<(score2*5);
		outtextxy(235,153,"SCORE OF PLAYER 1 IS");
		outtextxy(235,190,"SCORE OF PLAYER 2 IS");
		getch();
		end();
		break;
	 }


}
//getch();
}


getch();

closegraph();
}

//loading your game
void loading()
{
for(int i=1;i<=5;i++)
	{

	setusercharsize(50,1,40,1);
	settextstyle(10,0,4);
	setcolor(RED);

	outtextxy(20,290,"LOADING YOUR GAME . . . ");
	setusercharsize(50,1,40,1);
	settextstyle(5,0,4);
	setcolor(CYAN);
	if(i==1)
	{
	outtextxy(290,185,"5");
	}
	else if(i==2)
	{
	outtextxy(290,185,"4");
	}
	else if(i==3)
	{
	outtextxy(290,185,"3");
	}
	else if(i==4)
	{
	outtextxy(290,185,"2");
	}
	else if(i==5)
	{
	outtextxy(290,185,"1");
	}
	setcolor(8);
	setlinestyle(1,0,3);
	arc(300,210,5,85,60);
	arc(300,210,5,85,61);
	delay(300);
	arc(300,210,275,355,60);
	arc(300,210,275,355,61);
	delay(300);
	arc(300,210,185,265,60);
	arc(300,210,185,265,61);
	delay(300);
	arc(300,210,95,175,60);
	arc(300,210,95,175,61);
	delay(300);
	cleardevice();

}
}
//start
void start()
{
	  for(int i=1;i<=120;i++)
      {

       settextstyle(7,0,0);
       setcolor(i);
       setusercharsize(15,11,9,3);
       outtextxy(115,i,"PADDLE BALLING");
       delay(12);
       setcolor(0);
       setusercharsize(15,11,9,3);
       outtextxy(115,i,"PADDLE BALLING");

     }
	setcolor(5);
	setusercharsize(15,11,9,3);
	outtextxy(115,i,"PADDLE BALLING");
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(45,400,"PRESS ANY KEY TO CONTINUE.....");
	float octave[25] = {262,262,294,262,349,330,262,262,294,262,392,349,262,262,523,440,349,330,294,466,466,440,349,392,349};

	while( !kbhit() )
	{
		sound( octave[ random(7) ]*1 );
		delay(300);
	}
   nosound();
	getch();
}
void end()
{

	cleardevice();
	setusercharsize(50,1,40,1);
	settextstyle(7,0,10);
	setcolor(YELLOW);
	outtextxy(120,85,"GAME");
	outtextxy(270,195,"OVER");
	do
    {
     sound(300);
     delay(50);
     sound(100);
     delay(100);
     sound(200);
     delay(50);
    }
    while(!kbhit());

       nosound();
    exit(0);
}