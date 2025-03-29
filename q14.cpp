#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

#define ll long long
#define ull unsigned long long


vector<vector<int>> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<vector<int>>arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) {
        vector<int>row;
        stringstream ss(line);
        int num;
        while(ss>>num) row.push_back(num);
        arr.push_back(row);
    }
    file.close();
    return arr;
}

void part1(vector<vector<int>>arr) {
    cout<<"Part1:: "<<""<<"\n";
}

void part2(vector<vector<int>>arr) {
    cout<<"Part2:: "<<""<<"\n";
}

void part3(vector<vector<int>>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<vector<int>>arr = get_input("14");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}
