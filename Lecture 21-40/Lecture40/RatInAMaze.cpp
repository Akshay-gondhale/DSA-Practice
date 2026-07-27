// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &visitedMapping)
{
    if ((x >= 0 && x < maze.size()) && (y >= 0 && y < maze.size()) && visitedMapping[x][y] != 1 && maze[x][y] == 0)
        return true;
    return false;
}
void findPathInMaze(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &visitedMapping, string path, vector<string> &ans)
{

    cout << "X: " << x << " Y: " << y << endl;
    if (x == maze.size() - 1 && y == maze.size() - 1)
    {
        ans.push_back(path);
        return;
    }

    visitedMapping[x][y] = 1;
    int newX, newY;
    // Down
    newX = x + 1;
    newY = y;
    if (isSafe(newX, newY, maze, visitedMapping))
    {
        path.push_back('D');
        findPathInMaze(newX, newY, maze, visitedMapping, path, ans);
        path.pop_back();
    }
    // Up
    newX = x - 1;
    newY = y;
    if (isSafe(newX, newY, maze, visitedMapping))
    {
        path.push_back('U');
        findPathInMaze(newX, newY, maze, visitedMapping, path, ans);
        path.pop_back();
    }
    // Left
    newX = x;
    newY = y - 1;
    if (isSafe(newX, newY, maze, visitedMapping))
    {
        path.push_back('L');
        findPathInMaze(newX, newY, maze, visitedMapping, path, ans);
        path.pop_back();
    }
    // Right
    newX = x;
    newY = y + 1;
    if (isSafe(newX, newY, maze, visitedMapping))
    {
        path.push_back('R');
        findPathInMaze(newX, newY, maze, visitedMapping, path, ans);
        path.pop_back();
    }
    visitedMapping[x][y] = 0;
}
int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    vector<vector<int>> visitedMapping = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    string path = "";
    vector<string> ans;
    findPathInMaze(0, 0, maze, visitedMapping, path, ans);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}
