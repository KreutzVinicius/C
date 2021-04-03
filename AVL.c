#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

bool AVL(nodo* root) { //retorna true se a arvore for AVL
   int lh;
   int rh;
   if(root == NULL)
      return 1;
   lh = height(root->l); // left height
   rh = height(root->r); // right height
   if(abs(lh-rh) <= 1 && AVL(root->l) && AVL(root->r)) return 1;
   return 0;
}

int height(nodo* node) {
   if(node == NULL)
      return 0;
   return 1 + max(height(node->l), height(node->r));
}