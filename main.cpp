#include <iostream>
#include <array.h>

using namespace std;

int main()
{
    int size = 10;
    Array<int> arr(size);
    for(int i = 0; i < size; i++)
    {
        arr[i] = i*10;
    }

    auto iter = arr.begin();

    auto iter2 = iter;
    iter2++;

    arr.insert(iter2, 500);

    for(auto it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}
