/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
int check(vector<vector<int>>&g, int a, int b, int n)
{
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(g[i+a][j+b]==1)
                x=1;
            else if(g[i+a][j+b]==0)
                y=1;
            
            if(x==1 && y==1)
                return -1;
        }
    }
    if(x==1)
    return 1;
    return 0;
}
Node* solv(vector<vector<int>>&g, int i, int j, int n)
{
    Node *t= new Node();
    int x=check(g,i,j,n);
    if(x!=-1)
    {
        t->isLeaf=1;
        t->val=x;
    }
    else
    {
        t->topLeft=solv(g,i,j,n/2);
        t->topRight=solv(g,i,j+n/2,n/2);
        t->bottomLeft=solv(g,i+n/2,j,n/2);
        t->bottomRight=solv(g,i+n/2,j+n/2,n/2);
    }
    return t;
}
class Solution {
public:
    Node* construct(vector<vector<int>>& g) {
        return solv(g,0,0,g.size());
    }
};