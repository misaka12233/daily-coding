/*
�������� : 3*3*3����ħ����ԭC++����
�㷨ʵ�� :
+---------�����㷨 : ˫������������ ��˵õ��Ľ�������(���ٲ���)��ԭ����
+---------���Ӷȷ��� :
+--------------------ÿ��״̬��6����˳��ʱ��ת��,��12��״̬��������һ��״̬(����֮һ��Ӧʵ�ʻ�ԭ��һ������)
+--------------------��Ӧn����Ŀռ临�Ӷ�ΪO(12^1+12^2+...+12^(n/2))=O(12^(n/2))*sizeof(State);ʱ�临�Ӷ�(12^(n/2)*log(12^n));
���뻷�� : Microsoft Visual C++ 6.0 || Microsoft Visual Studio 2008
���л��� : AMD 3200++ 1.8GHz 1.5GB �ڴ�
�������� : luosiyong
��д���� : 2009��5��22��
��ϵ��ʽ : https://hi.baidu.com/luosiyong
���ڰ汾 :
+--------- : https://hi.baidu.com/luosiyong/blog/item/101fcfdec513bc5294ee3795.html
+--------- : https://hi.baidu.com/luosiyong/blog/item/355d5f2710e53e0b918f9de9.html
�㷨�Ƚ� : ˫������������ �� ��������������
+--------- : ���ڸ��ӶȺ�����һ��ָ��������,ÿ����һ����ͻ����12.�ռ临�Ӷ�Ϊ O(12^n)
+--------- : ˫�������������ʼ�����ֹ��ͬʱ��ʼ����,�ռ临�Ӷȱ�Ϊ 2*O(12^(n/2))
�������� : 10������ʱ����ڴ涼��С,10��5s,11��20+s,12��40+s�ڴ�400+MB.
���˵�� : �����������ab���� ��ʾa�� ���bΪ0,��ʱ����ת90��,����˳ʱ����ת90��
���˸��� : ������ѧ��֤��������3��ħ���Ļ�ԭ����С�ڵ���26,����26��Ҳ�ü����������η!
*/

#pragma warning (disable:4786)
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <set>
using namespace std;

const int STEP=13; //����ܻ�ԭ�Ĳ���

struct State
{
char color[6][9];
char op[STEP*2+1];
};

static const int INDEX1[]={0,1,2,3,4,5,6,7};
static const int INDEX2[6][16]= //6������� %4==0��Ϊ��� ����ͳһ������ת
{
{1,0,1,2, 2,0,1,2, 3,0,1,2, 4,0,1,2}, //0
{0,8,7,6, 4,2,5,8, 5,0,1,2, 2,6,3,0}, //1
{0,2,5,8, 1,2,5,8, 5,2,5,8, 3,6,3,0}, //2
{0,0,1,2, 2,2,5,8, 5,8,7,6, 4,6,3,0}, //3
{0,6,3,0, 3,2,5,8, 5,6,3,0, 1,6,3,0}, //4
{1,8,7,6, 4,8,7,6, 3,8,7,6, 2,8,7,6} //5
};

bool rotate(State & s,int sIdx,int clockwise)
{
if(strlen(s.op)>=2*STEP) return false;
char buf[3];
sprintf(buf,"%d%d",sIdx,clockwise);
strcat(s.op,buf);
int i,j;
if(clockwise) //tmp=0, 0=1,1=2,2=3, 3=tmp
{
    for(i=0;i<5;++i)
    {
     for(j=0;j<3;++j)
     {
      if(i==0)
       buf[j]=s.color[INDEX2[sIdx][0*4+0]][INDEX2[sIdx][0*4+j+1]];
      else if(i==4)
       s.color[INDEX2[sIdx][3*4+0]][INDEX2[sIdx][3*4+j+1]]=buf[j];
      else
       s.color[INDEX2[sIdx][(i-1)*4+0]][INDEX2[sIdx][(i-1)*4+j+1]]=s.color[INDEX2[sIdx][i*4+0]][INDEX2[sIdx][i*4+j+1]];
     }
    }
    buf[0]=s.color[sIdx][0],buf[1]=s.color[sIdx][1];
    s.color[sIdx][0]=s.color[sIdx][6],s.color[sIdx][1]=s.color[sIdx][3];
    s.color[sIdx][6]=s.color[sIdx][8],s.color[sIdx][3]=s.color[sIdx][7];
    s.color[sIdx][8]=s.color[sIdx][2],s.color[sIdx][7]=s.color[sIdx][5];
    s.color[sIdx][2]=buf[0],s.color[sIdx][5]=buf[1];
}
else //tmp=3, 3=2,2=1,1=0, 0=tmp
{
    for(i=4;i>=0;--i)
    {
     for(j=0;j<3;++j)
     {
      if(i==4)
       buf[j]=s.color[INDEX2[sIdx][3*4+0]][INDEX2[sIdx][3*4+j+1]];
      else if(i==0)
       s.color[INDEX2[sIdx][0*4+0]][INDEX2[sIdx][0*4+j+1]]=buf[j];
      else
       s.color[INDEX2[sIdx][i*4+0]][INDEX2[sIdx][i*4+j+1]]=s.color[INDEX2[sIdx][(i-1)*4+0]][INDEX2[sIdx][(i-1)*4+j+1]];
     }
    }
    buf[0]=s.color[sIdx][0],buf[1]=s.color[sIdx][1];
    s.color[sIdx][0]=s.color[sIdx][2],s.color[sIdx][1]=s.color[sIdx][5];
    s.color[sIdx][2]=s.color[sIdx][8],s.color[sIdx][5]=s.color[sIdx][7];
    s.color[sIdx][8]=s.color[sIdx][6],s.color[sIdx][7]=s.color[sIdx][3];
    s.color[sIdx][6]=buf[0],s.color[sIdx][3]=buf[1];
}
return true;
}

