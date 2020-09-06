#include <iostream>
using namespace std;

int main() {
	int n;
	int m;
	cin>>n;
	cin>>m;
	int maze[n][m];
	int tab[n][m];
	for (int i = 0; i < n; i++) {
	   for (int j = 0; j < m; j++) {
	       cin>>maze[i][j];
	   }
	}
	for (int i = n-1; i>=0; i--) {
	    for (int j = m-1; j >= 0; j--) {
	        if(i==n-1&&j==m-1)
	        tab[i][j] = maze[i][j];
	        else if(i==n-1)
	        tab[i][j] =maze[i][j]+tab[i][j+1];
	        else if(j==m-1)
	        tab[i][j] = maze[i][j]+tab[i+1][j];
	        else
	        tab[i][j] = maze[i][j]+ std::min(tab[i][j+1],tab[i+1][j]);
	    }
	}
	std::cout << tab[0][0] << std::endl;
	return 0;
}
