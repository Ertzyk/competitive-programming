#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        vector<int> prefix0(n + 1), prefix1(n + 1), even_pos0(n + 1), even_pos1(n + 1);
        for(int i = 0; i < n; i++){
            if(a[i] == 0){
                prefix0[i + 1] = prefix0[i] + 1;
                prefix1[i + 1] = prefix1[i];
            } else {
                prefix0[i + 1] = prefix0[i];
                prefix1[i + 1] = prefix1[i] + 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(i%2 == 0){
                if(a[i] == 0){
                    even_pos0[i + 1] = even_pos0[i] + 1;
                    even_pos1[i + 1] = even_pos1[i];
                } else {
                    even_pos0[i + 1] = even_pos0[i];
                    even_pos1[i + 1] = even_pos1[i] + 1;
                }
            } else {
                even_pos0[i + 1] = even_pos0[i];
                even_pos1[i + 1] = even_pos1[i];
            }
        }
        while(q--){
            int l, r;
            cin >> l >> r;
            if(((prefix0[r] - prefix0[l - 1])%3) || ((prefix1[r] - prefix1[l - 1])%3)){
                cout << "-1\n";
                continue;
            }
            int result = (r - l + 1)/3;
            if(prefix0[r] - prefix0[l - 1] == prefix1[r] - prefix1[l - 1] && (even_pos1[r] - even_pos1[l - 1] == 0 || even_pos0[r] - even_pos0[l - 1] == 0)) result++;
            cout << result << '\n';
        }
    }
    return 0;
}