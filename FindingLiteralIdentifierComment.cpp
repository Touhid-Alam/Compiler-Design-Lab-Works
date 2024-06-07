#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <boost/algorithm/string.hpp>

using namespace std;
void findTokensInLine(const string& line, vector<string>& comments, vector<string>& identifiers, vector<string>& literals) {
    regex commentRegex("//[^\\n]*|/\\*[^*]*\\*+(?:[^/*][^*]*\\*+)*/|/\\*(?:(?!\\*/).)*");
    regex identifierRegex("[a-zA-Z_][a-zA-Z0-9_]*");
    regex literalRegex("\"[^\"]*\"|'[^']*'");

    smatch match;
    string lineCopy = line;
    while (regex_search(lineCopy, match, commentRegex)) {
        comments.push_back(match[0]);
        lineCopy = match.suffix().str();
    }

    lineCopy = line;
    while (regex_search(lineCopy, match, identifierRegex)) {
        identifiers.push_back(match[0]);
        lineCopy = match.suffix().str();
    }

    lineCopy = line;
    while (regex_search(lineCopy, match, literalRegex)) {
        literals.push_back(match[0]);
        lineCopy = match.suffix().str();
    }
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    vector<string> comments, identifiers, literals;
    string line;

    cout << "Reading input file..." << endl;

    while (getline(inputFile, line)) {
        findTokensInLine(line, comments, identifiers, literals);
    }

    inputFile.close();

    cout << "Results:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Comments:\t" << comments.size() << " found" << endl;
    cout << "Identifiers:\t" << identifiers.size() << " found" << endl;
    cout << "Literals:\t" << literals.size() << " found" << endl;

    cout << endl;

    cout << "Comment Tokens:" << endl;
    for (const string& comment : comments) {
        cout << comment << endl;
    }

    cout << endl;

    cout << "Identifier Tokens:" << endl;
    for (const string& identifier : identifiers) {
        cout << identifier << endl;
    }

    cout << endl;

    cout << "Literal Tokens:" << endl;
    for (const string& literal : literals) {
        cout << literal << endl;
    }

    return 0;
}
