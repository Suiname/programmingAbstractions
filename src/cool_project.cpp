// my project

#include <iostream>
#include <fstream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
using namespace std;

string CensorString1(string text, string remove){
    string returnString = "";
    for (int i=0; i < text.length(); i++){
        bool addChar = true;
        for (int j=0; j < remove.length(); j++){
            if (text[i] == remove[j]) {
                addChar = false;
            }
        }
        if (addChar){
            returnString = returnString + text[i];
        }
    }
    return returnString;
}

void CensorString2(string &text, string remove) {
    for (int i=text.length()-1; i >= 0; i--){
        for (int j=0; j < remove.length(); j++){
            if (text[i] == remove[j]){
                text.erase(i, 1);
            }
        }
    }
}

struct scores
{
    int min = 0;
    int max = 0;
    float avg = 0;
};

int convertStringToInt(const std::string& input)
{
    std::stringstream ss(input);
    int retval;
    ss >> retval;
    return retval;
}

scores getScores(string fileName){
    scores result;
    ifstream in(fileName.c_str());
    int lineNumber = 0;
    while (true) {
        lineNumber++;
        string line;
        getLine(in, line);
        if (in.eof()) break;
        if (in.fail()) break;
        int score;
        score = convertStringToInt(line);
        if ((score < result.min) || (lineNumber == 1)) {
            result.min = score;
        }
        if (score > result.max) {
            result.max = score;
        }
        result.avg = ((result.avg * (lineNumber - 1)) + score)/lineNumber;
    }

    return result;
}

int main() {
    string result = CensorString1("Stanford University", "nt");
    cout << result << endl;
    string result2 = "Llamas like to laugh";
    CensorString2(result2, "la");
    cout << result2 << endl;
    scores result3 = getScores("scores.txt");
    cout << "max: " << result3.max << " min: " << result3.min << " avg: " << result3.avg << endl;
    return 0;
}
