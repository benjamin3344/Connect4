
#include"connect4.h"

int checkWin(int x,int y,char connect4[N1][N2],char flagWin){
	int i,j,cou1=0,cou2=0;
	for(i=y+1;i<N2;i++)//->
		if(connect4[x][i]==flagWin)
			cou1++;
		else break;
	for(i=y-1;i>0;i--)
		if(connect4[x][i]==flagWin)
			cou1++;
		else break;
	if(cou1>=3) return 1;
	cou1=0;



	for(i=x+1;i<N1;i++)
		if(connect4[i][y]==flagWin)
			cou1++;
		else break;
	if(cou1>=3) return 1;
	cou1=0;



	for(i=x+1,j=y+1;i<N1,y<N2;i++,j++)
		if(connect4[i][j]==flagWin)
			cou1++;
		else break;
	for(i=x-1,j=y-1;i>0,j>0;i--,j--)
		if(connect4[i][j]==flagWin)
			cou1++;
		else break;
	if(cou1>=3) return 1;
	cou1=0;



	for(i=x-1,j=y+1;i>0,j<N2;i--,j++)
		if(connect4[i][j]==flagWin)
			cou1++;
		else break;
	for(i=x+1,j=y-1;i<N1,j>0;i++,j--)
		if(connect4[i][j]==flagWin)
			cou1++;
		else break;
	if(cou1>=3) return 1;
	return 0;
}

