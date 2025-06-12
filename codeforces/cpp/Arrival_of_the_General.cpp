#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, min_a = 101, max_a = 0, min_idx = -1, max_idx = - 1;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    for(int i = 0; i < n; i++){
        if(a[i] <= min_a){
            min_a = a[i];
            min_idx = i;
        }
        if(a[i] > max_a){
            max_a = a[i];
            max_idx = i;
        }
    }
    cout << max_idx + n - min_idx - ((max_idx > min_idx) ? 2 : 1) << '\n';
    return 0;
}