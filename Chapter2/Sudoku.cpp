#include<stdio.h>
#include<stdlib.h>                                                                                                                                                                                                                                                                                             
int x[9][9];
int count = 0;
void solution(){
	printf("\n**********\n");
	for(int i = 0; i < 9; i++){
		printf("\n");
		for (int j = 0; j < 9; j++){
			printf("%d ",x[i][j]);
		}
	}
	count++;
	if (count == 6) exit(1);
	
}
//v:UCV, r: row, c: column
int check(int v, int r, int c){
	//kiem tra hang trung
	for (int i = 0; i < c; i++){
		if ( x[r][i] == v) return 0;
	}
	//kiem tra cot trung
	for (int j = 0; j < r; j++){
		if (x[j][c] == v) return 0;
	}
	//kiem tra bang 3x3 trung
	int startRow = r - r % 3;
	int startCol = c - c % 3;
	int I = r - startRow;
	int J = c - startCol;
	for (int i = 0; i <= I; i++){
		for (int j = 0; j <= J; j++){
			if (x[startRow + i][startCol + j] == v){
				return 0;
			}
			
		}
	}
			
	return 1;	
}

void Try(int r, int c){
	for (int v = 1; v <= 9; v++){
		if(check(v,r,c)){
			x[r][c] = v;
			if (r == 8 && c == 8) {
			 solution();}
			else{ 
			    if (c == 8) Try(r+1,0); //het dong nay thi xuong dong khac
			    else Try(r,c+1);
			}
		}
		
	}
}

int main(){
	Try(0,0);
}
