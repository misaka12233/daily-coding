#include <iostream>
 using namespace std;
 struct node{
 	int val;
 };
 void myswap(node *&a, node *&b){
 	a->val = 1;
 b->val = 2;
 } 
 int main()
 {
 node *x, *y;
 x = new node;
 y = new node;
 x->val = 10;
 y->val = 100;
 myswap(x,y);
  cout << x->val << y->val;
  return 0;
 }
 
