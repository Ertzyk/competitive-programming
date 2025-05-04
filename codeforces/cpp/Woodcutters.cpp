#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> trees(n);
    for(int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        trees[i] = {x, h};
    }
    if(n == 1){
        cout << 1;
        return 0;
    }
    int result = 2;
    for(int i = 1; i < n - 1; i++){
        if(trees[i].first - trees[i].second > trees[i - 1].first) result++;
        else if(trees[i].first + trees[i].second < trees[i + 1].first){
            result++;
            trees[i].first += trees[i].second;
        }
    }
    cout << result;
    return 0;
}