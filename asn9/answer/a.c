#include <stdio.h>
#include <stdlib.h>
 
// Definition of TreeNode structure
typedef struct TreeNode {
   int val;
   struct TreeNode* left;
   struct TreeNode* right;
} TreeNode;
 
// Function to create a new TreeNode
TreeNode* createNode(int value) {
   TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
   newNode->val = value;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}
 
// Function to perform DFS traversal and calculate maximum path sum
int maxPathSum(TreeNode* root, int* max_sum) {
   if (root == NULL)
       return 0;
 
   // Calculate the maximum sum starting from the left child
   int left_sum = maxPathSum(root->left, max_sum);
   // Calculate the maximum sum starting from the right child
   int right_sum = maxPathSum(root->right, max_sum);
 
   // Update max_sum by considering the path that includes the current node
   *max_sum = (*max_sum > root->val + left_sum + right_sum) ? *max_sum : root->val + left_sum + right_sum;
 
   // Return the maximum sum starting from the current node
   return (left_sum > right_sum ? left_sum : right_sum) + root->val;
}
 
// Main function
int main() {
   int n;
   scanf("%d", &n); // Input size of the array representing the binary tree
 
   int values[n]; 
   for (int i = 0; i < n; i++)
       scanf("%d", &values[i]); // Input weights of Peanut Butter jars
 
   // Function to build the binary tree from the input array
   TreeNode** nodes = (TreeNode**)malloc(n * sizeof(TreeNode*));
   for (int i = 0; i < n; i++)
       nodes[i] = createNode(values[i]);
 
   // Link nodes to form the binary tree
   for (int i = 0; i < n; i++) {
       if (2 * i + 1 < n)
           nodes[i]->left = nodes[2 * i + 1];
       if (2 * i + 2 < n)
           nodes[i]->right = nodes[2 * i + 2];
   }
 
   int max_sum = 0;
   // Find the maximum path sum
   maxPathSum(nodes[0], &max_sum);
   printf("%d\n", max_sum);
 
   // Free dynamically allocated memory
   for (int i = 0; i < n; i++)
       free(nodes[i]);
   free(nodes);
 
   return 0;
}