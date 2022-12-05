#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int findPriority(char item) {
    int num;
    if (item >= 'a' and item <= 'z') num = item - 96;
    else num = item - 38;
    return num;
}

int main() {
    ifstream myfile;
    myfile.open("input.txt");
    string line;
    map<char, int> first;
    int sum = 0;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            for (int i = 0; i < line.size()/2; ++i) {
                first.insert(pair<char, int>(line[i], findPriority(line[i])));
            }
            for (int i = line.size()/2; i < line.size(); ++i) {
                map<char, int>::iterator it = first.find(line[i]);
                if (it != first.end()) {
                    sum += it->second;
                    cout << "copy is " << it->first << " with value " << it->second << endl;
                    break;
                }
            }
            map<char, int> emptyMap;
            first = emptyMap;
        }
    }
    cout << sum << endl;
    
}