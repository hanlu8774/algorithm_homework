//给定一个未排序的整数数组，找到最长递增子序列的个数。 
//
// 示例 1: 
//
// 
//输入: [1,3,5,4,7]
//输出: 2
//解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
// 
//
// 示例 2: 
//
// 
//输入: [2,2,2,2,2]
//输出: 5
//解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
// 
//
// 注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。 
// Related Topics 树状数组 线段树 数组 动态规划 
// 👍 337 👎 0


#include "iostream"
#include "vector"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ansval=0;
        int ans=0;
        int n=nums.size();
        if(n<=1) return n;
        vector<int>dp(n, 1);
        vector<int>count(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    if(dp[j]>=dp[i]){
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                    else if(dp[j]+1==dp[i]){
                        count[i] += count[j];
                    }
                }

                ansval = max(ansval, dp[i]);
//                cout << ansval << endl;
            }
//            cout << count[i] << endl;
        }
        for(int i=0; i<n; i++){
            if(dp[i]==ansval){
                ans += count[i];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
//    vector<int> nums{1,3,5,4,7};
//    vector<int> nums{2,2,2,2,2};
    vector<int> nums{1};
    int ans = s.findNumberOfLIS(nums);
    cout << ans;
}