class Cashier 
{
    public:
    int dis;
    int noOfCustomers=0;
    int count;
    unordered_map <int,int> umap;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) 
    {
        dis=discount;
        count=n;
        for (int i=0;i<products.size();i++)
        {
            umap[products[i]]=prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) 
    {
        noOfCustomers++;
        double ans=0;
        for (int i=0;i<amount.size();i++)
        {
            ans=ans+(amount[i]*umap[product[i]]);
        }
        if (noOfCustomers%count==0)
        {
            ans=ans-((ans*dis)/100);
        }
        return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */