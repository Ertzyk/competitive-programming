#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> prefix(n + 1);
        for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + ((s[i - 1] == 'a') ? 1 : -1);
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i <= n; i++) mp[prefix[i]].push_back(i);
        int result = n;
        for(int i = 0; i <= n; i++){
            if(!mp[prefix[i] + prefix[n]].empty()){
                auto it = lower_bound(mp[prefix[i] + prefix[n]].begin(), mp[prefix[i] + prefix[n]].end(), i);
                if(it != mp[prefix[i] + prefix[n]].end()) result = min(result, *it - i);
            }
        }
        cout << ((result == n) ? -1 : result) << '\n';
    }
    return 0;
}