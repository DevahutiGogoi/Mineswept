#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

int j, i, a=1, b=1, pos[50][20];
char c, d, e, lo, ol;
int input, score=0, bomb1, bomb2, bomb3, bomb4, count=0, opt, choice;
char ch, ans;
int l, k, p, q, r, s, u, v, w, x, y, o;   //coordinates for grid
void highscore(char nam[30], int scr)
     {  void play(void);
	void menu(void);
	fstream info;
	info.open("HighScore.txt", ios::out | ios::app);
	info<<"\nName      : "<<nam<<endl
	    <<"Score     : "<<scr<<endl;
	info.close();

	info.open("HighScore.txt", ios::in);
	char ch[100];
	clrscr();
	cout<<"\t\t======================================="<<endl
	    <<"\t\t\t\tSCOREBOARD                "<<endl
	    <<"\t\t======================================="<<endl;

	while(!info.eof())
	  {  info.getline(ch,100);
	     cout<<"\t\t            "<<ch<<endl;
	  }
	cout<<"\n\n\n\t\t            1. Play again";
	cout<<"\n\t\t            2. Back to MAIN MENU";
	cout<<"\n\t\t            3. Exit";
	cout<<"\n\n\t\t            Enter a choice: ";
	cin>>opt;
	if(opt==1)
	  {  b=1;
	     score=0;
	     play();
	  }
	else if(opt==2)
	  {  a=1;
	     menu();
	  }
	else
	     exit(0);
	info.close();
     }


void display()
     {  void play(void);
	void menu(void);
	fstream show;
	show.open("Highscore.txt", ios::in);
	char ch[100];
	clrscr();
	cout<<"\t\t======================================="<<endl
	    <<"\t\t\t\tSCOREBOARD                "<<endl
	    <<"\t\t======================================="<<endl;

	while(!show.eof())
	  {  show.getline(ch,100);
	     cout<<"\t\t            "<<ch<<endl;
	  }
	cout<<"\n\n\n\t\t            1. Play the game";
	cout<<"\n\t\t            2. Back to MAIN MENU";
	cout<<"\n\t\t            3. Exit";
	cout<<"\n\n\t\t            Enter a choice: ";
	cin>>choice;
	if(choice==1)
	  { b=1;
	    score=0;
	    play();
	  }
	else if(choice==2)
	  { a=1;
	    menu();
	  }
	else
	    exit(0);
	show.close();
     }
void play()
     {  clrscr();
	z:
	randomize();
	bomb1=random(26);
	bomb2=random(26);
	bomb3=random(26);
	bomb4=random(26);
	clrscr();
	cout<<"\n\n\t\t\t\tALL THE BEST!";
		   //code for grid....
		   //ROWS
		for( l=26; l<=47; l++)
		  {  gotoxy(l, 6);
		     cout<<char(205);
		  }
		for( k=26; k<=47; k++)
		  {  gotoxy(k, 16);
		     cout<<char(205);
		  }
		for( p=26; p<=47; p++)
		  {  gotoxy(p, 8);
		     cout<<char(196);
		  }
		for( q=26; q<=47; q++)
		  {  gotoxy(q, 10);
		     cout<<char(196);
		  }
		for( r=26; r<=47; r++)
		  {  gotoxy(r, 12);
		     cout<<char(196);
		  }
		for( s=26; s<=47; s++)
		  {  gotoxy(s, 14);
		     cout<<char(196);
		  }
	       //COLUMNS
		for( u=6; u<=16; u++)
		  {  gotoxy(26, u);
		     cout<<char(186);
		  }
		for( v=6; v<=16; v++)
		  {  gotoxy(47, v);
		     cout<<char(186);
		  }
		for( w=6; w<=16; w++)
		  {  gotoxy(30, w);
		     cout<<char(179);
		  }
		for( x=6; x<=16; x++)
		  {  gotoxy(34, x);
		     cout<<char(179);
		  }
		for( y=6; y<=16; y++)
		  {  gotoxy(39, y);
		     cout<<char(179);
		  }
		for( o=6; o<=16; o++)
		  {  gotoxy(43, o);
		     cout<<char(179);
		  }
		//end of code for grid!!!

	for( j=28; j<48; j=j+4 )
	  {  for( i=7; i<17; i=i+2 )
	       {  gotoxy(j, i);
		  cout<<b;
		  pos[j][i]=b++;
	       }
	  }
	do
	  {  gotoxy(60,7);
	     textcolor(LIGHTGRAY);
	     cprintf("POINTS: ");
	     textcolor(YELLOW);
	     cprintf("%i",score);
	     gotoxy(28,20);
	     cout<<"Input: ";
	     cin>>input;
	     gotoxy(35,20);
	     cout<<" ";
	     gotoxy(36,20);
	     cout<<" ";
	     if(input<1||input>25)
		count++;
	     score=score+10;

	     for( j=28; j<48; j=j+4 )
	       {  for( i=7; i<17; i=i+2 )
		    {  if(input==pos[j][i])
			 { gotoxy(j, i);
			   textcolor(YELLOW);
			   c= char(1);
			   cprintf("%c ", c);
			   if((input==bomb1||input==bomb2||input==bomb3||input==bomb4))
			     { gotoxy(j, i);
			       textcolor(RED + BLINK);
			       e= char(15);
			       cprintf("%c ", e);
			     }
			 }
		    }
		}
	  }while((input!=bomb1)&&(input!=bomb2)&&(input!=bomb3)&&(input!=bomb4)&&(score<=210));
	   gotoxy(28,20);
	   d=input;
	   textcolor(RED + BLINK);
	   cout<<"Bomb exploded at "; cprintf("%i ", d);
	   gotoxy(28,21);
	   textcolor(LIGHTGRAY);
	   int finalscore=0;
	   finalscore = score-10-(10*count);
	   cout<<"\n\nYour total score: "<<finalscore;
	   gotoxy(28,22);
	   cout<<"GAME OVER!!!!";
	   cout<<"\n\nDo you want to try again? (Y/N): ";
	   cin>>ans;
	   if(ans=='y'|| ans=='Y')
	     { b=1;
	       score=0;
	       goto z;
	     }
	    else
	     { char name[30];
	       cout<<"\n\nEnter your name   : ";cin>>name;
	       system("pause");
	       highscore(name, finalscore);
	     }

     }
