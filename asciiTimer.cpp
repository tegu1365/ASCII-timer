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
* <Main program>
*
*/

#include<iostream>
#include <stdlib.h>
#include <unistd.h>
#include "timerDisplay.cpp"
using namespace std;

int minutes=0;
int seconds=0;

bool verify(int a)
{
    if(a>9999)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void input()
{
    int in=0;
    cin>>in;
    if(verify(in))
    {
        minutes=in/60;
        seconds=in%60;
    }
    else
    {
        system("CLS");
        cout<<"The number must be under 5 digits. Please try again: ";
        input();
    }
}

void timer()
{
    int min_=minutes;
    int sec=seconds;
    for(; min_>=0; min_--)
    {
        for(; sec>=0; sec--)
        {
            sleep(1);
            system("CLS");
            timerDisplay(min_,sec);
            // cout<<min_<<":"<<sec<<endl;
            if(sec==0)
            {
                sec=60;
            }
        }

    }
}

int main()
{

    input();
    system("CLS");
    timer();
    return 0;
}
