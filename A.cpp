#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 2 == 1) {
            cout << 0 << endl;
            continue;
        }
        int S = n / 2;
        int result = S / 2 + 1;  
        cout << result << endl;
    }
    return 0;
}