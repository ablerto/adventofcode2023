#include <iostream>
using namespace std;
#include <string>
#include <fstream>

int searchstring(string line) {
    int first = 0;
    int last = 0;
    bool foundFirst, foundLast;
    int len  = line.size();
    // Go through the string both ways
    for (int i = 0; i < len; i++) {
        // Adds the number only if it is a digit and is the first digit to be found
        first += (line[i]-'0')*isdigit(line[i])*!foundFirst;
        last += (line[len-i-1]-'0')*isdigit(line[len-i-1])*!foundLast;
        // This will tell if the first / last digit has been found
        foundFirst = isdigit(line[i])||foundFirst;
        foundLast = isdigit(line[len-i-1])||foundLast;
        // If both has been found, break the loop
        if (foundFirst && foundLast) {
            break;
        }
    }
    return first * 10 + last;
}

int main () {
    string line;
    ifstream inputfile("input1.txt");
    int sum;
    // cycle through all strings in the input file
    while (getline(inputfile,line)) {
        sum += searchstring(line);
    }
    cout << sum;
    return 0;
}