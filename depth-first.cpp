#include <iostream>
#include <vector>

void depthFirstSearch(const std::vector<std::vector<int>>& graph,
                      std::vector<bool>& visited, int vertex) {
    visited[vertex] = true;
    std::cout << vertex << ' ';

    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            depthFirstSearch(graph, visited, neighbor);
        }
    }
}

int main() {
    const std::vector<std::vector<int>> graph{
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1, 5},
        {2, 4}
    };
    std::vector<bool> visited(graph.size(), false);

    std::cout << "DFS traversal from vertex 0: ";
    depthFirstSearch(graph, visited, 0);
    std::cout << '\n';

    return 0;
}
