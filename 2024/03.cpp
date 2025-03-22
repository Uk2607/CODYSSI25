#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;


vector<pair<string,int>> get_input(string day) {
    string file_path = "2024/"+day+".in";
    ifstream file(file_path);

    vector<pair<string,int>>arr;
    string num;
    int base;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(file>>num>>base) {
        arr.push_back({num, base});
    }
    file.close();
    return arr;
}

void part1(vector<pair<string,int>>arr) {
    int sum = 0;
    for(pair<string,int>p: arr) sum += p.second;
    cout<<"Part1:: "<<sum<<"\n";
}

int to_base10(string num, int base) {
    if(base==10) return stoi(num);
    int n = num.length(), x = 0, mult = 0, i = n-1;
    while(i>=0) {
        int b = (num[i]>='0' && num[i]<='9')?num[i]-'0':num[i]-'A'+10;
        x += (b*pow(base, mult));
        mult++;
        i--;
    }
    return x;
}

void part2(vector<pair<string,int>>arr) {
    long long sum = 0;
    for(pair<string,int>p: arr)
        sum += to_base10(p.first, p.second);
    cout<<"Part2:: "<<sum<<"\n";
}

char get_base_65_char(int n) {
    if(n>=0 && n<10) return '0'+n;
    else if(n<36) return n-10+'A';
    else if(n<62) return n-36+'a';
    else if(n==62) return '!';
    else if(n==63) return '@';
    else return '#';
}

string bas10_to_base65(long long num) {
    string res = "";

    while(num>0) {
        int r = num%65;
        char c = get_base_65_char(r);
        res = c+res;
        num /= 65LL;
    }

    return res;
}

void part3(vector<pair<string,int>>arr) {
    long long sum = 0;
    for(pair<string,int>p: arr)
        sum += to_base10(p.first, p.second);
    string base65 = bas10_to_base65(sum);
    cout<<"Part3:: "<<base65<<"\n";
}

int main() {
    vector<pair<string,int>>arr = get_input("03");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}

// Part 1: 7122
// Part 2: 410358142199
// Part 3: 5ShT2Wi
