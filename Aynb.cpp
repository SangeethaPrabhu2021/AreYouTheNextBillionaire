
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<fstream.h>
#include<time.h>
#include"H:\PROJECTS\MOUSE.CPP"
 clock_t start=clock(), end=clock();
int x,y,button;
int qno=0;
int fif=1,exp=1,e20=1;
int dip=1,dipactive=0;
int expq=0;
void Dip()
{ outtext("Double Dip Activated");
 dipactive=1;
 dip=0;
}
double moneywon;
double permawon=0;
int exprtans(int rans);
void Startplay();
void Mainpage();
void Walloffame();
void About();
void Drawhexa(int x, int y,int a, int b,int w, int col)
{
int hexa[14];
  hexa[0]=x;
  hexa[1]=y;

  hexa[2]=x+a;
  hexa[3]=y-b;

  hexa[4]=x+a+w;
  hexa[5]=y-b;

  hexa[6]=x+2*a+w;
  hexa[7]=y;

  hexa[8]=x+a+w;
  hexa[9]=y+b;

  hexa[10]=x+a;
  hexa[11]=y+b;

  hexa[12]=x;
  hexa[13]=y;
  drawpoly(7,hexa);
  setfillstyle(SOLID_FILL,col);
  fillpoly(7,hexa);
}

struct Question
{
   char quest[500];
   struct option
   {
    int opno;
    char op[125];
    }o1,o2,o3,o4;//options
   int Rans ;
   double money;
   int Status ;
};
void display(Question Que)
 { cleardevice();
   setbkcolor(0);
   if(!expq)
   {
   if(dip)
   {
   bar(getmaxx()-430,10,getmaxx()-330,30);
   settextstyle(5,0,1);
   outtextxy(getmaxx()-425,5,"Double Dip");
   }
   if(fif)
   {bar(getmaxx()-320,10,getmaxx()-220,30);
    outtextxy(getmaxx()-315,5,"50-50");
   }
   if(exp)
   { bar(getmaxx()-210,10,getmaxx()-110,30);
   settextstyle(5, 0, 1);
    outtextxy(getmaxx()-210,5,"Expert Advice");
   }
   if(e20)
   { bar(getmaxx()-100,10,getmaxx(),30);
    outtextxy(getmaxx()-95,5,"Extra 20");
    }
    }
   Drawhexa(20,getmaxy()/3,30,40,getmaxx()-100,3);//quest
   Drawhexa(20,2*getmaxy()/3,30,30,(getmaxx()-170)/2,3);//op1
   Drawhexa(90+(getmaxx()-170)/2,2*getmaxy()/3,30,30,(getmaxx()-170)/2,3);//op2
   Drawhexa(20,2*getmaxy()/3+80,30,30,(getmaxx()-170)/2,3);//op3
   Drawhexa(90+(getmaxx()-170)/2,2*getmaxy()/3+80,30,30,(getmaxx()-170)/2,3);//op4
   setcolor(RED);
 settextstyle(2 , 0, 4); //style,direction, size
 outtextxy(40,getmaxy()/3,Que.quest);
  setcolor(BLACK);
 settextstyle(2, 0, 4);
 outtextxy(35,2*getmaxy()/3-10, "A.");
 outtextxy(45,2*getmaxy()/3-10,Que.o1.op);
 outtextxy(90+(getmaxx()-170)/2+15,2*getmaxy()/3-10, "B.");
 outtextxy(90+(getmaxx()-170)/2+25,2*getmaxy()/3-10,Que.o2.op);
 outtextxy(35,2*getmaxy()/3+70, "C.");
 outtextxy(45,2*getmaxy()/3+70,Que.o3.op);
 outtextxy(90+(getmaxx()-170)/2+15,2*getmaxy()/3+70, "D.");
 outtextxy(90+(getmaxx()-170)/2+25,2*getmaxy()/3+70,Que.o4.op);
 setcolor(RED);
 }//DISPLAY
 void display(int r1,int r2,Question Que)//for 50-50
 {
   cleardevice();
   setbkcolor(0);
   if(dip)
   {
   bar(getmaxx()-430,10,getmaxx()-330,30);
     settextstyle(5, 0, 1);
   outtextxy(getmaxx()-425,5,"Double Dip");
   }
   if(fif)
   {bar(getmaxx()-320,10,getmaxx()-220,30);
    outtextxy(getmaxx()-315,5,"50-50");
   }
   if(exp)
   { bar(getmaxx()-210,10,getmaxx()-110,30);
   settextstyle(5, 0, 1);
    outtextxy(getmaxx()-210,5,"Expert Advice");
   }
   if(e20)
   { bar(getmaxx()-100,10,getmaxx(),30);
    outtextxy(getmaxx()-95,5,"Extra 20");
    }
   Drawhexa(20,getmaxy()/3,30,40,getmaxx()-100,3);//quest
   Drawhexa(20,2*getmaxy()/3,30,30,(getmaxx()-170)/2,3);//op1
   Drawhexa(90+(getmaxx()-170)/2,2*getmaxy()/3,30,30,(getmaxx()-170)/2,3);//op2
   Drawhexa(20,2*getmaxy()/3+80,30,30,(getmaxx()-170)/2,3);//op3
   Drawhexa(90+(getmaxx()-170)/2,2*getmaxy()/3+80,30,30,(getmaxx()-170)/2,3);//op4
   setcolor(RED);
 settextstyle(5, 0, 2); //style,direction, size
 outtextxy(40,getmaxy()/3-40,Que.quest);

 settextstyle(2, 0, 4);
 if(Que.o1.opno==r1||Que.o1.opno==r2)
 {outtextxy(35,2*getmaxy()/3-10, "A.");
 outtextxy(45,2*getmaxy()/3-10,Que.o1.op);}
 if(Que.o2.opno==r1||Que.o2.opno==r2)
 { outtextxy(90+(getmaxx()-170)/2+15,2*getmaxy()/3-10, "B.");
 outtextxy(90+(getmaxx()-170)/2+25,2*getmaxy()/3-10,Que.o2.op); }
 if(Que.o3.opno==r1||Que.o3.opno==r2)
 {outtextxy(35,2*getmaxy()/3+70, "C.");
 outtextxy(45,2*getmaxy()/3+70,Que.o3.op);}
 if(Que.o4.opno==r1||Que.o4.opno==r2)
 {outtextxy(90+(getmaxx()-170)/2+15,2*getmaxy()/3+70, "D.");
 outtextxy(90+(getmaxx()-170)/2+25,2*getmaxy()/3+70,Que.o4.op);  }
 }//DISPLAY
 int E20(int x)
 {e20=0;
 x+=20;
 }
