#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, res = 0;
        cin >> n;
        vector<int> cnt(n + 1);
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            mp[a]++;
            cnt[mp[a]]++;
        }
        for(int i = 1; i <= n; i++) res = max(res, i*cnt[i]);
        cout << n - res << '\n';
    }
    return 0;
}