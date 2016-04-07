#include "Sudoku.h"
#include <iostream>
#include <cstdlib>

void Sudoku::giveQuestion(){
	
	int	map[81] = {0,0,0,0,3,0,6,0,0,
	    	   	   9,8,6,0,0,1,2,0,0,
    			   0,7,0,0,9,0,0,0,4,
	   			   0,0,1,3,7,5,0,6,0,
				   7,0,0,0,0,0,0,0,5,
		    	   0,6,0,9,8,2,7,0,0,
			       4,0,0,0,1,0,0,8,0,
    			   0,0,9,8,0,0,1,5,7,
	   			   0,0,7,0,6,0,0,0,0};
	printOut(map);
}

void Sudoku::readIn(){
	for(i = 0; i < 81; i++){
		cin>>su[i];
	}
}

void Sudoku::printOut(int *su){
	for(i = 0; i < 81; i++){
		cout<<su[i]<<" ";
		if(i%9 == 8)
			cout<<endl;
	}
}

void Sudoku::changeNum(int a, int b){
		int i=0;
			
		while(i<=80){
				
			if(su[i]==a)
				su[i]=b;
			else if(su[i]==b)
				su[i]=a;	
			i++;
		}
	/*	for(i = 0; i < 81; i++){
		if(su[i] == a){
			su[i] = b;
		}
		else if(su[i] == b){
			su[i] = a;
		}else{}
	}*/
}

void Sudoku::changeRow(int a, int b){
	int change;
	int i,j;

		for(i=0;i<27;i++){
		
			change=su[27*a+i];
			su[27*a+i]=su[27*b+i];
			su[27*b+i]=change;
		}
/*	switch(a){
		case 0: A = su;
				break;
		case 1: A = &su[27];
				break;
		case 2: A = &su[54];
				break;
	}

	switch(b){
		case 0: B = su;
				break;
		case 1: B = &su[27];
				break;
		case 2: B = &su[54];
				break;
	}

	for(i = 0; i < 27; i++){
		temp[i] = A[i];
		A[i] = B[i];
		B[i] = temp[i];
	}*/
}

void Sudoku::changeCol(int a, int b){
		
		int change;
		int i,j;
			
		for(i=0;i<9;i++){
			
			for(j=0;j<3;j++){
						
				change=su[9*i+3*a+j];
				su[9*i+3*a+j]=su[9*i+3*b+j];
				su[9*i+3*b+j]=change;
			}
		}
/*	switch(a){
		case 0: A = su;
				break;
		case 1: A = &su[3];
				break;
		case 2: A = &su[6];
				break;
	}

	switch(b){
		case 0: B = su;
				break;
		case 1: B = &su[3];
				break;
		case 2: B = &su[6];
				break;
	}

	for(j = 0; j < 81; j += 9){
		temp[j] = A[j];
		A[j] = B[j];
		B[j] = temp[j];
		j++;
		temp[j] = A[j];
		A[j] = B[j];
		B[j] = temp[j];
		j++;
		temp[j] = A[j];
		A[j] = B[j];
		B[j] = temp[j];
		j -= 2;
	}*/
}
void Sudoku::rotate(int n){
	n=n%4;

	int New[81];
	int i,j;
				
	i=0;
					
	while(i<81){
					
		New[i]=0;
		i++;
	}
					
					
	if(n==1){
							
		for(i=0;i<9;i++){
										
			for(j=0;j<9;j++){
													
				New[(9*i+j)+((8-j-i)+9*(j-i))]=su[9*i+j];
			}//rotate 90 degree
		}
	}else if(n==2){
									
		for(i=0;i<9;i++){
											
			for(j=0;j<9;j++){
														
				New[(9*i+j)+((8-2*j)+9*(8-2*i))]=su[9*i+j];
			}//rotate 180 degree
		}
	}else if(n==3){
								
		for(i=0;i<9;i++){
												
			for(j=0;j<9;j++){
															
				New[(9*i+j)+((0-j+i)+9*(8-j-i))]=su[9*i+j];
			}//rotate 270 degree
		}
	}else{
											
		for(i=0;i<81;i++){
													
			New[i]=su[i];
		}
	}
										
	i=0;
										
	while(i<81){
											
		su[i]=New[i];
		i++;
	}
	/*	for(i = 0; i < 81; i++){
		sqr1[i/9][i - 9*(i/9)] = su[i];
	}
	if(n > 0){
		for(a = 1; a <= n; a++){
			for(i = 0; i < 9; i++){
				for(j = 0; j <9; j++){
					sqr2[j][9-i-1] = sqr1[i][j];
				}
			}
		}
	}
	
	for(i = 0; i < 81; i++){
		su[i] = sqr2[i/9][i - 9*(i/9)];
	}*/
}

