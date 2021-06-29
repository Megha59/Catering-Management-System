#include<constream.h>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<ctype.h>
int driver=DETECT,mode;
double zak=0;
class menu{
public:
void main_menu(void);
private:
void edit_menu(void);
};

class cuisine
{
public :
    void add_cuis(void) ;
    void delete_cuis(void) ;
    void modify_cuis(void) ;
    void list_of_cuis(void) ;
    void purchase(void) ;
private :
    int last_code(void) ;
    void delete_record(int) ;
    void modify_record(int) ;
    void display_record(int) ;
    int cuis_found(int) ;
    int recordno(int) ;
    void sort(void) ;

    int cuiscode ;
    char cuisname[30] ;
    float cuiscost, cuisprice ;
} ;


//**********************************************************
// CLASS NAME : Account
// DETAILS : IT CONTROLLS OVER ALL THE FUNCTIONS
// RELATED TO MAKING BILL
//**********************************************************

class account
{
public :
    void bill_list(void) ;
    void prepare_bill(int) ;
    int last_billno(void) ;
    void add_bill(int, int t_cuiscode, char *t_cuisname, float t_qty,
                  float t_cost, float t_price) ;
private :
    int code, billno, length ;
    int dd, mm, yy ;
    float cost, price, guests ;
    char name[30] ;
} ;

///////////////////////logo/////////////////////////////////////////
void logo()
{    clrscr();

{
initgraph(&driver,&mode,"c://turboc3//bgi");
cout<<"WELCOME";
}
}
///////////////////////////exit///////////////////////////
void exit()
{            closegraph();

clrscr();  int i;
initgraph(&driver,&mode,"c://turboc3//bgi");
setcolor(RED); int b=640;
outtextxy(270,220,"shutting down..");
for(i=1;i<=320;i++)
{  setfillstyle(SOLID_FILL,RED);
bar(1,480,i,1);
setcolor(BLACK);
outtextxy(i-40,220,"THANK ");
bar(640,1,b,480);
outtextxy(b+10,220,"YOU ");
delay(20); ;b--;
}
delay(2000);closegraph();
}
/////////////////////////////////////////////////////////////////////
///////////////////////////animated-menu function////////////////////////////
void menu :: main_menu(void)
{
clrscr();
char ch;
while(1){
clrscr();
initgraph(&driver,&mode,"");
outtextxy(275,116,"MAIN MENU");
setcolor(RED);
rectangle(260,100,360,130);
for(int i=100;i>=80;i--)
{    delay(5);
 for(int j=150;j>=130;j--)
rectangle(270,i,350,j);
}
delay(10);
//////////////////////////////////////////////
for(i=200;i<=420;i++)
{ setcolor(BLACK);
outtextxy(240,196,"LOADING...");
setfillstyle(SOLID_FILL,RED);
bar(200,215,i,185);
delay(1);
}
outtextxy(240,196,"1....Place order");
setcolor(GREEN);
rectangle(200,185,420,215);
       delay(1);
///////////////////////////////////////////////
for(i=200;i<=420;i++)
{ setcolor(BLACK);
outtextxy(240,230,"LOADING...");
setfillstyle(SOLID_FILL,RED);
bar(200,250,i,220);
delay(1);
}
outtextxy(240,230,"2.....List of cuisines");
setcolor(WHITE);
rectangle(200,220,420,250);
   delay(1);
///////////////////////////////////////////////
for(i=200;i<=420;i++)
{ setcolor(BLACK);
outtextxy(240,265,"LOADING...");
setfillstyle(SOLID_FILL,RED);
bar(200,285,i,255);
delay(1);
}
outtextxy(240,265,"3.....modify cuisine details");
setcolor(BLUE);
rectangle(200,255,420,285);  delay(1);
//////////////////////////////////////////////////
for(i=200;i<=420;i++)
{ setcolor(BLACK);
outtextxy(240,300,"LOADING...");
setfillstyle(SOLID_FILL,RED);
bar(200,320,i,290);
delay(1);
}
outtextxy(240,300,"4.....bill report");
setcolor(15);
rectangle(200,290,420,320);
     delay(1);
/////////////////////////////////////////

for(i=200;i<=420;i++)
{ setfillstyle(3,RED);
outtextxy(240,445,"LOADING...");
bar(200,465,i,435);
delay(1);
}
outtextxy(240,445,"e..exit");
setcolor(14);
rectangle(200,435,420,465);
ch=getche();
if (ch == '1')
        {
            cuisine p ;
            p.purchase() ;
        }
        else if (ch == '2')
        {
            cuisine p ;
            p.list_of_cuis() ;
        }
        else if (ch == '3')
            edit_menu() ;
        else if (ch == '4')
        {
            account a ;
            a.bill_list();
        }
	else if (ch == 'e')
            break ;
    }
}

