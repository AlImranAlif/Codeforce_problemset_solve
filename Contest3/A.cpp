/*#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int forced = 0;      
        int sleepCount = 0;  
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                forced = k;
            } else {
                if(forced > 0) {
                    forced--;
                } else {
                    sleepCount++;
                }
            }
        }
        cout << sleepCount << "\n";
    }
    return 0;
}*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int awake_remaining = 0, awake_count = 0;
        for (int i = 0; i < n; ++i) {
            if (awake_remaining > 0) {
                awake_count++;
                awake_remaining--;
                if (s[i] == '1') {
                    awake_remaining = max(awake_remaining, k);
                }
            } else {
                if (s[i] == '1') {
                    awake_count++;
                    awake_remaining = k;
                }
            }
        }
        cout << n - awake_count << endl;
    }
    return 0;
}
