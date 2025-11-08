#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), res(n);
    for(int &x: a) cin >> x;
    sort(a.rbegin(), a.rend());
    int l = 1, r = (n - 1)/2, k = 0;
    while(l <= r){
        int m = (l + r)/2;
        bool flag = false;
        for(int i = 1; i <= m; i++){
            if(a[i] <= a[n - m + i - 1]){
                flag = true;
                break;
            }
        }
        if(flag) r = m - 1;
        else {
            l = m + 1;
            k = m;
        }
    }
    cout << k << '\n';
    res[0] = a[0];
    int p_upper = 1, p_lower = n - k, p_res = 1;
    while(p_lower < n){
        res[p_res] = a[p_lower];
        p_lower++;
        p_res++;
        res[p_res] = a[p_upper];
        p_upper++;
        p_res++;
    }
    while(p_res < n){
        res[p_res] = a[p_upper];
        p_upper++;
        p_res++;
    }
    for(int x: res) cout << x << ' ';
    cout << '\n';
    return 0;
}