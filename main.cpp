#include "tree.h"

using namespace std;


node* pacman(int A, int B){
    int x=A, y=B;
    node* root = new node(A, B);
    node* current, next;
    current = root;
    while(x!=0 && y!=0){
        if(x==0){
            current->left = new node(y+1);
            y--;
        }
        else if(y==0){
            current->right = new node(x-1,1);
            current = current->right;
        }
        else{
            current->left = new node(x-1);
            current->right = new node(x,(y-1));
            current = current->right;
        }
    }
    return root;


}

//crappy recursion traversal function cause im lazy
void scalePacman(node* root){
    node* current = root;
    
}

