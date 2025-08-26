#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int p = n;
    vector<bool> fell(n + 1);
    for(int i = n; i > 0; i--){
        int a;
        cin >> a;
        fell[a] = true;
        while(fell[p]){
            cout << p << ' ';
            p--;
        }
        cout << '\n';
    }
    return 0;
}