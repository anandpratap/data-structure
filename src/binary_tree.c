#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define TRUE 1
#define FALSE 0

// contains implementation of a sorted binary tree and various functions related
// to the binary tree to solve the problems here: http://cslibrary.stanford.edu/110/BinaryTrees.html

// return max of x and y
int max(int x, int y){
    return (x > y) ? x : y;
}

// return min of x and y
int min(int x, int y){
    return (x < y) ? x : y;
}

// struct for the tree node
struct node{
    int data;
    struct node* left;
    struct node* right;
};

// helper function to insert, returns pointer to a new node
struct node* newnode(int data){
    struct node* node;
    node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// insert a node containig value 'data' to a tree with root as 'node'
struct node* insert(struct node* node, int data){
    if(node == NULL){
        return newnode(data);
    }
    else{
        if(data < node->data){
            node->left = insert(node->left, data);
        }
        else{
            node->right = insert(node->right, data);
        }
        return node;
    }
}


// lookup whether a given value is present in the tree
static int lookup(struct node* node, int target){
    if(node == NULL){
        return FALSE;
    }
    else{
        if(target == node->data){
            return TRUE;
        }
        else{
            if(target < node->data){
                return lookup(node->left, target);
            }
            else{
                return lookup(node->right, target);
            }
        }
    }
}

// return size of a tree, i.e. total number of nodes
int size(struct node* node){
    int count = 0;
    if(node==NULL){
        return count;
    }
    else{
        count ++;
        count += size(node->left);
        count += size(node->right);
        return count;
    }
}

// return maximum depth of a tree i.e. the longest distance from root to the leaf
int maxdepth(struct node* node){
    int depth = 0;
    if(node==NULL){
        return depth;
    }
    else{
        depth = 1 + max(maxdepth(node->left), maxdepth(node->right));
        return depth;
    }
}

// return minimum value of 'data' in a tree
int minvalue(struct node* node){
    struct node* current = node;
    while(current->left != NULL){
        current = current->left;
    }
    return current->data;
}

// print tree
void printtree(struct node* node){
    if(node != NULL){
        printtree(node->left);
        printf("%d\n", node->data);
        printtree(node->right);
    }
}

void printpostorder(struct node* node){
    if(node != NULL){
        printpostorder(node->left);
        printpostorder(node->right);
        printf("%d\n", node->data);
    }
}


int main(void){
    struct node* root = NULL;
    struct node* n1;
    struct node* n2;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);

    int n;
    n = size(root);
    printf("No. of nodes = %d\n", n);

    int md;
    md = maxdepth(root);
    printf("Max Depth = %d\n", md);

    int mn;
    mn = minvalue(root);
    printf("Min Value = %d\n", mn);


    printtree(root);
    printpostorder(root);

    return SUCCESS;
}
