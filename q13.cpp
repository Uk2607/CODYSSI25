#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
using namespace std;

#define ll long long
#define ull unsigned long long


vector<pair<pair<string,string>, int>> get_input(string day) {
    string file_path = "ip/"+day+".in";
    ifstream file(file_path);

    vector<pair<pair<string,string>, int>>arr;
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }
    while(getline(file, line)) {
        stringstream ss(line);
        string a, b, t;
        int x;
        ss>>a>>t>>b>>t>>x;
        arr.push_back({{a, b}, x});
    }
    file.close();
    return arr;
}

map<string, int> dij(map<string, vector<pair<string,int>>>&mp, string start) {
    // Dijkstra's algorithm
    map<string, int> distances;
    for (const auto& location : mp) {
        distances[location.first] = numeric_limits<int>::max(); // Initialize distances
    }
    distances[start] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        string current_location = pq.top().second;
        pq.pop();

        if (current_distance > distances[current_location]) {
            continue; // Skip if we have already found a shorter path
        }

        for (const auto& neighbor : mp[current_location]) {
            string next_location = neighbor.first;
            int weight = neighbor.second;
            int new_distance = current_distance + weight;

            if (new_distance < distances[next_location]) {
                distances[next_location] = new_distance;
                pq.push({new_distance, next_location});
            }
        }
    }
    return distances;
}

void part1(vector<pair<pair<string,string>, int>>arr) {
    string start = "STT";
    map<string, vector<pair<string,int>>>mp;
    for(pair<pair<string,string>, int>p: arr)
        mp[p.first.first].push_back({p.first.second, 1});  // Using path length 1 for part 1
    
    map<string, int>distances = dij(mp, start);

    // Collect distances and find the three longest paths
    vector<int> lengths;
    for (const auto& entry : distances) {
        if (entry.second != numeric_limits<int>::max() && entry.first != start) {
            lengths.push_back(entry.second);
        }
    }

    // Sort lengths in descending order
    sort(lengths.rbegin(), lengths.rend());

    // Calculate the product of the lengths of the 3 longest paths
    int product = 1;
    for (int i = 0; i < 3 && i < lengths.size(); ++i) {
        product *= lengths[i];
    }

    cout << "Part1:: " << product << "\n";
}

void part2(vector<pair<pair<string,string>, int>>arr) {
    string start = "STT";
    map<string, vector<pair<string,int>>>mp;
    for(pair<pair<string,string>, int>p: arr)
        mp[p.first.first].push_back({p.first.second, p.second});  // Using path length 1 for part 1
    
    map<string, int>distances = dij(mp, start);

    // Collect distances and find the three longest paths
    vector<int> lengths;
    for (const auto& entry : distances) {
        if (entry.second != numeric_limits<int>::max() && entry.first != start) {
            lengths.push_back(entry.second);
        }
    }

    // Sort lengths in descending order
    sort(lengths.rbegin(), lengths.rend());

    // Calculate the product of the lengths of the 3 longest paths
    int product = 1;
    for (int i = 0; i < 3 && i < lengths.size(); ++i) {
        product *= lengths[i];
    }

    cout << "Part2:: " << product << "\n";
}

void part3(vector<pair<pair<string,string>, int>>arr) {
    cout<<"Part3:: "<<""<<"\n";
}

int main() {
    vector<pair<pair<string,string>, int>>arr = get_input("13");
    part1(arr);
    part2(arr);
    part3(arr);
    return 0;
}
