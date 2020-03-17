class Solution 
{
    public:
    int lengthOfLongestSubstring(string s) 
    {
        int len=0,start=0;
        int A[95];
        for (int i=0;i<95;i++)
        {
            A[i]=-1;
        }
        for (int i=0;i<s.size();i++)
        {
            if (A[s[i]-32]==-1)
            {
                A[s[i]-32]=i;
                len=max(len,i-start+1);
            }
            else
            {
                start=A[s[i]-32]+1;
                for (int i=0;i<95;i++)
                {
                    if (A[i]<start)
                    {
                        A[i]=-1;
                    }
                }
                A[s[i]-32]=i;
            }
        }
        return len;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}