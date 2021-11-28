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

vector<int> iterativePreorder(node* root)
{
    stack<node*>st;
    vector<int>ans;
    st.push(root);
    while (!st.empty())
    {
        /* code */
        node* n = st.top();
        st.pop();
        ans.push_back(n->data);
        if(n->right)
        {
            st.push(n->right);
        }
        if(n->left)
        {
            st.push(n->left);
        }
    }
    return ans;
}

int main()
{
    node* root = CreateTree();
    vector<int>ans = iterativePreorder(root);
    cout<<"Preorder travesal of given tree is : "<<endl;
    for(auto ele:ans)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
