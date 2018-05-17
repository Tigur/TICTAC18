#include <iostream>
#include"List.h"
#include"miscFunc.h"
using namespace std;

int main()
{
    List <int> L ;

    L.add(1);
    L.add(1);

    L.add(1);

    L.add(1);

    L.add(1);

    L.add(1);

    L.del(3);

    show(L);

}