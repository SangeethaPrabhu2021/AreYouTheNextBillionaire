#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<process.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>
#include"H:PROJECTS\MOUSE.CPP"
int gdriver = DETECT, gmode, errorcode;
class KBC
{

 int status;
 char quest[500];
 struct option
 {
  int opno;
  char op[150];
 }o1,o2,o3,o4;
 int Rans;
  double money;
 public:
 void input(double mon)
 {
   money=mon;
   cout<<"\n\n Enter the Question : ";
   gets(quest);
   o1.opno=1;
   o2.opno=2;
   o3.opno=3;
   o4.opno=4;
   cout<<"\n OPTION 1: ";
   gets(o1.op);
   cout<<"\n OPTION 2: ";
   gets(o2.op);
   cout<<"\n OPTION 3: ";
   gets(o3.op);
   cout<<"\n OPTION 4: ";
   gets(o4.op);
   cout<<"\n Enter the Right Answer(1/2/3/4) : ";
   cin>>Rans;
 }
 void output(int qnno)
 {
   cout<<"\n\n Question "<<qnno<<" :";
   puts(quest);
   cout<<"\n OPTION 1: ";
   puts(o1.op);
   cout<<"\n OPTION 2: ";
   puts(o2.op);
   cout<<"\n OPTION 3: ";
   puts(o3.op);
   cout<<"\n OPTION 4: ";
   puts(o4.op);
   cout<<"\n Right Answer : ";
   cout<<Rans;
   cout<<"\n STATUS : "<<status;
 }
 int retsta()
 {return status;}
 int retrans()
 {return Rans;}
 float retmoney()
 {return money;}
 void modify()
 {status=1;}
 char* retque()
 {return quest;}
 void reset()
 {status=0;}
 KBC()
 {  status=0;
 }
 };
//copy the;
char Name[3][20]={"Pranamya Mady",
		  "Sangeetha",
		  "Sona Maria"
		 };
char Pass[3][30]={"feelinlucky#2002",
		  "Sangeelris",
		  "mylifemystyle#sona123"
		  };
