//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["flower","flow","flight"]
//输出："fl"
// 
//
// 示例 2： 
//
// 
//输入：strs = ["dog","racecar","car"]
//输出：""
//解释：输入不存在公共前缀。 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 200 
// 0 <= strs[i].length <= 200 
// strs[i] 仅由小写英文字母组成 
// 
// Related Topics 字符串 
// 👍 1719 👎 0


#include "iostream"
#include "vector"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        int len = strs[0].size();
        int lenstrs = strs.size();
        for(int i=0; i<len; i++){
            char ch = strs[0][i];
            for(int j=1; j<lenstrs; j++){
                if(i==strs[j].length() || strs[j][i]!=ch){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
//    vector<string> strs{"dog","racecar","car"};
    vector<string> strs{"a"};
    string ans = s.longestCommonPrefix(strs);
    cout << ans;
}