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
    while(getline(file, line)) arr.push_back(line);
    file.close();
    return arr;
}

void part1(vector<string>arr) {
    int memory = 0;
    for(string line: arr)
        for(char c: line)
            memory += (c-'A'+1);
    cout<<"Part1:: "<<memory<<"\n";
}

void part2(vector<string>arr) {
    int memory = 0;
    for(string line: arr) {
        int len = line.length();
        int ends_len = len/10;
        string s = line.substr(0, ends_len) + to_string(len - (2*ends_len)) + line.substr(len-ends_len, ends_len);
        for(char c: s) {
            if(c>='0' && c<='9') memory += (c-'0'+1);
            else memory += (c-'A'+1);
        }
    }
    cout<<"Part2:: "<<memory<<"\n";
}

void part3(vector<string>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<string>arr = get_input("04");
    part1(arr);
    part2(arr);
    // part3(arr);
    return 0;
}
