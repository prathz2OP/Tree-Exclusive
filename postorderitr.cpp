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

vector<int> postOrderIterative(node* root)
{
    stack<node*>st;
    node* curr = root;
    node* temp;
    vector<int>ans;
    while(curr or !st.empty())
    {
        if(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = st.top()->right;
            if(!temp)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() and temp==st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return ans;
}

int main()
{
    node*root = CreateTree();
    vector<int>ans = postOrderIterative(root);
    for(auto ele:ans)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
