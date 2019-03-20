//To search for an element in a BST

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
int test = 0;
//Function to create a new BST node
struct node* newnode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
//To insert a node into BST
struct node* insert(struct node* node, int item)
{
    if(node == NULL) return(newnode(item));
    if(item < node->data) node->left = insert(node->left, item);
    else if(item > node->data) node->right = insert(node->right, item);
    return node;
}
struct node *search(struct node *root, int item)
{
    if(root->data != item) test = -1;
    if(root->data == item) test = 1;
    if(root == NULL || root->data == item) return root;
    if(root->data > item) return search(root->left, item);
    if(root->data < item) return search(root->right, item);
}
//Display BST (inorder traversal)
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void main()
{
    int d, s; char ch;
    struct node *root = NULL;
    printf("Creating BST:\n");
    do
    {
        printf("Enter an element: ");
        scanf("%d", &d);
        root = insert(root, d);
        printf("Enter 0 to quit, any other key to continue: ");
        scanf(" %c", &ch);
    }while(ch!='0');
    printf("\nGiven BST:\n");
    inorder(root);
    printf("\n\nEnter the element to be searched: ");
    scanf("%d", &s);
    root = search(root, s);
    if(test == 1) printf("The element is present in the BST\n\n");
    else if(test == -1) printf("The element is not found in the BST\n\n");
}
