#pragma comment(linker, "/STACK:16777216")

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

void fillBorder(vector<vector<int>> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        a[i][0] = INT_MAX;
        a[0][i] = INT_MAX;
        a[i][n - 1] = INT_MAX;
        a[n - 1][i] = INT_MAX;
    }
}

void dfs(int row, int col, vector<vector<int>> &a, vector<vector<bool>> &reachable) {
    int n = a.size();

    reachable[row][col] = true;

    if (row - 1 >= 0 && row - 1 < n && a[row][col] > a[row - 1][col] && !reachable[row - 1][col])
        dfs(row - 1, col, a, reachable);

    if (row + 1 < n && row + 1 >= 0 && a[row][col] > a[row + 1][col] && !reachable[row + 1][col])
        dfs(row + 1, col, a, reachable);

    if (col - 1 >= 0 && col - 1 < n && a[row][col] > a[row][col - 1] && !reachable[row][col - 1])
        dfs(row, col - 1, a, reachable);

    if (col + 1 < n && col + 1 >= 0 && a[row][col] > a[row][col + 1] && !reachable[row][col + 1])
        dfs(row, col + 1, a, reachable);
}

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    int n;
    in >> n;
    int x, y, x1, y1;
    in >> x >> y >> x1 >> y1;
    vector<vector<int>> a(n + 2, vector<int>(n + 2));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            in >> a[i][j];
        }
    }
    in.close();

    fillBorder(a);

    vector<vector<bool>> reachable(n + 2, vector<bool>(n + 2, false));
    dfs(x, y, a, reachable);

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (reachable[i][j]) {
                if (j == n)
                    out << a[i][j];
                else
                    out << a[i][j] << " ";
            } else {
                if (j == n)
                    out << 0;
                else
                    out << 0 << " ";
            }
        }
        out << '\n';
    }

    return 0;
}