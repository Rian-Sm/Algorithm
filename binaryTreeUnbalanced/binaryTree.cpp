#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
} Node;

Node *insert(Node *root, int data){
    Node *temp = (Node*) malloc(sizeof(Node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL){
        root = temp;
    } else {
        Node *current = root;
        Node *parent = NULL;

         while(1){
            parent = current;

            if(data < parent->data){
                current = current->left;

                if (current == NULL){
                    parent->left = temp;

                    return root;
                }
                
            } else {
                current = current->right;

                if (current == NULL){
                    parent->right = temp;

                    return root;
                }
            }
         }
    }

    return root;
}

Node *search(Node *root, int value){
    Node *current = root;

    printf("Visiting elements: ");

    while(current){
        printf("%d ", current->data);

        if(value < current->data){
            current = current->left;
        } else if(value > current->data){
            current = current->right;
        } else {
            return current;
        }
    }
    return NULL;
}

void inorder_traversal(Node* root){
    if (root){
        inorder_traversal(root->left);
        printf("%d, ", root->data);
        inorder_traversal(root->right);
    }
}

int main(){
    int i;
    int array[14] = {
        14, 15, 4, 9, 7, 18, 3,
        5, 16, 4, 20, 17, 9, 14
    };

    Node *root = NULL; 

    for(i = 0; i<13 ; i++){
        root = insert(root, array[i]);
        printf("Insert %d\n", array[i]);
    }

    inorder_traversal(root);


    Node *temp = search(root, 20);
    if (temp){
        printf("[%d] Found.\n", temp->data);
    } else {
        printf("[x] Not found.");
    }

    return 0;
}