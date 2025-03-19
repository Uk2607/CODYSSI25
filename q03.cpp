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
        stringstream ss(line);
        string range;
        vector<int>row;
        while(getline(ss, range, ' ')) {
            stringstream ssv(range);
            string v;
            while(getline(ssv, v, '-')) row.push_back(stoi(v));
        }
        arr.push_back(row);
    }
    file.close();
    return arr;
}

void part1(vector<vector<int>>arr) {
    int boxes = 0;
    for(vector<int>v:arr)
        boxes += (v[1]-v[0]+1 + v[3]-v[2]+1);
    cout<<"Part1:: "<<boxes<<"\n";
}

void part2(vector<vector<int>>arr) {
    cout<<"Part2:: "<<""<<"\n";
}

void part3(vector<vector<int>>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<vector<int>>arr = get_input("03");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}
