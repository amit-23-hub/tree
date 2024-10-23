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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
            if(root== NULL){
                return root ; 
            }
        //  step -1   saare level ka sum nikaal k array me strore kr lenge 

        


        // bfs laga de rhe 
       queue<TreeNode*>q ; 
       // array har level ka sum store krne k liye 
       vector<int>LevelSum ; 

       q.push(root) ; 
       while(!q.empty()){
        int n =  q.size() ; 
        int curLevelSum = 0 ; 
        while(n--){
             TreeNode* cur = q.front() ; 
             q.pop() ; 
             // add kr denge 
              curLevelSum+=cur->val ; 

             // agr node ka left child and right child hoga to push kre denge q me 

             if(cur->left){
                q.push(cur->left) ; 
             }
             if(cur->right){
                q.push(cur->right) ; 
             }
        }

        LevelSum.push_back(curLevelSum) ; 
       }


        // jis node pr honge uske child ko add kr ke currentLevelSum me se subtract kr denge 
            q.push(root) ; 
            root->val = 0 ;  //  root ka koi cousin nhi hota hai

            int i = 1 ; 
            while(!q.empty()){

                int n = q.size() ; 
                while(n--){
                    TreeNode* cur = q.front() ; 
                    q.pop() ; 

                    //abb hme sibling sum niklana hai bcz yahi se hm do child ko access kr skte hai 
                    int siblingSum = 0 ; 
                    if(cur->left){
                        siblingSum+=cur->left->val ; 
                    }
                    if(cur->right){
                        siblingSum+=cur->right->val ; 
                    }


                    //  sibling sum mil gya abb uss level me se subtract kr replace kr denge 

                   if(cur->left){
                        cur->left->val= LevelSum[i] - siblingSum ; 
                        q.push(cur->left);
                    }
                    if(cur->right){
                      cur->right->val= LevelSum[i] - siblingSum ; 
                      q.push(cur->right);
                    }
                }

                i++ ; 
            }

            return root ; 
    }
};