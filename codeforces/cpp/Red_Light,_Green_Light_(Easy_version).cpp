#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        ll n, k;
        cin >> n >> k;
        vector<ll> p(n);
        for(ll &x: p) cin >> x;
        vector<ll> d(n);
        for(ll &x: d) cin >> x;
        int q;
        cin >> q;
        while(q--){
            ll a, start = -1;
            cin >> a;
            int position_idx;
            for(int i = 0; i < n; i++){
                if(p[i] >= a){
                    start = p[i];
                    position_idx = i;
                    break;
                }
            }
            if(start == -1){
                cout << "YES\n";
                continue;
            }
            ll t = start - a;
            t %= k;
            bool fell_of = false;
            int direction = 1;
            vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(k, vector<bool>(2, false)));
            while(!visited[position_idx][t][(direction + 1)/2]){
                visited[position_idx][t][(direction + 1)/2] = true;
                if(t%k == d[position_idx]) direction*= -1;
                if(direction == 1){
                    position_idx++;
                    if(position_idx == n){
                        fell_of = true;
                        break;
                    }
                    t += p[position_idx] - p[position_idx - 1];
                    t %= k;
                } else {
                    position_idx--;
                    if(position_idx == -1){
                        fell_of  = true;
                        break;
                    }
                    t += p[position_idx + 1] - p[position_idx];
                    t %= k;
                }
            }
            if(fell_of) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}