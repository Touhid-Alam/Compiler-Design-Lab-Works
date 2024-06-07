
#include<bits/stdc++.h>
using namespace std;


int main(){

string s;
cout<<"Input The String: "<<endl;
getline(cin,s);
cout<<"Removed Duplicate Character: " ;
    string result = "";

    for (int i = 0; i < s.length(); ++i) {
        bool isDuplicate = false;

        for (int j = 0; j < i; ++j) {
            if (s[i] == s[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            result += s[i];
        }
    }
    for(int i = 0;i<result.size();i++){
        cout<<result[i];
    }
cout<<endl;

cout<<"Removed Blank character: ";

string result1 = "";
for(int i=0;i<result.size();i++){
    if(result[i]!=' '){
        cout<<result1[i];
        result1+=result[i];
    }

}
cout<<result1;
cout<<endl;
cout<<"Length: ";
cout<<result1.length();

cout<<endl;

cout<<"Printed as row: ";
for(int i=0;i<result1.size();i++){
    for(int j = 0;j<i+1;j++){
        cout<<result1[j];
    }
    cout<<endl;
}


}
