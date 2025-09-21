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
        int n, result = 0;
        cin >> n;
        vector<int> a(n), b;
        for(int &x: a) cin >> x;
        unordered_map<int, int> mp;
        for(int x: a) mp[x]++;
        for(auto pr: mp) b.push_back(pr.second);
        sort(b.rbegin(), b.rend());
        for(int i = 0; i < b.size(); i++) result = max(result, (i + 1)*b[i]);
        cout << result << '\n';
    }
    return 0;
}