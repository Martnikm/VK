    #include <iostream>
    #include <vector>
    #include <queue>
    #include <fstream>

    void BFS(const std::vector<std::vector<int> > &graph, int start, std::vector<int> &distance) {
        int n = graph.size();
        std::queue<int> q;
        std::vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;
        distance[start] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int neighbor : graph[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[v] + 1;
                    q.push(neighbor);
                }
            }
        }
    }

    int main() {    
        std::ifstream file("graph.txt");
        if (!file) {
            std::cerr << "Error" << std::endl;
            return 0;
        }

        int ver = 0, edges = 0;
        file >> ver >> edges;
        std::vector<std::vector<int> > graph(ver);

        for(int i = 0; i < edges; ++i) {
            int u = 0, v = 0;
            file >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int start = 0;
        file >> start;
        file.close();
        std::vector<int> distance(ver, -1);

        BFS(graph, start, distance);

        for(int i = 0; i < ver; ++i) {
            std::cout << distance[i] << std::endl;
        }

        return 0;
    }
