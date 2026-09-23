#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--){
        string s, t;
        cin >> s >> t;
        vector<vector<ll>> hashmap(26);
        for(ll i = 0; i < s.size(); i++) hashmap[s[i] - 'a'].push_back(i);
        ll result = 1, last = -1;
        bool flag = false;
        for(ll i = 0; i < t.size(); i++){
            if(!hashmap[t[i] - 'a'].empty()){
                auto it = upper_bound(hashmap[t[i] - 'a'].begin(), hashmap[t[i] - 'a'].end(), last);
                if(it != hashmap[t[i] - 'a'].end()) last = *it;
                else {
                    result++;
                    last = hashmap[t[i] - 'a'][0];
                }
            } else {
                cout << "-1\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout << result << '\n';
    }
    return 0;
}