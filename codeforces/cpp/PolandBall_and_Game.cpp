#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, both = 0;
    unordered_set<string> pol_set;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        pol_set.insert(s);
    }
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(pol_set.count(s)) both++;
    }
    if(n - m + both%2 > 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}