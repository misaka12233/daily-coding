#include<stdio.h>
void count(char a[], char w[][10], int n, int b[]) {
	int i, j, k, t, num=0;
	char c[10][10] = { '\0'};
	for (i = 0,j = 0,k = 0; a[i] != '\0'; i++)
		if ('a' <= a[i] && a[i] <= 'z') {
			c[j][k] = a[i];
			k++;
		}
		else {
			c[j][k] = '\0';
			j++;
			k = 0;
		}
	for (i = 0; i < n; i++) {
		for (t = 0; t < j; t++)
			for (k = 0; w[i][k] == c[t][k] && c[t][k] != '\0'; k++);
				if (c[t][k] =='\0')
					num++;
		b[i] = num;
	}
}
int main() {
	int i;
	char a[] = { "this is a book,that is an apple" };
	char w[][10] = { "is","that" };
	int b[2];
	count(a, w, 2, b);
	for(i = 0;i < 2;i++)
        printf("%d ", b[i]);
}
