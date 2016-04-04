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

void Sudoku::printOut(int* su){
	for(i = 0; i < 81; i++){
		cout<<su[i]<<" ";
		if(i%9 == 8)
			cout<<endl;
	}
}

void Sudoku::changeNum(int a, int b){
	for(i = 0; i < 81; i++){
		if(su[i] == a){
			su[i] = b;
		}
		else if(su[i] == b){
			su[i] = a;
		}else{}
	}
}

void Sudoku::changeRow(int a, int b){

	switch(a){
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
	}
}

void Sudoku::changeCol(int a, int b){

	switch(a){
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
	}
}
void Sudoku::rotate(int n){
	for(i = 0; i < 81; i++){
		sqr1[i/9][i - 9*(i/9)] = su[i];
	}

	for(a = 1; a <= n; a++){
		for(i = 0; i < 9; i++){
			for(j = 0; j <9; j++){
				sqr2[j][9-i-1] = sqr1[i][j];
			}
		}
	}
	
	for(i = 0; i < 81; i++){
		su[i] = sqr2[i/9][i - 9*(i/9)];
	}
}

void Sudoku::flip(int n){
	if(n == 0){
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
			
	}
}

void Sudoku::transform(){
	readIn();
	cout<<"Origin:"<<endl;
	printOut(su);
	cout<<endl;
	change();
	printOut(su);
}

void Sudoku::change(){
	srand(time(NULL));
	cout<<"Change number:"<<endl;
	changeNum(rand()%9+1, rand()%9+1);
	printOut(su);
	cout<<endl;
	cout<<"Change row:"<<endl;
	changeRow(rand()%3, rand()%3);
	printOut(su);
	cout<<endl;
	cout<<"Change column:"<<endl;
	changeCol(rand()%3, rand()%3);
	printOut(su);
	cout<<endl;
	cout<<"Rotate:"<<endl;
	rotate(rand()%101);
	printOut(su);
	cout<<endl;
	cout<<"Flip:"<<endl;
	flip(rand()%2);
}

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
}

