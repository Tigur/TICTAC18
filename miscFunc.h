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
template <typename type>
bool copy_table_twoD(type **board_one, type **board_two, int n, int m)
{
    for(int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
        {
            board_one[n][m]=board_two[n][m];
        }
    }
    return true;

}

#endif //TICTAC18_MISCFUNC_H
