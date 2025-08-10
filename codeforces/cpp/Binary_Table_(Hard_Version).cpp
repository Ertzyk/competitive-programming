#include <iostream>
#include <vector>
using namespace std;

struct Triple{
    int x1, y1, x2, y2, x3, y3;
};

void my_swap(int x, int y, vector<string> &grid){
    if(grid[x][y] == '1') grid[x][y] = '0';
    else grid[x][y] = '1';
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, ones = 0;
        cin >> n >> m;
        vector<string> grid(n);
        for(string &s: grid) cin >> s;
        vector<Triple> result;
        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < m - 1; j++){
                if(grid[i][j] == '1'){
                    Triple p;
                    if(grid[i][j + 1] == '1'){
                        p.x2 = i + 1;
                        my_swap(i, j + 1, grid);
                    } else {
                        p.x2 = i + 2;
                        my_swap(i + 1, j + 1, grid);
                    }
                    p.x1 = i + 1;
                    p.y1 = j + 1;
                    p.y2 = j + 2;
                    p.x3 = i + 2;
                    p.y3 = j + 1;
                    result.push_back(p);
                    my_swap(i, j, grid);
                    my_swap(i + 1, j, grid);
                }
            }
            if(grid[i][m - 1] == '1'){
                Triple p;
                p.x1 = i + 1;
                p.y1 = m;
                p.x2 = i + 2;
                p.y2 = m - 1;
                p.x3 = i + 2;
                p.y3 = m;
                result.push_back(p);
                my_swap(i, m - 1, grid);
                my_swap(i + 1, m - 2, grid);
                my_swap(i + 1, m - 1, grid);
            }
        }
        for(int i = 0; i < m - 2; i++){
            if((grid[n - 2][i] == '1') && (grid[n - 1][i] == '1')){
                Triple p;
                p.x1 = n - 1;
                p.y1 = i + 1;
                p.x2 = n;
                p.y2 = i + 1;
                p.x3 = n - 1;
                p.y3 = i + 2;
                result.push_back(p);
                my_swap(n - 2, i, grid);
                my_swap(n - 1, i, grid);
                my_swap(n - 2, i + 1, grid);
            } else if(grid[n - 2][i] == '1'){
                Triple p;
                p.x1 = n - 1;
                p.y1 = i + 1;
                p.x2 = n;
                p.y2 = i + 2;
                p.x3 = n - 1;
                p.y3 = i + 2;
                result.push_back(p);
                my_swap(n - 2, i, grid);
                my_swap(n - 1, i + 1, grid);
                my_swap(n - 2, i + 1, grid);
            } else if(grid[n - 1][i] == '1'){
                Triple p;
                p.x1 = n;
                p.y1 = i + 1;
                p.x2 = n;
                p.y2 = i + 2;
                p.x3 = n - 1;
                p.y3 = i + 2;
                result.push_back(p);
                my_swap(n - 1, i, grid);
                my_swap(n - 1, i + 1, grid);
                my_swap(n - 2, i + 1, grid);
            }
        }
        if(grid[n - 2][m - 2] == '1') ones++;
        if(grid[n - 1][m - 2] == '1') ones++;
        if(grid[n - 2][m - 1] == '1') ones++;
        if(grid[n - 1][m - 1] == '1') ones++;
        while(ones > 0){
            Triple p;
            if(ones == 4){
                p.x1 = n - 1;
                p.y1 = m - 1;
                p.x2 = n - 1;
                p.y2 = m;
                p.x3 = n;
                p.y3 = m - 1;
                my_swap(n - 2, m - 2, grid);
                my_swap(n - 2, m - 1, grid);
                my_swap(n - 1, m - 2, grid);
                ones = 1;
            } else if(ones == 3){
                int k = 1;
                for(int i = n - 2; i <= n - 1; i++){
                    for(int j = m - 2; j <= m - 1; j++){
                        if(grid[i][j] == '1'){
                            if(k == 1){
                                p.x1 = i + 1;
                                p.y1 = j + 1;
                            } else if(k == 2){
                                p.x2 = i + 1;
                                p.y2 = j + 1;
                            } else {
                                p.x3 = i + 1;
                                p.y3 = j + 1;
                            }
                            k++;
                            grid[i][j] = '0';
                        }
                    }
                }
                ones = 0;
            } else if(ones == 2){
                if(((grid[n - 2][m - 2] == '1') && (grid[n - 1][m - 2] == '1')) || 
                ((grid[n - 1][m - 2] == '1') && (grid[n - 1][m - 1] == '1')) || 
                ((grid[n - 2][m - 1] == '1') && (grid[n - 1][m - 2] == '1'))){
                    p.y1 = m - 1;
                    p.x2 = n - 1;
                    p.y2 = m;
                    my_swap(n - 2, m - 2, grid);
                    my_swap(n - 2, m - 1, grid);
                } else if(((grid[n - 2][m - 2] == '1') && (grid[n - 2][m - 1] == '1')) || 
                ((grid[n - 2][m - 1] == '1') && (grid[n - 1][m - 1] == '1'))){
                    p.y1 = m - 1;
                    p.x2 = n;
                    p.y2 = m - 1;
                    my_swap(n - 2, m - 2, grid);
                    my_swap(n - 1, m - 2, grid);
                } else {
                    p.y1 = m;
                    p.x2 = n;
                    p.y2 = m - 1;
                    my_swap(n - 2, m - 1, grid);
                    my_swap(n - 1, m - 2, grid);
                }
                p.x1 = n - 1;
                p.x3 = n;
                p.y3 = m;
                my_swap(n - 1, m - 1, grid);
                ones = 3;
            } else {
                if(grid[n - 2][m - 2] == '0'){
                    p.y1 = m;
                    my_swap(n - 2, m - 1, grid);
                } else {
                    p.y1 = m - 1;
                    my_swap(n - 2, m - 2, grid);
                }
                p.x1 = n - 1;
                p.x2 = n;
                p.y2 = m - 1;
                p.x3 = n;
                p.y3 = m;
                my_swap(n - 1, m - 2, grid);
                my_swap(n - 1, m - 1, grid);
                ones = 2;
            }
            result.push_back(p);
        }
        cout << result.size() << '\n';
        for(auto tr: result) cout << tr.x1 << ' ' << tr.y1 << ' ' << tr.x2 << ' ' << tr.y2 << ' ' << tr.x3 << ' ' << tr.y3 << '\n';
    }
    return 0;
}