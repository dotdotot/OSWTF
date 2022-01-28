#include <iostream>
using namespace std;

int main()
{
    int index = 0;
    double a = 0;
    for(int i =0; i< 100; i++){
        a = (8000 * i + 6000 )/10000.0;
        if(i - 1 == a){
            index = i;
            break;
        }
    }

    cout << index;

    return 0;
}