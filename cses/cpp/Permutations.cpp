#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1){
        cout << "1\n";
        return 0;
    }
    if(n == 2 || n == 3){
        cout << "NO SOLUTION\n";
        return 0;
    }
    vector<int> result(n);
    int k = (n + 1)/2;
    for(int i = 0; i < n; i += 2){
        result[i] = k;
        k--;
    }
    k = n;
    for(int i = 1; i < n; i += 2){
        result[i] = k;
        k--;
    }
    for(int x: result) cout << x << ' ';
    cout << '\n';
    return 0;
}