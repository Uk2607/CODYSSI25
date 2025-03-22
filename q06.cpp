#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;



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
    int n = str.length(), valid_data = 0;
    vector<int>val(n, 0);
    for(int i=0;i<n;i++) {
        char c = str[i];
        if(c>='a' && c<='z') {
            val[i] = (c-'a'+1);
        } else if (c>='A' && c<='Z') {
            val[i] = (c-'A'+27);
        } else {
            int x = (i>0)?val[i-1]:0;
            x = (x*2)-5;
            while(x>52) x-=52;
            while(x<1) x+=52;
            val[i] = x;
        }
        valid_data += val[i];
    }
    cout<<"Part3:: "<<valid_data<<"\n";
}

int main() {
    string str = get_input("06");
    part1(str);
    part2(str);
    part3(str);
    return 0;
}

// Part 1: 1323
// Part 2: 35264
// Part 3: 52815
