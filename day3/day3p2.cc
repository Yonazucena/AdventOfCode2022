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
    map<char, int> second;
    int sum = 0;
    int count = 0;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if (count == 0) {
                for (int i = 0; i < line.size(); ++i) {
                    first.insert(pair<char, int>(line[i], findPriority(line[i])));
                }
                count++;
            }
            else if (count == 1) {
                for (int i = 0; i < line.size(); ++i) {
                    second.insert(pair<char, int>(line[i], findPriority(line[i])));
                }
                count++;
            }
            else { //count == 2
                for (int i = 0; i < line.size(); ++i) {
                    map<char, int>::iterator it1 = first.find(line[i]);
                    map<char, int>::iterator it2 = second.find(line[i]);
                    if (it1 != first.end() and it2 != second.end()) {
                        sum += it1->second;
                        cout << "copy is " << line[i] << " with value " << it1->second << endl;
                        break;
                    }
                }
                map<char, int> emptyMap;
                first = emptyMap;
                second = emptyMap;
                count = 0;
            }
        }
    }
    cout << sum << endl;
    
}