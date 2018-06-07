//
// Created by resolution on 12.05.18.
//

#include<iostream>
#include"List.h"
#include"Tree.h"

#ifndef TICTAC18_MISCFUNC_H
#define TICTAC18_MISCFUNC_H

template <typename type>
void show (List <type> list)
{
    LNode <type> *tmp=list.head.back;
    while(tmp->back != NULL)
    {
        cout << tmp->index << endl;
        tmp=tmp->back;

    }
}

void show (int n, int m, int **table)
{
    for(int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
        {
            cout << table[i][j] << endl;
        }
    }

}

template <typename type>
bool copy_table_twoD(type **board_one, type **board_two, int n, int m)
{
    for(int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
        {
            board_one[i][j]=board_two[i][j];
        }
    }
    return true;

}
template <typename type>
bool FillWithZeros(int n, int m, type **table)
{
    for ( int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        table[i][j]=0;
    }
    return true;




}


//bool WorthIt(Tree* decider, int value)

#endif //TICTAC18_MISCFUNC_H