int exprtans(int rans)
{
while(1)
{

     cout<<"00:";
    end = clock() ;
    int TimeSec = 60-(int)(end - start) / CLK_TCK;
    gotoxy(35, 4);
    cout<<TimeSec ;
	delay( 100 );

    getmousepos( &button,  &x, &y );
   if( button & 1 == 1)  //Left mouse button
   {
if(x>=50&&x<=50+(getmaxx()-170)/2&&y>=2*getmaxy()/3-30&&y<=2*getmaxy()/3+30)
  if(1==rans)
   return 1;
   else return 0;
 if(x>=120+(getmaxx()-170)/2&&x<=120+getmaxx()-170&&y>=2*getmaxy()/3-30&&y<=2*getmaxy()/3+30)
  if(2==rans)
   return 1;
   else return 0;
 if(x>=50&&x<=50+(getmaxx()-170)/2&&y>=2*getmaxy()/3+500&&y<=2*getmaxy()/3+110)
  if(3==rans)
   return 1;
   else return 0;
 if(x>=120+(getmaxx()-170)/2&&x<=120+getmaxx()-170&&y>=2*getmaxy()/3+50&&y<=2*getmaxy()/3+110)
  if(4==rans)
   return 1;
   else return 0;
   }
   }
}
void fifty(Question Que)
 { fif=0;
  int r1=Que.Rans,r2=Que.Rans;
  while(r2==Que.Rans)
  {

  r2=rand()%4+1;
  }
  display(r1,r2,Que);
 }//fifty
