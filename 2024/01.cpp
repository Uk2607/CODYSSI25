#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;


vector<int> get_input(string day) {
    string file_path = "2024/"+day+".in";
    ifstream file(file_path);

    vector<int>arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) {
        arr.push_back(stoi(line));
    }
    file.close();
    return arr;
}

void part1(vector<int>arr) {
    int total = 0;
    for(int x: arr) total += x;
    cout<<"Part1:: "<<total<<"\n";
}

void part2(vector<int>arr) {
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    int total = 0;
    for(int i=20;i<arr.size();i++) total += arr[i];
    cout<<"Part2:: "<<total<<"\n";
}

void part3(vector<int>arr) {
    int total = 0;
    for(int i=0;i<arr.size();i++) {
        if(i%2==0) total += arr[i];
        else total -= arr[i];
    }
    cout<<"Part3:: "<<total<<"\n";
}

int main() {
    vector<int>arr = get_input("01");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}

// Part 1: 153968069
// Part 2: 134846540
// Part 3: 1009247
