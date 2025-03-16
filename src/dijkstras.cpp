
#include <algorithm>

#include "dijkstras.h"


struct Node {
      int vertex;
      int weight;

      Node(int v, int w) : vertex(v), weight(w) {}
};

struct WeightComparator {
    bool operator()(const Node& a, const Node& b) const {
        return a.weight > b.weight;
    }
};

//struct Edge {
//    int src=0;
//    int dst=0;
//    int weight=0;
//    Edge(int s = 0, int d = 0, int w = 0) : src(s), dst(d), weight(w) {}
//    friend istream& operator>>(istream& in, Edge& e)
//    {
//        return in >> e.src >> e.dst >> e.weight;
//    }
//
//    friend ostream& operator<<(ostream& out, const Edge& e)
//    {
//        return out << "(" << e.src << "," << e.dst << "," << e.weight << ")";
//    }
//};
//
//struct Graph : public vector<vector<Edge>> {
//    int numVertices=0;
//};
//
//inline istream& operator>>(istream& in, Graph& G) {
//    if (!(in >> G.numVertices))
//        throw runtime_error("Unable to find input file");
//    G.resize(G.numVertices);
//    for (Edge e; in >> e;)
//        G[e.src].push_back(e);
//    return in;
//}
//
//inline void file_to_graph(const string& filename, Graph& G) {
//    ifstream in(filename);
//    if (!in) {
//        throw runtime_error("Can't open input file");
//    }
//    in >> G;
//    in.close();
//}

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;

    vector<int> distance(n, INF);
    vector<bool> visited(n, false);
    previous.resize(n, -1);

    priority_queue<Node, vector<Node>, WeightComparator> pq;

    distance[source] = 0;
    pq.push(Node(source, 0));

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.vertex;

        if (visited[u]) continue;
        visited[u] = true;

        for (auto & neighbor : G[u]) {
            int v = neighbor.dst;
            int weight = neighbor.weight;
            if (!visited[v] && distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                
                pq.push(Node(v, distance[v]));
            }
        }
    }
    
    return distance;
}
vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> path;
    int current = destination;
    
    while (current != -1) {
        path.push_back(current);
        current = previous[current];
    }
    
    reverse(path.begin(), path.end());
    return path;
}


void print_path(const vector<int>& v, int total) {
    if (v.empty()) {
        cout << "Path is empty" << endl; 
        return;
    }
    
    for (int i = 0; i < v.size(); ++i) 
        cout << v[i] << " ";  
}