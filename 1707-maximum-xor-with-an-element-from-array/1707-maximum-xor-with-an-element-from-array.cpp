struct Node{
    Node * bits[2];
    Node * links[2];

    Node()
    {
        links[0]=links[1]=nullptr;
    }
    bool containsKey(int bit)
    {
        return links[bit]!=NULL;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node * node)
    {
        links[bit]=node;
    }
};

class Solution {
public:
    Node * root;
    Solution()
    {
        root=new Node();
    }
       void insert(int num)
        {
            Node * node=root;
            for(int i=31;i>=0;i--)
            {
                int bit=num>>i&1;
                if(!node->links[bit])
                {
                    node->links[bit]=new Node();
                }
                node=node->links[bit];
            }
        }


    int getmax(int x)
    {
        Node * node=root;
        int ans=0;

     
        for(int i=31;i>=0;i--)
        {
            int bit=(x>>i)&1;
            int ops=1-bit;
            if(node->links[ops])
            {
                ans|=1<<i;
                node=node->links[ops];
            }
            else{
                node=node->links[bit];
            }
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<array<int,3>>q;

        for(int i=0;i<queries.size();i++)
        {
            q.push_back({queries[i][1],queries[i][0],i});
        }
        sort(q.begin(),q.end());
        vector<int>res(queries.size());
        int idx=0;
        for(auto &[m,x,qi]:q)
        {
            while(idx<nums.size()&&nums[idx]<=m)
            {
                insert(nums[idx]);
                idx++;
            }
            if(idx==0)res[qi]=-1;
            else res[qi]=getmax(x);
        }
        return res;
    }
};