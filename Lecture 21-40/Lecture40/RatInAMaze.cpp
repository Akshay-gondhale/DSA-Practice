// [https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Checks whether the rat can move to the given cell.
 *
 * A cell is considered safe if it:
 * - Lies within the maze boundaries.
 * - Has not been visited in the current path.
 * - Is an open cell (value = 1).
 *
 * @param x Row index of the destination cell.
 * @param y Column index of the destination cell.
 * @param maze Binary matrix representing the maze.
 * @param visitedMapping Tracks cells already visited in the current path.
 * @return true if the move is valid; otherwise false.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool isSafe(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &visitedMapping)
{
    if ((x >= 0 && x < maze.size()) && (y >= 0 && y < maze.size()) && visitedMapping[x][y] == 0 && maze[x][y] == 1)
        return true;
    return false;
}

/**
 * @brief Finds all possible paths from the source to the destination using backtracking.
 *
 * The algorithm explores every valid direction from the current cell while
 * maintaining a visited matrix to avoid revisiting cells within the same path.
 * After exploring a path, it backtracks by undoing both the path string and
 * the visited state, allowing other possible paths to reuse those cells.
 *
 * @param x Current row index.
 * @param y Current column index.
 * @param maze Binary matrix representing the maze.
 * @param visitedMapping Tracks cells visited in the current recursive path.
 * @param path String representing the path constructed so far.
 * @param ans Stores all valid paths from source to destination.
 *
 * @note Direction order is Down, Up, Left, Right.
 *
 * Time Complexity: O(4^(N*N)) in the worst case.
 * Space Complexity: O(N*N) for the visited matrix and recursion stack.
 */
void findPathInMaze(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &visitedMapping, string path, vector<string> &ans)
{

    cout << "X: " << x << " Y: " << y << endl;

    //* Destination reached. Store the complete path.
    if (x == maze.size() - 1 && y == maze.size() - 1)
    {
        ans.push_back(path);
        return;
    }

    //* Mark the current cell as visited to prevent cycles.
    visitedMapping[x][y] = 1;

    int newX, newY;

    //* Explore the Down direction.
    newX = x + 1;
    newY = y;
    if (isSafe(newX, newY, maze, visitedMapping))
    {
        path.push_back('D');
        findPathInMaze(newX, newY, maze, visitedMapping, path, ans);

        //? Backtrack by removing the last move before exploring another direction.
        path.pop_back();
    }

    //* Explore the Up direction.
    newX = x - 1;
    newY = y;
    if (isSafe(newX, newY, maze, visitedMapping))
    {
        path.push_back('U');
        findPathInMaze(newX, newY, maze, visitedMapping, path, ans);
        path.pop_back();
    }

    //* Explore the Left direction.
    newX = x;
    newY = y - 1;
    if (isSafe(newX, newY, maze, visitedMapping))
    {
        path.push_back('L');
        findPathInMaze(newX, newY, maze, visitedMapping, path, ans);
        path.pop_back();
    }

    //* Explore the Right direction.
    newX = x;
    newY = y + 1;
    if (isSafe(newX, newY, maze, visitedMapping))
    {
        path.push_back('R');
        findPathInMaze(newX, newY, maze, visitedMapping, path, ans);
        path.pop_back();
    }

    //* Backtrack by unmarking the current cell so it can be used in other paths.
    visitedMapping[x][y] = 0;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    //* Initially, no cell has been visited.
    vector<vector<int>> visitedMapping = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    string path = "";
    vector<string> ans;

    //* Start searching from the top-left cell.
    findPathInMaze(0, 0, maze, visitedMapping, path, ans);

    //* Sort paths to obtain lexicographical order.
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}