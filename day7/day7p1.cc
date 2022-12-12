#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

map<string, map<string, int>> files; //dir fileName fileSize
map<string, vector<string>> folders; //dir vector(dirs included)
map<string, int> folderSizes;

void writeFolders() {
    cout << "folders:" << endl;
    map<string, vector<string>>::iterator it = folders.begin();
    while (it != folders.end()) {
        cout << it->first;
        for (int i = 0; i < it->second.size(); ++i) {
            cout << " " << it->second[i];
        }
        cout << endl;
        it++;
    }
}

void writeFiles() {
    cout << "files:" << endl;
    map<string, map<string, int>>::iterator it = files.begin();
    while (it != files.end()) {
        cout << "file: " << it->first << endl;
        for (map<string, int>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            cout << it2->first << " " << it2->second << endl;
        }
        it++;
    }
}

int writeSizes() {
    int total = 0;
    cout << "sizes:" << endl;
    map<string, int>::iterator it = folderSizes.begin();
    while (it != folderSizes.end()) {
        cout << it->first << ": " << it->second << endl;
        if (it->second <= 100000) total += it->second;
        it++;
    }
    return total;
}

bool existsDir(string dir, vector<string> folder) {
    for (int i = 0; i < folder.size(); ++i) {
        if (folder[i] == dir) return true;
    }
    return false;
}

string findPrev(string dir) {
    for (map<string, vector<string>>::iterator it = folders.begin(); it != folders.end(); ++it) {
        for (int i = 0; i < it->second.size(); ++i) {
            if (it->second[i] == dir) return it->first;
        }
    }
    return dir;
}

void cdDir(string dir, string& currentDir) {
    if (dir == ".." || dir == "/") {
        dir = findPrev(currentDir);
        currentDir = dir;
    }
    else {
        map<string, vector<string>>::iterator it = folders.find(currentDir);
        if (it == folders.end()) {
            vector<string> empty;
            empty.push_back(dir);
            folders.insert({currentDir, empty});
        }
        else if (!existsDir(dir, it->second)) {
            vector<string> empty;
            it->second.push_back(dir);
            folders.insert({dir, empty});
        }
        currentDir = dir;
    }
}

void addDir(string dir, string currentDir) {
    map<string, vector<string>>::iterator it = folders.find(currentDir);
    if (it == folders.end()) {
        vector<string> empty;
        empty.push_back(dir);
        folders.insert({currentDir, empty});
    }
    else {
        vector<string> empty;
        it->second.push_back(dir);
        folders.insert({dir, empty});
    }
}

bool existsFile(string fileName, string currentDir, map<string, int> folderFile) {
    map<string, int>::iterator it = folderFile.find(currentDir);
    if (it == folderFile.end()) return false;
    return true;
}

void addSize(string currentDir, int sizeint) {
    map<string, int>::iterator it = folderSizes.find(currentDir);
    if (it == folderSizes.end()) {
        folderSizes.insert({currentDir, sizeint});
    }
    else it->second += sizeint;
    if (currentDir != "/") {
        addSize(findPrev(currentDir), sizeint);
    }
}

void addFile(string size, string fileName, string currentDir) {
    int sizeint = atoi(size.c_str());
    map<string, map<string, int>>::iterator it = files.find(fileName);
    if (it == files.end()) {
        map<string, int> file;
        file.insert({currentDir, sizeint});
        files.insert({fileName, file});
        addSize(currentDir, sizeint);
    }
    else if (!existsFile(fileName, currentDir, it->second)) {
        it->second.insert({currentDir, sizeint});
        addSize(currentDir, sizeint);
    }
}

int main() {
    ifstream myfile;
    myfile.open("input.txt");
    string line;

    string currentDir = "/";

    bool reading = false;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            //reading commands
            string first, second;
            stringstream ss(line);
            getline(ss, first, ' ');
            getline(ss, second, ' ');

            if (second == "ls") reading = true;
            else if (first == "$") reading = false;

            //$ cd command
            if (second == "cd") {
                string dir;
                getline(ss, dir, ' ');
                cdDir(dir, currentDir);
            }

            //$ ls command
            if (reading && second != "ls") {
                if (first == "dir") addDir(second, currentDir);
                else {
                    addFile(first, second, currentDir);
                }
            }
        }
    }
    //writeFolders();
    //writeFiles();
    cout << writeSizes() << endl;
    
}