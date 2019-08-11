class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int,int> a;
        vector<int> ans(2,0);
        for(int i=0;i<nums.size();++i)
        {
            if(a.count(target-nums[i])!=0)
            {
                ans[0]=a[target-nums[i]];
                ans[1]=i;
                break;
            }
            a[nums[i]]=i;
        }
        return ans;
    }
};