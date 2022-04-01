#include <stdio.h>

int vhash[30], a[30][30], n;
int ans = 0, count;
void dfs(int k) {
	if (k > n) {
		/*for (int i = 1; i <= n; i++) {
			printf("%d ", vhash[i]);
		}
		printf("\n");*/
		count++;
		for (int i = 1; i < n; i++) {
			if (vhash[i])
			{
				for (int j = i + 1; j <= n; j++) {
					if (vhash[j]) {
						if (!vhash[a[i][j]] || !vhash[a[j][i]])
						return;
					}
				}
			}
		}
		/*for (int i = 1; i <= n; i++) {
			if (!vhash[i]) {
				continue;
			}
			for (int j = 1; j <= n; j++) {
				if (!vhash[j]) {
					continue;
				}
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
		ans++;
		return ;
	}
	dfs(k + 1);
	vhash[k] = 1;
	dfs(k + 1);
	vhash[k] = 0;
}
int main(void) {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	dfs(1);
	printf("%d", ans - 1);
	//printf("%d\n", count - 1);
	return 0;
}
