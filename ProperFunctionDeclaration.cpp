#include <bits/stdc++.h>
#include <string>



using namespace std;



bool IsFunctionDeclaration(const string& line) {
    size_t openParenthesis = line.find('(');
    size_t closeParenthesis = line.find(')');



    if (openParenthesis == string::npos || closeParenthesis == string::npos) {
        return false;
    }



    size_t spacePos = line.rfind(' ', openParenthesis);
    if (spacePos == string::npos) {
        return false;
    }



    return spacePos < openParenthesis;
}



void FindFunctions(const string input[]) {
    bool isInsideFunction = false;



    for (int i = 0; input[i] != ""; i++) {
        const string& line = input[i];
        if (IsFunctionDeclaration(line)) {
            isInsideFunction = true;
            cout << "Function Declaration: " << line << endl;
        } else if (isInsideFunction) {
            if (line.find('{') != string::npos) {
                isInsideFunction = false;
            }
            cout << "Function Definition: " << line << endl;
        }
    }
}



int main() {
    const string input[] = {
        "int  func(int a,int b)",
        "{return a+b}",

        "int main() {",
        "    cout << 'Hello, World!' << endl;",
        "   func(5,5)",

        "}"
    };
    FindFunctions(input);



    return 0;
}
