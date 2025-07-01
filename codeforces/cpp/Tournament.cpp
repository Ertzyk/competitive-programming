#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, j, k;
        cin >> n >> j >> k;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        if(k > 1) cout << "YES\n";
        else cout << ((a[j - 1] == *max_element(a.begin(), a.end())) ? "YES" : "NO") << '\n';
    }
    return 0;
}