void menu :: edit_menu(void)
{
	char ch;
while(1)
{
clrscr();
initgraph(&driver,&mode,"");
outtextxy(275,116,"EDIT MENU");
setcolor(RED);
rectangle(260,100,360,130);
for(int i=100;i>=80;i--)
{    delay(5);
 for(int j=150;j>=130;j--)
rectangle(270,i,350,j);
}
delay(10);
//////////////////////////////////////////////
for(i=200;i<=420;i++)
{ setcolor(BLACK);
outtextxy(240,196,"LOADING...");
setfillstyle(SOLID_FILL,RED);
bar(200,215,i,185);
delay(1);
}
outtextxy(240,196,"1..Add cuisine");
setcolor(GREEN);
rectangle(200,185,420,215);
       delay(1);
///////////////////////////////////////////////
for(i=200;i<=420;i++)
{ setcolor(BLACK);
outtextxy(240,230,"LOADING...");
setfillstyle(SOLID_FILL,RED);
bar(200,250,i,220);
delay(1);
}
outtextxy(240,230,"2..modify cuisine");
setcolor(WHITE);
rectangle(200,220,420,250);
   delay(1);
///////////////////////////////////////////////
for(i=200;i<=420;i++)
{ setcolor(BLACK);
outtextxy(240,265,"LOADING...");
setfillstyle(SOLID_FILL,RED);
bar(200,285,i,255);
delay(1);
}
outtextxy(240,265,"3..delete cuisine");
setcolor(BLUE);
rectangle(200,255,420,285);  delay(1);
//////////////////////////////////////////////////

////////////////////////////////////////////////
outtextxy(240,445,"e..exit");
setcolor(14);
rectangle(200,435,420,465);
ch=getche();
if (ch == '1')
        {
	 cuisine p ;
            p.add_cuis() ;
            break ;
        }
        else if (ch == '2')
        {
            cuisine p ;
            p.modify_cuis() ;
            break ;
        }
        else if (ch == '3')
        {
            cuisine p ;
            p.delete_cuis() ;
            break ;
        }
	else if (ch == 'e')
            break ;
    }
}
///////////////////////////////////////////////////////////////////////////
int cuisine :: last_code(void)
{
    fstream file ;
    file.open("cuisine.txt", ios::in) ;
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(cuisine)))
        t = cuiscode ;
    file.close() ;
    return t ;
}
/////////////////////////////////////////////////////////////////////////////////


///////////////////////////startup_animation/////////////////////////

void startup()
{         closegraph();
initgraph(&driver,&mode,"c://turboc3//bgi");

clrscr();
setcolor(RED);
outtextxy(270,220,"STARTING UP..");
for(int u=0;u<3;u++)
{for(int k=270;k<=379;k++)
{setfillstyle(SOLID_FILL,BLACK);
bar(270,234,389,231);
rectangle(270,230,390,235);
setfillstyle(1,GREEN);
bar(k,234,k+10,231);
delay(5);
}}
delay(300);}
//////////////////////////non-animated menu///////////////////////////


