class Solution {
public:

    int intVal(char ch)
    {   
        
        if(ch=='I')return 1;
        else if(ch=='V') return 5;
        else if(ch=='X') return 10;
        else if(ch=='L') return 50;
        else if(ch=='C') return 100;
        else if(ch=='D') return 500;
        else if(ch=='M') return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int n=s.size();
        int prevval= intVal(s[n-1]);
        int total=prevval;
        for(int i=n-2;i>=0;i--)
        {
            int val= intVal(s[i]);
            if(prevval>val)
            {
                total-=val;
                
            }
            
            else total+=val;
            prevval=val;

        }
        return total;
    }
};