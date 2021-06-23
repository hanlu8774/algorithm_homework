//560. 和为K的子数组
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0]=1;
        int ans=0, presum=0;
        for(auto num:nums){
            presum += num;
            if(map.find(presum-k) != map.end()){
                ans += map[presum-k];
            }
            map[presum]++;
        }
        return ans;
    }
};