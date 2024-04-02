#include <vector>
#include <iostream>

using namespace std;

struct node{
    static int counter;
    int ID, data, m,n;
    node* left;
    node* right;

    node(){
        ID=-1;
        m =-1;
        n = -1;
        data = -1;
        left = nullptr;
        right = nullptr;
    }

    node(int newM, int newN){
        ID=-1;
        m = newM;
        n = newN;
        data = -1;
        left = nullptr;
        right = nullptr;
    }

    node(int newData){ //leaf node
        data = newData;
        ID = ++counter; //counter only for leaves
        m = -1;
        n = -1;
        left = nullptr;
        right = nullptr;
    }

    void setLeft(node* west){
        left = west;
    }
    void setRight(node* east){
        right = east;
    }
    void makeLeaf(){
        data = n+1; //ackerman y+1
        left = nullptr;
        right = nullptr;
        m =-1;
        n=-1;
    }
    
};