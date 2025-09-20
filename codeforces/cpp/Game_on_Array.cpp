#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        sort(a.begin(), a.end());
        int count = 1;
        vector<ll> c(n + 1);
        for(int i = 0; i < n - 1; i++){
            if(a[i] == a[i + 1]) count++;
            else {
                c[count] += a[i];
                count = 1;
            }
        }
        c[count] += a[n - 1];
        ll A = 0, B = 0;
        char start = 'A';
        for(int i = n; i >= 0; i--){
            A += i*(c[i]/2);
            B += i*(c[i]/2);
            if(c[i]%2){
                if(start == 'A'){
                    A += i;
                    start = 'B';
                } else {
                    B += i;
                    start = 'A';
                }
            }
        }
        cout << A << ' ' << B << '\n';
    }
    return 0;
}