void Sudoku::flip(int n){
	int i,j;
	int New[81];
		
	if(n==0){
		
		for(i=0;i<9;i++){
								
			for(j=0;j<9;j++){
							
				New[9*i+j+8-2*j]=su[9*i+j];
			}//vertically
		}
	}else{
				
		for(i=0;i<9;i++){
						
			for(j=0;j<9;j++){
									
				New[9*i+j+9*(8-2*i)]=su[9*i+j];
			}//horizontally
		}
	}
					
	i=0;
					
	while(i<81){
						
		su[i]=New[i];
		i++;
	}
							
/*	if(n == 0){
		for(i = 0; i < 81; i++){
			sqr1[i/9][i - 9*(i/9)] = su[i];
		}

		for(i = 0; i < 9; i++){
			for(j = 0; j < 9; j++){
				sqr2[8 - i][j] = sqr1[i][j];
			}
		}

		for(i = 0; i < 81; i++){
			su[i] = sqr2[i/9][i - 9*(i/9)];
		}
	}else{
		for(i = 0; i < 81; i++){
			sqr1[i/9][i - 9*(i/9)] = su[i];
		}

		for(i = 0; i < 9; i++){
			for(j = 0; j < 9; j++){
				sqr2[i][8 - j] = sqr1[i][j];
			}
		}

		for(i = 0; i < 81; i++){
			su[i] = sqr2[i/9][i - 9*(i/9)];
		}
			
	}*/
}

