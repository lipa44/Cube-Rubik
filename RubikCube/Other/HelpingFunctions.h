#ifndef HELPING_FUNCTIONS_H
#define HELPING_FUNCTIONS_H

#include <chrono>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

const unsigned long maxWordSize = 1; // the length of the biggest word in input

inline void printWithSleep(const string &text, unsigned int sleepTime) {
    for (int i = 0; i < text.size(); ++i) {
        cout << text[0];
        sleep(sleepTime);
    }
}

inline void deleteText(const string &text) {
    unsigned long size = text.size();
    while (size--)
        cout << "\b" << flush;
}

void PrintColor(const string &color, ostream &outputStream = cout) {
    string result(maxWordSize, ' '), strColor;

    unsigned long lengthField = result.size() + 1, step = (lengthField - color.size()) / 2;

    strColor = color;
    copy(strColor.begin(), strColor.end(), result.begin() + step);

    outputStream << result << " ";
}

int setRGBColor(const string &color) {
    int result = 0;

    if (color[0] == 'G' || color[0] == 'g')
        result = 0x32CD32;
    else if (color[0] == 'B' || color[0] == 'b')
        result = 0x0000FF;
    else if (color[0] == 'Y' || color[0] == 'y')
        result = 0xFFD700;
    else if (color[0] == 'W' || color[0] == 'w')
        result = 0xFFFFFF;
    else if (color[0] == 'O' || color[0] == 'o')
        result = 0xFF8C00;
    else if (color[0] == 'R' || color[0] == 'r')
        result = 0xFF0000;

    return result;
}

#endif /* HELPING_FUNCTIONS_H */
