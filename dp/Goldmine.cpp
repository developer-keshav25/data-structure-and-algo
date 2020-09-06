#include <iostream>
using namespace std;

int main() {
	int n;
	int m;
	cin>>n;
	cin>>m;
	int mine[n][m];
	int tab[n][m];
	for (int i = 0; i < n; i++) {
	   for (int j = 0; j < m; j++) {
	       cin>>mine[i][j];
	   }
	}
	for (int j = m-1; j>=0; j--) {
	    for (int i = n-1; i >= 0; i--) {
	        if(j==m-1)
	        tab[i][j] =mine[i][j];
	        else if(i==0)
	        tab[i][j] = mine[i][j]+std::max(tab[i+1][j+1],tab[i][j+1]);
	        else if(i==n-1)
	        tab[i][j] = mine[i][j]+std::max(tab[i-1][j+1],tab[i][j+1]);
	        else
	        tab[i][j] = mine[i][j]+std::max(tab[i+1][j+1],std::max(tab[i-1][j+1],tab[i][j+1]));
	    }
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
	    if(tab[i][0]>max)
	    max = tab[i][0];
	}
	std::cout <<max << std::endl;
	return 0;
}
