#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

#define ll long long
#define ull unsigned long long


vector<int> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<int>arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) {
        arr.push_back(stoi(line));
    }
    file.close();
    return arr;
}

void part1(vector<int>arr) {
    cout<<"Part1:: "<<""<<"\n";
}

void part2(vector<int>arr) {
    cout<<"Part2:: "<<""<<"\n";
}

void part3(vector<int>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<int>arr = get_input("08");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}

// Part 1: 22971
// Part 2: 19486
// Part 3: 12901
