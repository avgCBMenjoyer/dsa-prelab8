#include "tree.h"

using namespace std;


node* pacman(int A, int B){
    int x=A, y=B;
    node* root = new node(A, B);
    node* current, next;
    current = root;
    while(x!=0 || y!=0){
        if(x==0){
            current->left = new node(y+1);
            y--;
        }
        else if(y==0){
            current->right = new node(x-1,1);
            current = current->right;
            x = current->m;
            y= current->n;
        }
        else{
            current->left = new node(x-1);
            current->right = new node(x,(y-1));
            current = current->right;
            x = current->m;
            y= current->n;
        }
    }
    return root;


}

//crappy recursion traversal function cause im lazy
void scalePacman(node* myPointer){
    node* current = myPointer;
    string intLabel;
    //base case
    if(myPointer==nullptr){
        return;
    }
    if(myPointer->left == nullptr && myPointer->right==nullptr){
        cout << myPointer->ID << "(" << myPointer->data << ")\n";
        return;
    }

    //recursive case
    intLabel = to_string(myPointer->m) + ":" + to_string(myPointer->n);
    cout << intLabel << "\n";
    cout << intLabel << "-->";
    if(myPointer->left != nullptr){
        scalePacman(myPointer->left);
        cout << intLabel << "-->";
        
    }
    
    
    scalePacman(myPointer->right);
    //cout << intLabel << "\n";


}

//execute mspacman
int main(){
    node* myAck = pacman(3,3);
    scalePacman(myAck);
    return 0;
}

