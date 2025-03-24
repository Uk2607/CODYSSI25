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

string reduce_str(string str) {
    string res = "";
    while(true) {
        for(char c: str) {
            if(res.length()==0) res+=c;
            else {
                if(is_digit(c)) {
                    if(!is_digit(res.back())) res.pop_back();
                    else res+=c;
                } else {
                    if(is_digit(res.back())) res.pop_back();
                    else res+=c;
                }
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
        string reduced = reduce_str(row);
        cnt += reduced.length();
    }
    cout<<"Part2:: "<<cnt<<"\n";
}

void part3(vector<string>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<string>arr = get_input("08");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}

// Part 1: 22971
// Part 2: 19486
// Part 3: 12901
