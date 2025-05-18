#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll start_x, start_y, prev_x, prev_y, result = 0, result2 = 0;
        cin >> start_x >> start_y;
        prev_x = start_x;
        prev_y = start_y;
        while(true){
            ll cur_x, cur_y;
            cin >> cur_x >> cur_y;
            result += (cur_x - prev_x)*(cur_y + prev_y);
            prev_x = cur_x;
            prev_y = cur_y;
            if(prev_x == start_x && prev_y == start_y) break;
        }    
        result = abs(result);
        result *= 2;
        cin >> start_x >> start_y;
        prev_x = start_x;
        prev_y = start_y;
        while(true){
            ll cur_x, cur_y;
            cin >> cur_x >> cur_y;
            result2 += (cur_x - prev_x)*(cur_y + prev_y);
            prev_x = cur_x;
            prev_y = cur_y;
            if(prev_x == start_x && prev_y == start_y) break;
        }    
        result2 = abs(result2);
        result2 *= 3;
        cout << result + result2 << '\n';
    }
    return 0;
}