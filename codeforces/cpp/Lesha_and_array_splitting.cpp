#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int s = accumulate(a.begin(), a.end(), 0);
    if(s != 0) cout << "YES\n1\n1 " << n << '\n';
    else {
        int p = 0;
        while(p < n && a[p] == 0) p++;
        if(p == n) cout << "NO\n";
        else cout << "YES\n2\n1 " << p + 1 << "\n" << p + 2 << ' ' << n << '\n';
    }
    return 0;
}