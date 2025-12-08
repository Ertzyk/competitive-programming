#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    vector<double> a(1001, r);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cout << fixed << setprecision(10) << a[x] << ' ';
        for(int i = 1; i <= 2*r && x - i > 0; i++) a[x - i] = max(a[x - i], a[x] + sqrt(4*r*r - i*i));
        for(int i = 1; i <= 2*r && x + i <= 1000; i++) a[x + i] = max(a[x + i], a[x] + sqrt(4*r*r - i*i));
        a[x] += 2*r;
    }
    return 0;
}