void cuisine :: list_of_cuis(void)
{
    clrscr() ;
    fstream file ;
    file.open("cuisine.txt", ios::in) ;
    file.seekg(0) ;
    int row = 6 , found = 0 ;
    gotoxy(30,2) ;
    cout <<"LIST OF CUISINES" ;
    gotoxy(3,4) ;
    cout <<"CUISINE CODE CUISINE NAME CUISINE COST LABOUR PRICE" ;
    gotoxy(2,5) ;
    cout <<"***********************************************************" ;
    while (file.read((char *) this, sizeof(cuisine)))
    {
        delay(20) ;
        found = 1 ;
        gotoxy(5,row) ;
        cout <<cuiscode ;
        gotoxy(14,row) ;
        cout <<cuisname ;
        gotoxy(37,row) ;
        cout <<cuiscost ;
        gotoxy(51,row) ;
        cout <<cuisprice ;
        if ( row == 22 )
        {
            row = 5 ;
            gotoxy(1,25) ;
            cout <<"Press any key to continue..." ;
            getche() ;
            clrscr() ;
            gotoxy(30,2) ;
            cout <<"LIST OF CUISINES" ;
            gotoxy(3,4) ;
            cout <<"CUISINE CODE CUISINE NAME CUISINE COST LABOUR PRICE" ;
            gotoxy(2,5) ;
            cout <<"***********************************************************"
                 ;
        }
        else
            row++ ;
    }
    if ( !found )
    {
        gotoxy(5,10) ;
        cout <<"\7Records not found" ;
    }
    gotoxy(1,25) ;
    cout <<"Press any key to continue..." ;
    getche() ;
    file.close () ;
}
//////////////////////////////////////////////////////////////////////////////////////
void cuisine :: add_cuis(void)
{
    int tcode, valid ;
    char ch, t_cuiscost[10], t_cuisprice[10] ;
    tcode = last_code() ;
    tcode++ ;
    do
    {
        clrscr() ;
        gotoxy(71,2) ;
        cout <<"<0>=Exit" ;
        gotoxy(27,3) ;
        cout <<"ADDITION OF CUISINES" ;
        gotoxy(26,4) ;
        cout <<"********************" ;
        gotoxy(5,6) ;
        cout <<"Cuisine Code : " <<tcode ;
        gotoxy(5,8) ;
        cout <<"Cuisine Name : " ;
        gotoxy(5,10) ;
        cout <<"Cuisine Cost : " ;
        gotoxy(5,12) ;
        cout <<"Labour Price : " ;
        do
        {
            valid = 1 ;
            gotoxy(1,8) ;
            clreol() ;
            gotoxy(1,24) ;
            clreol() ;
            gotoxy(1,25) ;
            clreol() ;
            gotoxy(3,25) ;
            cout <<"ENTER CUISINE NAME TO ADD IN THE MENU" ;
            gotoxy(5,8) ;
            cout <<"Cuisine Name : " ;
            gets(cuisname) ;
            strupr(cuisname) ;
            if (cuisname[0] == '0')
                return ;
            if ((strlen(cuisname) < 1) || (strlen(cuisname) > 20))
            {
                valid = 0 ;
                gotoxy(3,24) ;
                cout <<"\7 Range = 1..20" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            valid = 1 ;
            gotoxy(1,10) ;
            clreol() ;
            gotoxy(1,24) ;
            clreol() ;
            gotoxy(1,25) ;
            clreol() ;
            gotoxy(3,25) ;
            cout <<"ENTER CUISINE COST TO ADD IN THE MENU" ;
            gotoxy(5,10) ;
            cout <<"Cuisine Cost : " ;
            gets(t_cuiscost) ;
            cuiscost = atof(t_cuiscost) ;
            if (t_cuiscost[0] == '0')
                return ;
            if (cuiscost < 1 || cuiscost > 80000)
            {
                valid = 0 ;
                gotoxy(3,24) ;
                cout <<"\7 Range = 1..80000" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            valid = 1 ;
            gotoxy(1,12) ;
            clreol() ;
            gotoxy(1,24) ;
            clreol() ;
            gotoxy(1,25) ;
            clreol() ;
            gotoxy(3,25) ;
            cout <<"ENTER LABOUR PRICE TO ADD IN THE MENU" ;
            gotoxy(5,12) ;
            cout <<"Labour Price : " ;
            gets(t_cuisprice) ;
            cuisprice = atof(t_cuisprice) ;
            if (t_cuisprice[0] == '0')
                return ;
            if (cuisprice < cuiscost || cuisprice > 10000)
            {
                valid = 0 ;
                gotoxy(3,24) ;
                cout <<"\7 Range = " <<cuiscost <<"..10000" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            gotoxy(1,15) ;
            clreol() ;
            gotoxy(1,24) ;
            clreol() ;
            gotoxy(1,25) ;
            clreol() ;
            gotoxy(5,15) ;
            cout <<"Do you want to save this record (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
            if (ch == '0')
                return ;
        }
        while (ch != 'N' && ch != 'Y') ;
        if (ch == 'Y')
        {
            cuiscode = tcode ;
            fstream file ;
	    file.open("cuisine.txt", ios::out | ios::app ) ;
            file.write((char *) this, sizeof(cuisine)) ;
            file.close() ;
            tcode++ ;
        }
        do
        {
            gotoxy(1,17) ;
            clreol() ;
            gotoxy(1,24) ;
            clreol() ;
            gotoxy(1,25) ;
            clreol() ;
            gotoxy(5,17) ;
            cout <<"Do you want to add more records (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
            if (ch == '0')
                return ;
        }
        while (ch != 'N' && ch != 'Y') ;
    }
    while (ch == 'Y') ;
}


//**********************************************************
// THIS FUNCTION DISPLAY THE RECORD OF THE GIVEN CODE FROM
// THE cuisine FILE (cuisine.txt)
//**********************************************************

void cuisine :: display_record(int tcode)
{
    fstream file ;
    file.open("cuisine.txt", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) this, sizeof(cuisine)))
    {
        if (cuiscode == tcode)
        {
            gotoxy(5,3) ;
            cout <<"cuis Code : "<<cuiscode ;
            gotoxy(5,4) ;
            cout <<"cuis Name : "<<cuisname ;
            gotoxy(5,5) ;
            cout <<"cuis Cost : "<<cuiscost ;
            gotoxy(5,6) ;
            cout <<"cuis Price : "<<cuisprice ;
            break ;
        }
    }
    file.close() ;
}


//**********************************************************
// THIS FUNCTION RETURN THE VALUE 1 IF THE RECORD IS FOUND
// FOR THE GIVEN CODE IN THE cuisine FILE (cuisine.txt)
//**********************************************************

int cuisine :: cuis_found(int tcode)
{
    fstream file ;
    file.open("cuisine.txt", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(cuisine)))
    {
        if (cuiscode == tcode)
        {
            found++ ;
            break ;
        }
    }
    file.close() ;
    return found ;
}


