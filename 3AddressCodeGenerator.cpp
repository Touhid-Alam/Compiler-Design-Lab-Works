#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class ThreeAddressCodeGenerator {
public:
    string generateFromFile(const string& filename) {
        readExpressionFromFile(filename);
        return generateCode();
    }

private:
    vector<string> tokens;
    stringstream code;
    int tempCount = 1;

    void readExpressionFromFile(const string& filename) {
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            exit(1);
        }

        string token;
        while (file >> token) {
            tokens.push_back(token);
        }

        file.close();
    }

    string generateCode() {
        for (size_t i = 0; i < tokens.size() - 2; ++i) {
            if (isOperator(tokens[i + 1][0])) {
                string temp = getNextTemp();
                code << temp << " = " << tokens[i] << " " << tokens[i + 1] << " " << tokens[i + 2] << endl;
                tokens[i + 2] = temp;
                i += 2;
            } else {
                string temp = getNextTemp();
                code << temp << " = " << tokens[i] << " " << tokens[i + 1] << " " << tokens[i + 2] << endl;
                tokens[i] = temp;
                i += 2;
            }
        }

        return code.str();
    }

    string getNextTemp() {
        stringstream ss;
        ss << "t" << tempCount++;
        return ss.str();
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
};

int main() {
    string filename;

    cout << "Enter the filename: ";
    cin >> filename;

    ThreeAddressCodeGenerator generator;
    string threeAddressCode = generator.generateFromFile(filename);

    cout << "Generated Three-Address Code:\n" << threeAddressCode;

    return 0;
}
