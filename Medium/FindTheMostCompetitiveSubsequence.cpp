//First of all we have to find a subsequence here and not a subarray. Implies that order of elemtns should be same but all elements need not be continuous. Now we need
//the subsequence which on comparison with all other subsequences has the smallest numbers from the left. We only take elements if size of answer array is less than the
//required size. Now whenever an element larger than the last element of our array comes we keep on removing all the greater elements from our array till the time main
//array has sufficient elements left to cover for the loss. 

class Solution 
{
    public:
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        vector<int> ans;
        for(int i=0;i<nums.size();i++) 
        {
            while(!ans.empty() && (ans.back()>nums[i]) && (nums.size()-i>k-ans.size()))
            {
                ans.pop_back();
            }
            if(ans.size()<k)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};