//**********************************************************
// THIS FUNCTION RETURN THE RECORD NO. OF THE GIVEN CODE IN
// THE cuisine FILE (cuisine.txt)
//**********************************************************

int cuisine :: recordno(int tcode)
{
    fstream file ;
    file.open("cuisine.txt", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(cuisine)))
    {
        found++ ;
        if (cuiscode == tcode)
            break ;
    }
    file.close() ;
    return found ;
}


//**********************************************************
// THIS FUNCTION DELETES THE RECORD FOR THE GIVEN CODE FROM
// THE cuisine FILE (cuisine.txt)
//**********************************************************

void cuisine :: delete_record(int tcode)
{
    fstream file ;
    file.open("cuisine.txt", ios::in) ;
    fstream temp ;
    temp.open("temp.txt", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
        file.read((char *) this, sizeof(cuisine)) ;
        if ( file.eof() )
            break ;
        if ( cuiscode != tcode )
            temp.write((char *) this, sizeof(cuisine)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("cuisine.txt", ios::out) ;
    temp.open("temp.txt", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
        temp.read((char *) this, sizeof(cuisine)) ;
        if ( temp.eof() )
            break ;
        file.write((char *) this, sizeof(cuisine)) ;
    }
    file.close() ;
    temp.close() ;
}


//**********************************************************
// THIS FUNCTION GIVES THE CODE NO. TO DELETE RECORD FROM
// THE cuisine FILE (cuisine.txt)
//**********************************************************

void cuisine :: delete_cuis(void)
{
    clrscr() ;
    char t_code[5], ch ;
    int t, tcode ;
    gotoxy(3,25) ;
    cout <<"Press <ENTER> to see the list" ;
    gotoxy(5,3) ;
    cout <<"Enter cuisine Code of the cuis to be deleted : " ;
    gets(t_code) ;
    t = atoi(t_code) ;
    tcode = t ;
    if (t_code[0] == '0')
        return ;
    if (tcode == 0)
    {
        list_of_cuis() ;
        gotoxy(1,25) ;
        clreol() ;
        gotoxy(3,25) ;
        cout <<"Press <ENTER> to Exit" ;
        gotoxy(5,24) ;
        cout <<"Enter cuisine Code of the cuisine to be deleted : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (tcode == 0)
            return ;
    }
    clrscr() ;
    if (!cuis_found(tcode))
    {
        gotoxy(5,5) ;
        cout <<"\7Record not found" ;
        getch() ;
        return ;
    }
    display_record(tcode) ;
    do
    {
        gotoxy(1,8) ;
        clreol() ;
        gotoxy(5,8) ;
        cout <<"Do you want to delete this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    delete_record(tcode) ;
    gotoxy(5,15) ;
    cout <<"\7Record Deleted" ;
    getch() ;
}


//**********************************************************
// THIS FUNCTION MODIFY THE RECORD FOR THE GIVEN CODE FROM
// THE cuisine FILE (cuisine.txt)
//**********************************************************

void cuisine :: modify_record(int tcode)
{
    int recno ;
    recno = recordno(tcode) ;
    int valid, t_code ;
    char ch, t_cuiscost[10], t_cuisprice[10], t_cuiscode[5] ;
    gotoxy(71,2) ;
    cout <<"<0>=Exit" ;
    gotoxy(5,12) ;
    cout <<"cuisine Code : " ;
    gotoxy(5,14) ;
    cout <<"cuisine Name : " ;
    gotoxy(5,16) ;
    cout <<"cuisine Cost : " ;
    gotoxy(5,18) ;
    cout <<"Labour Price : " ;
    do
    {
        gotoxy(20,12) ;
        clreol() ;
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        gotoxy(1,12) ;
        clreol() ;
        gotoxy(1,24) ;
        clreol() ;
        gotoxy(1,25) ;
        clreol() ;
        gotoxy(3,25) ;
        cout <<"ENTER Cuisine CODE TO ADD IN THE MENU" ;
        gotoxy(5,12) ;
        cout <<"cuis Code : " ;
        gets(t_cuiscode) ;
        t_code = atoi(t_cuiscode) ;
        if (t_code == 0)
            return ;
        if (cuis_found(t_code) && t_code != tcode)
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 CODE ALREADY GIVEN" ;
            getch() ;
        }
    }
    do
    {
        gotoxy(20,14) ;
        clreol() ;
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        gotoxy(1,14) ;
        clreol() ;
        gotoxy(1,24) ;
        clreol() ;
        gotoxy(1,25) ;
        clreol() ;
        gotoxy(3,25) ;
        cout <<"ENTER CUISINE NAME TO ADD IN THE MENU" ;
        gotoxy(5,14) ;
        cout <<"Cuisine Name : " ;
        gets(cuisname) ;
        strupr(cuisname) ;
        if (cuisname[0] == '0')
            return ;
        if ((strlen(cuisname) < 1) || (strlen(cuisname) > 20))
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 Range = 1..20" ;
            getch() ;
        }
    }
    do
    {
        gotoxy(20,16) ;
        clreol() ;
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        gotoxy(1,16) ;
        clreol() ;
        gotoxy(1,24) ;
        clreol() ;
        gotoxy(1,25) ;
        clreol() ;
        gotoxy(3,25) ;
        cout <<"ENTER CUISINE COST TO ADD IN THE MENU" ;
        gotoxy(5,16) ;
        cout <<"cuis Cost : " ;
        gets(t_cuiscost) ;
        cuiscost = atof(t_cuiscost) ;
        if (t_cuiscost[0] == '0')
            return ;
        if (cuiscost < 1 || cuiscost > 80000)
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 Range = 1..80000" ;
            getch() ;
        }
    }
    do
    {
        gotoxy(20,18) ;
        clreol() ;
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        gotoxy(1,18) ;
        clreol() ;
        gotoxy(1,24) ;
        clreol() ;
        gotoxy(1,25) ;
        clreol() ;
        gotoxy(3,25) ;
        cout <<"ENTER LABOUR PRICE TO ADD IN THE MENU" ;
        gotoxy(5,18) ;
        cout <<"cuis Price : " ;
        gets(t_cuisprice) ;
        cuisprice = atof(t_cuisprice) ;
        if (t_cuisprice[0] == '0')
            return ;
        if (cuisprice < cuiscost || cuisprice > 10000)
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 Range = " <<cuiscost <<"..10000" ;
            getch() ;
        }
    }
    do
    {
        gotoxy(1,21) ;
        clreol() ;
        gotoxy(1,24) ;
        clreol() ;
        gotoxy(1,25) ;
        clreol() ;
        gotoxy(5,21) ;
        cout <<"Do you want to save this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    cuiscode = t_code ;
    cout <<"\n" <<cuisname ;
    cout <<cuiscost ;
    cout <<cuisprice ;
    getch() ;
    fstream file ;
    file.open("cuisine.txt", ios::out | ios::ate) ;
    int location ;
    location = (recno-1) * sizeof(cuisine) ;
    file.seekp(location) ;
    file.write((char *) this, sizeof(cuisine)) ;
    file.close() ;
    sort() ;
    clrscr() ;
    gotoxy(5,15) ;
    cout <<"\7Record Modified" ;
    getch() ;
}


