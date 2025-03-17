    #include <iostream>
    #include <vector>
    #include <queue>
    #include <fstream>

    void BFS(const std::vector<std::vector<int> > &graph, int start, std::vector<int> &distance) {
        int n = graph.size();
        std::queue<int> Queue;
        std::vector<bool> visited(n, false);

        Queue.push(start);
        visited[start] = true;
        distance[start] = 0;

        while (!Queue.empty()) {
            int node = Queue.front();
            Queue.pop();

            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[node] + 1;
                    Queue.push(neighbor);
                }
            }
        }
    }

    int main() {    
        std::ifstream file("graph.txt");
        if (!file) {
            std::cerr << "Error. Graph.txt not found." << std::endl;
            return 0;
        }

        int nodes = 0, edges = 0;
        file >> nodes >> edges;
        std::vector<std::vector<int> > graph(nodes);

        for(int i = 0; i < edges; ++i) {
            int firstNode = 0, secondNode = 0;
            file >> firstNode >> secondNode;
            graph[firstNode].push_back(secondNode);
            graph[secondNode].push_back(firstNode);
        }

        int start = 0;
        file >> start;
        file.close();
        std::vector<int> distance(nodes, -1);

        BFS(graph, start, distance);

        for(int i = 0; i < nodes; ++i) std::cout << distance[i] << std::endl;

        return 0;
    }