void expadv(Question dup)
 {  exp=0;
  Question Q;
  fstream KBfile;
  KBfile.open("H:EXPADV.som",ios::in|ios::binary);
  int num;
KBfile.seekg(0,ios::end);
int size=KBfile.tellg();
int nofq=(size-1)/sizeof(Q);
num=rand()%nofq+1;
KBfile.seekg(0);
KBfile.read((char*)&Q,sizeof(Q));
int i=1; int flag=0; Question temp;int flagf=0;
while(!KBfile.eof())//selecting a random q
{
 if(flag==0&&Q.Status==0)
 {temp=Q;flag=1;}
  if(i==num)
  {
   if(Q.Status==0)
   {flagf=1;
    KBfile.seekp(KBfile.tellg()-sizeof(Q));
     Q.Status=1;
     settextstyle(4,0,2) ;
     KBfile.write((char*)&Q,sizeof(Q));
    break;
   }
  else//if(status==1)
  num++;
 }
 else//(i!=num)
  {KBfile.read((char*)&Q,sizeof(Q));
  i++;
  }
}
if(flagf==0)
{
 if(flag==1)
 {temp=Q;
   KBfile.seekg(0);
    KBfile.seekp(0);
   KBfile.read((char*)&Q,sizeof(Q));
  while(!KBfile.eof())
  {
    if(!strcmpi(Q.quest,temp.quest))
    { KBfile.seekp(KBfile.tellg()-sizeof(Q));
      Q.Status=1;
      settextstyle(4,0,2);
      KBfile.write((char*)&Q,sizeof(Q));
      break;
     }

  }//EOF
 }//FLAG==1
else//all are used....set status=0;..read first one
 {
  KBfile.seekg(0);
  KBfile.seekp(0);
   KBfile.read((char*)&Q,sizeof(Q));
  while(!KBfile.eof())
  {
    Q.Status=0;
    KBfile.write((char*)&Q,sizeof(Q));

   KBfile.read((char*)&Q,sizeof(Q));
  }
   KBfile.seekg(0);
   KBfile.seekp(0);
    KBfile.read((char*)&Q,sizeof(Q));
    Q.Status=1;
    KBfile.write((char*)&Q,sizeof(Q));

 }
}
 cleardevice();
 expq=1;
  outtextxy(10,10," To get the most probable answer for the question answer this question : ");
 display(Q);
 if(exprtans(Q.Rans))
 { delay(1000);
 expq=0;
   display(dup);
   outtextxy(10,20," The most probable answer for this question is : ");
  int r=rand()%1000+1;
  int m=dup.Rans;
   if(r%200==0)//to get wrong ans.
    while(m==dup.Rans)
     m=rand()%4+1;
  if(dup.o1.opno==m)
  {outtext("A. ");outtext(dup.o1.op);}
  if(dup.o2.opno==m)
  {outtext("B. ");outtext(dup.o2.op);}
  if(dup.o3.opno==m)
  {outtext("C. ");outtext(dup.o3.op);}
  if(dup.o4.opno==m)
  {outtext("D. ");outtext(dup.o4.op);}
 }//if correct ans.

 else
   {
    outtextxy(10,20," Sorry, you answered it wrong...");
    delay(1000);
   display(dup);
   }
}//expadv

