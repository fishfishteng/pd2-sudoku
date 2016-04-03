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
		possibleNum(su);
}

void Sudoku::possibleNum(int* su){
	for(i = 0; i < 81; i++){
		for(j = 0; j < 9; j++){
			pos[i][j] = j + 1;
		}
	}
	checkRow(su);
//	checkCol(su);
//	checkSqr(su);
}

void Sudoku::checkRow(int* su){
	for(i = 0; i < 81; i += 9){
		for(j = 0; j < 9; j++){
			if(su[i+j] == 0){
				for(k = 0; k < 9; k++){
					if(su[i+k] != 0)
						pos[i+j][su[i+k] - 1] = 0;
						for(l = 0; l < 9; l++){
							pos[su[i+k]][l] = 0;
						}
				}
			}
		}
	}
	for(i = 0; i < 81; i++){
		for(j = 0; j < 9; j++){
			cout<<pos[i][j]<<" ";
			
		}
		cout<<endl;
	}
}

void Sudoku::checkCol(int* su){

}

void Sudoku::checkSqr(int* su){

}
