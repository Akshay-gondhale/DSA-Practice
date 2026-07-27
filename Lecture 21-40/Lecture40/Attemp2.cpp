#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> &m)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && m[x][y] == 1 && visited[x][y] == 0)
        return true;
    return false;
}
void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> &visited, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // 4 choice -> D, U, L, R
    int newX, newY;
    // down
    newX = x + 1;
    newY = y;
    if (isSafe(newX, newY, n, visited, m))
    {
        path.push_back('D');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }
    // up
    newX = x - 1;
    newY = y;
    if (isSafe(newX, newY, n, visited, m))
    {
        path.push_back('U');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }
    // left
    newX = x;
    newY = y - 1;
    if (isSafe(newX, newY, n, visited, m))
    {
        path.push_back('L');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }
    // right
    newX = x;
    newY = y + 1;
    if (isSafe(newX, newY, n, visited, m))
    {
        path.push_back('R');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }
    visited[x][y] = 0;
}
int main()
{
    vector<string> ans;
    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    int n = m.size();
    if (m[0][0] == 0)
    {
        return 1;
    }
    int srcX = 0;
    int srcY = 0;

    vector<vector<int>> visited = m;
    for (int i = 0; i < visited.size(); i++)
    {
        for (int j = 0; j < visited[i].size(); j++)
        {
            visited[i][j] = 0;
        }
    }
    string path = "";
    solve(m, n, ans, srcX, srcY, visited, path);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}