struct Score
{
 char name[30];
 double monwon;
};
void Mainpage()
{ cleardevice();
    setbkcolor(0);
settextstyle(3, 0, 1 );
outtextxy(620,10,"X");
settextstyle(5, 0, 5 );
outtextxy(50,20,"Are you the next billionaire ?");
setcolor( RED) ;
outtextxy(51,20,"Are you the next billionaire ?");
setcolor(WHITE);
setfillstyle(SOLID_FILL,BLUE);
 Drawhexa(getmaxx()/2-100-20,getmaxy()/3,30,30,220,3);//play
 Drawhexa(getmaxx()/2-100-20,getmaxy()/3+90,30,30,220,3);//WALL OF FAME
 Drawhexa(getmaxx()/2-100-20,getmaxy()/3+180,30,30,220,3);//ABOUT

 setcolor( RED) ;
 settextstyle(7, 0, 5 );
outtextxy(285,getmaxy()/3-30+5,"PLAY");
settextstyle(7, 0, 4 );
outtextxy(213,getmaxy()/3-30+110-10,"WALL OF FAME");
settextstyle(7, 0, 5 );
outtextxy(265,getmaxy()/3-30+185,"ABOUT");
//int left, int top, int right, int bottom
//rectangle(620,15,630,30);
   while(1)
   {
   getmousepos( &button,  &x, &y );
   if( button & 1 == 1)  //Left mouse button
   {
    if(x>=getmaxx()/2-70-20&&x<=getmaxx()/2+70+80&&y>=getmaxy()/3-30&&y<=getmaxy()/3+30)
    Startplay();
    if(x>=getmaxx()/2-70-20&&x<=getmaxx()/2+70+80&&y>=getmaxy()/3-30+90&&y<=getmaxy()/3+30+90)
    Walloffame();
    if(x>=getmaxx()/2-70-20&&x<=getmaxx()/2+70+80&&y>=getmaxy()/3-30+180&&y<=getmaxy()/3+30+180)
    About();
    if(x>=620&&x<=630&&y<=30&&y>=15)
    {
      delay(1000);
      exit(0);
    }
   }//button &1
   }
   }
void About()
{
cleardevice();
setbkcolor(0);
setcolor(RED);
settextstyle(5,0,5);//style,direction,size
outtextxy(170,25,"HOW TO PLAY\? ");
setcolor(WHITE);
outtextxy(171,25,"HOW TO PLAY\? ");

char c=4;
char ch[3];
gcvt(c,5,ch);

settextstyle(1,0,5);
fstream KBfile;
KBfile.open("H:RULE.som",ios::binary|ios::in);
if(!KBfile)
outtextxy(10,30,"File not found!!");
else
{ char temp;
 outtextxy(5,35,ch);
 KBfile.get(temp);
 while(!KBfile.eof())
 { if(temp=='\n')
   {
     outtext("\n\n");
     outtext(ch);
   }//if \n
  else
  { char cha[5];
	gcvt(temp,5,cha);
  outtext(cha);
  }
 KBfile.get(temp);
 }//while
}//else
KBfile.close();
bar(10,getmaxy()-20,50,getmaxy());
settextstyle(2,0,4);
outtextxy(20,getmaxy()-10,"BACK");
while(1)
{
 getmousepos( &button,  &x, &y );
   if( button & 1 == 1)  //Left mouse button
   {
 if(x>=20&&x<=50&&y>=getmaxy()-20&&y<=getmaxy())
 Mainpage();
}}
}//about
void Displaytree(int i)//i- question to be ans
{  int yadd=0;
  cleardevice();
 for(int j=1;j<=11;j++)
 {
 if(j==11-(i-1)||(j==7&&i==7))
 Drawhexa(getmaxx()/2+100,30+yadd,10,15,200,1);
 else if(j==7)
 Drawhexa(getmaxx()/2+100,30+yadd,10,15,200,2);
 else
 Drawhexa(getmaxx()/2+100,30+yadd,10,15,200,3);
 yadd+=40;
 }
 settextstyle(5,0,2);
 outtextxy(getmaxx()/2+120,15,"$1,000,000,000");
 outtextxy(getmaxx()/2+153,55,"$10,000,000");
 outtextxy(getmaxx()/2+154,95,"$1,000,000");
 outtextxy(getmaxx()/2+155,135,"$500,000");
  outtextxy(getmaxx()/2+155,175,"$250,000");
  outtextxy(getmaxx()/2+155,215,"$100,000");
   outtextxy(getmaxx()/2+157,255,"$50,000");
   outtextxy(getmaxx()/2+157,295,"$25,000");
   outtextxy(getmaxx()/2+157,335,"$10,000");
  outtextxy(getmaxx()/2+160,375,"$5000");

 outtextxy(getmaxx()/2+160,415,"$1000");
  if(dip)
  {bar(20,200,130,230);
  outtextxy(20,205,"Double Dip");
  }


if(fif)
   {bar(20,getmaxy()/2,120,getmaxy()/2+30);
    outtextxy(25,getmaxy()/2,"50-50");
   }
   if(exp)
   { bar(20,getmaxy()/2+40,120,getmaxy()/2+70) ;
    settextstyle(5,0,1);
    outtextxy(20,getmaxy()/2+40,"Expert advice");
   }
   if(e20)
   { bar(20,getmaxy()/2+80,120,getmaxy()/2+110);
    settextstyle(5,0,1);
    outtextxy(23,getmaxy()/2+80,"Extra 20");
    }

}

