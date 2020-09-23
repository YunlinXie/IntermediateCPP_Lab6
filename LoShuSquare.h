/******************************************************************
CIS 22B
   Lab6: [This is the header file of LoShuSquare class. This class
          creates a 3*3 square, and ask users to fill the array with
          number 1-9. This class will check whether the given square
          is a Lo Shu Square.]
   Author: [Yunlin Xie]
   Date:[12/05/2018]
*******************************************************************/


#ifndef LAB6_LOSHUSQUARE_H
#define LAB6_LOSHUSQUARE_H
#include <iostream>
using namespace std;

class LoShuSquare
{
private:
    int square[3][3];


public:

    /****************************************************
     * Constructor which initializes the grid with zeros.
     ****************************************************/
    LoShuSquare()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                square[i][j] = 0;
            }
        }
    }

    /************************************************************
     * Function to fill a place in the square with a number 1-9,
     * receiving row and column and a value as parameters.
     ************************************************************/
    void fillSquare(int Row, int Column, int Value)
    {
        square[Row][Column] = Value;
    }

    /************************************************************
     * Function to print out the array to screen.
     ************************************************************/
     void printBoard()
     {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << square[i][j] << "  ";
            }
            cout << endl;
        }
     }

    /***********************************************************
     * Function to check whether the sum of each row is equal.
     ***********************************************************/
     bool checkRows()
     {
         int row1, row2, row3;
         row1 = square[0][0] + square[0][1] + square[0][2];
         row2 = square[1][0] + square[1][1] + square[1][2];
         row3 = square[2][0] + square[2][1] + square[2][2];
         if(row1 == row2 && row2 == row3)
         {
             return true;
         }
     }

    /***********************************************************
     * Function to check whether the sum of each column is equal.
     ***********************************************************/
     bool checkColumns()
     {
        int column1, column2, column3;
        column1 = square[0][0] + square[1][0] + square[2][0];
        column2 = square[0][1] + square[1][1] + square[2][1];
        column3 = square[0][2] + square[1][2] + square[2][2];
        if(column1 == column2 && column2 == column3)
        {
            return true;
        }
     }

    /***********************************************************
     * Function to check whether the sum of each diagonal is equal.
     ***********************************************************/
     bool checkDiagonals()
    {
         int diagonal1, diagonal2;
         diagonal1 = square[0][0] + square[1][1] + square[2][2];
         diagonal2 = square[0][2] + square[1][1] + square[2][0];
         if(diagonal1 == diagonal2)
         {
             return true;
         }
    }
};

#endif //LAB6_LOSHUSQUARE_H
