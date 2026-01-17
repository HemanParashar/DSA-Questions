#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    void createMap( unordered_map<TreeNode*, TreeNode*>&parent, TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode->left){
                parent[frontNode->left] = frontNode;
                q.push(frontNode->left);
            }

            if(frontNode -> right){
                parent[frontNode->right] = frontNode;
                q.push(frontNode->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        vector<int>arr;
        createMap(parent, root);
        queue<TreeNode*>q;
        unordered_map<TreeNode*, bool>visited;
        int dist = 0;
        q.push(target);
        visited[target] = true;

        while(!q.empty()){
            int n =  q.size();
            if(dist++ == k) break;

            for(int i=0; i<n; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                if(frontNode->left && !visited[frontNode->left]){
                    visited[frontNode->left] = 1;
                    q.push(frontNode->left);
                }
                
                if(frontNode->right && !visited[frontNode->right]){
                    visited[frontNode->right] = 1;
                    q.push(frontNode->right);
                }

                  if(parent[frontNode] && !visited[parent[frontNode]]) {
                    visited[parent[frontNode]] = 1;
                    q.push(parent[frontNode]);
                }
                

            }

        }
        while(!q.empty()){
            arr.push_back(q.front()->val);
            q.pop();
        }
        return arr;

    }
};