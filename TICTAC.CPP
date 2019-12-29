#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
char a[9]={0,0,0,0,0,0,0,0,0};
char arr[9];
char arr1[9];
	char p1name[20],p2name[20];

void Instruction()
{
    cout<<"-------------------------------------PLEASE READ INSTRUCTION CAREFULLY----------------------------"<<endl;
    cout<<"1.ONLY TWO PLAYER CAN PLAY THE GAME."<<endl;
    cout<<"2.CHOOSE Capital 'X' LETTER NOT SMALLER 'X' LETTER."<<endl;
    cout<<"3.STARTING POISTION IS 0 AND LAST IS 8 POISITION";
    cout<<"4.IF ANY PLAYER ENETR POISITION OF EXISTING POISTION THEN ANOTHER PLAYER WILL WIN."<<endl;
    cout<<"5.IF PLAYER ENTER POISTION MORE THAN 9 THEN HE/SHE WILL SKIP THIER CHANCE FOR FILLING X OR 0 IN TIC TAC TOE."<<endl;
    cout<<"6.GAME CAN BE DRAW OR WIN BY PLAYER."<<endl;
    cout<<"--------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
}
int checkDraw()
{
    int i;
    int k=0;
    for(i=0;i<9;i++)
    {
        if(a[i]!=0) k++;
    }
    if(k==9) return 1;
    else return 0;

}

int  player1()
{
    int poi;
    cout<<p1name<<endl;
    cout<<"Enter The position for Tic and Tac:";
    cin>>poi;
    return poi;
}

int player2()
{
    int poi;
    cout<<p2name<<endl;
    cout<<"Enter The position for Tic and Tac:";
    cin>>poi;
    return poi;
}

void display(int poi=0,char z=' ')
{

    a[poi]=z;
    cout<<"     "<< a[0] <<"   |      "<< a[1] <<"   |      "<<a[2];
	cout<<endl<<"_________|__________|_________ "<<endl;
	cout<<"         |          |     "<<endl;
	cout<<"     "<<a[3]<<"   |       "<<a[4]<<"  |      "<<a[5];
	cout<<endl<<"_________|__________|_________ "<<endl;
	cout<<"         |          |     "<<endl;
	cout<<"     "<<a[6]<<"   |       "<<a[7]<<"  |      "<<a[8];
	cout<<endl<<"_________|__________|_________ "<<endl;
	cout<<"         |          |     "<<endl;
}

int checkWinPlayer1(char c,int poi)
{
    arr1[poi]=c;
    if(arr1[0]==c && arr1[4]==c && arr1[8]==c)
    {
	return 1;
    }
    if(arr1[0]==c && arr1[3]==c && arr1[6]==c)
    {
       return 1;
    }
    if(arr1[0]==c && arr1[1]==c && arr1[2]==c)
    {
       return 1;
    }
    if(arr1[3]==c && arr1[4]==c &&arr1[5]==c)
    {
       return 1;
    }
    if(arr1[6]==c && arr1[7]==c && arr1[8]==c)
    {
       return 1;
    }
    if(arr1[1]==c && arr1[4]==c &&arr1[7]==c)
    {
       return 1;
    }
    if(arr1[2]==c && arr1[5]==c && arr1[8]==c)
    {
       return 1;
    }
      if(arr1[2]==c && arr1[4]==c && arr1[6]==c)
    {
      return 1;
    }
    return 0;
}

int checkWinPlayer2(char c,int poi)
{
    arr[poi]=c;
    if(arr[0]==c && arr[4]==c && arr[8]==c)
    {
	return 1;
    }
    if(arr[0]==c && arr[3]==c &&arr[6]==c)
    {
       return 1;
    }
    if(arr[0]==c && arr[1]==c && arr[2]==c)
    {
       return 1;
    }
    if(arr[3]==c && arr[4]==c &&arr[5]==c)
    {
       return 1;
    }
    if(arr[6]==c && arr[7]==c && arr[8]==c)
    {
       return 1;
    }
    if(arr[1]==c && arr[4]==c &&arr[7]==c)
    {
	return 1;
    }
    if(arr[2]==c && arr[5]==c && arr[8]==c)
    {
	return 1;
    }
      if(arr[2]==c && arr[4]==c && arr[6]==c)
    {
	return 1;
    }
    return 0;
}
int checkpoi(int poi)
{
    if(arr[poi]!=0 && arr1[poi]!=0) return 1;
    else return 0;

}

int main()
{
//	clrscr();

    Instruction();
	display();
	cout<<endl<<endl<<"--------------------------------GAME START------------------------------------"<<endl<<endl;

	char p1,p2;
    char choice;
    cout<<"-------------------------------------------ENTER PLAYERS NAME------------------------------"<<endl;
    cout<<"Enter player1 name: ";
    gets(p1name);
    fflush(stdin);
    cout<<"Enter player2 name: ";
    gets(p2name);
    
    cout<<endl<<"--------------------------------------------------------------------------------------"<<endl;
	 cout<<p1name<<endl;
	 fflush(stdin);
    cout<<"choose symbol X | 0 : ";
    cin>>choice;
    cout<<endl<<"------------------------------------------------------------------------------------------"<<endl;

    if(choice=='X'||choice=='0')   {}
    else
    {
            cout<<"Sorry! plz choose valid option "<<endl;
            return 0;
    }

	p1=choice;

    if(p1!='X')
    {
	p2='X';
	p1='0';
    }
    else
    {
	p1='X';
	p2='0';
    }


   int p1_poi,p2_poi;

    while(1)
    {
    // player 1
        p1_poi=player1();
        if(a[p1_poi]==p2 || checkpoi(p1_poi)==1)
        {

            cout<<endl<<"                  SOORY "<<p1name<<" LOST GAME            "<<p2name <<" WIN THE GAME" ;
            getch();
            return 0;
        }
       else
       {
           display(p1_poi,p1);

            if(checkWinPlayer1(p1, p1_poi)==1)
            {
                cout<<endl<<p1name<<" win ";
                getch();
                return 0;
            }
       }
         if(checkDraw()==1)
        {
            cout<<"Draw";
            getch();
            return 0;
        }
// player 2
       p2_poi=player2();

       if(a[p2_poi]==p1 || checkpoi(p2_poi)==1)
       {
                cout<<endl<<"                  SOORY "<<p2name<<" LOST GAME            " <<p1name<<" WIN THE GAME";getch(); return 0;


       }
       else
       {
           display(p2_poi,p2);
           if(checkWinPlayer2(p2, p2_poi)==1)
            {
                cout<<endl<<p2name<<" win";
                break;
            }
       }

        if(checkDraw()==1)
        {
            cout<<"Draw";
            getch();
            return 0;
        }

   }
    cout<<endl<<"--------------------------------------GAME OVER--------------------------------------------";
    getch();
    return 0;
}
