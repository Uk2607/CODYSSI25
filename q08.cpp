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
    int cnt = 0;
    for(string row: arr) {
        for(char c: row) {
            if(c>='a' && c<='z') cnt++;
        }
    }
    cout<<"Part1:: "<<cnt<<"\n";
}

bool is_digit(char c) {
    return c>='0' && c<='9';
}
bool is_alpha(char c) {
    return c>='a' && c<='z';
}

string reduce_str1(string str) {
    string res = "";
    while(true) {
        for(char c: str) {
            if(res.length()==0) res+=c;
            else {
                if((is_digit(c) && !is_digit(res.back())) || (is_digit(res.back()) && !is_digit(c))) res.pop_back();
                else res+=c;
            }
        }
        if(str == res) break;
        str = res;
        res = "";
    }
    return res;
}

void part2(vector<string>arr) {
    int cnt = 0;
    for(string row: arr) {
        string reduced = reduce_str1(row);
        cnt += reduced.length();
    }
    cout<<"Part2:: "<<cnt<<"\n";
}

string reduce_str2(string str) {
    string res = "";
    while(true) {
        for(char c: str) {
            if(res.length()==0) res+=c;
            else {
                if((is_digit(c) && is_alpha(res.back())) || (is_digit(res.back()) && is_alpha(c))) res.pop_back();
                else res+=c;
            }
        }
        if(str == res) break;
        str = res;
        res = "";
    }
    return res;
}

void part3(vector<string>arr) {
    int cnt = 0;
    for(string row: arr) {
        string reduced = reduce_str2(row);
        cnt += reduced.length();
    }
    cout<<"Part3:: "<<cnt<<"\n";
}

int main() {
    vector<string>arr = get_input("08");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}

// Part 1: 4704
// Part 2: 686
// Part 3: 1306
