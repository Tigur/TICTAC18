//
// Created by resolution on 09.05.18.
//



#ifndef TICTAC18_LIST_H
#define TICTAC18_LIST_H


#include<iostream>

using namespace std;

template <typename type>
class LNode
{
public:
    type key ;
    LNode* front = NULL;
    LNode* back = NULL;
    int index ;  // nie przejmujemy się utylizacją numeracji w dużym stopniu.

};


template <typename type>
class List // w kluczu wrzuce drzewo
{
public:
    LNode <type> head ;
    LNode <type> tail ;
     int nextIndex=0 ;


    LNode <type> *searchFor(int index)
    {
        LNode <type> *tmp=head.back;
        while(tmp!=&tail) // czy będzie w stanie znaleźc ostatni ?
        {
            if(tmp->index==index)
            {
                return tmp;
            }
            tmp=tmp->back;
        }

        cout << " KEY NOT FOUND " << endl;
        return 0;


    }




    List()
    {
        head.back = NULL;
        tail.front = NULL;
        nextIndex=1;
    }
    LNode <type>* add (type key )
    {


        LNode <type> *newNode = new LNode <type>;
        newNode->key=key;
        newNode->index=this->nextIndex;
        this->nextIndex=this->nextIndex+1;

        if (!head.back)
        {
            head.back= newNode;
            tail.front= newNode;
            newNode->front=&head;
            newNode->back=&tail;

            return newNode;
        }
        else
        {
            LNode <type> *tmp = tail.front;
            tail.front=newNode;
            tmp->back=newNode;
            newNode->front=tmp;
            newNode->back=&tail;

            return newNode;
        }

    }
    bool del (int indexToDel)
    {
        LNode <type> *delNode = searchFor(indexToDel);
        LNode <type> *tmp=0;
        delNode->back->front = delNode->front; // poprzedni pomija usuwany
        delNode->front->back = delNode->back; // nastepny pomija usuwany

        delete delNode;


    }

    type get(int getIndex) // zwraca odrazu klucz.
    {
        type got;
      got = searchFor(getIndex)->key;

        return got;
    }

    bool exist()
    {
        if(nextIndex==1)
            return false;
        if(nextIndex>1)
            return true;
    }




};


#endif //TICTAC18_LIST_H
