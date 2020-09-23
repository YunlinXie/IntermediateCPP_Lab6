/******************************************************************
CIS 22B
   Lab6: [This is the header file of Player class. It implements
          the interaction with the user by receiving a LoShuSquare
          object as a parameter and call the functions from Player
          class.]
   Author: [Yunlin Xie]
   Date:[12/05/2018]
*******************************************************************/

#ifndef LAB6_PLAYER_H
#define LAB6_PLAYER_H
#include "LoShuSquare.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

class Player
{
public:
    // Constructor which receives an object of LoShuSquare as a parameter and will handle the interface.
    Player(LoShuSquare game)
    {
        while(true)
        {
            int temp;

            cout << endl << "This game will ask you to fill a 3*3 square with numbers 1-9 in different orders," << endl;
            cout << "it can check whether your square is a Lo Shu Square." << endl << endl;
            cout << "If you want to continue playing, please press '1'. Otherwise, press '0' to quit: ";
            cin >> temp; // A temporary variable to check status.

            if(temp == 0)
            {
                cout << endl << "Game quited!" << endl;
                exit(0);
            }

            if(temp == 1)
            {
                int row, column, value;

                for(int count = 1; count < 10; count++)
                {
                    cout << endl <<  "Enter three integers separated by space, they represent Row, Column, and Value(1-9)." << endl;
                    cout << "For example, '0 0 4' will change the upper leftmost square to 4. Remember to enter" << endl;
                    cout << "them in order(Row Column Value): ";

                    cin >> row >> column >> value;

                    game.fillSquare(row, column, value);
                    cout << endl << endl << "Here is your Square (empty grid is assigned with'0'):" << endl << endl;
                    game.printBoard();
                }
                if(game.checkRows() && game.checkColumns() && game.checkDiagonals())
                {
                    cout << "Congratulaion! Your square is a Lo Shu Square! Try again!" << endl;
                   for(int i = 0; i < 3; i++)
                    {
                        for(int j = 0; j < 3; j++)
                        {
                            game.fillSquare(i,j,0);
                        }
                    }
                }
                else
                {
                    cout << "Game failed! Try one more time!" << endl;
                    for(int i = 0; i < 3; i++)
                    {
                        for(int j = 0; j < 3; j++)
                        {
                            game.fillSquare(i,j,0);
                        }
                    }
                }
            }
        }
    }
};


#endif //LAB6_PLAYER_H
