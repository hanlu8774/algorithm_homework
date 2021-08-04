//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 
// 👍 1259 👎 0


#include "iostream"
#include "vector"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    fa.push_back(i*n+j);
                    count++;
                }
                else
                    fa.push_back(-1);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='0') continue;
                else{
                    for(int k=0; k<2; k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if(ni<m && nj<n && grid[ni][nj]=='1'){
                            UnionSet(i*n+j, ni*n+nj);
                        }
                    }
                }
            }
        }
        return getCount();
    }

private:
    int m;
    int n;
    int count=0;
    vector<int>fa;
    int dx[2]={0, 1};
    int dy[2]={1, 0};
    int getCount(){
        return count;
    }
    int find(int x){
        if(fa[x]==x) return x;
        return fa[x] = find(fa[x]);
    }
    void UnionSet(int x, int y){
        int i = find(x);
        int j = find(y);
        if(i!=j){
            fa[i]=j;
            count--;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<vector<char>> grid{{'1','1','1','1','0'}, {'1','1','0','1','0'},
                             {'1','1','0','0','0'}, {'0','0','0','0','0'}};
    int ans = s.numIslands(grid);
    cout << ans;
}