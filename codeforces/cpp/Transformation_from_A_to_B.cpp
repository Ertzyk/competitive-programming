#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    vector<int> result;
    result.push_back(b);
    while(b > a){
        if(b%2 == 0){
            b /= 2;
            result.push_back(b);
        } else if(b%10 == 1){
            b /= 10;
            result.push_back(b);
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    if(b == a){
        reverse(result.begin(), result.end());
        cout << "YES\n" << result.size() << '\n';
        for(int x: result) cout << x << ' ';
    } else cout << "NO\n";
    return 0;
}