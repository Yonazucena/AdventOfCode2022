#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
    return score;
}

//A rock, B paper, C scissors
//X lose, Y draw, Z win
int find_me(char a, char result) {
    char b;
    if (a == 'A') { //rock
        switch(result) {
            case 'X': //lose
            b = 'Z';
            break;

            case 'Y': //draw
            b = 'X';
            break;

            case 'Z': //win
            b = 'Y';
            break;
        }
    }

    if (a == 'B') { //paper
        switch(result) {
            case 'X': //lose
            b = 'X';
            break;

            case 'Y': //draw
            b = 'Y';
            break;

            case 'Z': //win
            b = 'Z';
            break;
        }
    }

    if (a == 'C') { //scissors
        switch(result) {
            case 'X': //lose
            b = 'Y';
            break;

            case 'Y': //draw
            b = 'Z';
            break;

            case 'Z': //win
            b = 'X';
            break;
        }
    }
    return calc_score(a,b);
}

int main() {
    ifstream myfile;
    myfile.open("input.txt");
    string line;
    int score = 0;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            char op, result;
            op = line[0];
            result = line[2];

            score += find_me(op, result);
        }
    }
    cout << score << endl;
    
}