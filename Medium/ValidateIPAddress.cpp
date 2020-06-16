//1)Remove spaces from string
//2)Check if given string is number or hexadecimal number
//3)Tokenising a string

class Solution 
{
    public:
    
    bool isHexNumber(string s)
    {
        for (int i = 0; i < s.length(); i++) 
            if (isxdigit(s[i]) == false) 
                return false; 
        return true; 
    }
    
    bool isNumber(string s) 
    { 
        for (int i = 0; i < s.length(); i++) 
            if (isdigit(s[i]) == false) 
                return false; 
        return true; 
    } 
    
    string removeSpaces(string str)  
    { 
        str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
        return str; 
    }    
    
    string validIPAddress(string IP) 
    {
        vector <string> tokens4; 
        vector <string> tokens6;
        stringstream check1(IP); 
        string intermediate; 
        while(getline(check1, intermediate,'.')) 
        { 
            tokens4.push_back(intermediate); 
        } 
        stringstream check2(IP);
        while(getline(check2, intermediate,':')) 
        { 
            tokens6.push_back(intermediate); 
        } 
        
        int countDot=0,countColon=0;
        for (int i=0;i<IP.size();i++)
        {
            if (IP[i]=='.')
            {
                countDot++;
            }
            else if (IP[i]==':')
            {
                countColon++;
            }
        }
        
        if (tokens4.size()==4 && countDot==3 && countColon==0)
        {
            int cnt=0;
            for (int i=0;i<4;i++)
            {
                tokens4[i]=removeSpaces(tokens4[i]);
                if (isNumber(tokens4[i])==true && (tokens4[i]!="") && (tokens4[i].size()<=3) &&
                    (stoi(tokens4[i])>=0 && stoi(tokens4[i])<=255))
                {
                    if ((tokens4[i].size()==1 && tokens4[i][0]=='0') ||
                        (tokens4[i][0]!='0'))
                    {
                        cnt++;
                    }
                }
            }
            if (cnt==4)
            {
                return "IPv4";
            }
            else
            {
                return "Neither";
            }
        }
        else if (tokens6.size()==8 && countColon==7 && countDot==0)
        {
            int cnt=0;
            for (int i=0;i<8;i++)
            {
                tokens6[i]=removeSpaces(tokens6[i]);
                if (isHexNumber(tokens6[i])==true && (tokens6[i]!="") && (tokens6[i].size()<=4) && tokens6[i].size()<=4)
                {
                    cnt++;
                }
            }
            //cout<<cnt;
            if (cnt==8)
            {
                return "IPv6";
            }
            else
            {
                return "Neither";
            }
        }
        return "Neither";
    }
};