void rules()
     {  clrscr();
	cout<<"\n\n\n\t\t        RULES AND INSTRUCTIONS";
	cout<<"\n\n1. Keep on typing a number until you get exploded. Once you encounter a bomb,      your GAME is OVER!!!";
	cout<<"\n2. Do not type the same number that has been typed before.";
	cout<<"\n3. You get 10 points if your input survives. There are 4 bombs hidden in the       grid.";
	cout<<"\n4. You can score a maximum of 210 points. Once this score is achieved, you will    be declared as the winner!";
	cout<<"\n\nDo you want to continue? (Y/N): ";
	cin>>ch;
	if(ch=='y'|| ch=='Y')
	  { b=1;
	    score=0;
	    play();
	  }
	else
	    exit(0);
     }
void menu()
     {
	clrscr();
	cout<<"\n\n\n\t\t\tWELCOME TO MINESWEEPING!!!";
	  //code for grid....
	  //ROWS
	  for( l=26; l<=47; l++)
	    {  gotoxy(l, 6);
	       cout<<char(205);
	    }
	  for( k=26; k<=47; k++)
	    {  gotoxy(k, 16);
	       cout<<char(205);
	    }
	  for( p=26; p<=47; p++)
	    {  gotoxy(p, 8);
	       cout<<char(196);
	    }
	  for( q=26; q<=47; q++)
	    {  gotoxy(q, 10);
	       cout<<char(196);
	    }
	  for( r=26; r<=47; r++)
	    {  gotoxy(r, 12);
	       cout<<char(196);
	    }
	  for( s=26; s<=47; s++)
	    {  gotoxy(s, 14);
	       cout<<char(196);
	    }
	  //COLUMNS
	  for( u=6; u<=16; u++)
	    {  gotoxy(26, u);
	       cout<<char(186);
	    }
	  for( v=6; v<=16; v++)
	    {  gotoxy(47, v);
	       cout<<char(186);
	    }
	  for( w=6; w<=16; w++)
	    {  gotoxy(30, w);
	       cout<<char(179);
	    }
	  for( x=6; x<=16; x++)
	    {  gotoxy(34, x);
	       cout<<char(179);
	    }
	  for( y=6; y<=16; y++)
	    {  gotoxy(39, y);
	       cout<<char(179);
	    }
	  for( o=6; o<=16; o++)
	    {  gotoxy(43, o);
	       cout<<char(179);
	    }
	    //end of code for griding!!!
	for( j=28; j<48; j=j+4 )
	  {  for( i=7; i<17; i=i+2 )
	       {  gotoxy(j, i);
		  cout<<a++;
	       }
	  }
	// special effects    (loading.....!!)
	  for(int ts=28; ts<48; ts=ts+4)
	    {  for(int ps=7; ps<17; ps=ps+2)
		 {  delay(50);
		    gotoxy(ts, ps);
		    textcolor(YELLOW);
		    lo= char(1);
		    cprintf("%c ", lo);
		  }
	    }
	  gotoxy(44,15);
	  textcolor(RED + BLINK);
	  ol= char(15);
	  cprintf("%c ", ol);
	textcolor(LIGHTGRAY);
	cout<<"\n\nMENU";
	cout<<"\n1. Rules and instructions";
	cout<<"\n2. Continue to game";
	cout<<"\n3. Scoreboard";
	cout<<"\n4. Exit";
	cout<<"\n\n Enter your option: ";
	cin>>opt;
	if(opt==1)
	    rules();
	else if(opt==2)
	  { b=1;
	    score=0;
	    play();
	  }
	else if(opt==3)
	    display();
	else
	   exit(0);
     }
void main()
{
  clrscr();
  menu();
  getch();
}