//**********************************************************
// THIS FUNCTION GIVES THE CODE NO. TO MODIFY RECORD FROM
// THE cuisine FILE (cuisine.txt)
//**********************************************************

void cuisine :: modify_cuis(void)
{
    clrscr() ;
    char t_code[5], ch ;
    int t, tcode ;
    gotoxy(3,25) ;
    cout <<"Press <ENTER> to see the list" ;
    gotoxy(5,3) ;
    cout <<"Enter Cuisine Code of the cuis to be Modify : " ;
    gets(t_code) ;
    t = atoi(t_code) ;
    tcode = t ;
    if (t_code[0] == '0')
        return ;
    if (tcode == 0)
    {
        list_of_cuis() ;
        gotoxy(1,25) ;
        clreol() ;
        gotoxy(3,25) ;
        cout <<"Press <ENTER> to Exit" ;
        gotoxy(5,24) ;
        cout <<"Enter cuisine Code of the cuis to be modify : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (tcode == 0)
            return ;
    }
    clrscr() ;
    if (!cuis_found(tcode))
    {
        gotoxy(5,5) ;
        cout <<"\7Record not found" ;
        getch() ;
        return ;
    }
    display_record(tcode) ;
    do
    {
        gotoxy(5,8) ;
        cout <<"Do you want to Modify this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    modify_record(tcode) ;
}


//****************************************************************
// THIS FUNCTION SORT THE RECORD IN THE cuisine FILE (cuisine.txt)
// ACCORDING TO THE CODE NOS.
//****************************************************************

void cuisine :: sort(void)
{
    int i=0,j ;
    cuisine arr[100] ;
    cuisine temp ;
    fstream file ;
    file.open("cuisine.txt", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) &arr[i], sizeof(cuisine)))
        i++ ;
    int size ;
    size = i ;
    file.close() ;
    for (i=1; i<size; i++)
        for (j=0; j<size-i; j++)
        {
            if (arr[j].cuiscode > arr[j+1].cuiscode)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    file.open("cuisine.txt", ios::out) ;
    for (i=0; i<size; i++)
        file.write((char *) &arr[i], sizeof(cuisine)) ;
    file.close() ;
}


