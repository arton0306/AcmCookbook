// list all subset with alphabet order (the input MUST in increase order)
//
// time complexity: O( N*(2^N) ), all subset is 2^N, printing each one is N
//
// example:
// input: {2,4,6,8}
// output: (notice the empty is skipped)
// 2 
// 2 4 
// 2 4 6 
// 2 4 6 8 
// 2 4 8 
// 2 6 
// 2 6 8 
// 2 8 
// 4 
// 4 6 
// 4 6 8 
// 4 8 
// 6 
// 6 8 
// 8

#include <bits/stdc++.h>

using namespace std;

int a[] = {2,4,6,8};
vector<int> s;

void dump() {
    for (int i : s) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool update() {
    int k = sizeof(a)/sizeof(a[0]);
    if (s.back() < k-1) {
        s.push_back(s.back()+1);
    } else {
        if (s.size() >= 2) {
            s.pop_back();
            s.back() += 1;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    s.push_back(0);
    do {
        dump();
    } while (update());

    return 0;
}
