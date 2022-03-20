#include<iostream>

using namespace std;

const int n = 10;
int temp[n];

void merge(int tab[], int left, int mid, int right)
{
	int i = left, j = mid + 1;

	for (int i = left; i <= right; i++) {
		temp[i] = tab[i];
	}

	for (int k = left; k <= right; k++) {
		if (i <= mid) {
			if (j <= right) {
				if (temp[j] < temp[i]) {
					tab[k] = temp[j++];
				}
				else {
					tab[k] = temp[i++];
				}
			}
			else {
				tab[k] = temp[i++];
			}
		}
		else {
			tab[k] = temp[j++];
		}
	}
}

void merge_sort(int tab[], int left, int right)
{
	if (right <= left) return;

	int middle = (right + left) / 2;

	merge_sort(tab, left, middle);
	merge_sort(tab, middle + 1, right);

	merge(tab, left, middle, right);
}

int main()
{
	int tab[n] = {3,1,9,5,88,13,90,65,33,41};

	merge_sort(tab, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << tab[i] << " ";

	return 0;
}