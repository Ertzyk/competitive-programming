#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    if((ax - bx)*(ax - bx) + (ay - by)*(ay - by) == (cx - bx)*(cx - bx) + (cy - by)*(cy - by) &&
    (bx - ax)*(cy - ay) - (by - ay)*(cx - ax) != 0){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}