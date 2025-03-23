#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

#define ll long long
#define ull unsigned long long


pair<pair<vector<int>, vector<pair<int,int>>>,int> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<int>arr;
    vector<pair<int,int>>ops;
    int test;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return {{arr, ops}, test};
    }
    int t=0;
    while(getline(file, line)) {
        if(line.length()==0) {
            t++;
            continue;
        }
        if(t==0) arr.push_back(stoi(line));
        else if(t==1) {
            int idx;
            for(int i=0;i<line.length();i++) if(line[i]=='-') {idx=i; break;}
            ops.push_back({stoi(line.substr(0, idx)), stoi(line.substr(idx+1))});
        }
        else if(t==2) test = stoi(line);
    }
    file.close();
    return {{arr, ops}, test};
}

void part1(vector<int>arr, vector<pair<int,int>>ops, int test_idx) {
    for(pair<int,int>p: ops)
        swap(arr[p.first-1], arr[p.second-1]);
    cout<<"Part1:: "<<arr[test_idx-1]<<"\n";
}

void part2(vector<int>arr, vector<pair<int,int>>ops, int test_idx) {
    int n = ops.size();
    for(int i=0;i<n;i++) {
        swap(arr[ops[i].first-1], arr[ops[i].second-1]);
        swap(arr[ops[i].first-1], arr[ops[(i+1)%n].first-1]);
    }
    cout<<"Part2:: "<<arr[test_idx-1]<<"\n";
}

void part3(vector<int>arr, vector<pair<int,int>>ops, int test_idx) {
    int n = arr.size();
    for(auto [a, b]: ops) {
        int l = min(a, b), r = max(a, b), len = min(r-l, n-r+1);
    }
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    pair<pair<vector<int>, vector<pair<int,int>>>,int>ip = get_input("07");
    part1(ip.first.first, ip.first.second, ip.second);
    part2(ip.first.first, ip.first.second, ip.second);
    part3(ip.first.first, ip.first.second, ip.second);
    return 0;
}
