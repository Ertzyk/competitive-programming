#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int x = 0, y = 1, count = 0;
    queue<pair<int, int>> q;
    while(count < n){
        if(a[count] == 1){
            if(q.empty()){
                if(x%3 == 1 && y%3 == 1 || x%3 == 1 && y%3 == 2 || x%3 == 2 && y%3 == 1){
                    cout << x << ' ' << y << '\n';
                    count++;
                } else if(x%3 == 0 && y%3 == 0 && x > 0 && y > 0){
                    cout << x - 1 << ' ' << y - 1 << '\n';
                    count++;
                }
            } else {
                auto front = q.front();
                q.pop();
                cout << front.first << ' ' << front.second << '\n';
                count++;
            }
        } else {
            if(x%3 == 1 && y%3 == 1){
                cout << x << ' ' << y << '\n';
                count++;
            } else if(x%3 == 1 && y%3 == 2 || x%3 == 2 && y%3 == 1){
                q.push({x, y});
            } else if(x%3 == 0 && y%3 == 0 && x > 0 && y > 0){
                q.push({x - 1, y - 1});
            }
        }
        if(y == 0){
            y = x;
            x = 1;
        } else if(y == 2){
            y--;
            x++;
        } else if(y == -1){
            y = x - 1;
            x = 1;
        } else {
            if((x + y)%3){
                x++;
                y--;
            } else {
                if(x%3 == 0 && y%3 == 0){
                    x--;
                    y++;
                } else {
                    x += 2;
                    y -= 2;
                }
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}