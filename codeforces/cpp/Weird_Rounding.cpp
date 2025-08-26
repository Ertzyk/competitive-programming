#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string n;
    int k, ans = 0;
    cin >> n >> k;
    for(int i = n.size() - 1; i >= 0; i--){
        if(n[i] == '0') k--;
        else ans++;
        if(!k){
            cout << ans << '\n';
            return 0;
        }
    }
    cout << n.size() - 1 << '\n';
    return 0;
}