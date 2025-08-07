#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int hc, mc, hw, mw;
        cin >> hc >> mc >> hw >> mw;
        cout << "Case " << i << ": " << 60*(hw - hc) + mw - mc << '\n';
    }
    return 0;
}