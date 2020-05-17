#pragma once
#include <thread>
#include <vector>
#include<iostream>
#include<fstream>
#include<iomanip>
#include"Header.h"
using namespace std;
void print(const vector<vector<int>> &matrixA);
void implimentFirst(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, int z, int b, int q);
void implimentsSecond(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, int t, int c, int l, int k);
void third(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, int n, int m, int l, int k);
void implimentFour(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, int n, int m, int l, int k);