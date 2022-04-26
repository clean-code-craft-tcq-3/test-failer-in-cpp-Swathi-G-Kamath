#include <iostream>
#include <assert.h>

void checkPairNumberValidity(int pair_no)
{
    assert(pair_no>=1 && pair_no<=25);
}

void displayPairNumber(int x, int y)
{
    int pair_number = x * 5 + y;
    std::cout<<pair_number+1;   //Pair numbers should start from 1
    checkPairNumberValidity(pair_number);
}


void displayColourPair(int major, int minor)
{
    const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    std::cout << "|" << majorColor[major] <<"|"<<minorColor[minor]<<"\n";
}

int printColorMap() {
    int i , j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            displayPairNumber(i, j);
            displayColourPair(i, j);
        }
    }
    return i * j;
}

int main() {
    printColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
