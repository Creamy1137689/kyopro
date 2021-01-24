#include "pch.h"
#include <iostream>
using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	int a[n] = { 0 };
	for (int i = 1; i <= n; i++) {
		cin >> a[i - 1];
	}

	//for (int i = 1; i <= n; i++){
	//  cout << a[i-1] << endl;
	//}

	int index;
	int pb[n * 2] = { 0 };
	for (int i = 1; i <= n * 2; i++) {
		index = i % n;
		if (index == 0) index = n;
		pb[i - 1] = a[index - 1];
	}

	//for (int i = 1; i <= n*2; i++){
	//  cout << pb[i-1] <<endl;
	//}

	int inc[n * 2] = { 0 };
	int count = 0;
	for (int j = n * 2 - 2; j >= 0; j--) {
		for (int i = j + 1; i <= n * 2 - 1; i++) {
			if (pb[j] > pb[i]) count++;
		}
		inc[j] = count;
		count = 0;
	}

	int incnum[n - 1];
	for (int i = 2 * n - 1; i >= n - 1; i--) {
		incnum[i - n] = inc[i - n] - inc[i];
	}

	int num = 0;
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 1; j <= k; j++) {
			num += (inc[n + i] + incnum[i] * (j - 1));
		}
	}
	int warusuu = pow(10.0, 9.0) + 7;
	cout << num % warusuu << endl;

}