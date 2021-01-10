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

int minutes= 0;
int seconds= 0;

bool verify (int a);//function for verifying the input
void input ();//function for the input
void timer ();//countdown function
void resetOrExit ();//function to reset the timer with new number of seconds
void beep ();//sound function

int main()
{
    cout<<"Input the number of seconds (0;10000): ";
    input ();
    system("CLS");
    timer ();
    beep ();
    resetOrExit ();
    return 0;
}

bool verify (int a)
{
    if (a > 9999 || a < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void input ()
{
    int in = 0;
    cin>> in;
    if (verify (in))
    {
        minutes = in/60;
        seconds = in%60;
    }
    else
    {
        system ("CLS");
        cout<<"The number must be under 5 digits and positive. Please try again: ";
        input ();
    }
}

void timer ()//calls up the function to generate the timer's display every second
{
    int min_= minutes;
    int sec= seconds;

    for(; sec >= 0; sec--)
    {
        sleep (1);
        system ("CLS");
        timerDisplay (min_, sec);
        if (sec == 0 && min_ != 0)
        {
            sec= 60;
            min_--;
        }

    }
}

void resetOrExit ()
{
    char ans;
    cout<<"Do you want to reset? Y/N: ";
    cin>>ans;
    if (ans == 'y' || ans == 'Y')
    {
        system ("CLS");
        main ();
    }
    else
    {
        if (ans == 'n' || ans == 'N')
        {
            system("EXIT");
        }
        else
        {
            system ("CLS");
            cout<<"The answer must be Y/y or N/n. ";
            resetOrExit ();
        }
    }

}


void beep()
{
    cout << "\a";
}

