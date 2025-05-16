#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int l = 0, cur_zer = 0, result = -1, result_l = 0, result_r = 0;
    for(int r = 0; r < n; r++){
        if(a[r] == 0) cur_zer++;
        while(cur_zer > k){
            if(a[l] == 0) cur_zer--;
            l++;
        }
        if(r - l + 1 > result){
            result = r - l + 1;
            result_l = l;
            result_r = r;
        }
    }
    cout << result << '\n';
    for(int i = result_l; i <= result_r; i++) a[i] = 1;
    for(int x: a) cout << x << ' ';
    cout << '\n';
    return 0;
}