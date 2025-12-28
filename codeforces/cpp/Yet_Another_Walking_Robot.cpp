#include <iostream>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, res = LLONG_MAX, cur_x = 0, cur_y = 0, start_res = -1;
        string s;
        cin >> n >> s;
        map<pair<ll, ll>, ll> mp;
        mp[{0, 0}] = -1;
        for(ll i = 0; i < n; i++){
            if(s[i] == 'L') cur_x--;
            else if(s[i] == 'R') cur_x++;
            else if(s[i] == 'U') cur_y++;
            else cur_y--;
            auto it = mp.find({cur_x, cur_y});
            if(it != mp.end() && i - it->second < res){
                res = i - it->second;
                start_res = it->second + 2;
            }
            mp[{cur_x, cur_y}] = i;
        }
        if(res == LLONG_MAX) cout << "-1\n";
        else cout << start_res << ' ' << start_res + res - 1 << '\n';
    }
    return 0;
}