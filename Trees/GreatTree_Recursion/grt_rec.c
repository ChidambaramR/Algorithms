#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node *root, int data){
    if(!root){
        root = (struct node*)malloc(sizeof(struct node));
        root->left = root->right = NULL;
        root->data = data;
        return root;
    }
    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root; // This is required because always the main function expects the root to be returned.
}

void print(struct node *root){
    if(!root)
        return;
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}

struct node* tree2list(struct node *root){
    struct node *aList, *bList;

    if(root == NULL)
        return NULL;

    aList = tree2list(root->left);
    bList = tree2list(root->right);

    root->left = root;
    root->right = root;

    if(aList == NULL && bList == NULL)
        aList = root;
    else{
        /*
         * Remember the diagrams for all the cases.
         * If aList is NULL, then bList should be appended to root.
         *  So think of a node and a right child. Append them bList 
         *  to the root. A catch
         *  here is that, root->left should be pointing to the last node
         *  in the bList which is given by bList->left since it is going
         *  to be a circular linked list.
         * Similarly if bList is NULL, root should be appended to aList.
         * Thus think of the diagrams
         */
        if(!aList){
            root->right = bList;
            root->left = bList->left;
            bList->left = root;
            bList->left->right = root;
            aList = root;
            return aList;
        }
        else if(!bList){
            root->left = aList->left;
            root->right = aList;
            aList->left->right = root;
            aList->left = root;
            return aList;
        }
        root->left = aList->left;
        root->right = bList;
        aList->left->right = root;
        aList->left = bList->left;
        bList->left = root;
        bList->right = aList;
    }

    return aList;

}

void print_ll(struct node *root, int n){
    while(n--){
        printf("%d -> ",root->data);
        root = root->left;
    }
}


int main(){
    struct node *root = NULL;
    int n, data, temp;
    printf("Enter the total number of nodes: ");
    scanf("%d",&n);
    temp = n;
    while(n--){
        printf("Enter node: ");
        scanf("%d",&data);
        root = insert(root, data);
    }
//    print(root); 
    root = tree2list(root);
    printf("The circular linked list printed in reverse: \n");
    print_ll(root->left, temp);
    return 0;
}


