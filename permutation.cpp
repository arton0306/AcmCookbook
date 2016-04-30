// list all permutation
//
// time complexity: O(N!N), all permutation is N!, printing each permutation costs N
//
// example:
// input: {1,2,3,4}
// output:
// 1 2 3 4 
// 2 1 3 4 
// 2 3 1 4 
// 3 2 1 4 
// 3 1 2 4 
// 1 3 2 4 
// 2 3 4 1 
// 3 2 4 1 
// 3 4 2 1 
// 4 3 2 1 
// 4 2 3 1 
// 2 4 3 1 
// 3 4 1 2 
// 4 3 1 2 
// 4 1 3 2 
// 1 4 3 2 
// 1 3 4 2 
// 3 1 4 2 
// 4 1 2 3 
// 1 4 2 3 
// 1 2 4 3 
// 2 1 4 3 
// 2 4 1 3 
// 4 2 1 3

#include <bits/stdc++.h>

using namespace std;

int ov[] = {1,2,3,4}; // origin
int v[] = {1,2,3,4};  // working

void dump() {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void rotate(int n) {
    if (n <= 0) return;

    int temp = v[0];
    for (int i = 1; i < n; ++i) {
        v[i-1] = v[i];
    }
    v[n-1] = temp;
}

void rec(int n) {
    if (n == 0) {
        dump();
        return;
    }
    for (int i = 0; i < n; ++i) {
        rec(n-1);
        rotate(n);
    }
}

void nonrec(int n) {
    int p = n;
    do {
        dump();
        p = n;
        rotate(n);
        while (p>1 && v[p-1]==ov[p-1]) {
            --p;
            rotate(p);
        }
    } while (p>1);
}

int main() {
    cout << "rec version" << endl;
    rec(4);

    memcpy(v, ov, sizeof(v));
    cout << "nonrec version" << endl;
    nonrec(4);

    return 0;
}
