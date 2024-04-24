#include <algorithm> // std::swap
#include <iostream>
#include "heap.h"

using std::swap;
static int urmom = 0;
void HeapNode::push(int x)
{
    // ...
    // ...
    // ...
    // ...
    // ...
    // ...
    // ...
    // ...
    // ...

    //base case 
    if(left == nullptr){
        left = new HeapNode(x);
        heapify();
        size++;
        return;
    }
    else if(right==nullptr){
        right = new HeapNode(x);
        heapify();
        size++;
        return;
    }
    else{
    //shitty conditions
    if(left->size <= right->size){
        size++;
        left->push(x);
    }
    else{
        size++;
        right->push(x);
    }
    }
    
   

}

int HeapNode::pop()
{
    //assuming right most element is last
    if(left == nullptr && right == nullptr){
        return val;
    }
    
    if(left != nullptr){
        if (left->left == nullptr && left->right == nullptr){
            int weee = left->pop();
            delete left;
            left = nullptr;
            return weee;
        }
    }
    if(right != nullptr){
        if (right->left == nullptr && right->right == nullptr){
            int weee = left->pop();
            delete left;
            right = nullptr;
            return weee;
        }
    }

    int theFinal = val;
    if(left != nullptr && right != nullptr){
        if(left->size > right->size){
            theFinal = left->pop();
        }
        else{
            theFinal = right->pop();
        }
        //size--;
        swap(val, theFinal);
        heapify();
    }/*
    else if(left != nullptr){
        theFinal = left->pop();
        size--;
        
    }*/
    heapify();
    

    
    return theFinal;
}

void HeapNode::heapify()
{
    //fml
    if(left->size <=3){
    
    
        if(left->val < val){
            swap(left->val, val);
        }
        else if(right != nullptr && left != nullptr){
        if(right->val < val){
            swap(left->val, right->val);
            swap(left->val, val);
        }
        if(left->val > right->val){
            swap(left->val, right->val);
        }
        }
    }
    
    
    
    

}
