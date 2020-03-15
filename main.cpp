//剑指Offer
//从上往下打印出二叉树的每个节点，同层节点从左至右打印。

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        deque<TreeNode*> duilie;
        vector<int> result;
        duilie.push_back(root);

        if(root==NULL)
            return result;

        while(duilie.size()){
            TreeNode* temp=duilie.front();
            result.push_back(temp->val);
            duilie.pop_front();

            if(temp->left)
                duilie.push_back(temp->left);

            if(temp->right)
                duilie.push_back(temp->right);
        }
        return result;
    }
};

//调试成功，怀疑是程序的鲁棒性导致溢出问题