//**********************************************************
// THIS FUNCTION PURCHASES THE cuisine cuis IN THE MENU
//**********************************************************

void cuisine :: purchase(void)
{
    clrscr() ;
    account a ;
    int t_billno, purchased=0 ;
    t_billno = a.last_billno() ;
    t_billno++ ;
    char t_code[5], ch;
    float t_guests ;
    int t, tcode, i=0, valid ;
    float qty ;
    int t_cuiscode ;
    float t_qty, t_cost, t_price ;
    char t_cuisname[30] ;
    struct date d;
    int d1, m1, y1 ;
    getdate(&d);
    d1 = d.da_day ;
    m1 = d.da_mon ;
    y1 = d.da_year ;
    do
    {
        clrscr() ;
        gotoxy(3,25) ;
        cout <<"Press <ENTER> to see the list" ;
        gotoxy(5,3) ;
        cout <<"Enter cuis Code of the cuis to be Purchase : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (t_code[0] == '0')
        {
            if (purchased)
                a.prepare_bill(t_billno) ;
            return ;
        }
        if (tcode == 0)
        {
            list_of_cuis() ;
            gotoxy(1,25) ;
            clreol() ;
            gotoxy(3,25) ;
            cout <<"Press <ENTER> to Exit" ;
            gotoxy(5,24) ;
            cout <<"Enter cuisine Code of the cuis to be Purchase : " ;
            gets(t_code) ;
            t = atoi(t_code) ;
            tcode = t ;
            if (tcode == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno) ;
                return ;
            }
        }
        clrscr() ;
        if (!cuis_found(tcode))
        {
            gotoxy(5,5) ;
            cout <<"\7cuisine Code not found" ;
            getch() ;
            if (purchased)
                a.prepare_bill(t_billno) ;
            return ;
        }
        gotoxy(60,2) ;
        cout <<"Date:" <<d1 <<"/" <<m1 <<"/" <<y1 ;
        display_record(tcode) ;
        do
        {
            valid = 1 ;
            gotoxy(1,8) ;
            clreol() ;
            gotoxy(1,24) ;
            clreol() ;
            gotoxy(1,25) ;
            clreol() ;
            gotoxy(3,25) ;
            cout <<"ENTER NUMBER OF GUESTS :\n" ;
            gotoxy(5,8) ;
            cout <<"No_of_guests : " ;
	    cin>>t_guests ;
	    qty=t_guests ;
	    if (t_guests == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno) ;
                return ;
            }
            if (qty < 1 || qty > 800)
            {
                valid = 0 ;
                gotoxy(3,24) ;
                cout <<"\7 Range = 1..800" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            gotoxy(5,10) ;
            clreol() ;
            gotoxy(5,10) ;
            cout <<"Do you want to cancel this purchase (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
        }
        while (ch != 'N' && ch != 'Y') ;
        if (ch == 'N')
        {
            purchased = 1 ;
            fstream file ;
	    file.open("cuisine.txt", ios::in) ;
            file.seekg(0,ios::beg) ;
            while (file.read((char *) this, sizeof(cuisine)))
            {
                if (cuiscode == tcode)
                {
                    t_cuiscode = cuiscode ;
                    strcpy(t_cuisname,cuisname) ;
                    t_cost = cuiscost ;
                    t_price = cuisprice ;
                    t_qty = qty ;
                    a.add_bill(t_billno,t_cuiscode,t_cuisname,t_qty,t_cost,t_price) ;
                    i++ ;
                    break ;
                }
            }
            file.close() ;
        }
        do
        {
            gotoxy(5,12) ;
            clreol() ;
            gotoxy(5,12) ;
            cout <<"Do you want to purchase more (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
        }
        while (ch != 'N' && ch != 'Y') ;
    }
    while (ch == 'Y') ;
    a.prepare_bill(t_billno) ;
}


