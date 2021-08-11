//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入："ab-cd"
//输出："dc-ba"
// 
//
// 示例 2： 
//
// 输入："a-bC-dEf-ghIj"
//输出："j-Ih-gfE-dCba"
// 
//
// 示例 3： 
//
// 输入："Test1ng-Leet=code-Q!"
//输出："Qedo1ct-eeLg=ntse-T!"
// 
//
// 
//
// 提示： 
//
// 
// S.length <= 100 
// 33 <= S[i].ASCIIcode <= 122 
// S 中不包含 \ or " 
// 
// Related Topics 双指针 字符串 
// 👍 82 👎 0


#include "iostream"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.length();
        int start=0, end=n-1;
        while (start<end){
            while(start<n && !((s[start]>='A' && s[start]<='Z') | (s[start]>='a' && s[start]<='z'))){
                start++;
            }
            while(end>start && !((s[end]>='A' && s[end]<='Z') | (s[end]>='a' && s[end]<='z'))){
                end--;
            }
            if(start<end){
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    string string1 = "a-bC-dEf-ghIj";
    string ans = s.reverseOnlyLetters(string1);
    cout << ans;
}