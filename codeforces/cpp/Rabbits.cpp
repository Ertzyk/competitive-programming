#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<bool> fixed(n);
        bool out = false;
        for(int i = 1; i < n - 1; i++) if(s[i] == '0'){
            if((s[i - 1] == '0') || (s[i + 1] == '0')) continue;
            else if((i - 2 >= 0 && s[i - 2] == '0' && !fixed[i - 2])) continue;
            else if((i + 2 < n && s[i + 2] == '0')) fixed[i + 2] = true;
            else {
                cout << "NO\n";
                out = true;
                break;
            }
        }
        if(!out) cout << "YES\n";
    }
    return 0;
}