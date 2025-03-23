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

int get_memory_size(string s) {
    int memory = 0;
    for(char c: s) {
        if(c>='0' && c<='9') memory += (c-'0');
        else memory += (c-'A'+1);
    }
    return memory;
}

void part1(vector<string>arr) {
    int memory = 0;
    for(string line: arr) memory += get_memory_size(line);
    cout<<"Part1:: "<<memory<<"\n";
}

void part2(vector<string>arr) {
    int memory = 0;
    for(string line: arr) {
        int len = line.length();
        int ends_len = len/10;

        string s = line.substr(0, ends_len) + to_string(len - (2*ends_len)) + line.substr(len-ends_len, ends_len);
        memory += get_memory_size(s);
    }
    cout<<"Part2:: "<<memory<<"\n";
}

string compress_str(string s) {
    string res = "";
    int x = 1, len = s.length();
    char c = s[0];
    for(int i=1;i<len;i++) {
        if(c==s[i]) x++;
        else {
            res += to_string(x)+c;
            c = s[i];
            x=1;
        }
    }
    res += to_string(x)+c;
    return res;
}

void part3(vector<string>arr) {
    int memory = 0;
    for(string line: arr) {
        string str = compress_str(line);
        memory += get_memory_size(str);
    }
    cout<<"Part3:: "<<memory<<"\n";
}

int main() {
    vector<string>arr = get_input("04");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}

// Part 1: 135056
// Part 2: 27026
// Part 3: 45359
