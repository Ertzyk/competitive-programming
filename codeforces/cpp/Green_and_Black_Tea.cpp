#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    string result;
    while(a > 0 && b > 0){
        if(a - b >= k - 1){
            for(int i = 0; i < k; i++) result += 'G';
            result += 'B';
            a -= k;
            b--;
        } else if(a - b > 0){
            for(int i = 0; i <= a - b; i++) result += 'G';
            result += 'B';
            a = b - 1;
            b--;
        } else if(a == b){
            if(result.size() > 0 && result.back() == 'B') result += "GB";
            else result += "BG";
            a--;
            b--;
        } else if(b - a >= k - 1){
            for(int i = 0; i < k; i++) result += 'B';
            result += 'G';
            a--;
            b -= k;
        } else {
            for(int i = 0; i <= b - a; i++) result += 'B';
            result += 'G';
            b = a - 1;
            a--;
        }
        if(a < 0 || b < 0){
            cout << "NO\n";
            return 0;
        }
    }
    if(a > 0){
        if(a <= k){
            for(int i = 0; i < a; i++) result += 'G';
        } else {
            cout << "NO\n";
            return 0;
        }
    } else if(b > 0){
        if(b <= k){
            for(int i = 0; i < b; i++) result += 'B';
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << result << '\n';
    return 0;
}