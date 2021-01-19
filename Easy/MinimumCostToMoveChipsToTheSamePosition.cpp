class Solution 
{
    public:
    int minCostToMoveChips(vector<int>& position) 
    {
        int countE=0,countO=0;
        for (int i=0;i<position.size();i++)
        {
            if (position[i]%2==0)
            {
                countE++;
            }
            else
            {
                countO++;
            }
        }
        if (countO<=countE)
        {
            return countO;
        }
        return countE;
    }
};