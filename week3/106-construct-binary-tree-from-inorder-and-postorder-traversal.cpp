//根据一棵树的中序遍历与后序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
// Related Topics 树 数组 哈希表 分治 二叉树 
// 👍 530 👎 0


#include "iostream"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder, int l1, int r1, vector<int>& postorder, int l2, int r2){
        if(l1>r1) return nullptr;
        int mid = 0;
        while(inorder[mid] != postorder[r2]) mid++;
        cout << inorder[mid] << endl;
        int leftsize = mid - l1;
        int rightsize = l2 - mid;
        TreeNode* root = new TreeNode(postorder[r2]);
        root->left = build(inorder, l1, mid-1, postorder, l2, l2+leftsize-1);
        root->right = build(inorder, mid+1, r1, postorder, l2+leftsize, r2-1);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
}