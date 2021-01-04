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
char display[11][55];
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
    //dots(10)
    "*-*-*-▓-*-*-▓-*-*-*-*",
    //space(11)
    "*-*-*-*-*-*-*-*-*-*-*"
};

void timeToChar(int min_,int sec){
    int i=0;
    if(min_<10){
        time[0]='0';
        time[1]='0'+min_;
        i=2;
    }else{
        if(min_>9 && min_<100){
            time[0]='0'+min_/10;
            time[1]='0'+min_%10;
            i=2;
        }else{
            time[0]='0'+min_/100;
            int a=min_%100;
            time[1]='0'+a/10;
            time[2]='0'+a%10;
            i=3;
        }
    }
    time[i]=':';
    if(sec<10){
       time[i+1]='0';
       time[i+2]='0'+sec;
    }else{
       time[i+1]='0'+sec/10;
       time[i+2]='0'+sec%10;
    }
}

void fillDisplay(int numOfDigit){
}

void timerDisplay(int minutes,int seconds)
{
    //cout<<minutes<<":"<<seconds<<endl;
    timeToChar(minutes,seconds);
    //cout<<time;

}


