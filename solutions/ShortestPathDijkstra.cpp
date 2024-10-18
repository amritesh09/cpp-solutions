// Problem 3: Dijkstra's Algorithm
// Given a graph, find the shortest path from a source node to all other nodes using Dijkstra's algorithm.

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
using namespace std;

vector<int> dijkstra(int source, const vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, numeric_limits<int>::max());
    dist[source] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<pair<int, int>>> adj = {
        {{1, 2}, {4, 1}},
        {{2, 3}, {4, 3}},
        {{3, 1}},
        {{4, 1}},
        {{3, 3}}
    };
    vector<int> distances = dijkstra(0, adj);
    cout << "Shortest distances from node 0: ";
    for (int i = 0; i < distances.size(); ++i) {
        cout << i << ": " << distances[i] << " ";
    }
    cout << endl;
    return 0;
}