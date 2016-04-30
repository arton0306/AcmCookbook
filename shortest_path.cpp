#include <bits/stdc++.h>

using namespace std;

const int V = 1000;

int d[V];
bool used[V];
int w[V][V];
int from[V];

void dijkstra(int s, int t) {
    fill(d, d+V, INT_MAX);
    d[s] = 0;

    fill(used, used+V, false);
    used[s] = true;

    from[s] = -1;
    for (int i = 0; i < V && d[t] < INT_MAX; ++i) {
        int new_node = -1;
        int shortest = INT_MAX;
        for (int j = 0; j < V; ++j) {
            if (!used[j] && d[j] < shortest) {
                shortest = d[j];
                new_node = j;
            }
        }
        if (new_node != -1) {
            for (int j = 0; j < V; ++j) {
                if (w[new_node][j] < INT_MAX) {
                    // assume d[new_node] + w[new_node][j] not overflow
                    if (d[j] > d[new_node] + w[new_node][j]) {
                        d[j] = d[new_node] + w[new_node][j];
                        from[j] = new_node;
                    }
                }
            }
            used[new_node] = true;
        } else {
            // s is not connected to t
            break;
        }
    }
}

int main() {
    return 0;
}
