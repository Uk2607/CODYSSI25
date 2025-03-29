#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include<set>
#include <unordered_set>
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

    vector<int> lengths;
    for (const auto& entry : distances)
        if (entry.second != numeric_limits<int>::max() && entry.first != start)
            lengths.push_back(entry.second);

    sort(lengths.rbegin(), lengths.rend());

    int product = 1;
    for (int i = 0; i < 3 && i < lengths.size(); ++i)
        product *= lengths[i];

    cout << "Part1:: " << product << "\n";
}

void part2(vector<pair<pair<string,string>, int>>arr) {
    string start = "STT";
    map<string, vector<pair<string,int>>>mp;
    for(pair<pair<string,string>, int>p: arr)
        mp[p.first.first].push_back({p.first.second, p.second});
    
    map<string, int>distances = dij(mp, start);

    vector<int> lengths;
    for (const auto& entry : distances)
        if (entry.second != numeric_limits<int>::max() && entry.first != start)
            lengths.push_back(entry.second);

    sort(lengths.rbegin(), lengths.rend());

    int product = 1;
    for (int i = 0; i < 3 && i < lengths.size(); ++i) product *= lengths[i];

    cout << "Part2:: " << product << "\n";
}

void dfs(const string& node, const string& startNode, const map<string, vector<pair<string, int>>>& graph,
         unordered_set<string>& visited, unordered_set<string>& currentPath,
         int currentCost, int& longestCycle) {
    // If we revisit the starting node and the path length is greater than 1, we found a cycle
    if (currentPath.count(node) && node == startNode) {
        // Update the longest cycle cost if the cycle is valid
        longestCycle = max(longestCycle, currentCost);
        return;
    }

    // If the node has already been visited in a different path, return
    if (visited.count(node)) {
        return;
    }

    // Mark the node as visited and add it to the current path
    visited.insert(node);
    currentPath.insert(node);

    // Explore all neighbors if the node exists in the graph
    if (graph.find(node) != graph.end()) {
        for (const auto& neighbor : graph.at(node)) {
            dfs(neighbor.first, startNode, graph, visited, currentPath, currentCost + neighbor.second, longestCycle);
        }
    }

    // Backtrack: remove the node from the current path
    currentPath.erase(node);
    visited.erase(node);
}

int longestCycle(const map<string, vector<pair<string, int>>>& graph) {
    int longestCycle = 0;

    for (const auto& entry : graph) {
        const string& node = entry.first;
        unordered_set<string> currentPath; // To track the current path
        unordered_set<string> visited;

        dfs(node, node, graph, visited, currentPath, 0, longestCycle);
    }

    return longestCycle;
}

void part3(vector<pair<pair<string, string>, int>> arr) {
    map<string, vector<pair<string, int>>> graph;
    for (const auto& p : arr) graph[p.first.first].push_back({p.first.second, p.second});

    int longest_cycle_length = longestCycle(graph);
    cout << "Part3:: " << longest_cycle_length << "\n";
}

int main() {
    vector<pair<pair<string,string>, int>>arr = get_input("13");
    part1(arr);
    part2(arr);
    part3(arr);

    return 0;
}

// Part 1: 3600
// Part 2: 3557250
// Part 3: 265
