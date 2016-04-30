/*
Important!
The CalcMaxCycle only works for a graph whose each node exactly has ONE out edge
Is is NP-Hard for find max cycle for a general graph.

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

// g is an adjcency list, node index START FROM 1
int CalcMaxCycle(vector<int> const & g) {
    int maxcyc = 0;
    int cyc = 0;
    vector<int> visited(g.size(), 0);
    int order = 1;
    for (int i = 1; i < g.size(); ++i) {
        // TODO: clear visited flags if order > INT_MAX - g.size()
        
        if (visited[i] > 0) {
            continue;
        }
        int cur = i;
        const int start_order = order;
        while (true) {
            visited[cur] = order;
            int next = g[cur];
            if (visited[next] > start_order) {
                cyc = order - visited[next] + 1;
                break;
            } else {
                cur = next;
                ++order;
                assert(order < INT_MAX);
            }
        }
        maxcyc = max(maxcyc, cyc);
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
