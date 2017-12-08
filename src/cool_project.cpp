// my project

#include <iostream>
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

int main() {
    string result = CensorString1("Stanford University", "nt");
    cout << result << endl;
    string result2 = "Llamas like to laugh";
    CensorString2(result2, "la");
    cout << result2 << endl;
    return 0;
}
