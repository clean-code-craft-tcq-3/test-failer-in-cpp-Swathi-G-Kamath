#include <iostream>
#include <assert.h>
#include <map>

const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

int calculatePairNo(int majorIndex, int minorIndex)
{
    return ((majorIndex * 5 + minorIndex) + 1); 
}

std::string createColorPair(int majorIndex, int minorIndex)
{
    std::string majorColorName(majorColor[majorIndex]);
    std::string minorColorName(minorColor[minorIndex]);
    return majorColorName.append(" | ").append(minorColorName);
}

int getPairNumber(int majorIndex, int minorIndex, std::map<int, std::string>& ColorPairs)
{
    int pair_no = calculatePairNo(majorIndex, minorIndex);
    std::string colorPair = createColorPair(majorIndex, minorIndex);
    ColorPairs[pair_no] = colorPair;
    return pair_no;
}

void printColorCode(int majorIndex, int minorIndex, std::map<int, std::string>& ColorPairs)
{
    int pair_no = getPairNumber(majorIndex, minorIndex, ColorPairs);
    std::cout << pair_no << " | " << ColorPairs[pair_no] << "\n";
}

int printColorMap(std::map<int, std::string>& ColorPairs) {
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printColorCode(i, j, ColorPairs);
        }
    }
    return i * j;
}
void testPrintColorMap(std::map<int, std::string>& ColorPairs)
{
    int result = printColorMap(ColorPairs);
    assert(ColorPairs[1] == "White | Blue");
    assert(ColorPairs[25] == "Violet | Slate");
    assert(result == 25);
}

void testUpdateColorCoderMap(std::map<int, std::string>& colorCodedList)
{
    int pairNumber = getPairNumber(0, 0, colorCodedList);
    assert(pairNumber == 1);
    assert(colorCodedList[1] == "White | Blue");
}
int main() {
    std::map<int, std::string> colorCoderList;
    testPrintColorMap(colorCoderList);
    std::map<int, std::string> testColorCoderList;
    testUpdateColorCoderMap(testColorCoderList);
    return 0;
}