void Addviewq();
void Addq()
{int op; double money;
 do
  { clrscr();
  cout<<"\n\n a)Questions for :  "
      <<"\n   1.$1,000"
      <<"\n   2.$5,000"
      <<"\n   3.$10,000"
      <<"\n   4.$25,000"
      <<"\n   5.$50,000"
      <<"\n   6.$100,000"
      <<"\n   7.$250,000"
      <<"\n   8.$500,000"
      <<"\n   9.$1,000,000"
      <<"\n   10.$10,000,000"
      <<"\n   11.$1,000,000,000"
      <<"\n   12.EXPERT ADVICE"
      <<"\n\n 13.BACK"
      <<"\n\n Enter your choice : ";
  cin>>op;
  if(op!=13)
  {fstream KBfile;
   switch(op)
  {
   case 1:KBfile.open("H:\XIIC\KBCPRO\QUE1.BKB",ios::out|ios::app|ios::binary);money=1000;break;
   case 2:KBfile.open("H:\XIIC\KBCPRO\QUE2.BKB",ios::out|ios::app|ios::binary);money=5000;break;
   case 3:KBfile.open("H:\XIIC\KBCPRO\QUE3.BKB",ios::out|ios::app|ios::binary);money=10000;break;
   case 4:KBfile.open("H:\XIIC\KBCPRO\QUE4.BKB",ios::out|ios::app|ios::binary);money=25000;break;
   case 5:KBfile.open("H:\XIIC\KBCPRO\QUE5.BKB",ios::out|ios::app|ios::binary);money=50000;break;
   case 6:KBfile.open("H:\XIIC\KBCPRO\QUE6.BKB",ios::out|ios::app|ios::binary);money=100000;break;
   case 7:KBfile.open("H:\XIIC\KBCPRO\QUE7.BKB",ios::out|ios::app|ios::binary);money=250000;break;
   case 8:KBfile.open("H:\XIIC\KBCPRO\QUE8.BKB",ios::out|ios::app|ios::binary);money=500000;break;
   case 9:KBfile.open("H:\XIIC\KBCPRO\QUE9.BKB",ios::out|ios::app|ios::binary);money=1000000;break;
   case 10:KBfile.open("H:\XIIC\KBCPRO\QUE10.BKB",ios::out|ios::app|ios::binary);money=10000000;break;
   case 11:KBfile.open("H:\XIIC\KBCPRO\QUE11.BKB",ios::out|ios::app|ios::binary);money=1000000000;break;
   case 12:KBfile.open("H:\XIIC\KBCPRO\EXPADV.BKB",ios::out|ios::app|ios::binary);money=0;break;
   case 13:Addviewq();break;
   default : cout<<"\n NOT A VALID OPTION!!";
  }

  if(!KBfile)
  cout<<"\n File not created!!";

  else
  {
   KBC dum;
   dum.input(money);
   KBfile.write((char*)&dum,sizeof(dum));
  }
  KBfile.close();
  }
  }while(op!=13);
};
void Displayq()
{int op;
 do
  { clrscr();
  cout<<"\n\n a)Questions of :  "
      <<"\n   1.$1,000"
      <<"\n   2.$5,000"
      <<"\n   3.$10,000"
      <<"\n   4.$25,000"
      <<"\n   5.$50,000"
      <<"\n   6.$100,000"
      <<"\n   7.$250,000"
      <<"\n   8.$500,000"
      <<"\n   9.$1,000,000"
      <<"\n   10.$10,000,000"
      <<"\n   11.$1,000,000,000"
      <<"\n   12.EXPERT ADVICE"
      <<"\n\n 13.BACK"
      <<"\n\n Enter your choice : ";
  cin>>op;
  if(op!=13)
  {
  fstream KBfile;
  switch(op)
  {
   case 1:KBfile.open("H:\XIIC\KBCPRO\QUE1.BKB",ios::in|ios::binary);break;
   case 2:KBfile.open("H:\XIIC\KBCPRO\QUE2.BKB",ios::in|ios::binary);break;
   case 3:KBfile.open("H:\XIIC\KBCPRO\QUE3.BKB",ios::in|ios::binary);break;
   case 4:KBfile.open("H:\XIIC\KBCPRO\QUE4.BKB",ios::in|ios::binary);break;
   case 5:KBfile.open("H:\XIIC\KBCPRO\QUE5.BKB",ios::in|ios::binary);break;
   case 6:KBfile.open("H:\XIIC\KBCPRO\QUE6.BKB",ios::in|ios::binary);break;
   case 7:KBfile.open("H:\XIIC\KBCPRO\QUE7.BKB",ios::in|ios::binary);break;
   case 8:KBfile.open("H:\XIIC\KBCPRO\QUE8.BKB",ios::in|ios::binary);break;
   case 9:KBfile.open("H:\XIIC\KBCPRO\QUE9.BKB",ios::in|ios::binary);break;
   case 10:KBfile.open("H:\XIIC\KBCPRO\QUE10.BKB",ios::in|ios::binary);break;
   case 11:KBfile.open("H:\XIIC\KBCPRO\QUE11.BKB",ios::in|ios::binary);break;
   case 12:KBfile.open("H:\XIIC\KBCPRO\EXPADV.BKB",ios::in||ios::binary);break;
   case 13:Addviewq();break;
   default : cout<<"\n NOT A VALID OPTION!!";
  }
  if(!KBfile)
  cout<<"\n File not created!!";
  else
  {int count=0;
   KBC dum;
   KBfile.read((char*)&dum,sizeof(dum));
   while(!KBfile.eof())
   {
   dum.output(count++);
   KBfile.read((char*)&dum,sizeof(dum));
   }
  }
  KBfile.close();
  }
  }while(op!=13);
};
void main()
{
char user[30];
int flag=0;
char pass[30];
initgraph(&gdriver, &gmode, "");
//initialize mouse
while(1)
{
 clrscr();
 setcolor(RED);
 settextstyle(4,0,5);//style,direction,size
 outtextxy(30,20,"Are you the next billionaire?");
 setcolor(WHITE);
 outtextxy(31,20,"Are you the next billionaire?");
 settextstyle(4,0,3);
 outtextxy(40,50,"Login To View or Add Questions : ");
 outtextxy(40,70,"User Name : ");
 gets(user);
 for(int i=0;i<3;i++)
  if(!strcmpi(user,Name[i]))
  { flag=1;
    outtextxy(40,90,"Password : ");
    int i=0;
    char ch=getch();
    while(ch!='\r')
    {
     outtext("*");
     pass[i++]=ch;
     ch=getch();
    }
    int star=0;
    for(i=0;i<3;i++)
    if(!strcmp(pass,Pass[i]))
    {outtextxy(100,110,"ACCESS GRANTED!!");
     star=1;
     Addviewq();
    }
    if(star==0)
    {outtextxy(100,110,"Incorrect Password!!...");
     bar(90,230,190,260);//(int left, int top, int right, int bottom);
     outtextxy(92,240,"Try Again");
     bar(230,230,330,260);//(int left, int top, int right, int bottom);
     outtextxy(232,240,"Exit");

      if(x>=100&&x<=190&&y>=230&&y<=250)
      if(x>=230&&x<=320&&y>=230&&y<=250)
      {delay(1000);
       exit(0);
      }
    }//star
   }//for
 if(flag==0) //not found
   { outtextxy(20,100,"Sorry, You do not have access to view or add questions!!... ");
     getch();
     exit(0);
   }
closegraph();
}//main
void Addviewq()
{ int op;
  do
  { clrscr();
  cout<<"\n\n\n\t\t\t Are you the next billionaire? "
      <<"\n\t\t\t ------------------------------"
      <<"\n\n MENU : "
      <<"\n\n   1.ADD QUESTIONS"
      <<"\n\n   2.VIEW QUESTIONS"
      <<"\n\n   3.EXIT"
      <<"\n\n\n     Enter your choice : ";
  cin>>op;
  switch(op)
  {
   case 1:clrscr();
	  Addq();
	  break;
   case 2:clrscr();
	  Displayq();
	  break;
   case 3:delay(1000);
	  exit(0);
   default : cout<<"\n Not a valid option!";
  }

 }while(op!=3);

}
