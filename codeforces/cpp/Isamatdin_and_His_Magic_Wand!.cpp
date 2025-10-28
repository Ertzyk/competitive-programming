#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, even = 0, odd = 0;
        cin >> n;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        for(int i = 0; i < n; i++){
            if(a[i]%2) odd++;
            else even++;
        }
        if(odd > 0 && even > 0) sort(a.begin(), a.end());
        for(int x: a) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}