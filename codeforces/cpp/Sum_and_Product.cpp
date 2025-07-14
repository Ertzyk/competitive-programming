#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n;
        unordered_map<ll, ll> hashmap;
        hashmap.reserve(n);
        for(int i = 1; i <= n; i++){
            ll x;
            cin >> x;
            hashmap[x]++;
        }
        cin >> q;
        hashmap.reserve(n + 2*q + 1);
        while(q--){
            ll x, y;
            cin >> x >> y;
            ll delta = x*x - 4*y;
            if(delta > 0){
                ll root = floor(sqrt(delta));
                if(root*root == delta && (x - root)%2 == 0) cout << hashmap[(x - root)/2]*hashmap[(x + root)/2] << ' ';
                else cout << "0 ";
            } else if(delta == 0 && x%2 == 0) cout << hashmap[x/2]*(hashmap[x/2] - 1)/2 << ' ';
            else cout << "0 ";
        }
        cout << '\n';
    }
    return 0;
}