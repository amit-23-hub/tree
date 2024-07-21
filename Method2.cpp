#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class node {
    public :
    int data ;
    node* left , *right ;

    // constructor

    node(int d){
        data = d;
        left=right=NULL ;
    }
};

node* binarytree(){
    int x;
 
    cin>>x ;
    if(x==-1){
        return NULL ;
    }
    node* temp = new node(x) ;
    cout<<"enter the left child of "<<x <<endl ;
    temp->left = binarytree();
    cout<<"enter the right  child of "<<x  <<endl ;
    temp->right = binarytree();

    return temp ;

};



int main()
{
    cout<<"enter the root node "<<endl ; 
    node* root ;
    root = binarytree();
    return 0;
}