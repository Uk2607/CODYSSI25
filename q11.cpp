#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

#define ll long long
#define ull unsigned long long


vector<pair<string, int>> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<pair<string, int>>arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) {
        string s;
        int x;
        stringstream ss(line);
        ss>>s>>x;
        arr.push_back({s, x});
    }
    file.close();
    return arr;
}

int get_numeric_val(char c) {
    if(c>='0' && c<='9') return c-'0';
    else if(c>='A' && c<='Z') return c-'A'+10;
    else if(c>='a' && c<='z') return c-'a'+36;
    return -1;
}

ll to_base10(string num, int base) {
    if(base==10) return stoll(num);
    int n = num.length(), mult = 0, i = n-1;
    ll x = 0LL;
    while(i>=0) {
        int b = get_numeric_val(num[i]);
        x += (b*pow(base, mult));
        mult++;
        i--;
    }
    return x;
}

void part1(vector<pair<string, int>>arr) {
    ll mx = LLONG_MIN;
    for(auto [num, base]: arr) {
        ll x = to_base10(num, base);
        mx = max(mx, x);
    }
    cout<<"Part1:: "<<mx<<"\n";  // 2142537924
}

char get_base_68_char(int n) {
    if(n>=0 && n<10) return '0'+n;
    else if(n<36) return n-10+'A';
    else if(n<62) return n-36+'a';
    else if(n==62) return '!';
    else if(n==63) return '@';
    else if(n==64) return '#';
    else if(n==65) return '$';
    else if(n==66) return '%';
    else return '^';
}

string bas10_to_base68(long long num) {
    ll base = 68;
    string res = "";
    while(num>0) {
        int r = num%base;
        char c = get_base_68_char(r);
        res = c+res;
        num /= base;
    }

    return res;
}

void part2(vector<pair<string, int>>arr) {
    ll sum = 0LL;
    for(auto [num, base]: arr) {
        ll x = to_base10(num, base);
        sum += x;
    }
    cout<<sum<<"\n";
    string base68 = bas10_to_base68(sum);
    cout<<"Part2:: "<<base68<<"\n";  // 5EQHr1v#E
}

void part3(vector<pair<string, int>>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<pair<string, int>>arr = get_input("11");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}
