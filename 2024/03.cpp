#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;


vector<int> get_input(string day) {
    string file_path = "2024/"+day+".in";
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
    vector<int>arr = get_input("03");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}
