#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, y, r;
        cin >> n;
        cin >> y >> r;

        int suspended = r + (y / 2);
        suspended = min(suspended, n);

        cout << suspended << endl;
    }
    return 0;
}
