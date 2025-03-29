#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

#define ll long long
#define ull unsigned long long


vector<pair<pair<string,string>, int>> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<pair<pair<string,string>, int>>arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) {
        stringstream ss(line);
        string a, b, t;
        int x;
        ss>>a>>t>>b>>t>>x;
        arr.push_back({{a, b}, x});
    }
    file.close();
    return arr;
}

void part1(vector<pair<pair<string,string>, int>>arr) {
    cout<<"Part1:: "<<""<<"\n";
}

void part2(vector<pair<pair<string,string>, int>>arr) {
    cout<<"Part2:: "<<""<<"\n";
}

void part3(vector<pair<pair<string,string>, int>>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<pair<pair<string,string>, int>>arr = get_input("13");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}
