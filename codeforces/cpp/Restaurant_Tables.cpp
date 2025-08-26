#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, half_b = 0, ans = 0;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(t == 1){
            if(a) a--;
            else if(b){
                b--;
                half_b++;
            } else if(half_b) half_b--;
            else ans++;
        } else {
            if(b) b--;
            else ans += 2;
        }
    }
    cout << ans << '\n';
    return 0;
}