//**********************************************************
// THIS FUNCTION RETURNS THE BILL NO. OF THE LAST RECORD
// IN THE BILL FILE (BILL.txt)
//**********************************************************

int account :: last_billno(void)
{
    fstream file ;
    file.open("BILL.txt", ios::in) ;
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(account)))
        t = billno ;
    file.close() ;
    return t ;
}


//**********************************************************
// THIS FUNCTION ADDS THE RECORD IN THE BILL FILE (BILL.txt)
//**********************************************************

void account :: add_bill(int t_billno, int t_cuiscode, char
                         t_cuisname[30], float t_qty, float t_cost, float t_price)
{
    struct date d;
    int d1, m1, y1 ;
    getdate(&d);
    d1 = d.da_day ;
    m1 = d.da_mon ;
    y1 = d.da_year ;
    dd = d1 ;
    mm = m1 ;
    yy = y1 ;
    code = t_cuiscode ;
    strcpy(name,t_cuisname) ;
    cost = t_cost ;
    price = t_price ;
    guests = t_qty ;
    billno = t_billno ;
    fstream file ;
    file.open("BILL.txt", ios::out | ios:: app ) ;
    file.write((char *) this, sizeof(account)) ;
    file.close() ;
}


//**********************************************************
// THIS FUNCTION PREPARES AND DISPLAYS THE BILL FOR THE
// GIVEN BILL NO. ACCORDING TO PURCHASES MADE.
//**********************************************************

void account :: prepare_bill(int t_billno)
{
    clrscr() ;
    struct date d;
    int d1, m1, y1 ;
    getdate(&d);
    d1 = d.da_day ;
    m1 = d.da_mon ;
    y1 = d.da_year ;
    float total=0.0, total_bill=0.0 ;
    gotoxy(33,3) ;
    cout <<"CUSTOMER BILL" ;
    gotoxy(55,5) ;
    cout <<"Date:" <<d1 <<"/" <<m1 <<"/" <<y1 ;
    gotoxy(8,7) ;
    cout <<"CUISINES PURCHASED" ;
    gotoxy(8,8) ;
    cout <<"+++++++++++++++" ;
    gotoxy(8,9) ;
    cout <<"cuis code cuis name Cost Price Qty Total"
         ;
    gotoxy(8,10) ;
    cout <<"------------------------------------------------------------"
         ;
    int row=11 ;
    fstream file ;
    file.open("BILL.txt", ios::in) ;
    file.seekg(0) ;
    while (file.read((char *) this, sizeof(account)) !=0 )
    {
        if (billno == t_billno)
        {
            gotoxy(8,5) ;
            cout <<"BILL NO. # " <<billno ;
            gotoxy(8,6) ;
            cout <<"===============" ;
            gotoxy(10,row) ;
            cout <<code ;
            gotoxy(18,row) ;
            cout <<name ;
            gotoxy(39,row) ;
            cout <<cost ;
            gotoxy(47,row) ;
            cout <<price ;
            gotoxy(56,row) ;
            cout <<guests ;
            total = guests * price ;
            gotoxy(63,row) ;
            cout <<total ;
            total_bill = total_bill + total ;
            row++ ;
        }
    }
    file.close() ;
    gotoxy(39,row+1) ;
    cout <<"TOTAL BILL: Rs." <<total_bill <<" /=" ;
    getch() ;
}


//**********************************************************
// THIS FUNCTION DISPLAYS THE LIST OF THE BILLS
//**********************************************************

