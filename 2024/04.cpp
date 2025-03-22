#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;


string get_input(string day) {
    string file_path = "2024/"+day+".in";
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
    cout<<"Part1:: "<<""<<"\n";
}

void part2(string str) {
    cout<<"Part2:: "<<""<<"\n";
}

void part3(string str) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    string str = get_input("04");
    part1(str);
    part2(str);
    part3(str);
    return 0;
}
