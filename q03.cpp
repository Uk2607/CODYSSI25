#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define ll long long
#define ull unsigned long long

const ll A = 151LL;
const ll B = 85LL;


vector<int> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<int> arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) arr.push_back(stoi(line));
    file.close();
    return arr;
}

ll get_price(int n) {
    // Function A: ADD 151
    // Function B: MULTIPLY 85
    // Function C: RAISE TO THE POWER OF 3
    ll x = n;
    return (x*x*x*B)+A;
}

void part1(vector<int>arr) {
    sort(arr.begin(), arr.end());
    int med = arr[arr.size()/2];
    cout<<"Part1:: "<<get_price(med)<<"\n";
}

void part2(vector<int>arr) {
    int sum = 0;
    for(int x: arr) if(x%2==0) sum += x;
    cout<<"Part2:: "<<get_price(sum)<<"\n";
}

void part3(vector<int>arr) {
    ll limit = 15000000000000LL, diff = LLONG_MAX;
    int room = -1;
    for(int x: arr) {
        ll price = get_price(x);
        if(price<limit && limit-price<diff) {
            diff = limit-price;
            room = x;
        }
    }
    cout<<"Part3:: "<<room<<"\n";
}

int main() {
    vector<int>arr = get_input("03");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}

// Part 1: 11275335000151
// Part 2: 2917782888825994711
// Part 3: 5587