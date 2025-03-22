#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<set>
using namespace std;

#define ll long long
#define ull unsigned long long


string get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return "";
    }
    getline(file, line);
    file.close();
    return line;
}

void part1(string str) {
    int valid_data = 0;
    for(char c: str) {
        if((c>='a' && c<='z') || (c>='A' && c<='Z')) valid_data++;
    }
    cout<<"Part1:: "<<valid_data<<"\n";
}

void part2(string str) {
    int valid_data = 0;
    for(char c: str) {
        if(c>='a' && c<='z') {
            valid_data += (c-'a'+1);
        } else if (c>='A' && c<='Z') {
            valid_data += (c-'A'+27);
        }
    }
    cout<<"Part2:: "<<valid_data<<"\n";
}

void part3(string str) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    string str = get_input("06");
    part1(str);
    part2(str);
    part3(str);
    return 0;
}
