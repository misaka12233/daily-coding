#include<iostream>
using namespace std;

typedef int KeyType;
typedef int InfoType;

typedef struct{
	KeyType key;
	InfoType otherinfo;
}ElemType;

typedef struct BSTNode{
	ElemType data;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree; 

void InsertBST(BSTree &T,ElemType e){
	BSTree S;
	if(!T){
		S=new BSTNode;
		S->data=e;
		S->lchild=S->rchild=NULL;
		T=S;
	}
	else if(e.key<T->data.key)
	InsertBST(T->lchild,e);
	else if(e.key>T->data.key)
	InsertBST(T->rchild,e);
}

void DeleteBST(BSTree &T,KeyType key){
	BSTree p,f,q,s;
	p=T;
	f=NULL;
	while(p){
		if(p->data.key==key)
		break;
		f=p;
		if(p->data.key>key)
		p=p->lchild;
		else
		p=p->rchild;
	}
	if(!p)
	return;
	q=p;
	if((p->lchild)&&(p->rchild)){
		s=p->lchild;
		while(s->rchild){
			q=s;
			s=s->rchild;
		}
		p->data=s->data;
		if(q!=p)
		q->rchild=s->lchild;
		else
		q->lchild=s->lchild;
		delete s;
		return;
	}
	else if(!p->rchild){
		p=p->lchild;
	}
	else if(!p->lchild){
		p=p->rchild;
	}
	if(!f)
	T=p;
	else if(q==f->lchild)
	f->lchild=p;
	else
	f->rchild=p;
	delete q;
}

void PreOrderTraverse(BSTree T){
	if(T){
	    cout<<T->data.key<<" ";	
	    PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BSTree T){
	if(T){
		InOrderTraverse(T->lchild);
		cout<<T->data.key<<" ";
		InOrderTraverse(T->rchild);
	}
}

int main(){
	int n,i;
	ElemType e;
	KeyType k;
	cin>>n;
	char operation[n];
	int data[n]; 
	for(i=0;i<n;i++)
	cin>>operation[i]>>data[i];	
	BSTree T=NULL;
	for(i=0;i<n;i++)
	if(operation[i]=='I'){
	    e.key=data[i];
	    InsertBST(T,e);
	}
	else if(operation[i]=='D'){
		k=data[i];
		DeleteBST(T,k);
	}
	PreOrderTraverse(T);
	cout<<endl;
	InOrderTraverse(T);
}
