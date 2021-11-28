#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node *CreateTree()
{
    node *root = NULL;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    root->left = CreateTree();
    root->right = CreateTree();
    return root;
}

vector<int> inorderTraversalItr(node* root)
{
    vector<int>ans;
    stack<node*>st;
    node* temp = root;
    // st.push(temp);
    while(true)
    {
        if(temp)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if(st.empty())
            {
                break;
            }
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

int main()
{
    node* root = CreateTree();
    vector<int>ans = inorderTraversalItr(root);
    for(auto ele:ans)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
/*

1
2
4
-1
-1
5
-1
-1
3
6
-1
-1
7
-1
-1
4 2 5 1 6 3 7


*/