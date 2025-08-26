#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    cout << ((n%2 && a[0]%2 && a[n - 1]%2) ? "Yes\n" : "No\n");
    return 0;
}