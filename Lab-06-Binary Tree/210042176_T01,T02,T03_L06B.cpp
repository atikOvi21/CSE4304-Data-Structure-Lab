    #include<bits/stdc++.h>
    #include <algorithm>
    using ll = long long;
    #define endl '\n'

    using namespace std;
    int h = 0;

    void init_code()
    {
        ios_base::sync_with_stdio(false);           cin.tie(NULL);
        
        #ifndef ONLINE_JUDGE

        freopen("input.txt", "r", stdin);

        freopen("output.txt", "w", stdout);

        #endif
    }

    struct TreeNode{
        int data,parent;
        TreeNode *left;
        TreeNode *right;
        
    };
    
    void Inorder(TreeNode *root)
    {
        if(root!=NULL)
        {
            Inorder(root->left);
            cout<<root->data<<endl;
            Inorder(root->right);
        }
    }
    void Postorder(TreeNode *root)
    {
        if(root!=NULL)
        {
            Postorder(root->left);
            Postorder(root->right);
            cout<<root->data<<endl;
        }
    }
    void Preorder(TreeNode *root)
    {
        if(root!=NULL)
        {
            cout<<root->data;
            if(root->parent)
                cout<<"("<<root->parent<<")"<<endl;
            else 
                cout<<"(N)"<<endl;

            Preorder(root->left);
            Preorder(root->right);
        }

    }

    void RemoveNode(TreeNode *root , int val , vector<TreeNode>&node )
    {   
        if( root == NULL )
        {
            return;
        }
        else if( root->left ==( &node[val]) )
        {
            root->left = nullptr;
            
        }
        else if(root->right == ( &node[val]))
        {
            root->right = nullptr;
        }
        RemoveNode( root->left ,  val , node);
        RemoveNode( root->right , val , node);


    }
    
    bool Search( TreeNode *root , int val )
    {   
        if( root == NULL )
        {   
            return false;
        }
        else if ( root->data == val )
        {   
            
            cout<<"Present  ";

            if(root->left)
                cout<<"Left("<<root->left->data<<") ";
            else
                cout<<"Left(Null) ";
            if(root->right)
                cout<<"Right("<<root->right->data<<") \n";
            else
                cout<<"Right(Null)\n";
            
            return true;
        }
        
        return Search(root->left, val) || Search(root->right, val);
    }
    
    void height(TreeNode *root , int depth)
    {
        if( root == nullptr )
        {   
            return;
        }
        h = max(h,depth);
        height(root->left,depth+1);
        height(root->right,depth+1);
    }
        
    void LevelOrder(TreeNode* root) 
    {
            if (root == nullptr)
               return;

            queue<TreeNode*> q;
            q.push(root);

            while (!q.empty()) 
            {
              TreeNode* current = q.front();
              q.pop();

              cout << current->data << " ";

              if (current->left)
                q.push(current->left);

              if (current->right)
                q.push(current->right);
            }            
    }

    void PathLength(TreeNode* root , int depth)
    {
        if (root == nullptr)
            return;
        else
            cout<<root->parent<<" ";

        if (root->left == nullptr and root->right == nullptr) {
            cout << root->data<<"("<<depth+1 << ") \n";
        }
        PathLength(root->left,depth+1);
        PathLength(root->right,depth+1);

    }

    void PrintPaths(TreeNode* root, vector<int>& path ) 
    {
        if (root == nullptr) 
        {
            return;
        }

        path.push_back(root->data);

        if ( root->left == nullptr && root->right == nullptr) 
        {
            
            cout << "Path: ";
            for (int i = 0; i < path.size(); i++) 
            {
              cout << path[i];
              if (i < path.size() - 1) 
              {
                cout << " -> ";
              }

            }
            cout << " (Length: " << path.size() << ")" << endl;
        } 
            
        PrintPaths(root->left, path);
        PrintPaths(root->right, path);
        

        path.pop_back(); 
    }
    
    int main() 
    {
        
        init_code();
        /*TASK_01__*/
        vector<TreeNode>node(8);
        
        for (int i = 1; i <= 7; i++) 
        {
            node[i].data  = i;
            node[i].left  = nullptr;
            node[i].right = nullptr;
        }
        
        node[1].left = &node[2];
        node[2].parent = node[1].data;
        node[1].right = &node[3];
        node[3].parent = node[1].data;
        

        node[2].left =  &node[4];
        node[4].parent = node[2].data;
        node[2].right = &node[5];
        node[5].parent = node[2].data;
        
        node[3].left = &node[6];
        node[6].parent = node[3].data;
        node[3].right = &node[7];
        node[7].parent = node[3].data;
        Preorder(&node[1]);


        RemoveNode(&node[1],4,node);
        cout<<"After removing:\n";
        Preorder(&node[1]);

        cout<<"After Searching:";
        
        if(!Search(&node[1],5))
            cout<<"Not present\n";
            
        

        height(&node[1],0);


        cout<<"Height of tree:"<<h<<endl;

        /*TASK-02::Level order,post order,pre order traversal::*/
        cout<<"Inorder Traversal:"<<endl; 

        Inorder(&node[1]);  //node no 6 was deleted 


        cout<<"Postorder Traversal:"<<endl; 

        Postorder(&node[1]);

        cout << "Level-order traversal: ";
        LevelOrder(&node[1]);

        
        /*Task-03-printing paths*/
        cout << "\nprinting paths: ";
        vector<int> path;
        PrintPaths(&node[1],path);   



        
    

    } 