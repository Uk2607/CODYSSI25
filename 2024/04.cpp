#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<set>
#include<map>
#include<queue>
using namespace std;


vector<pair<string,string>> get_input(string day) {
    string file_path = "2024/"+day+".in";
    ifstream file(file_path);

    vector<pair<string,string>>arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) {
        stringstream ss(line);
        string src, t, dest;
        ss>>src>>t>>dest;
        arr.push_back({src, dest});
    }
    file.close();
    return arr;
}

void part1(vector<pair<string,string>>arr) {
    set<string>st;
    for(auto [src, dest]: arr) {
        st.insert(src);
        st.insert(dest);
    }
    cout<<"Part1:: "<<st.size()<<"\n";
}

void part2(vector<pair<string,string>>arr) {
    map<string, vector<string>>mp;
    for(auto [src, dest]: arr) {
        mp[src].push_back(dest);
        mp[dest].push_back(src);
    }
    set<string>vis;
    queue<string>q;

    string start = "STT";
    q.push(start);
    int limit = 3, idx=0;

    while(idx<=limit) {
        int n = q.size();
        while(n--) {
            string curr = q.front();
            q.pop();
            vis.insert(curr);
            for(string v: mp[curr]) {
                if(vis.find(v)==vis.end())
                    q.push(v);
            }
        }
        idx++;
    }
    cout<<"Part2:: "<<vis.size()<<"\n";
}

void part3(vector<pair<string,string>>arr) {
    map<string, vector<string>>mp;
    map<string,int>time;
    for(auto [src, dest]: arr) {
        mp[src].push_back(dest);
        mp[dest].push_back(src);
    }
    set<string>vis;
    queue<string>q;

    string start = "STT";
    q.push(start);
    int limit = 3, idx=0;

    while(vis.size()!=mp.size()) {
        int n = q.size();
        while(n--) {
            string curr = q.front();
            time[curr] = idx;
            q.pop();
            vis.insert(curr);
            for(string v: mp[curr]) {
                if(vis.find(v)==vis.end())
                    q.push(v);
            }
        }
        idx++;
    }
    int total = 0;
    for(auto [pos, t]: time) {
        cout<<pos<<": "<<t<<"\n";
        total += t;
    }
    cout<<"Part3:: "<<total<<"\n";  // != 198
}

int main() {
    vector<pair<string,string>>arr = get_input("04");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}
