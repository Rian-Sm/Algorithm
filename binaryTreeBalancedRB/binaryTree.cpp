#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0

#define RED 0
#define BLACK 1

typedef int KEYVALUE;
typedef int COLOR;

typedef struct Node
{
    KEYVALUE key;
    COLOR color;
    
    Node *left, *right, *parent;

} NO, *PONT;

PONT createNode(KEYVALUE value){
    PONT newNode = (PONT) malloc (sizeof(NO));

    newNode->color = RED;
    newNode->key = value;
    newNode->left = newNode->right = newNode->parent = nullptr;

    return newNode;
}

PONT turnLeft(PONT r, PONT &node){
    PONT aux;
    aux = node->right;
    node->right = aux->left;

    if (node->right != nullptr)
        node->right->parent = node;
    
    aux->parent = node->parent;

    if (node->parent == nullptr)
        r = aux;
    else if (node == node->parent->left)
        node->parent->left = aux;
    else 
        node->parent->right = aux;

    aux->left = node;
    node->parent = aux;

    return r;
}

void ColorSwap(PONT &nodeX, PONT &nodeY){
    COLOR auxColor = nodeX->color;

    nodeX->color = nodeY->color;
    nodeY->color = auxColor;
}


PONT turnRight(PONT r, PONT &node){
    PONT aux;
    aux = node->left;
    node->left = aux->right;


    if(node->left != nullptr)
        node->left->parent = node;

    aux->parent = node->parent;

    if (node->parent == nullptr)
        r = aux;
    else  if (node == node->parent->left)
        node->parent->left = aux;
    else 
        node->parent->right = aux;

    aux->right = node;
    node->parent = aux;

    return r;
}

PONT fixViolationsRB(PONT r, PONT fixingNode){
    PONT parent = nullptr;
    PONT grandParent = nullptr;

    while ((fixingNode != r) &&  (fixingNode->color != BLACK) &&  (fixingNode->parent->color == RED)){
        parent = fixingNode->parent;
        grandParent = fixingNode->parent->parent;
         PONT uncle = nullptr;

        if(parent == grandParent->left) {
            uncle = grandParent->right;

            if (uncle != nullptr && uncle->color == RED){
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;

                fixingNode = grandParent;

            } else {
                if (fixingNode == parent->right){
                    r = turnLeft(r, parent);
                    fixingNode = parent;
                    parent = fixingNode->parent;
                }

                r = turnRight(r, grandParent);
                ColorSwap(grandParent, parent);
                fixingNode = parent;
            }
        } else {
            uncle = grandParent->left;

            if(uncle!=nullptr && uncle->color == RED){

                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;

                fixingNode = grandParent;
            } else {

                if (fixingNode == parent->left){
                    r = turnRight(r, parent);
                    fixingNode = parent;
                    parent = fixingNode->parent;
                }

                r = turnLeft(r, grandParent);
                ColorSwap(grandParent, parent);

                fixingNode = parent;
            }
        }

    }
   
    r->color = BLACK;
    return r;
}



PONT insertNode(PONT r, KEYVALUE key){
    PONT newNode = createNode(key);

    if (r == nullptr){
        r = newNode;
        r->color = BLACK;
        return r;
    }
    
    PONT auxNode = nullptr;
    PONT pontIndiceNode = r;

    while (pontIndiceNode != nullptr)
    {
        auxNode = pontIndiceNode;

        if(newNode->key < pontIndiceNode->key)
            pontIndiceNode = pontIndiceNode->left;
        else 
            pontIndiceNode = pontIndiceNode->right;
    }

    newNode->parent = auxNode;

    if(newNode->key < auxNode->key)
        auxNode->left = newNode;
    else 
        auxNode->right = newNode;

    PONT fixTree = fixViolationsRB(r, newNode);

    return fixTree;

}

void inorderTraversal(Node* r) {
    if (r == nullptr)
        return;

    inorderTraversal(r->left);
    printf("%d - %s \n", r->key, (r->color == RED)? "RED" : "BLACK");
    inorderTraversal(r->right);
}

PONT init(){
    return (nullptr);
}

int main(int argc, char **argv) {
    PONT root = init();

    root = insertNode(root,14);
    root = insertNode(root,17);
    root = insertNode(root,4);
    root = insertNode(root,12);
    root = insertNode(root,15);
    root = insertNode(root,5);
    root = insertNode(root,20);
    root = insertNode(root,11);
    root = insertNode(root,2);

    inorderTraversal(root);

    return 0;
}



