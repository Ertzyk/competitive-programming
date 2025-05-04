#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int h, w, xa, ya, xb, yb;
        cin >> h >> w >> xa >> ya >> xb >> yb;
        if(xa >= xb){
            cout << "Draw\n";
            continue;
        }
        int alice_l_max = max(1, ya - (xb - xa + 1)/2), alice_r_max = min(w, ya + (xb - xa + 1)/2);
        int bob_l_max = max(1, yb - (xb - xa)/2), bob_r_max = min(w, yb + (xb - xa)/2);
        if((xb - xa)%2) cout << ((alice_l_max <= bob_l_max && alice_r_max >= bob_r_max) ? "Alice\n" : "Draw\n");
        else cout << ((alice_l_max >= bob_l_max && alice_r_max <= bob_r_max) ? "Bob\n" : "Draw\n");
    }
    return 0;
}