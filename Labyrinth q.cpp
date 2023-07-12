#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<string> labyrinth;
vector<vector<bool>> visited;
int startX, startY;
int dx[] = {0, 0, 1, -1}; // Possible movement directions (right, left, down, up)
int dy[] = {1, -1, 0, 0};
string directions = "RULD"; // Mapping for directions

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != '#' && !visited[x][y]);
}

bool dfs(int x, int y, string& path) {
    visited[x][y] = true;
    
    if (labyrinth[x][y] == '.') {
        path.push_back(directions[0]);
        return true;
    }
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (isValid(nx, ny)) {
            path.push_back(directions[i]);
            if (dfs(nx, ny, path))
                return true;
            path.pop_back();
        }
    }
    
    return false;
}

int main() {
    cin >> n >> m;
    labyrinth.resize(n);
    visited.resize(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        cin >> labyrinth[i];
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') {
                startX = i;
                startY = j;
            }
        }
    }
    
    string path;
    if (dfs(startX, startY, path)) {
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
