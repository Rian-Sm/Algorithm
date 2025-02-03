#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0

#define RED 0
#define BLACK 1

typedef int bool;
typedef int KEYVALUE;
typedef int COLOR;

typedef struct Node
{
    KEYVALUE data;
    COLOR color;
    
    struct Node *left, *right;

} NO, *PONT;

PONT createNode(KEYVALUE value){
    PONT newNode = (PONT) malloc (sizeof(NO));

    newNode->color = RED;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

PONT turnLeft(PONT r){
    PONT aux;
    aux = r->right;
    r->right = r->left;
    aux->left = r;
    
    return aux
}


PONT turnRight(PONT r){
    PONT aux;
    aux = r->left;
    r->left = aux->right;
    aux->right = r;

    return (aux);
}

PONT init(){
    return (NULL);
}

int main() {
    PONT root = init();

    return 0;
}



