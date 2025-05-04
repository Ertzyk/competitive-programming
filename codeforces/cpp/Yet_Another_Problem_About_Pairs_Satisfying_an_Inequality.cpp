#include <iostream>
#include <vector>
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
        vector<ll> acc(n + 2);
        acc[0] = acc[1] = 0;
        for(int i = 2; i <= n + 1; i++){
            acc[i] = acc[i - 1];
            if(a[i - 2] < i - 1) acc[i]++;
        }
        ll result = 0;
        for(int i = 0; i < n; i++){
            if(a[i] < i + 1){
                if(a[i] < acc.size()) result += acc[a[i]];
                else result += acc.back();
            }
        }
        cout << result << '\n';
    }
    return 0;
}