#include"Header.h"
void print(const vector<vector<int>> &matrixA) {
	for (int i = 0; i < matrixA.size(); ++i) {
		for (int j = 0; j < matrixA[0].size(); ++j) {
			cout << setw(5) << left << matrixA[i][j] << ' ';
		}
		cout << endl;
	}
}
void implimentFirst(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB,
	int z, int b, int q) {
	cout << "one task:\n";
	auto start = chrono::high_resolution_clock::now();
	vector<vector<int>> C(z, vector<int>(q, 0));
	for (int i = 0; i < z; ++i) {
		for (int p = 0; p < q; ++p) {
			for (int j = 0; j < b; ++j) {
				C[i][p] += matrixA[i][j] * matrixB[j][p];
			}
		}
	}
	auto last = chrono::high_resolution_clock::now();
	auto seconds = chrono::duration_cast<std::chrono::microseconds>(last - start);
	cout << "microseconds " << seconds.count() << endl;
	print(C);
}

void implimentsSecond(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, int t, int c, int l, int k) {
	cout << "two task:\n";
	auto first = chrono::high_resolution_clock::now();
	vector<vector<int>> ccc(t, vector<int>(l));
	vector<thread> threads;
	auto multiply_by_blocks2 = [&](int amountRow, int amountColumn) {
		int amountRowsInBlock = (t / k) <= 1 ? 1 : (t / k);
		int amountColumInBlock = (l / k) <= 1 ? 1 : (l / k);
		int n1, n2;
		int l1, l2;
		if (amountRow >= k - 1 || amountRow >= t - 1) {
			n1 = amountRow * amountRowsInBlock;
			n2 = t;
		}
		else {
			n1 = amountRow * amountRowsInBlock;
			n2 = (amountRow + 1) * amountRowsInBlock;
		}
		if (amountColumn >= k - 1 || amountColumn >= l - 1) {
			l1 = amountColumn * amountColumInBlock;
			l2 = l;
		}
		else {
			l1 = amountColumn * amountColumInBlock;
			l2 = (amountColumn + 1) * amountColumInBlock;
		}
		for (int i = n1; i < n2; ++i) {
			for (int p = l1; p < l2; ++p) {
				for (int j = 0; j < c; ++j) {
					ccc[i][p] += matrixA[i][j] * matrixB[j][p];
				}
			}
		}
	};

	for (int i = 0; i < k; ++i) {
		threads.clear();
		threads.reserve(k);
		for (int j = 0; j < k; ++j) {
			threads.emplace_back(multiply_by_blocks2, i, j);
		}
		for (int i = 0; i < k; ++i) {
			threads[i].join();
		}
	}

	auto end = chrono::high_resolution_clock::now();
	auto seconds = chrono::duration_cast<chrono::microseconds>(end - first);
	cout << "microseconds " << seconds.count() << endl;
	print(ccc);
}

void third(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, int n, int m, int l, int k) {
	cout << "three task:\n";
	auto start = chrono::high_resolution_clock::now();
	vector<vector<int>> ccc(n, vector<int>(l));
	vector<thread> threads;
	auto multiply_by_blocks3 = [&](int number) {
		int columns_in_block = (m / k) <= 1 ? 1 : (m / k);
		int m1, m2;
		if (number >= k - 1 || number >= m - 1) {
			m1 = number * columns_in_block;
			m2 = m;
		}
		else {
			m1 = number * columns_in_block;
			m2 = (number + 1) * columns_in_block;
		}
		for (int i = 0; i < n; ++i) {
			for (int p = 0; p < l; ++p) {
				for (int j = m1; j < m2; ++j) {
					ccc[i][p] += matrixA[i][j] * matrixB[j][p];
				}
			}
		}
	};
	for (int i = 0; i < k; ++i) {
		threads.emplace_back(multiply_by_blocks3, i);
	}
	for (int i = 0; i < k; ++i) {
		threads[i].join();
	}
	auto end = chrono::high_resolution_clock::now();
	auto seconds = chrono::duration_cast<std::chrono::microseconds>(end - start);
	cout << "microseconds " << seconds.count() << endl;
	print(ccc);
}

void implimentFour(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, int n, int m, int l, int k) {
	cout << "four task:\n";
	auto start = chrono::high_resolution_clock::now();
	vector<vector<int>> C(n, vector<int>(l));
	vector<thread> threads;
	auto multiply_by_blocks4 = [&](int i, int p, int j) {
		int rows_in_block = (n / k) <= 1 ? 1 : (n / k);
		int columns_in_block1 = (m / k) <= 1 ? 1 : (m / k);
		int columns_in_block2 = (l / k) <= 1 ? 1 : (l / k);
		int n1, n2;
		int m1, m2;
		int l1, l2;
		if (i >= k - 1 || i >= n - 1) {
			n1 = i * rows_in_block;
			n2 = n;
		}
		else {
			n1 = i * rows_in_block;
			n2 = (i + 1) * rows_in_block;
		}
		if (p >= k - 1 || p >= m - 1) {
			m1 = p * columns_in_block1;
			m2 = m;
		}
		else {
			m1 = p * columns_in_block1;
			m2 = (p + 1) * columns_in_block1;
		}
		if (j >= k - 1 || j >= l - 1) {
			l1 = j * columns_in_block2;
			l2 = l;
		}
		else {
			l1 = j * columns_in_block2;
			l2 = (j + 1) * columns_in_block2;
		}
		for (int i = n1; i < n2; ++i) {
			for (int j = l1; j < l2; ++j) {
				for (int p = m1; p < m2; ++p) {
					C[i][j] += matrixA[i][p] * matrixB[p][j];
				}
			}
		}
	};

	for (int i = 0; i < k; ++i) {
		for (int p = 0; p < k; ++p) {
			threads.clear();
			threads.reserve(k);
			for (int j = 0; j < k; ++j) {
				threads.emplace_back(multiply_by_blocks4, i, p, j);
			}
			for (int y = 0; y < k; ++y) {
				threads[y].join();
			}
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto seconds = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "microseconds " << seconds.count() << endl;
	print(C);
}