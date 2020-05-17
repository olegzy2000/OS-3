#include "Header.h"

int main() {
	ifstream input("input.txt");
	int k, n, m, l;
	input >> k >> n >> m;
	vector<vector<int>> A(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			input >> A[i][j];
		}
	}
	input >> l;
	vector<vector<int>> B(m, vector<int>(l));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < l; ++j) {
			input >> B[i][j];
		}
	}
	implimentFirst(A, B, n, m, l);
	implimentsSecond(A, B, n, m, l, k);
	third(A, B, n, m, l, k);
	implimentFour(A, B, n, m, l, k);
	system("pause");
	return 0;
}