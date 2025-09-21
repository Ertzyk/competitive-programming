#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, last_not_done = 1;
        string s;
        cin >> n >> s;
        vector<int> result(n);
        for(int i = 0; i < n; i++){
            if(s[i] == '0' && i > 0 && s[i - 1] == '1') last_not_done = i + 1;
            if(s[i] == '1') result[i] = i + 1;
            else if(s[i] == '0' && i < n - 1 && s[i + 1] == '0') result[i] = i + 2;
            else result[i] = last_not_done;
        }
        bool out = false;
        for(int i = 0; i < n; i++) if(s[i] == '0' && result[i] == i + 1){
            cout << "NO\n";
            out = true;
            break;
        }
        if(!out){
            cout << "YES\n";
            for(int x: result) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}