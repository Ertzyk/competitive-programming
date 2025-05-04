#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), runs;
        for(int &x: a) cin >> x;
        int cur_len = 1;
        for(int i = 2; i < n; i++){
            if(a[i] > a[i - 1]){
                cur_len++;
            } else {
                runs.push_back(cur_len);
                cur_len = 1;
            }
        }
        runs.push_back(cur_len);
        queue<int> q;
        q.push(0);
        for(int x: runs){
            int depth = q.front();
            q.pop();
            while(x--){
                q.push(depth + 1);
            }
        }
        cout << q.back() << '\n';
    }
    return 0;
}