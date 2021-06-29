//给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。 
//
// 你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。 
//
// 
//
// 示例 1： 
//
// 
//输入：[1, 2, 2, 3, 1]
//输出：2
//解释：
//输入数组的度是2，因为元素1和2的出现频数最大，均为2.
//连续子数组里面拥有相同度的有如下所示:
//[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
//最短连续子数组[2, 2]的长度为2，所以返回2.
// 
//
// 示例 2： 
//
// 
//输入：[1,2,2,3,1,4,2]
//输出：6
// 
//
// 
//
// 提示： 
//
// 
// nums.length 在1到 50,000 区间范围内。 
// nums[i] 是一个在 0 到 49,999 范围内的整数。 
// 
// Related Topics 数组 哈希表 
// 👍 350 👎 0


#include "iostream"
#include "vector"
#include "unordered_map"
#include "algorithm"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int ans=0;
        unordered_map<int, vector<int>> m;
        for(int i=0; i<nums.size(); i++){

            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = {1, i, i};
            }
            else {
                m[nums[i]][0] += 1;
                m[nums[i]][2] = i;
            }
        }

        int maxNum = 0;
        for(auto& mp : m){
            cout << to_string(mp.first) << "," << to_string(mp.second[0]) << endl;
            if(mp.second[0] > maxNum){
                maxNum = mp.second[0];
                ans = mp.second[2] - mp.second[1] + 1;
            }
            else if(mp.second[0] == maxNum){
                ans = min(ans, mp.second[2] - mp.second[1] + 1);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{1, 2, 2, 3, 1, 4, 2};
    int ans = s.findShortestSubArray(data);
    cout << ans;
}