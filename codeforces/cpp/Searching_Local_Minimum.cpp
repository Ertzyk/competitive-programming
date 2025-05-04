#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int l = 1, r = n;
    while(r - l > 3){
        int m1 = l + (r - l)/3, m2 = r - (r - l)/3, val1, val2, val3;
        cout << "? " << m1 << '\n';
        cout.flush();
        cin >> val1;
        cout << "? " << m2 << '\n';
        cout.flush();
        cin >> val2;
        if(val1 < val2){
            cout << "? " << m1 + 1 << '\n';
            cout.flush();
            cin >> val3;
            if(val3 > val1) r = m1;
            else l = m1 + 1;
        } else {
            cout << "? " << m2 - 1 << '\n';
            cout.flush();
            cin >> val3;
            if(val3 > val2) l = m2;
            else r = m2 - 1;
        }
    }
    int last, cur;
    cout << "? " << l << '\n';
    cout.flush();
    cin >> last;
    for(int i = l + 1; i <= r; i++){
        cout << "? " << i << '\n';
        cout.flush();
        cin >> cur;
        if(last < cur){
            cout << "! " << i - 1 << '\n';
            return 0;
        }
        last = cur;
    }
    cout << "! " << r << '\n';
    cout.flush();
    return 0;
}