void Sudoku::transform(){
	//change();
	srand(time(NULL));
	changeNum(rand()%9+1, rand()%9+1);
	changeRow(rand()%3, rand()%3);
	changeCol(rand()%3, rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	printOut(su);
}

void Sudoku::change(){
	srand(time(NULL));
	changeNum(rand()%9+1, rand()%9+1);
	changeRow(rand()%3, rand()%3);
	changeCol(rand()%3, rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}
/*
void Sudoku::solve(){
	int pos[9] = {0};
	int possibleNum[9] = {0};
	int* poss = pos; 
	int* possible = possibleNum;
	int* Pos;
	i = findZero(su);
	cout<<i<<endl;
	Pos = checkRow(i, su, poss);
	Pos = checkCol(i, su, Pos);
	Pos = checkSqr(i, su, Pos);
	Pos = transPos(Pos, possible);
	for(k = 0; k < 9; k++){
		cout<<Pos[k]<<" ";
	}
	cout<<endl;
	fillIn(i, su, Pos);
}

int Sudoku::findZero(int* su){
	for(i = 0; i < 81; i++)
		if(su[i] == 0)
			return i;
	return -1;
}

int* Sudoku::checkRow(int i, int* su, int* poss){
	int k = 0;
	int row;
	row = (i/9)*9;
	for(j = 0; j < 9; j++){
		if(su[row + j] != 0){
			poss[k] = su[row + j];
			k++;
		}
	}
	cout<<"k="<<k<<endl;
	return poss;
}

int* Sudoku::checkCol(int i, int* su, int* pos){
	int col;
	col = i%9;
	for(j = 0; j < 73; j+=9){
		if(su[col + j] != 0){
			for(l = 0; l < 9; l++){
				if(pos[l] == su[col + j])
					break;
				else{
					for(k = 0; k < 9; k++){
						if(pos[k] == 0){
							pos[k] = su[col + j];
							break;
						}
					}
					break;
				}
			}
		}
	}
	return pos;
}

int* Sudoku::checkSqr(int i, int*su, int* pos){
	int sqr, m;
	sqr = (i/27)*27 + ((i-9*(i/9))/3)*3;
	cout<<"i="<<i<<endl<<"sqr="<<sqr<<endl;
	for(m = 0; m < 3; m++){
		for(j = 0; j < 3; j++){
			if(su[sqr + j] != 0){
				for(l = 0; l < 9; l++){
					if(pos[l] == su[sqr + j]){
						break;
					}
				}
				if(l == 9){
					for(k = 0; k < 9; k++){
						if(pos[k] == 0){
							pos[k] = su[sqr + j];
							break;
						}
					}
					break;
				}
			}
		}
		cout<<"sqr="<<sqr<<endl;
		sqr+=9;
	}
	return pos;
}

int* Sudoku::transPos(int* Pos, int* possible){
	k = 0;
	for(i = 1; i < 10; i++){
		for(j = 0; j < 9; j++){
			if(i == Pos[j])
				break;
		}
		if(j == 9){
			possible[k] = i;
			k++;
		}
	}
	return possible;
}

void Sudoku::fillIn(int i, int* su, int* Pos){
	int j = 0;
	while(Pos[j] == 0){
		j++;
		if(j == 9)
			return;
	}
	su[i] = Pos[j];
	Pos[j] = 0;
}*/
void Sudoku::solve(){
	int I;
	int J;
	int K;

	for(i = 0; i < 81; i++){
		if(su[i] != 0){
			I = 0;
			J = 0;
			K = 0;

			for(j = 0; j < 9; j++){
				if(su[i] == su[(i/9)*9+j]){
					I++;
					if(I > 1){
						cout<<"0"<<endl;
						exit(1);
					}
				}
				if(su[i] == su[i%9+j*9]){
					J++;
					if(J > 1){
						cout<<"0"<<endl;
						exit(1);
					}
				}
				if(su[i] == su[(i/27)*27+((i%9)/3)*3+j%3+j/3*9]){
					K++;
					if(K > 1){
						cout<<"0"<<endl;
						exit(1);
					}
				}
			}
		}
	}
	int Sudo[9][9];
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			Sudo[i][j] =su [9*i+j];
		}
	}

	int zero = 0;
	
	for(i = 0; i < 81; i++){
		if(su[i] == 0)
			zero++;
	}
	if(zero == 0){
		cout<<"1"<<endl;
		for(i = 0; i < 9; i++){
			for(j = 0; j < 9; j++){
				cout<<Sudo[i][j]<<" ";
			}
				cout<<endl;
		}
		exit(0);
	}
//	cout<<"zero="<<zero<<endl;
	int zerosite[zero];
	int j = 0;


	for(i = 0; i < 81; i++){
		if(su[i] == 0){
			zerosite[j] = i;
			j++;
		}
	}
/*	for(i = 0; i < zero; i++){
		cout<<zerosite[i]<<" ";
	}*/
	int* Z;
	Z = zerosite;
	int a = 0;
	int ans = 0;
	fillIn(Sudo, Z, zero, a, ans);
//	cout<<"i="<<i<<endl<<"j="<<j<<endl;

/*	for(i = 0; i < 81; i++){
		cout<<i+1<<" ";
		for(j = 0; j < 9; j++){
			cout<<poss[i][j];
		}
			cout<<endl;
	}*/
	cout<<endl;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			cout<<Sudo[i][j]<<" ";
		}
			if(j == 9)
				cout<<endl;
	}
}
int Sudoku::fillIn(int(* Sudo)[9], int* Z, int zero, int a, int ans){
	int poss[81][9];
//	cout<<"a="<<a<<endl<<"ans="<<ans<<endl;	
	for(i = 0; i < 81; i++){
		for(j = 0; j < 9; j++){
			poss[i][j] = j + 1;
		}
	}
/*	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			cout<<poss[i][j]<<" ";
		}
			cout<<endl;
	}*/
	
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			if(Sudo[i][j] != 0)
				for(k = 0; k < 9; k++){
					poss[i*9+j][k] = 0;
				}
		}
	}

	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			for(k = 0; k < 9; k++){
					if(Sudo[i][k] != 0)
						poss[9*i+j][Sudo[i][k]-1] = 0;
			}
		}
	}

	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			for(k = 0; k < 9; k++){
				if(Sudo[k][j] != 0)
					poss[9*i+j][Sudo[k][j]-1] = 0;
			}
		}
	}

	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			for(k = 0; k < 3; k++){
				for(l = 0; l < 3; l++){
					if(Sudo[(i/3)*3+k][(j/3)*3+l] != 0)
						poss[9*i+j][Sudo[(i/3)*3+k][(j/3)*3+l]-1] = 0;
				}
			}
		}
	}
