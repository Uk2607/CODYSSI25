#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;


vector<pair<string,int>> get_input(string day) {
    string file_path = "2024/"+day+".in";
    ifstream file(file_path);

    vector<pair<string,int>>arr;
    string line;
    int base;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(file>>line>>base) {
        arr.push_back({line, base});
    }
    file.close();
    return arr;
}

void part1(vector<pair<string,int>>arr) {
    cout<<"Part1:: "<<""<<"\n";
}

void part2(vector<pair<string,int>>arr) {
    cout<<"Part2:: "<<""<<"\n";
}

void part3(vector<pair<string,int>>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<pair<string,int>>arr = get_input("03");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}
