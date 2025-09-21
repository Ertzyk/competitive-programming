#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(m + 1);
        for(int i = 1; i <= n; i++){
            int l;
            cin >> l;
            while(l--){
                int x;
                cin >> x;
                a[x].push_back(i);
            }
        }
        vector<bool> can_del(n + 1, true);
        can_del[0] = false;
        bool out = false;
        for(int i = 1; i <= m; i++){
            if(a[i].size() == 1) can_del[a[i][0]] = false;
            else if(a[i].size() == 0){
                cout << "NO\n";
                out = true;
                break;
            }
        }
        if(out) continue;
        int amount = 0;
        for(bool b: can_del) if(b) amount++;
        if(amount >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}