/*	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			if(Sudo[i][j] == 0)
				break;
		}
		if(Sudo[i][j] == 0)
			break;
	}*/
	while(a < zero){
		for(k = 0; k < 9; k++){
			i = Z[a]/9;
			j = Z[a]%9;
			if(poss[9*i+j][k] != 0){
				Sudo[i][j] = poss[9*i+j][k];
				poss[9*i+j][k] = 0;
/*				cout<<endl;
					for(i = 0; i < 9; i++){
						for(j = 0; j < 9; j++){
							cout<<Sudo[i][j]<<" ";
						}
							if(j == 9)
								cout<<endl;
					}
	cout<<"zero="<<zero<<endl<<"a="<<a;*/
				a++;
				if(a == zero){
					ans++;
					if(ans == 1){
						for(i = 0; i < 9; i++){
							for(j = 0; j < 9; j++){
								answer[i][j] = Sudo[i][j];
							}
						}
					}
					a--;
					if(ans == 2){
						cout<<"2"<<endl;
						exit(0);
					}
					/*cout<<"1"<<endl;
						for(i = 0; i < 9; i++){
							for(j = 0; j < 9; j++){
								cout<<Sudo[i][j]<<" ";
							}
								if(j == 9)
									cout<<endl;
						}
					exit(0);*/
				}

				ans = fillIn(Sudo, Z, zero, a, ans);
				Sudo[i][j] = 0;
				a--;
				k = 0;
			}
		}
/*		if(ans == 1&&k == 9&&check(poss)){
			cout<<"1"<<endl;
			for(i = 0; i < 9; i++){
				for(j = 0; j < 9; j++){
					cout<<answer[i][j]<<" ";
				}
					if(j == 9)
						cout<<endl;
			}
			exit(0);
		}*/
		if(a == 0&&k == 9&&ans == 1){
			cout<<"1"<<endl;
			for(i = 0; i < 9; i++){
				for(j = 0; j < 9; j++){
					cout<<answer[i][j]<<" ";
				}
					if(j == 9)
						cout<<endl;
			}
			exit(0);
		}
		if(a == 0&&k == 9&&ans == 0){
			cout<<"0"<<endl;
			exit(0);
		}
		return ans;
	}
	return ans;
}
/*int Sudoku::check(int(* poss)[9]){
	int a = 0;
	for(i = 0; i < 9; i++){
		for(j - 0; j < 9; j++){
			if(poss[i][j] != 0)
				a++;
		}
	}
	if(a == 0)
		return 1;
	else
		return 0;
}*/
