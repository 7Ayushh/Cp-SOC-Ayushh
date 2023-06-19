#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir[4] = {'U', 'D', 'L', 'R'};

//transverse ke time - valid means inside grid, not in wall, not visited earlier
bool isValid(int x, int y, int n, int m, const vector<string>& labyrinth, vector<vector<bool>>& visited) {
    if (x < 0 || x >= n || y < 0 || y >= m || labyrinth[x][y] == '#' || visited[x][y]) {
        return false;
    }
    return true;
}

string bfs(int n, int m, const vector<string>& labyrinth, pair<int, int> start, pair<int, int> end) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));  // dim of vec = m, dim of outermost or row vector is n
    queue<pair<int, int>> q;

    visited[start.first][start.second] = true;
    parent[start.first][start.second] = {-1, -1};  // store posi of each visited position
    q.push(start);

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        if (curr == end) {
            string path;
            while (parent[x][y] != make_pair(-1, -1)) {
                pair<int, int> prev = parent[x][y];
                if (prev.first == x - 1) {
                    path += 'D';
                } else if (prev.first == x + 1) {
                    path += 'U';
                } else if (prev.second == y - 1) {
                    path += 'R';
                } else if (prev.second == y + 1) {
                    path += 'L';
                }
                x = prev.first;
                y = prev.second;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY, n, m, labyrinth, visited)) {
                visited[newX][newY] = true;
                parent[newX][newY] = {x, y};
                q.push({newX, newY});
            }
        }
    }

    return "NO";
}

// use for input and output and calling the functions
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> labyrinth(n);  // n strings

    for (int i = 0; i < n; i++) {
        cin >> labyrinth[i];
    }

    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') {
                start = {i, j};  //pair mei '{}' use
            } else if (labyrinth[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    string path = bfs(n, m, labyrinth, start, end);
    if (path != "NO") {
        cout << "YES\n";
        cout << path.length() << '\n';
        cout << path << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}