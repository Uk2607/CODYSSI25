#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

#define ll long long
#define ull unsigned long long


vector<vector<pair<int,int>>> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<vector<pair<int,int>>>arr;
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
        arr.push_back({{row[0], row[1]}, {row[2], row[3]}});
    }
    file.close();
    return arr;
}

void part1(vector<vector<pair<int,int>>>arr) {
    cout<<"Part1:: "<<""<<"\n";
}

void part2(vector<vector<pair<int,int>>>arr) {
    cout<<"Part2:: "<<""<<"\n";
}

void part3(vector<vector<pair<int,int>>>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<vector<pair<int,int>>>arr = get_input("07");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}
