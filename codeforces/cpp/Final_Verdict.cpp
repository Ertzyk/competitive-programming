#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        int sum_a = accumulate(a.begin(), a.end(), 0);
        if(n*x == sum_a) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}