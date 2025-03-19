#include<iostream>
#include<fstream>
#include<string>
using namespace std;

pair<vector<int>, string> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<int> arr;
    string line, ops;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return {arr, ops};
    }
    while(getline(file, line)) {
        if(line[0] == '+' || line[0] == '-') ops = line;
        else arr.push_back(stoi(line));
    }
    file.close();
    return {arr, ops};
}

void part1n2(vector<int>arr, string ops, int part=1) {
    int x = arr[0];
    for(int i=1;i<arr.size();i++) {
        if(ops[i-1]=='+') x+=arr[i];
        else x-=arr[i];
    }
    if(part == 1)
        cout<<"Part1:: "<<x<<"\n";
    else
        cout<<"Part2:: "<<x<<"\n";
}

void part3(vector<int>arr, string ops) {
    int x = arr[0]*10+arr[1];
    for(int i=2;i<arr.size();i+=2) {
        int y = arr[i]*10+arr[i+1];
        if(ops[(i/2)-1]=='+') x+=y;
        else x-=y;
    }
    cout<<"Part3:: "<<x<<"\n";
}

int main() {
    vector<int>arr;
    string ops;
    pair<vector<int>, string>ip = get_input("01");
    arr = ip.first;
    ops = ip.second;
    part1n2(arr, ops);
    reverse(ops.begin(), ops.end());
    part1n2(arr, ops, 2);
    part3(arr, ops);
}

// Part 1: -196
// Part 2: -60
// Part 3: -645