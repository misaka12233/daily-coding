#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
 
//�궨�� 
#define  TRUE  1
#define  FALSE 0
#define  OK    1
#define  ERROR 0
#define  INFEASIBLE -1
#define  OVERFLOW   -2
#define  STACK_INIT_SIZE  100
#define  STACKINCREMENT    10
typedef  int  ElemType;
typedef  int    Status;
 
//ջ��˳��ṹ��ʾ 
typedef struct
{
    ElemType *base;
    ElemType  *top;
    int  stacksize;
}SqStack;
 
//1.����һ����ջ 
Status InitStack(SqStack &S)
{
    S.base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if (!S.base)
        exit(OVERFLOW);//�洢����ʧ��
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}
 
//3.���ջ 
Status ClearStack(SqStack &S)
{
    S.top = S.base;
    return OK;
}
 
//6.//��ջ��Ԫ�� 
Status GetTop(SqStack S, ElemType &e)
{
    if (S.top == S.base)
        return FALSE;
    else
        e = *(S.top - 1);
    return e;
}
 
//7.ջ������Ԫ�� 
Status Push(SqStack &S, ElemType &e)
{
    if (S.top - S.base >= STACK_INIT_SIZE)
    {
        S.base = (ElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!S.base)
        {
            return false;
        }
        S.top = S.base + STACK_INIT_SIZE;
        S.stacksize = S.stacksize + STACKINCREMENT;
    }
    *S.top = e;
    S.top++;
    return OK;
}
 
//8.ɾ��ջ��Ԫ�� 
Status Pop(SqStack &S, ElemType &e)
{
    if (S.top == S.base)
        return ERROR;
    else
    {
        S.top--;
        e = *S.top;
        return e;
    }
}

int main(){
	int x,y,m,n,i,j,k,up,down,left,right,mstart,nstart,mend,nend,error,e;
	up=1;down=2;left=3;right=4;
	SqStack s;
	InitStack(s);
	scanf("%d%d",&x,&y);
	int a[x][y];
	for(i=0;i<x;i++)
	for(j=0;j<y;j++)
	scanf("%d",&a[i][j]);
	scanf("%d%d",&mstart,&nstart);
	scanf("%d%d",&mend,&nend);
	m=mstart;
	n=nstart;
    do{
    	if(mstart==mend&&nstart==nend)
		break; 
    	do{
		    if(m>=1&&a[m-1][n]==0){
	            a[m][n]=1;
	            m-=1;
	            Push(s,up);
	        }
	        else if(m<=x-2&&a[m+1][n]==0){
	            a[m][n]=1;
	            m+=1;
	            Push(s,down);
            }
   	        else if(n>=1&&a[m][n-1]==0){
	            a[m][n]=1;
	            n-=1;
	            Push(s,left);
            }
	        else if(n<=y-2&&a[m][n+1]==0){
	            a[m][n]=1;
	            n+=1;
	            Push(s,right);
            }
            else
            error=1;
            if(m==mend&&n==nend)
		    break; 
	    }while(error!=1);
		if(n==nstart&&m==mstart){
			printf("No");
			break;
		}
		if(m==mend&&n==nend)
		break; 
		do{
			e=GetTop(s,e);
			if(e==up){
	            a[m][n]=1;
	            a[++m][n]=0;
	        }
	        else if(e==down){
	            a[m][n]=1;
	            a[--m][n]=0;
            }
   	        else if(e==left){
	            a[m][n]=1;
	            a[m][++n]=0;
            }
	        else if(e==right){
	            a[m][n]=1;
	            a[m][--n]=0;
            }
            Pop(s,e);
		}while(a[m-1][n]!=0&&a[m+1][n]!=0&&a[m][n-1]!=0&&a[m][n+1]!=0);
        error=0;
	}while(m!=mend||n!=nend);
    if(m==mend&&n==nend) 
	printf("Yes");
	return 0;
}

