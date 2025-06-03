#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> result(n);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        result[x - 1] = i;
    }
    for(int x: result) cout << x << ' ';
    cout << '\n';
    return 0;
}