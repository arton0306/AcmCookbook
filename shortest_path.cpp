#include <bits/stdc++.h>

using namespace std;

const int V = 1000;

int d[V];
bool used[V];
int w[V][V];
int from[V];

void dijkstra(int s, int t) {
    fill(d, d+V, INT_MAX);
    fill(used, used+V, false);
    d[s] = 0;
    from[s] = -1;
    while (true) {
        int v = -1;
        for (int u = 0; u < V; ++u) {
            if (!used[u] && (v == -1 || d[u] < d[v])) {
                v = u;
            }
        }
        if (v == -1) break; // s is not connected to t
        used[v] = true;

        for (int u = 0; u < V; ++u) {
            if (w[v][u] < INT_MAX) {
                // assume d[v] + w[v][u] not overflow
                if (d[u] > d[v] + w[v][u]) {
                    d[u] = d[v] + w[v][u];
                    from[u] = v;
                }
            }
        }
    }
}

int main() {
    return 0;
}
