#include <iostream>
#include "DoubleSubscriptedArray.h"
#include "Entity.h"

using namespace std;

int main()
{
    DoubleSubscriptedArray<int> arr1(2, 2);

    arr1.add(0, 0, 0);
    arr1.add(0, 1, 1);
    arr1.add(1, 0, 2);
    arr1.add(1, 1, 3);

    arr1.display();

    DoubleSubscriptedArray<Entity> arr2(5, 3);
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 3; c++) {
            arr2.add(r, c, Entity("name", 1));
        }
    }

    arr2.display();


}