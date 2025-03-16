
#include "dijkstras.h"

int main() {
    Graph G;
    file_to_graph("src/medium.txt", G);

    int source = 1;
    vector<int> previous;
    vector<int> dist = dijkstra_shortest_path(G, source, previous);

    int destination = 5;
    vector<int> path = extract_shortest_path(dist, previous, destination);
    print_path(path, dist[destination]);
}