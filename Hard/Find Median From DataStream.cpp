class MedianFinder 
{
    public:
    /** initialize your data structure here. */
    priority_queue <double> max; 
    priority_queue <double, vector<double>, greater<double>> min;
    
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        if (max.empty())
        {
            max.push(num);
        }
        else if (min.empty())
        {
            if (num>max.top())
            {
                min.push(num);
            }
            else
            {
                min.push(max.top());
                max.pop();
                max.push(num);
            }
        }
        else if (num>=min.top())
        {
            min.push(num);
            if (min.size()-max.size()==2)
            {
                max.push(min.top());
                min.pop();
            }
        }
        else 
        {
            max.push(num);
            if (max.size()-min.size()==2)
            {
                min.push(max.top());
                max.pop();
            }
        }
    }
    
    double findMedian() 
    {
        if (min.size()==max.size())
        {
            return (max.top()+min.top())/2;
        }
        else if (max.size()>min.size())
        {
            return max.top();
        }
        else
        {
            return min.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */