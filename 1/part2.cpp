#include <iostream>
using namespace std;
#include <string>
#include <fstream>

int checkNumber(string fiveletters, bool backwards) {
    int output = 0;
    int len  = fiveletters.size();
    if (len >= 5) {
        output += 3*(fiveletters == "three");
        output += 7*(fiveletters == "seven");
        output += 8*(fiveletters == "eight");
    }
    if (len >= 4) {
        output += 4*(fiveletters.substr(0+(len-4)*backwards,4) == "four");
        output += 5*(fiveletters.substr(0+(len-4)*backwards,4) == "five");
        output += 9*(fiveletters.substr(0+(len-4)*backwards,4) == "nine");
    }
    if (len >= 3) {
        output += 1*(fiveletters.substr(0+(len-3)*backwards,3) == "one");
        output += 2*(fiveletters.substr(0+(len-3)*backwards,3) == "two");
        output += 6*(fiveletters.substr(0+(len-3)*backwards,3) == "six");
    }
    output += (fiveletters[0+(len-1)*backwards]-'0')*isdigit(fiveletters[0+(len-1)*backwards]);
    
    return output;
}

int searchstring(string line) {
    int first = 0;
    int last = 0;
    int len  = line.size();
    // Go through the string both ways
    for (int i = 0; i < len; i++) {
        // Adds the number only if it is a digit and is the first digit to be found
        first += checkNumber(line.substr(i,5*(len-i>=5)+(len-i<5)*(len-i)),false)*(first==0);
        last += checkNumber(line.substr((len-i-5)*(len-i>=5),5*(len-i>=5)+(len-i<5)*(len-i)),true)*(last==0);
        //cout << first << " || " << last << " || "<< line << " " << endl;
        // If both has been found, break the loop
        if (!(first==0) && !(last==0)) {
            break;
        }
    }
    //cout << first * 10 + last << " | " << line << endl;
    return first * 10 + last;
}

int main () {
    string line;
    ifstream inputfile("input2.txt");
    int sum;
    // cycle through all strings in the input file
    while (getline(inputfile,line)) {
        sum += searchstring(line);
    }
    cout << sum;
    return 0;
}