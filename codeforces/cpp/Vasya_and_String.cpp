#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, l = 0, a = 0, b = 0, result = 0;
    string s;
    cin >> n >> k >> s;
    for(int r = 0; r < n; r++){
        if(s[r] == 'a') a++;
        else b++;
        while(b > k){
            if(s[l] == 'a') a--;
            else b--;
            l++;
        }
        result = max(result, r - l + 1);
    }
    a = b = l = 0;
    for(int r = 0; r < n; r++){
        if(s[r] == 'a') a++;
        else b++;
        while(a > k){
            if(s[l] == 'a') a--;
            else b--;
            l++;
        }
        result = max(result, r - l + 1);
    }
    cout << result << '\n';
    return 0;
}