#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, a_xor = 0;
        cin >> n;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        for(int x: a) a_xor ^= x;
        if(a_xor == 0){
            cout << "YES\n";
            continue;
        }
        int cnt_a = 0, seg_xor = 0;
        for(int x: a){
            seg_xor ^= x;
            if(seg_xor == a_xor){
                seg_xor = 0;
                cnt_a++;
            }
        }
        cout << ((cnt_a > 1) ? "YES\n" : "NO\n");
    }
    return 0;
}