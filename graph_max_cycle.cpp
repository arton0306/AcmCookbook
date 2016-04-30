/*
Important!
the CalcMaxCycle only works for a graph whose each node exactly has ONE out edge

input
4
4
2 3 4 1
4
3 3 4 1
4
3 3 4 3
10
7 8 10 10 9 2 9 6 3 3

output 
4
3
2
3
*/
#include <bits/stdc++.h>

using namespace std;

int dump(vector<int> const & g) {
    for (int i = 1; i < g.size(); ++i) {
        cout << g[i] << " ";
    }
    cout << endl;
}

// g is an adjcency list, node index start from 1
int CalcMaxCycle(vector<int> const & g) {
    int maxcyc = -1;
    int newcyc = 0;
    for (int i = 1; i < g.size(); ++i) {
        vector<int> visited(g.size(), 0);
        int order = 1;
        int cur = i;
        while (true) {
            visited[cur] = order;
            int next = g[cur];
            cout << "cur " << cur << " next: " << next << endl;
            if (visited[next] > 0) {
                newcyc = order - visited[next] + 1;
                break;
            } else {
                cur = next;
                ++order;
            }
        }
        // int newcyc = (order == 1 ? 0 : order);
        if (maxcyc < newcyc) {
            maxcyc = newcyc;
        }
    }

    return maxcyc;
}

int solve() {
    int n = 0;
    cin >> n;
    vector<int> g(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        int bff;
        cin >> bff;
        g[i] = bff;
    }

    return CalcMaxCycle(g);
}

int main() {
    int caseNum;
    cin >> caseNum;
    for (int caseIdx = 0; caseIdx < caseNum; ++caseIdx) {
        cout << "Case #" << caseIdx+1 << ": ";

        int ans = solve();
        cout << ans << endl;
    }

    return 0;
}
