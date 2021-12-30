#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


bool in(vector<vector<char>>& grid, int r, int c) {
	bool bRow = (r >= 0) && (r < (int)grid.size());
	bool bCol = (c >= 0) && (c < (int)grid[0].size());
	return bRow && bCol;
}



void dfs(vector<vector<char>>& grid, int r, int c) {

	if (!(grid, r, c)) {
		return;
	}


	if (grid[r][c] != '1') {
		return;
	}


	grid[r][c] = '2';

	dfs(grid, r - 1, c);
	dfs(grid, r + 1, c);
	dfs(grid, r, c - 1);
	dfs(grid, r, c + 1);
}

int numdao(vector<vector<char>>& grid) {
	int r = grid.size();
	if (!r)
		return 0;
	int c = grid[0].size();

	int num = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == '1') {
				++num;
				dfs(grid, i, j);
			}
		}
	}
	return num;
}

int main() {

	vector<char> row1;
	row1.push_back('1');
	row1.push_back('1');
	row1.push_back('1');

	vector<char> row2;
	row2.push_back('0');
	row2.push_back('1');
	row2.push_back('0');

	vector<char> row3;
	row3.push_back('1');
	row3.push_back('0');
	row3.push_back('0');

	vector<char> row4;
	row4.push_back('1');
	row4.push_back('0');
	row4.push_back('1');

	vector<vector<char>> grid;
	grid.push_back(row1);
	grid.push_back(row2);
	grid.push_back(row3);
	grid.push_back(row4);

	int numLands = numdao(grid);

	cout << numLands << endl;


	return 0;
}
