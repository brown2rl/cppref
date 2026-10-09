#include <iostream>
#include <queue>
#include <vector>

void breadthFirstSearch(const std::vector<std::vector<int>>& graph, int start) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> pending;

    visited[start] = true;
    pending.push(start);

    while (!pending.empty()) {
        const int vertex = pending.front();
        pending.pop();
        std::cout << vertex << ' ';

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                pending.push(neighbor);
            }
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

    std::cout << "BFS traversal from vertex 0: ";
    breadthFirstSearch(graph, 0);
    std::cout << '\n';

    return 0;
}
