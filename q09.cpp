#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

#define ll long long
#define ull unsigned long long


vector<string> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<string>arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) {
        arr.push_back(line);
    }
    file.close();
    return arr;
}

void part1(vector<string>arr) {
    cout<<"Part1:: "<<""<<"\n";
}

void part2(vector<string>arr) {
    cout<<"Part2:: "<<""<<"\n";
}

void part3(vector<string>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<string>arr = get_input("09");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}
