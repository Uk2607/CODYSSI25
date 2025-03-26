#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
using namespace std;

#define ll long long
#define ull unsigned long long


pair<map<string,int>, vector<pair<pair<string,string>, int>>> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    map<string, int> balance;
    vector<pair<pair<string,string>, int>> transactions;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return {balance, transactions};
    }
    bool flag = true;
    while(getline(file, line)) {
        if(line.length()==0) {
            flag = false;
            continue;
        }
        string a, b, t;
        int c;
        stringstream ss(line);
        if(flag) {
            ss>>a>>t>>c;
            balance[a] = c;
        } else {
            ss>>t>>a>>t>>b>>t>>c;
            transactions.push_back({{a, b}, c});
        }
    }
    file.close();
    return {balance, transactions};
}

int get_top_3_sum(vector<int>res) {
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    return res[0]+res[1]+res[2];
}

void part1(map<string, int> balance, vector<pair<pair<string,string>, int>> transactions) {
    for(pair<pair<string, string>, int> transaction: transactions) {
        string sender = transaction.first.first;
        string reciever = transaction.first.second;
        int amount = transaction.second;
        balance[sender] -= amount;
        balance[reciever] += amount;
    }
    vector<int>res;
    for(auto it: balance) res.push_back(it.second);
    
    int top_3_sum = get_top_3_sum(res);

    cout<<"Part1:: "<<top_3_sum<<"\n";
}

void part2(map<string, int> balance, vector<pair<pair<string,string>, int>> transactions) {
    for(pair<pair<string, string>, int> transaction: transactions) {
        string sender = transaction.first.first;
        string reciever = transaction.first.second;
        int amount = min(balance[sender], transaction.second);
        balance[sender] -= amount;
        balance[reciever] += amount;
    }
    vector<int>res;
    for(auto it: balance) res.push_back(it.second);
    
    int top_3_sum = get_top_3_sum(res);

    cout<<"Part2:: "<<top_3_sum<<"\n";
}

void part3(map<string, int> balance, vector<pair<pair<string,string>, int>> transactions) {
    map<string, vector<pair<string,int>>>debt_mp;
    for(pair<pair<string, string>, int> transaction: transactions) {
        string sender = transaction.first.first;
        string reciever = transaction.first.second;
        int amount = transaction.second;

        if(amount<=balance[sender]) {
            balance[sender] -= amount;
            balance[reciever] += amount;
        } else {
            int debt = amount-balance[sender];
            balance[reciever] += balance[sender];
            balance[sender] = 0;
            debt_mp[sender].push_back({reciever, debt});
        }
        for(auto &it: balance) {
            string sen = it.first;
            while(it.second>0 && debt_mp[sen].size()!=0) {
                string rec = debt_mp[sen][0].first;
                int debt_amt = debt_mp[sen][0].second;
                if(it.second>=debt_amt) {
                    balance[sen] -= debt_amt;
                    balance[rec] += debt_amt;
                    debt_mp[sen].erase(debt_mp[sen].begin());
                } else {
                    balance[rec]+= balance[sen];
                    debt_mp[sen][0].second = debt_amt-balance[sen];
                    balance[sen] = 0;
                }
            }
        }
    }

    vector<int>res;
    for(auto it: balance) res.push_back(it.second);
    
    int top_3_sum = get_top_3_sum(res);

    cout<<"Part3:: "<<top_3_sum<<"\n";
}

int main() {
    pair<map<string,int>, vector<pair<pair<string,string>, int>>>ip = get_input("09");
    part1(ip.first, ip.second);
    part2(ip.first, ip.second);
    part3(ip.first, ip.second);
    return 0;
}

// Part 1: 9891
// Part 2: 6287
// Part 3: 6181
