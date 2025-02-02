#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0

typedef int bool;
typedef int KEYVALUE;

typedef struct node {
    KEYVALUE key;

    struct node *left;
    struct node *right; 
    int height;
} NO, *PONT;

PONT createNode(KEYVALUE key){
    PONT newNode = (PONT) malloc (sizeof(NO));

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;

    return (newNode);
}

int max(int heightFirst, int HeightSecond){
    return (heightFirst > HeightSecond) ? heightFirst : HeightSecond;
}

int height(PONT r){
    return (!r) ? -1 : r->height;
}

PONT turnRight (PONT r){
    PONT aux;
    aux = r->left;
    r->left = aux->right;
    aux->right = r;

    r->height = max(height(r->right), height(r->left))+1;

    aux->height = max(height(aux->left), r->height)+1;

    return (aux);
}

PONT turnLeft (PONT r){
    PONT aux;
    aux = r-> right;
    r->right = aux->left;
    aux->left = r;

     r->height = max(height(r->left), height(r->right))+1; 
     aux->height = max(height(aux->right), r->height)+1;
}

PONT turnLeftDouble (PONT r){
    r->left = turnLeft(r->left);
    return(turnRight(r));
}

PONT tunrRightDouble (PONT r){
    r->right = turnRight(r->right);
    return (turnLeft(r));
}

PONT insert(PONT root, KEYVALUE key){
    if (!root) return (createNode(key));

    if (key < root->key){

        root->left = insert(root->left,key);

        if((height(root->left) - height(root->right)) == 2 )
            if (key < root->left->key)
                root = turnRight(root);
            else 
                root = turnLeftDouble(root);

    } else if(key > root->key){
        
        root->right = insert(root->right,key);

        if((height(root->right) - height(root->left)) == 2)
            if (key < root->right->key)
                root = turnLeft(root);
            else 
                root = tunrRightDouble(root);
    }

    root->height = max(height(root->left), height(root->right)) + 1;
    return root;
} 

PONT init(){
    return (NULL);
}

int main() {
    PONT root = init();

    return 0;
}




