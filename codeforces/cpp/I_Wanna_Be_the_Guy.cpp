#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p, q;
    cin >> n;
    vector<bool> levels(n, false);
    cin >> p;
    while(p--){
        int x;
        cin >> x;
        levels[x - 1] = true;
    }
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        levels[x - 1] = true;
    }
    for(bool b: levels){
        if(!b){
            cout << "Oh, my keyboard!\n";
            return 0;
        }
    }
    cout << "I become the guy.\n";
    return 0;
}