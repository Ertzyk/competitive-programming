#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), a_inverse(n + 1);
    for(int &x: a) cin >> x;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < n; i++){
        a_inverse[a[i]] = i;
        int pointer = i - a[i];
        while(pointer >= 0){
            if(a[pointer] > a[i]) graph[a[i]].push_back(a[pointer]);
            pointer -= a[i];
        }
        pointer = i + a[i];
        while(pointer < n){
            if(a[pointer] > a[i]) graph[a[i]].push_back(a[pointer]);
            pointer += a[i];
        }
    }
    string result(n, ' ');
    for(int i = n; i > 0; i--){
        result[a_inverse[i]] = 'B';
        for(int neighbor: graph[i]) if(result[a_inverse[neighbor]] == 'B'){
            result[a_inverse[i]] = 'A';
            break;
        }
    }
    cout << result;
    return 0;
}