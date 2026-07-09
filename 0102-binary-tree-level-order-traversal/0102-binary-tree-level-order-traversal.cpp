/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            
            vector<int> temp;
            while(q.front()!=NULL){
                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front->val);
                
                if(front->left!=NULL) q.push(front->left);
                if(front->right!=NULL) q.push(front->right); 
                  
            }
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};