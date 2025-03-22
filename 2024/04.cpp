#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<set>
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
    string me = "STT";
    int limit = 3;
    cout<<"Part2:: "<<""<<"\n";
}

void part3(vector<pair<string,string>>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<pair<string,string>>arr = get_input("04");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}
