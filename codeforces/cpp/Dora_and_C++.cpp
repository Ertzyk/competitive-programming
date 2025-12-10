#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        int g = gcd(a, b);
        vector<int> c(n);
        for(int &x: c) cin >> x;
        for(int i = 0; i < n; i++) c[i] %= g;
        sort(c.begin(), c.end());
        int max_diff = 0;
        for(int i = 0; i < n - 1; i++) max_diff = max(max_diff, c[i + 1] - c[i]);
        cout << min(g - max_diff, c[n - 1] - c[0]) << '\n';
    }
    return 0;
}