bool operator <(const State & a,const State & b)
{
return memcmp(&a,&b,54)<0;
}

bool operator ==(const State & a,const State & b)
{
return memcmp(&a,&b,54)==0;
}

bool DDBFS(State & b,State & e)
{
queue<State> q0,q1;
set<State> ss0,ss1;
q0.push(b),q1.push(e);
ss0.insert(b),ss1.insert(e);
int i,j;
while(! q0.empty() || ! q1.empty())
{
    State front,tmp;
    if(! q0.empty())
    {
     front=q0.front();
     q0.pop();
     if(ss1.find(front)!=ss1.end())
     {
      b=front,e=* ss1.find(front);
      return true;
     }
     for(i=0;i<6;++i)
     {
      for(j=0;j<2;++j)
      {
       tmp=front;
       if(! rotate(tmp,i,j)) continue;
       if(ss0.find(tmp)!=ss0.end()) continue;
       if(ss1.find(tmp)!=ss1.end())
       {
        b=tmp,e=* ss1.find(tmp);
        return true;
       }
       ss0.insert(tmp);
       q0.push(tmp);
      }
     }
    }
    if(! q1.empty())
    {
     front=q1.front();
     q1.pop();
     if(ss0.find(front)!=ss0.end())
     {
      b=front,e=* ss0.find(front);
      return true;
     }
     for(i=0;i<6;++i)
     {
      for(j=0;j<2;++j)
      {
       tmp=front;
       if(! rotate(tmp,i,j)) continue;
       if(ss1.find(tmp)!=ss1.end()) continue;
       if(ss0.find(tmp)!=ss0.end())
       {
        b=tmp,e=* ss0.find(tmp);
        return true;
       }
       ss1.insert(tmp);
       q1.push(tmp);
      }
     }
    }
}
return false;
}

bool input(State & s)
{
int i;
for(i=0;i<6;++i)
{
    if(! (cin>>s.color[i]))
     return false;
}
return true;
}

void output(const State & s)
{
int i,j;
for(i=0;i<6;++i)
{
    for(j=0;j<9;++j)
     putchar(s.color[i][j]);
    puts("");
}
puts(s.op);
puts("*****************************");
}

bool complate(const State & begin,State & end)
{
int i,j;
for(i=0;i<6;++i)
{
    for(j=0;j<9;++j)
     end.color[i][j]=begin.color[i][4];
}
return true;
}

void answer(const State & s1,const State & s2)
{
cout<<"��������:"<<endl;
cout<<s1.op;
int i;
for(i=strlen(s2.op)/2-1;i>=0;--i)
{
    putchar(s2.op[i*2]);
    putchar(s2.op[i*2+1]=='1' ? '0' : '1');
}
puts("\n=======================================");
}

int main()
{
srand(time(0));
State begin,end;
memset(&begin,0,sizeof(begin));
memset(&end,0,sizeof(end));
input(begin);
output(begin);
complate(begin,end);
/*
begin=end;
output(begin),output(end);
for(int i=0;i<12;++i)
    rotate(begin,rand()%6,rand()%2),output(begin);
/*
int i,j;
for(i=0;i<6;++i)
{
    for(j=0;j<2;++j)
    {
     end=begin;
     rotate(end,i,j);
     output(end);
    }
}
strcpy(begin.op,"");
*/
time_t to=clock();
DDBFS(begin,end);
cout<<"�м���̡���"<<endl;
output(begin);
output(end);
cout<<"�м���̽�������"<<endl;
answer(begin,end);
printf("time cost : %d ms\n",clock()-to);
return 0;
}
