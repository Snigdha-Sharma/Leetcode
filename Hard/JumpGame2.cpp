//TC:O(N square) solution

class Solution 
{
    public:
    int jump(vector<int>& nums) 
    {
        if (nums.size()<=1)
        {
            return 0;
        }
        if (nums.size()==2)
        {
            return 1;
        }
        vector<int> index;
        for (int i=0;i<nums.size();i++)
        {
            index.push_back(i);
        }
        int maxJump=nums.size()-1;
        int lastIndex=nums.size()-1;
        for (int i=0;i<nums.size();i++)
        {
            maxJump=min(lastIndex,i+nums[i]);
            for (int j=i+1;j<=maxJump;j++)
            {
                index[j]=min(index[j],index[i]+1);
            }
        }
        // for (int i=0;i<nums.size();i++)
        // {
        //     cout<<index[i]<<" ";
        // }
        //cout<<"dcd="<<index[index.size()-2]<<endl;
        return index[nums.size()-1];
    }
};


//Simple optimisation
class Solution 
{
    public:
    int jump(vector<int>& nums) 
    {
        if (nums.size()<=1)
        {
            return 0;
        }
        if (nums.size()==2)
        {
            return 1;
        }
        vector<int> index;
        for (int i=0;i<nums.size();i++)
        {
            index.push_back(i);
        }
        int maxJump=nums.size()-1;
        int lastIndex=nums.size()-1;
        for (int i=0;i<nums.size();i++)
        {
            maxJump=min(lastIndex,i+nums[i]);
            for (int j=maxJump;j>i;j--)
            {
                if (index[j]>index[i]+1)
                {
                    index[j]=index[i]+1;
                }
                else
                {
                    break;
                }
            }
        }
        // for (int i=0;i<nums.size();i++)
        // {
        //     cout<<index[i]<<" ";
        // }
        //cout<<"dcd="<<index[index.size()-2]<<endl;
        return index[nums.size()-1];
    }
};