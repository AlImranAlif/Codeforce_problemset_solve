#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        vector<int> tokens(3);

        cin >> tokens[0] >> tokens[1] >> tokens[2];

        sort(tokens.begin(), tokens.end());

        int lowerDifference = tokens[1] - tokens[0];
        int upperDifference = tokens[2] - tokens[1];

        cout << min(lowerDifference, upperDifference) << '\n';
    }

    return 0;
}