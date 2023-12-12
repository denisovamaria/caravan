#include <fstream>
#include <vector>

using namespace std;

void dfs(int row, int col, vector<vector<int>> &a, vector<vector<bool>> &reachable) {
    int n = a.size();

    reachable[row][col] = true;

    if (row - 1 >= 0 && a[row][col] >= a[row - 1][col] && !reachable[row - 1][col])
        dfs(row - 1, col, a, reachable);

    if (row + 1 < n && a[row][col] >= a[row + 1][col] && !reachable[row + 1][col])
        dfs(row + 1, col, a, reachable);

    if (col - 1 >= 0 && a[row][col] >= a[row][col - 1] && !reachable[row][col - 1])
        dfs(row, col - 1, a, reachable);

    if (col + 1 < n && a[row][col] >= a[row][col + 1] && !reachable[row][col + 1])
        dfs(row, col + 1, a, reachable);
}

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    int n;
    in >> n;
    int x, y, x1, y1;
    in >> x >> y >> x1 >> y1;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> a[i][j];
        }
    }
    in.close();

    vector<vector<bool>> reachable(n, vector<bool>(n, false));
    dfs(x, y, a, reachable);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (reachable[i][j]) {
                out << a[i][j] << " ";
            } else {
                out << "0 ";
            }
        }
        out << endl;
    }

    return 0;
}
