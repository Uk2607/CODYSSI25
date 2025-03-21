#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<set>
using namespace std;

#define ll long long
#define ull unsigned long long


vector<pair<int,int>> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<pair<int,int>>arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) {
        int idx = -1, n = line.length();
        for(int i=0;i<n;i++) if(line[i]==',') {idx = i; break;}
        int x = stoi(line.substr(1, idx-1));
        int y = stoi(line.substr(idx+2, n-idx-3));
        arr.push_back({x, y});
    }
    file.close();
    return arr;
}

void part1(vector<pair<int,int>>arr) {
    int mx = INT_MIN, mn = INT_MAX;
    for(pair<int,int>p: arr) {
        int dist = abs(p.first)+abs(p.second);
        if(dist>mx) mx = dist;
        if(dist<mn) mn = dist;
    }
    cout<<"Part1:: "<<mx-mn<<"\n";
}

void part2(vector<pair<int,int>>arr) {
    int mn = INT_MAX;
    pair<int,int>first_closest, second_closest = {INT_MAX, INT_MAX};
    for(pair<int,int>p: arr) {
        int dist = abs(p.first)+abs(p.second);
        if(dist<mn) {
            mn = dist;
            first_closest = p;
        }
    }
    mn = INT_MAX;
    for(pair<int,int>p: arr) {
        if(p == first_closest) continue;
        int dist = abs(p.first-first_closest.first)+abs(p.second-first_closest.second);
        if(dist<mn) {
            mn = dist;
            second_closest = p;
        } else if(dist == mn) {
            if(p.first<second_closest.first) {
                second_closest = p;
            } else if(p.first == second_closest.first) {
                if(p.second<second_closest.second) {
                    second_closest = p;
                }
            }
        }
    }
    cout<<"Part2:: "<<mn<<"\n";
}

void part3(vector<pair<int,int>>arr) {
    set<pair<int,int>>vis(arr.begin(), arr.end());
    int total_dist = 0;
    pair<int,int>me = {0, 0};
    while(!vis.empty()) {
        int mn = INT_MAX;
        pair<int,int>closest;
        for(pair<int,int>p: vis) {
            int dist = abs(p.first-me.first)+abs(p.second-me.second);
            if(dist<mn) {
                mn = dist;
                closest = p;
            }
        }
        total_dist += mn;
        vis.erase(closest);
        me = closest;
    }
    cout<<"Part3:: "<<total_dist<<"\n";
}

int main() {
    vector<pair<int,int>>arr = get_input("05");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}

// Part 1: 608
// Part 2: 106
// Part 3: 6535
