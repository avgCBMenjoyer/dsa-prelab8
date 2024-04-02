#include <vector>
#include <iostream>

using namespace std;

struct node{
    static int counter;
    int ID, data, m,n;
    node* left;
    node* right;

    node(){
        ID=++counter;
        m =-1;
        n = -1;
        data = -1;
        left = nullptr;
        right = nullptr;
    }

    node(int newM, int newN){
        ID = ++counter;
        m = newM;
        n = newN;
    }
};