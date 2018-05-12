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
    type key = 0;
    LNode* front = NULL;
    LNode* back = NULL;
    int index ;  // nie przejmujemy się utylizacją numeracji w dużym stopniu.

};


template <typename type>
class List
{
public:
    LNode <type> *head = NULL;
    LNode <type> *tail = NULL;
     int nextIndex=0 ;


    LNode <type> *searchFor(int index)
    {
        LNode <type> *tmp=head;
        while(tmp!=tail) // czy będzie w stanie znaleźc ostatni ?
        {
            if(tmp.index==index)
            {
                return tmp;
            }
            tmp=tmp.back;
        }

        cout << " KEY NOT FOUND " << endl;
        return 0;


    }




    List()
    {
        head = NULL;
        tail = NULL;
        nextIndex=1;
    }
    bool add (type key )
    {


        LNode <type> *newNode = new LNode <type>;
        newNode->key=key;
        newNode->index=this->nextIndex;
        this->nextIndex=this->nextIndex+1;

        if (!head)
        {
            head= newNode;
            tail= newNode;

            return true;
        }
        else
        {
            LNode <type> *tmp = tail;
            tail=newNode;
            tmp->back=newNode;
            newNode->front=tmp;

            return true;
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





};


#endif //TICTAC18_LIST_H