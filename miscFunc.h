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
    LNode <type> *tmp=list.head;
    while(tmp!=list.tail)
    {
        cout << tmp->index << endl;
        tmp=tmp->back;

    }
}

#endif //TICTAC18_MISCFUNC_H
