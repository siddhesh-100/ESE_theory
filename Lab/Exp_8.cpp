#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;
int countWords(const string &line){
    stringstream ss(line);
    string word;
    int wordCount = 0;
    while(ss >> word) wordCount++;
    return wordCount;
}
int main(){
    unordered_map<string, int> hash;
    int totalLine = 0, totalWord = 0;
    string line;
    cout << "Enter exit to stop\n";
    for(;;){
        cout << "Enter a line: ";
        getline(cin, line);
        if(line == "exit") break;
        totalLine++;
        totalWord += countWords(line);
        hash[line]++;
        cout << "Current Line Count: " << totalLine << "\n";
        cout << "Current Word Count: " << totalWord << "\n";
        cout << "Occurences of line: " << hash[line] << "\n";
    }
    cout << "Final Line Count: " << totalLine << "\n";
    cout << "Current Word Count: " << totalWord << "\n";
    cout << "Entered Lines: " << "\n";
    for(const auto &i : hash){
        cout << "The line \"" << i.first << "\" occured " << i.second << " times\n";
    }
    return 0;
}