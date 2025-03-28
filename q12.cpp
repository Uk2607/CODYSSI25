#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

#define ll long long
#define ull unsigned long long


tuple<vector<vector<int>>, vector<vector<string>>, vector<string>>get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<vector<int>>arr;
    vector<vector<string>>ins;
    vector<string>option;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return make_tuple(arr, ins, option);
    }
    int ip=0;
    while(getline(file, line)) {
        if(line.length()==0) {
            ip++;
            continue;
        }
        if(ip==0) {
            stringstream ss(line);
            int x;
            vector<int>t;
            while(ss>>x) t.push_back(x);
            arr.push_back(t);
        } else if(ip==1) {
            stringstream ss(line);
            string word;
            vector<string>t;
            while(ss>>word) t.push_back(word); 
            ins.push_back(t);
        } else {
            option.push_back(line);
        }
    }
    file.close();
    return make_tuple(arr, ins, option);
}

void shiftMatrix(vector<vector<int>>& matrix, int index, int x, const string& direction) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    if (direction == "ROW") {
        // Shift the specified row to the right
        x = x % cols;  // Handle shifts greater than the row length
        vector<int> row = matrix[index];
        matrix[index] = vector<int>(row.end() - x, row.end()); // Last x elements
        matrix[index].insert(matrix[index].end(), row.begin(), row.end() - x); // Remaining elements
    } else if (direction == "COL") {
        // Shift the specified column down
        x = x % rows;  // Handle shifts greater than the column length
        vector<int> col(rows);
        for (int i = 0; i < rows; ++i) {
            col[i] = matrix[i][index];
        }
        vector<int> new_col(col.end() - x, col.end()); // Last x elements
        new_col.insert(new_col.end(), col.begin(), col.end() - x); // Remaining elements
        for (int i = 0; i < rows; ++i) {
            matrix[i][index] = new_col[i];
        }
    }
}

void updateMatrix(vector<vector<int>>& matrix, const string& op, const string& dir, int amnt, int idx = -1) {
    const int L = 0, R = 1073741823, C = 1073741824;
    if(dir=="ALL") {
        for(vector<int>&row: matrix) {
            for(int &x: row) {
                if(op=="ADD") x+=amnt;
                else if(op=="SUB") x-=amnt;
                else x *= amnt;
                while(x<L) x+=C;
                while(x>R) x-=C;
            }
        }
    }
    else if(dir=="ROW") {
        for(int &x: matrix[idx-1]) {
            if(op=="ADD") x+=amnt;
            else if(op=="SUB") x-=amnt;
            else x *= amnt;
            while(x<L) x+=C;
            while(x>R) x-=C;
        }
    }
    else {
        for(int i=0;i<matrix.size();i++) {
            int x = matrix[i][idx-1];
            if(op=="ADD") x+=amnt;
            else if(op=="SUB") x-=amnt;
            else x *= amnt;
            while(x<L) x+=C;
            while(x>R) x-=C;
            matrix[i][idx-1] = x;
        }
    }
}

void part1(vector<vector<int>>arr, vector<vector<string>>ins, vector<string>opt) {
    for(vector<string> ins_arr: ins) {
        if(ins_arr[0]=="SHIFT") {
            shiftMatrix(arr, stoi(ins_arr[2])-1, stoi(ins_arr[4]), ins_arr[1]);
        } else { // Add, Sub, Mul
            if(ins_arr.size()==3) {
                updateMatrix(arr, ins_arr[0], ins_arr[2], stoi(ins_arr[1]));
            } else {
                updateMatrix(arr, ins_arr[0], ins_arr[2], stoi(ins_arr[1]), stoi(ins_arr[3]));
            }
        }
    }
    
    int r = arr.size(), c = arr[0].size();    
    vector<ll> rowSums(r, 0), colSums(c, 0);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            rowSums[i] += arr[i][j];
            colSums[j] += arr[i][j];
        }
    }
    
    ll mx = LLONG_MIN;
    for (ll sum : rowSums) if (sum > mx) mx = sum;
    for (ll sum : colSums) if (sum > mx) mx = sum;
    cout<<"Part1:: "<<mx<<"\n";
}

void part2(vector<vector<int>>arr, vector<vector<string>>ins, vector<string>opt) {
    vector<string>curr_ins;
    for(string action: opt) {
        if(action == "TAKE") {
            curr_ins = ins[0];
        } else if(action == "CYCLE") {
            ins.erase(ins.begin());
            ins.push_back(curr_ins);
        } else {
            ins.erase(ins.begin());
            if(curr_ins[0]=="SHIFT") {
                shiftMatrix(arr, stoi(curr_ins[2])-1, stoi(curr_ins[4]), curr_ins[1]);
            } else {
                if(curr_ins.size()==3) {
                    updateMatrix(arr, curr_ins[0], curr_ins[2], stoi(curr_ins[1]));
                } else {
                    updateMatrix(arr, curr_ins[0], curr_ins[2], stoi(curr_ins[1]), stoi(curr_ins[3]));
                }
            }
        }
    }
    int r = arr.size(), c = arr[0].size();    
    vector<ll> rowSums(r, 0), colSums(c, 0);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            rowSums[i] += arr[i][j];
            colSums[j] += arr[i][j];
        }
    }
    
    ll mx = LLONG_MIN;
    for (ll sum : rowSums) if (sum > mx) mx = sum;
    for (ll sum : colSums) if (sum > mx) mx = sum;
    cout<<"Part2:: "<<mx<<"\n";
}

void part3(vector<vector<int>>arr, vector<vector<string>>ins, vector<string>opt) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    auto ip = get_input("12");
    vector<vector<int>> arr = get<0>(ip);
    vector<vector<string>> ins = get<1>(ip);
    vector<string> opt = get<2>(ip);
    part1(arr, ins, opt);
    part2(arr, ins, opt);
    part3(arr, ins, opt);
    return 0;
}
