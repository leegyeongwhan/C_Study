#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    char data;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

TreeNode* createNode(char data){
     TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(TreeNode* root, char parent, char left, char right){
    root->data = parent;
    if(left != '.'){
        root->left = createNode(left);
    }
    if(right != '.')  {
        root->right = createNode(right);
    }
}

void print_pre(TreeNode* node){
  if (node!=NULL)
        printf("%c", node->data);
    if (node->left!=NULL)
    print_pre(node->left);
    if (node->right != NULL)
    print_pre(node->right);
}

void print_in(TreeNode* node){
     if (node->left!=NULL)
    print_in(node->left);
    if (node != NULL)
        printf("%c", node->data);
    if (node->right!=NULL)
    print_in(node->right);
}

void print_post(TreeNode* node){
    if (node->left != NULL)
        print_post(node->left);
    if (node->right != NULL)
    print_post(node->right);
    if (node != NULL)
        printf("%c", node->data);
}

int main(){
    int n;
    char parent, left, right;

    scanf("%d", &n);
    scanf("%c %c %c", &parent, &left, &right);
    getchar();


    TreeNode* root = createNode(parent);
    if (left != '.') {
        root->left = createNode(left);
    }
    if (right != '.') {
        root->right = createNode(right);
    }

 for (int i = 1; i < n; i++) {
        scanf("%c %c %c", &parent, &left, &right);
        getchar();
        insert(root, parent, left, right);
    }
    
    print_pre(root);
    printf("\n");
    print_in(root);
    printf("\n");
    print_post(root);
    printf("\n");
    return 0;
}