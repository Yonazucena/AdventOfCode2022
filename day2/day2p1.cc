#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//A rock, B paper, C scissors
//X rock, Y paper, Z scissors
int calc_score(char a, char b) {
    int score;
    if (b == 'X') score = 1;
    else if (b == 'Y') score = 2;
    else if (b == 'Z') score = 3;

    if (a == 'A') { //rock
        if (b == 'Y') score += 6; //vs paper lose
        else if (b == 'X') score += 3; //vs rock draw
    }
    if (a == 'B') { //paper
        if (b == 'Z') score += 6; //vs scissors lose
        else if (b == 'Y') score += 3; //vs paper draw
    }
    if (a == 'C') { //scissors
        if (b == 'X') score += 6; //vs rock lose 
        else if (b == 'Z') score += 3; //vs scissors draw
    }
    cout << a << " vs " << b << " score: " << score << endl;
    return score;
}

int main() {
ifstream myfile;
    myfile.open("input.txt");
    string line;
    int score = 0;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            char op, me;
            op = line[0];
            me = line[2];

            score += calc_score(op, me);
        }
    }
    cout << score << endl;
    
}