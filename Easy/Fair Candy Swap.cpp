class Solution 
{
    public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) 
    {
        vector<int> ans;
        int sumA=0,sumB=0;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        for (int i=0;i<A.size();i++)
        {
            sumA+=A[i];
        }
        for (int j=0;j<B.size();j++)
        {
            sumB+=B[j];
        }
        int target=(sumA-sumB)/2;
        for (int i=0;i<A.size();i++)
        {
            int l=0,u=B.size()-1;
            while(l<=u)
            {
                int mid=(l+u)/2;
                if (B[mid]==(A[i]-target))
                {
                    ans.push_back(A[i]);
                    ans.push_back(B[mid]);
                    return ans;
                }
                else if (B[mid]<(A[i]-target))
                {
                    l=mid+1;
                }
                else
                {
                    u=mid-1;
                }
            }
        }
        return ans;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);
        
        vector<int> ret = Solution().fairCandySwap(A, B);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}