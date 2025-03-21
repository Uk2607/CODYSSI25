#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<set>
using namespace std;

#define ll long long
#define ull unsigned long long


vector<pair<int,int>> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<pair<int,int>>arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) {
        int idx = -1, n = line.length();
        for(int i=0;i<n;i++) if(line[i]==',') {idx = i; break;}
        int x = stoi(line.substr(1, idx-1));
        int y = stoi(line.substr(idx+2, n-idx-3));
        arr.push_back({x, y});
    }
    file.close();
    return arr;
}

void part1(vector<pair<int,int>>arr) {
    cout<<"Part1:: "<<""<<"\n";
}

void part2(vector<pair<int,int>>arr) {
    cout<<"Part2:: "<<""<<"\n";
}

void part3(vector<pair<int,int>>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<pair<int,int>>arr = get_input("06");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}
