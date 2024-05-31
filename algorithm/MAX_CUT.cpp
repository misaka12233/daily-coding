#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n;
int ans;
int p[maxn]; 
int now_id[maxn];  // 表示当前对应状态的编号
int new_id[maxn];
int ans_id[maxn];
int c[maxn][maxn];

double rand_double()
{
	return (double) rand() / RAND_MAX; 
}

int calc(int *id)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (id[i] != id[j])
				sum += c[i][j];
	if (sum > ans)
	{
		ans = sum;
		for (int i = 1; i < n; i++)
			ans_id[i] = id[i];
	}
	return sum;
}

void get_new_id(int *id, int dis)
{
	for (int i = 1; i < n; i++)
	{
		new_id[i] = id[i];
		int j = rand() % (n - i) + i;
		int tmp = p[i];
		p[i] = p[j];
		p[j] = tmp;
	}
	for (int i = 1; i <= dis && i < n; i++)
		new_id[p[i]] ^= 1;
	return;
}

const double dec_T = 0.98;
const double end_T = 0.001;
const double init_T = 1000000;
const int final_check = 1000;

void simulateAnneal() 
{
	ans = 0;
	for (int i = 1; i < n; i++)
		ans_id[i] = 0;
	for (int i = 1; i < n; i++)
		p[i] = i;
	for (int i = 1; i < n; i++)
		now_id[i] = rand() % 2;
	calc(now_id);
	double T = init_T;
	while (T > end_T)
	{
		int origin_res = calc(now_id);
		int dis = 1 + T / init_T * rand_double() * (n - 1);
		get_new_id(now_id, dis);
		int new_res = calc(new_id);
		int delta = new_res - origin_res;
		if (exp(-delta / T) > rand_double())
		{
			for (int i = 1; i < n; i++)
				now_id[i] = new_id[i];
		}
		T *= dec_T;
	}
	for (int i = 1; i <= final_check; ++i) 
	{
		int dis = 1 + T / init_T * rand_double() * (n - 1);
		get_new_id(ans_id, dis);
		calc(new_id);
	}
}

int main()
{
	freopen("MAX_CUT.in", "r", stdin);
	freopen("MAX_CUT.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &c[i][j]);
	simulateAnneal();
	int res = ans, tot = 1 << (n - 1);
	for (int i = 0; i < tot; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if ((1 << j) & i)
				now_id[j + 1] = 1;
			else
			 	now_id[j + 1] = 0;
		}
		calc(now_id);
	}
	printf("%d %d\n", ans, res);
	return 0;
}

