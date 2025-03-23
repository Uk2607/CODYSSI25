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
        cout<<t<<" ";
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
    cout<<"Part1:: "<<""<<"\n";
}

void part2(vector<int>arr, vector<pair<int,int>>ops, int test_idx) {
    cout<<"Part2:: "<<""<<"\n";
}

void part3(vector<int>arr, vector<pair<int,int>>ops, int test_idx) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    pair<pair<vector<int>, vector<pair<int,int>>>,int>ip = get_input("07");
    part1(ip.first.first, ip.first.second, ip.second);
    part2(ip.first.first, ip.first.second, ip.second);
    part3(ip.first.first, ip.first.second, ip.second);
    return 0;
}
