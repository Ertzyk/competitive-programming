#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t, p;
    cin >> t >> p;
    vector<int> a(t.size());
    for(int &x: a) cin >> x;
    int l = 0, r = t.size() - p.size(), ans = 0;
    while(l <= r){
        int m = (l + r)/2, pointp = 0, pointt = 0;
        unordered_set<int> sett;
        for(int i = 0; i < m; i++) sett.insert(a[i] - 1);
        while(sett.count(pointt)) pointt++;
        while(pointp < p.size() && pointt < t.size()){
            if(t[pointt] == p[pointp]){
                pointt++;
                pointp++;
            } else pointt++;
            while(sett.count(pointt)) pointt++;
        }
        if(pointp == p.size()){
            ans = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << ans << '\n';
    return 0;
}