#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;


vector<bool> get_input(string day) {
    string file_path = "2024/"+day+".in";
    ifstream file(file_path);

    vector<bool>arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) {
        if(line == "TRUE") arr.push_back(true);
        else arr.push_back(false);
    }
    file.close();
    return arr;
}

void part1(vector<bool>arr) {
    int total = 0;
    for(int i=0;i<arr.size();i++)
        if(arr[i])
            total+=(i+1);
    cout<<"Part1:: "<<total<<"\n";
}

void part2(vector<bool>arr) {
    int total = 0;
    bool flag = true;
    for(int i=0;i<arr.size();i+=2) {
        bool c;
        if(flag) c = arr[i]&arr[i+1];
        else c = arr[i]|arr[i+1];
        if(c) total++;
        flag = !flag;
    }
    cout<<"Part2:: "<<total<<"\n";
}

void part3(vector<bool>arr) {
    int total = 0;
    while(arr.size()>0) {
        vector<bool>t;
        bool flag = true;
        for(int i=0;i<arr.size()-1;i+=2) {
            bool c;
            total+=(arr[i]+arr[i+1]);
            if(flag) c = arr[i]&arr[i+1];
            else c = arr[i]|arr[i+1];
            t.push_back(c);
            flag = !flag;
        }
        if(arr.size()==1 && arr[0]==1) total++;
        arr = t;
    }
    cout<<"Part3:: "<<total<<"\n";
}

int main() {
    vector<bool>arr = get_input("02");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}

// Part 1: 86712
// Part 2: 172
// Part 3: 676