void Walloffame()
{   cleardevice();
  setbkcolor(0);
 Drawhexa(20,40,30,30,getmaxx()-100,3);//for heading

   settextstyle(5,0,5);//style,direction,size
   outtextxy(getmaxx()/2-100,10,"Wall of Fame");
   settextstyle(5,0,3);
   outtextxy(70,60,"Player Name");
   outtextxy(390,60,"Money Won");


   bar(20,getmaxy()-60,100,getmaxy()-30);//left, top, right,bottom
   settextstyle(6,0,3);
   outtextxy(30,getmaxy()-60,"BACK");

   fstream KBfile;
   KBfile.open("H:FAME.QUE",ios::binary|ios::in|ios::out);
   if(!KBfile)
   outtextxy(10,20,"File not found!!");
   else
   {
     Score dum; int a=0,b=0,cou=0;//cou-how many r displayed already
     KBfile.read((char*)&dum,sizeof(dum));
     while(!KBfile.eof()&&cou==5)
     {

	char cha[5];
	gcvt(cou+1,5,cha);
	outtextxy(22+a,145+b,cha);
	outtextxy(25+a,145+b,". ");
	outtextxy(40+a,145+b,dum.name);
	a+=320;
	outtextxy(22+a,145+b,"$ ");
	gcvt(dum.monwon,5,cha);
	outtextxy(40+a,145+b,cha);
	a-=320;
	b+=30;
	cou++;
	KBfile.read((char*)&dum,sizeof(dum));
     }

   }
   KBfile.close();
   while(1)
   {
    getmousepos( &button,  &x, &y );
   if( button & 1 == 1)  //Left mouse button
   {
   if(x>=20&&x<=100&&y>=getmaxy()-60&&y<=getmaxy()-30)
   {
    Mainpage();
   }
    }
 }//while
}
int Askq(int qno)//increments money
{//pikc a random question from the set of questions
  //display the question and know whether the users ans is ocrretc or not
  Question dup;
  fstream KBfile;

   if(!KBfile)
   outtextxy(10,20,"FILE NOT FOUND!!")   ;

else
{
 switch(qno)
  {case 1:KBfile.open("h:q001.som",ios::in|ios::out|ios::binary);break;
   case 2:KBfile.open("h:q001.som",ios::in|ios::out|ios::binary);break;
   case 3:KBfile.open("h:q001.som",ios::in|ios::out|ios::binary);break;
   case 4:KBfile.open("h:q001.som",ios::in|ios::out|ios::binary);break;
   case 5:KBfile.open("h:q001.som",ios::in|ios::out|ios::binary);break;
   case 6:KBfile.open("h:q001.som",ios::in|ios::out|ios::binary);break;
   case 7:KBfile.open("h:q001.som",ios::in|ios::out|ios::binary);break;
   case 8:KBfile.open("h:q001.som",ios::in|ios::out|ios::binary);break;
   case 9:KBfile.open("h:q001.som",ios::in|ios::out|ios::binary);break;
   case 10:KBfile.open("h:q001.som",ios::in|ios::out|ios::binary);break;
   case 11:KBfile.open("h:q001.som",ios::in|ios::out|ios::binary);break;

   }
int num;


KBfile.seekg(0,ios::end);
int size=KBfile.tellg();
int nofq=(size-1)/sizeof(dup);
num=rand()%nofq+1;
KBfile.seekg(0);
KBfile.read((char*)&dup,sizeof(dup)); char dfg[30]="no";
int i=1; int flag=0; Question temp;int flagf=0;
while(!KBfile.eof())//selecting a random q
{
 if(flag==0&&dup.Status==0)
 {temp=dup;flag=1;}
  if(i==num)//status later
  {
   if(dup.Status==0)
    {flagf=1;   strcpy(dfg,"yes");
      KBfile.seekp(KBfile.tellg()-sizeof(dup));
      dup.Status=1;
      for(int e=0;e<sizeof(dup); e++)
      KBfile.write((char*)&dup,1);
       break;
    }
   else//if(status==1)
     num++;

  }//if i==num
  KBfile.read((char*)&dup,sizeof(dup));
  i++;

}
if(flagf==0)
{
 if(flag==1)
 {
   KBfile.seekg(0);
  KBfile.seekp(0);
   KBfile.read((char*)&dup,sizeof(dup));
  while(!KBfile.eof())
  { if(!strcmpi(dup.quest,temp.quest))
    { KBfile.seekp(KBfile.tellg()-sizeof(dup));
      dup.Status=1;
      for(i=0;i<sizeof(dup);i++)
 { KBfile.write((char*)&dup,1);  }
  break;
    }

  }
  dup=temp;
  }
else//all are used....set status=0;..read first one
 {
  KBfile.seekg(0);
  KBfile.seekp(0);
   KBfile.read((char*)&dup,sizeof(dup));
  while(!KBfile.eof())
  {
    dup.Status=0;
    KBfile.write((char*)&dup,sizeof(dup));

   KBfile.read((char*)&dup,sizeof(dup));
  }
   KBfile.seekg(0);
   KBfile.seekp(0);
    KBfile.read((char*)&dup,sizeof(dup));
    dup.Status=1;
    KBfile.write((char*)&dup,sizeof(dup));

 }
}
display(dup);
outtext(dfg);
}//else
KBfile.close();
   //display part is done
  start=clock(), end=clock();
  int flag=0;
   while(1)
   {   int TimeSec;
     cout<<"00:";
    end = clock() ;
    if(flag==1)
    {TimeSec = 60-(int)(end - start) / CLK_TCK+20;flag=0;}
    else
    TimeSec = 60-(int)(end - start) / CLK_TCK;
    gotoxy(35, 4);
    cout<<TimeSec ;
	delay( 100 );
      if(!TimeSec)
      {cout<<"\n\n Time up!!";
      cleardevice();
       outtextxy(50,50," Thank you for playing!!!");
       outtextxy(50,80," Enter your name : ");
       gotoxy(0,100);



       getch();
       exit(0);
       }



	getmousepos( &button,&x, &y );
   if( button & 1 == 1)  //Left mouse button
   {if(x>=50&&x<=(getmaxx()-170)/2+50&&y>=2*getmaxy()/3-30&&y<=2*getmaxy()/3+30)//op1 //hv a problem with hexagon


	   if(dipactive&&dup.Rans!=1)
	  { dipactive=0;
	      Drawhexa(20,2*getmaxy()/3,30,30,(getmaxx()-170)/2,4);

	      outtextxy(35,2*getmaxy()/3-10, "A.");
	      outtextxy(45,2*getmaxy()/3-10,dup.o1.op);
	      delay(1000);
	     continue; }
	    else if(dup.Rans==1)
	 {moneywon=dup.money;
	 if(moneywon==50000)
	 permawon=50000;
	 return 1;}
       else return 0;
      if(x>=120+(getmaxx()-170)/2&&x<=120+getmaxx()-170&&y<=2*getmaxy()/3+30&&y>=2*getmaxy()/3-30)//op2


	   if(dipactive&&dup.Rans!=2)
	  { dipactive=0;
	  Drawhexa(90+(getmaxx()-170)/2,2*getmaxy()/3,30,30,(getmaxx()-170)/2,4);
	     outtextxy(90+(getmaxx()-170)/2+15,2*getmaxy()/3-10, "B.");
	  outtextxy(90+(getmaxx()-170)/2+25,2*getmaxy()/3-10,dup.o2.op);
	  delay(1000);
	     continue; }
	    else if(dup.Rans==2)
	 {moneywon=dup.money;
	 if(moneywon==50000)
	 permawon=50000;
	 return 1;

	}
       else return 0;
      if(x>=50&&x<=(getmaxx()-170)/2+50&&y>=2*getmaxy()/3+50&&y<=2*getmaxy()/3+110)//op3


	   if(dipactive&&dup.Rans!=3)
	  { dipactive=0;
	      Drawhexa(20,2*getmaxy()/3+80,30,30,(getmaxx()-170)/2,4);
	      outtextxy(35,2*getmaxy()/3+70, "C.");
	       outtextxy(45,2*getmaxy()/3+70,dup.o3.op);
	       delay(1000);
	     continue; }
	     else if(dup.Rans==3)
	{
		moneywon=dup.money;
		if(moneywon==50000)
		permawon=50000;
		return 1;}
       else return 0;
      if(x>=120+(getmaxx()-170)/2&&x<=120+getmaxx()-170&&y>=2*getmaxy()/3+50&&y<=2*getmaxy()/3+110)//op4


	   if(dipactive&&dup.Rans!=4)
	  { dipactive=0;

	     Drawhexa(90+(getmaxx()-170)/2,2*getmaxy()/3+80,30,30,(getmaxx()-170)/2,4);
	     outtextxy(90+(getmaxx()-170)/2+15,2*getmaxy()/3+70, "D.");
	     outtextxy(90+(getmaxx()-170)/2+25,2*getmaxy()/3+70,dup .o4.op);
	     delay(1000);
	     continue; }
	   else  if(dup.Rans==4)
	{moneywon=dup.money;
	if(moneywon==50000)
	 permawon=50000;
       return 1;	}
       else return 0;

      if(x>=getmaxx()-320&&y>=10&&x<=getmaxx()-220&&y<=30)
      if(!expq)if(fif)
      fifty(dup);
      if(x>=getmaxx()-210&&y>=10&&x<=getmaxx()-110&&y<=30)
      if(!expq)if(exp)
      expadv(dup);
      //extra 20
      if(x>=getmaxx()-100&&y>=10&&x<=getmaxx()&&y<=30)
      if(!expq)if(e20)
      {flag=1;e20=0;display(dup);}
      if(!expq)if(dip)
       if(x>=getmaxx()-430&&y>=10&&x<=getmaxx()-330&&y<=30) //for dip
	Dip();
   }

   }//while for selecting
}
void SaveinFame(Score player)
{
 fstream KBfile,Kfile;Score dup;
 KBfile.open("H:FAME.QUE",ios::binary|ios::out|ios::in);
 if(!KBfile)
 outtextxy(10,20,"File not found!!!");

 else
 { Kfile.open("H:FAMEdup.QUE",ios::binary|ios::out|ios::in);
  if(!Kfile)
  outtextxy(10,20,"File not found!!!");
  else
  {
  KBfile.read((char*)&dup,sizeof(dup));
  while(!KBfile.eof())
  {
   if(player.monwon>=dup.monwon)
   {
     Kfile.write((char*)&player,sizeof(player));
     Kfile.write((char*)&dup,sizeof(dup));
   }
   else
   {
   Kfile.write((char*)&dup,sizeof(dup));
   }

  KBfile.read((char*)&dup,sizeof(dup));
 }//while
 Kfile.close();
 }
 KBfile.close();
  }
  remove("H:FAME.QUE");
 rename("H:FAMEdup.QUE","H:FAME.QUE");
}
void Repeat(int retval,int i)
{
  Score player;
 while(i!=11)
  {
  retval=Askq(i);
  if(retval==1&&i!=11)
  {  cleardevice();
  Displaytree(i);
   outtextxy(10,15,"That's the right answer!!!You won $");
   char cha[20];
	gcvt(moneywon,20,cha);
   outtextxy(325,15,cha);
   outtextxy(10,35,"Do you want to continue ?");
    bar(10,70,70,110);//left, top, right,bottom //yes
    outtextxy(14,75," YES ");
     bar(150,70,210,110);//NO
    outtextxy(154,70," NO ");
    while(1)
    {  getmousepos( &button,  &x, &y );
   if( button & 1 == 1)  //Left mouse button
   {
      if(x>=150&&y>=70&&x<=210&&y<=110)//no
      {
     cleardevice();
       outtextxy(50,50," Thank you for playing!!!");
       outtextxy(50,80," Enter your name : ");
       gotoxy(0,100);
       gets(player.name);
       char cha[20];
	gcvt(moneywon,20,cha);
   outtextxy(325,15,cha);

       player.monwon=moneywon;
       SaveinFame(player);
       getch();
       exit(0);
      }
      if(x>=10&y>=70&&x<=80&&y<=110)//yes
      {
	 delay(500);
	clrscr();
	Displaytree(i+1);
       //left, top, right,bottom
	outtextxy(20,getmaxy()-20,"Click 'PLAY' to continue...");
	bar(getmaxx()/2-50,getmaxy()-50,getmaxx()/2+50,getmaxy()-20);//left, top, right,bottom
	outtextxy(getmaxx()/2-25,getmaxy()-35,"PLAY");
	 while(1)
	 {  getmousepos( &button,  &x, &y );
   if( button & 1 == 1)  //Left mouse button
   {

	 if(x>=getmaxx()/2-50&&y>=getmaxy()-50&&x<=getmaxx()/2+50&&y<=getmaxy()-20)//play
	   Repeat(retval,++i);
	 }
	  }//while inside

      }//if yes
      }
    }//while outside
  }//if right
 else if(retval==1&&i==11)
 { //try inluding some animations
  clrscr ();
  outtextxy(10,30,"That was right!!!Congratulations!!!!...You won $1000,000,000!!!!");
  outtextxy(20,70,"Thank you for playing the game!!...");
  outtextxy(30,100,"Please enter your name : ");
  gotoxy(100,70);gets(player.name);
  player.monwon=1000000000;
  SaveinFame(player);
 }//11 orret
 else
 {cleardevice();
 settextstyle(11,0,3);
  outtextxy(30,50,"OOPS...You got that wrong!!!Better luck next time!!You win $");
  char cha[20];
	gcvt(permawon,20,cha);
  outtext(cha);
  outtextxy(50,70,"Please enter your name : ");
  gets(player.name); //save in the drive
  player.monwon=permawon;
  if(!permawon)
   SaveinFame(player);
  delay(1000);
  exit(0);
 }

 i++;
 }//while outside
}
void Realgame()
{int retval;int i=1;

 Repeat(retval,i);


}
void Startplay()
{
 setbkcolor(0);
 cleardevice();
 Displaytree(1);

 setcolor(RED);
 bar(5,getmaxy()-40,105,getmaxy()-10);//left, top, right,bottom
 settextstyle(1,0,3);
   outtextxy(11,getmaxy()-49,"BACK");
    bar(getmaxx()/2-100,getmaxy()-50,getmaxx()/2-10,getmaxy()-20);//left, top, right,bottom
   settextstyle(1,0,3);
   outtextxy(getmaxx()/2-85,getmaxy()-55,"PLAY");
  while(1)
  {
   getmousepos( &button,  &x, &y );
   if( button & 1 == 1)  //Left mouse button
   {
   if(x>=5&&x<=105&&y>=getmaxy()-40&&y<=getmaxy()-10)//back
   {
    Mainpage();
   }
   if(x>=getmaxx()/2-100&&x<=getmaxx()/2-10&&y>=getmaxy()-50&&y<=getmaxy()-20)//start
   {
    Realgame();
   }
   }

  }//WHILE
}//startplay
void main()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "");
randomize();
initmouse();
showmouseptr();
//mouse initialise
 Mainpage();
 closegraph();

}//main
