#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

#define ll long long
#define ull unsigned long long


vector<vector<int>> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<vector<int>>arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) {
        vector<int>row;
        stringstream ss(line);
        int num;
        while(ss>>num) row.push_back(num);
        arr.push_back(row);
    }
    file.close();
    return arr;
}

void part1(vector<vector<int>>arr) {
    int r = arr.size(), c = arr[0].size();    
    vector<int> rowSums(r, 0), colSums(c, 0);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            rowSums[i] += arr[i][j];
            colSums[j] += arr[i][j];
        }
    
    int mn = INT_MAX;
    for (int sum : rowSums)
        if (sum < mn) mn = sum;
    for (int sum : colSums)
        if (sum < mn) mn = sum;
    
    cout<<"Part1:: "<<mn<<"\n";
}

void part2(vector<vector<int>>arr) {
    cout<<"Part2:: "<<""<<"\n";
}

void part3(vector<vector<int>>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<vector<int>>arr = get_input("10");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}

// Part 1: 208
// Part 2: 109
// Part 3: 302
