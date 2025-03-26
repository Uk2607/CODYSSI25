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

int min_cost_path(vector<vector<int>>&arr, pair<int,int>me, pair<int,int>dest) {
    int r = arr.size(), c = arr[0].size();
    if(me.first>=r || me.second>=c || dest.first>=r || dest.second>=c) return -1;
    vector<vector<int>>dp(r, vector<int>(c, INT_MAX));
    for(int i=me.first;i<=dest.first;i++) {
        for(int j=me.second;j<=dest.second;j++) {
            if(i==me.first && j==me.second) {
                dp[i][j] = arr[i][j];
                continue;
            }
            if(i>me.first) dp[i][j] = min(dp[i][j], dp[i-1][j]+arr[i][j]);
            if(j>me.second) dp[i][j] = min(dp[i][j], dp[i][j-1]+arr[i][j]);
        }
    }
    return dp[dest.first][dest.second];
} 

void part2(vector<vector<int>>arr) {
    pair<int,int>me = {0, 0}, dest = {14, 14};
    int min_cost = min_cost_path(arr, me, dest);
    cout<<"Part2:: "<<min_cost<<"\n";
}

void part3(vector<vector<int>>arr) {
    pair<int,int>me = {0, 0}, dest = {49, 49};
    int min_cost = min_cost_path(arr, me, dest);
    cout<<"Part3:: "<<min_cost<<"\n";
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
