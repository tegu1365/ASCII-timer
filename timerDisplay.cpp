/**
*
* Solution to course project # 10
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Teodora Petkova
* @idnumber 62538
* @compiler GCC
*
* <file with function for drawing the timer's display>
*
*/
#include<iostream>
using namespace std;

//col=10
//row=11
/*
legend:
*=\0
-=\n
*/
char time[6];
char display[11][57];
bool inSec=false;
char digitsCodes[][121]=
{
    //0
    "0000000000-0********0-0********0-0********0-0********0-0********0-0********0-0********0-0********0-0********0-0000000000",
    //1
    "*********1-*********1-*********1-*********1-*********1-*********1-*********1-*********1-*********1-*********1-*********1",
    //2
    "2222222222-*********2-*********2-*********2-*********2-2222222222-2*********-2*********-2*********-2*********-2222222222",
    //3
    "3333333333-*********3-*********3-*********3-*********3-3333333333-*********3-*********3-*********3-*********3-3333333333",
    //4
    "4********4-4********4-4********4-4********4-4********4-4444444444-*********4-*********4-*********4-*********4-*********4",
    //5
    "5555555555-5*********-5*********-5*********-5*********-5555555555-*********5-*********5-*********5-*********5-5555555555",
    //6
    "6666666666-6*********-6*********-6*********-6*********-6666666666-6********6-6********6-6********6-6********6-6666666666",
    //7
    "7777777777-*********7-*********7-*********7-*********7-*********7-*********7-*********7-*********7-*********7-*********7",
    //8
    "8888888888-8********8-8********8-8********8-8********8-8888888888-8********8-8********8-8********8-8********8-8888888888",
    //9
    "9999999999-9********9-9********9-9********9-9********9-9999999999-*********9-*********9-*********9-*********9-9999999999",
//    //dots(10)
//    "*-*-*-▓-*-*-▓-*-*-*-*",
//    //space(11)
//    "*-*-*-*-*-*-*-*-*-*-*"
};

void timeToChar(int min_,int sec)
{
    int i=0;
    if(min_<10)
    {
        time[0]='0';
        time[1]='0'+min_;
        i=2;
    }
    else
    {
        if(min_>9 && min_<100)
        {
            time[0]='0'+min_/10;
            time[1]='0'+min_%10;
            i=2;
        }
        else
        {
            time[0]='0'+min_/100;
            int a=min_%100;
            time[1]='0'+a/10;
            time[2]='0'+a%10;
            i=3;
        }
    }
    time[i]=':';
    if(sec<10)
    {
        time[i+1]='0';
        time[i+2]='0'+sec;
    }
    else
    {
        time[i+1]='0'+sec/10;
        time[i+2]='0'+sec%10;
    }
}

void addSpace(int col)
{
    for(int i=0; i<11; i++)
    {
        display[i][col]='*';
    }
}

void addDots(int col)
{
    char dots[]= "***@**@****";
    addSpace(col);
    for(int i=0; i<11; i++)
    {
        display[i][col+1]=dots[i];
    }
    inSec=true;
}

void fillDisplay(int numOfDigit)
{
    int currentDigit=time[numOfDigit]-'0';
    char currentDigitCode[121];
    int size_=0;
    int row=0,col=0,offset=0;

    for(int i=0; digitsCodes[currentDigit][i]!='\0'; i++)
    {
        currentDigitCode[i]=digitsCodes[currentDigit][i];
        size_++;
    }
    currentDigitCode[size_+1]='\0';
    if(inSec)
    {
        offset=(numOfDigit-1)*11+2;
    }
    else
    {
        offset=numOfDigit*11;
    }

    for(int i=0; i<size_; i++)
    {
        if(currentDigitCode[i]!='-')
        {
            display[row][col+offset]=currentDigitCode[i];
            col++;
        }
        else
        {
            row++;
            col=0;
        }
    }
}

void clean(){

    for(int i=0; i<6; i++)
    {
        time[i] = '\0';
    }
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<57; j++)
        {
            display[i][j]=0;

        }
    }
}

void timerDisplay(int minutes,int seconds)
{
    inSec=false;
    clean();
    timeToChar(minutes,seconds);
    int i=0;
    while(time[i]!='\0')
    {
        if(time[i]==':')
        {
            addDots(i*10+1);
        }
        fillDisplay(i);
        i++;
    }

    for(int i=0; i<11; i++)
    {
        for(int j=0; j<57; j++)
        {
            if(display[i][j]=='*')
            {
               cout<<" ";
            }
            else
            {
                cout<<display[i][j];
            }
        }
        cout<<endl;
    }
}


