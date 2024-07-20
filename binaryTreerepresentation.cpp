#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public :
    int data ;
    node*left ,*right ;

    node(int d){
        data = d ;
        left = right = NULL ;
    }

} ;

int main()
{

    int x ;
    int first , second ;
    cout<<"enter root value " << endl ;
    cin>>x ;


    queue<node*>q ;
    node*root = new node(x);
    q.push(root);
    while(!q.empty()){
        node*temp = q.front();
        q.pop();
        cout<<"enter left child of "<<temp->data<<" " << endl ;
        cin>>first ; 
        if(first != -1){
            temp->left = new node(first ) ;
            q.push(temp->left);
        }
             cout<<"enter right child of "<<temp->data<<" " << endl ;
          cin>>second ;

          if(second!= -1){
            temp->right = new node(second) ;
            q.push(temp->right);
          }
    }
    return 0;
}