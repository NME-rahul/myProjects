/*
snake and ladder game
player is moving on the index value of array after each moving it checks, is there ladder or snake if yes then it collects the value on 
that specific position and again move according to it.
*/

#include<iostream>
#include<stdlib.h>
#include<random>
#include<conio.h>
using namespace std;

class Snake_Ladder
{
    /*You can make you customized on which you can select where how many and where you wants snakes and ladders*/
    unsigned int ladders[8]={0, 0, 7, 0, 0, 0, 0, 0};
    short int snakes[8]={0, 0, 0, 0, 3, 2, 0, 0};
    unsigned short int current_ptr=0;
    unsigned short int previous_ptr = current_ptr;
    short unsigned int initial_value = 0;

public:
    void logic(unsigned short int dice_move, unsigned short int &initial_value, unsigned short int &current_ptr, unsigned short int &previous_ptr)
    {
        if(current_ptr > 8)
        {
            cout<<"Error: value exceed"<<endl;
            exit(0);
        }
        if(initial_value==0 && dice_move!=6)
        {
            cout<<"Cannot move, Need 6 for Starting :( "<<endl;
        }
        else if(initial_value==0 && dice_move==6)
        {
            initial_value = 1;
            current_ptr = 0;
        }
        else if(initial_value!=0)
        {
            current_ptr[ptr] = current_ptr[ptr] + dice_move;
            if(current_ptr > 8)
            {
                cout<<"cannot Move, value exceeding"<<endl;
                current_ptr = current_ptr - dice_move;
            }
            if(ladders[current_ptr]!=0)
                current_ptr = current_ptr + ladders[current_ptr];
            if(snakes[current_ptr]!=0)
                current_ptr = current_ptr - snakes[current_ptr];
        }
        //previous_ptr = current_ptr;
        if(current_ptr == 8)
        {
            cout<<"Hurrey!, You are at Home :) "<<endl;
            getch();
            exit(0);
        }
    }

    void dice()
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(1, 6);
        unsigned short int dice_move = distr(gen);
        cout<<"Moving...  "<<dice_move<<endl;
        this->logic(dice_move, initial_value, current_ptr, previous_ptr);
    }

    void start_game(void)
    {
        while(true)
        {
            char roll;
            cout<<"Press Enter for rolling dice or t for terminate: ";
            cin>>roll;
            if(roll=='r')
                this->dice();
            else if(roll=='t')
                break;
            else
                cout<<"Press r/t not other keys"<<endl;
        }
    }
};

int main()
{
    cout<<"\t\t\tWelcome in Snake Ladder Game\n\n"<<endl;
    Snake_Ladder obj;
    obj.start_game();
    return 0;
}