void account :: bill_list(void)
{
    clrscr() ;
    fstream file ;
    file.open("BILL.txt", ios::in) ;
    file.seekg(0) ;
    int row=5, found=0, pageno=1, prev_billno=0, flag=0 ;
    float total=0.0, total_bill=0.0 ;
    gotoxy(30,2) ;
    cout <<"LIST OF BILLS" ;
    gotoxy(3,4) ;
    cout <<"Billno. Date\t cuis Code\t cuis name \tCost \tLabcost\t Guests\t Total" ;
    gotoxy(3,5) ;
    cout
            <<"===========================================================================" ;
    while (file.read((char *) this, sizeof(account)))
    {
        row++ ;
        delay(20) ;
        found = 1 ;
        if (prev_billno != billno)
        {
            if (flag)
            {
                gotoxy(52,row) ;
                cout <<"TOTAL BILL: Rs." <<total_bill <<"/=" ;
                total_bill = 0.0 ;
                row++ ;
            }
            gotoxy(4,row) ;
            cout <<billno ;
        }
        flag = 1 ;
        gotoxy(11,row) ;
        cout <<dd <<"/" <<mm <<"/" <<yy ;
        gotoxy(24,row) ;
        cout <<code ;
        gotoxy(32,row) ;
        cout <<name ;
        gotoxy(52,row) ;
        cout <<cost ;
        gotoxy(59,row) ;
        cout <<price ;
        gotoxy(67,row) ;
        cout <<guests ;
        total = guests * cost ;
        gotoxy(73,row) ;
        cout <<total ;
        total_bill = total_bill + total ;
        if ( row >= 23 )
        {
            row = 5 ;
            gotoxy(66,1) ;
            cout <<"Page no. : " <<pageno ;
            pageno++ ;
            gotoxy(1,25) ;
            cout <<"Press any key to continue..." ;
            getche() ;
            clrscr() ;
            gotoxy(30,2) ;
            cout <<"LIST OF BILLS" ;
            gotoxy(3,4) ;
            cout <<"Billno. Date cuis Code cuis name CostPrice Qty Total" ;
            gotoxy(3,5) ;
            cout
                    <<"===========================================================================" ;
        }
        prev_billno = billno ;
    }
    row++ ;
    gotoxy(52,row) ;
    cout <<"TOTAL BILL: Rs." <<total_bill <<"/=" ;
    if ( !found )
    {
        gotoxy(5,10) ;
        cout <<"\7Records not found" ;
    }
    gotoxy(66,1) ;
    cout <<"Page no. : " <<pageno ;
    gotoxy(1,25) ;
    cout <<"Press any key to continue..." ;
    getche() ;
    file.close () ;
}













///////////////////////////////////////MAIN/////////////////////////////////////
void main(void)
{clrscr();
logo();
////////////////////GRAPHICS MODULE////////////////////////////////
int /*x=170,*/i;
//ptr=fopen("data.txt","w");
initgraph(&driver,&mode,"c:\\turboc3\\bgi");
startup();
closegraph(); clrscr();
initgraph(&driver,&mode,"c:\\turboc3\\bgi");

settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
setcolor(GREEN);
outtextxy(150,190,"       PLEASE WAIT");
settextstyle(8,0,2);
setcolor(YELLOW);
outtextxy(100,130,"     SAHMEG CATERING SERVICES");
cout<<"\n";
setcolor(5);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
/*for(i=0;i<250;++i)
{
delay(30);
setcolor(RED);
line(x,200,x,220);
x++;}   */
//rectangle(170,215,470,230);
for(i=170;i<=470;i++)
{  setcolor(WHITE);
outtextxy(290,221,"LOADING..");
setfillstyle(8,RED);
bar(170,230,i,215);             delay(10);
}
char ch;
int flag;
do{
ch='y';
flag=0;
clrscr();
char r_name[30];
int r_pass;
cout<<"Enter the user name: \n";
cin>>r_name;
cout<<"Enter the password : \n";
cin>>r_pass;
if(r_pass==1){
flag=1;
break;
}
else{
cout<<"Login failed\n";
delay(1500);
}
cout<<"Do you want to re login............(y/n)\n";
cin>>ch;
}while(ch=='y');
clrscr();
      if(flag==1){
/////////////////menu call//////////////////
menu m;
m.main_menu();
///////////////////CHOICE HANDLING/////////////////////////////////////////
    }
}          
/////////////////////////////////////////////entry/////////////////////////////

