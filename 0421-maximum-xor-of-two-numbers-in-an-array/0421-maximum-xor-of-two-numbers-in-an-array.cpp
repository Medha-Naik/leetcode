struct Node{
    Node * links[2];
    bool flag=false;

    Node()
    {
        links[0]=0;
        links[1]=0;
    }
    bool containsKey(int bit)
    {
        return links[bit]!=NULL;
    }
    Node * get(int bit)
    {
        return links[bit];
    }
    void put(int bit , Node * node)
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
            int bit=(num>>i)&1;
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node * node=root;
        int maxnum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit))
            {
                maxnum|=1<<i;
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
            
        }
        return maxnum;
    }

    int findMaximumXOR(vector<int>& nums) {
        Node * node=root;
        for( auto num:nums)
        {
            insert(num);
        }
        int ans=0;
        for( auto num:nums)
        {
            ans =max(ans,getMax(num));
        }
        return ans;
    }
};