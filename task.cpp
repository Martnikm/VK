#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int x, y;
    vector<pair<int, int>> path;
};

vector<pair<int, int>> Solve(const vector<vector<int>>& lab, pair<int, int> start, pair<int, int> end) { // bfs
    int n = lab.size();
    int m = lab[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Node> q;

    vector<pair<int, int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    q.push({start.first, start.second, {start}});
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.x == end.first && curr.y == end.second) return curr.path;

        for (int i = 0; i < direct.size(); i++) {
            int nx = curr.x + direct[i].first;
            int ny = curr.y + direct[i].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && lab[nx][ny] != 0) {
                vector<pair<int, int>> new_path = curr.path;
                new_path.emplace_back(nx, ny);
                q.push({nx, ny, new_path});
                visited[nx][ny] = true;
            }
        }
    }

    cout << "Путь не найден";
    return {};
}

int main() {
    int n = 0, m = 0, start_x = 0, start_y = 0, end_x = 0, end_y = 0;
    cin >> n >> m;
    vector<vector<int>> lab(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> lab[i][j];
    }
    cin >> start_x >> start_y >> end_x >> end_y;

    vector<pair<int, int>> path = Solve(lab, {start_x, start_y}, {end_x, end_y});

    if (!path.empty()) {
        for (const auto& p : path) cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
