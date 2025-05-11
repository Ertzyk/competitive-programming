#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void dfs(const int& start, const int& end, int curidx, ll s, const int& m, const vector<ll>& a, vector<ll>& collected){
    if(curidx > end){
        collected.push_back(s%m);
        return;
    }
    dfs(start, end, curidx + 1, s + a[curidx], m, a, collected);
    dfs(start, end, curidx + 1, s, m, a, collected);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    vector<ll> lsums, rsums;
    dfs(0, n/2, 0, 0, m, a, lsums);
    dfs(n/2 + 1, n - 1, n/2 + 1, 0, m, a, rsums);
    sort(lsums.begin(), lsums.end());
    sort(rsums.begin(), rsums.end());
    ll result = 0;
    int l = lsums.size() - 1;
    for(int r = 0; r < rsums.size(); r++){
        while(l >= 0 && lsums[l] + rsums[r] >= m) l--;
        if(l == 0 && lsums[l] + rsums[r] >= m) break;
        result = max(result, lsums[l] + rsums[r]);
    }
    cout << result << '\n';
    return 0;
}