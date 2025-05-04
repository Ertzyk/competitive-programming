#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c, count = 0;
    cin >> n >> a >> b >> c;
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    vector<int> precal(n + 1, -1);
    precal[0] = 0;
    for(int i = 1; i <= n/a; i++) precal[a*i] = i;
    for(int i = 0; i <= n; i++){
        if(precal[i] != -1){
            int k = i + b, l = precal[i] + 1;
            while(k <= n){
                precal[k] = max(precal[k], l);
                k += b;
                l++;
            }
        }
    }
    int max_res = 0;
    while(n >= 0){
        if(precal[n] != -1) max_res = max(max_res, precal[n] + count);
        n -= c;
        count++;
    }
    cout << max_res;
    return 0;
}