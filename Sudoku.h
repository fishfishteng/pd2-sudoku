using namespace std;
class Sudoku{
	public:
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a, int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		void change();
		void printOut(int *su);
		int fillIn(int(* Sudo)[9], int* Z, int zero, int a, int ans);
		int check(int(*poss)[9]);
/*		int* findZero(int* Sudo);
		int* checkRow(int i, int* su, int* poss);
		int* checkCol(int i, int* su, int* pos);
		int* checkSqr(int i, int* su, int* pos);
		int* transPos(int* Pos, int* possible);
		void fillIn(int i, int* su, int* pos);*/
	
	private:
		int i, j, k, l;
		int map[81];
		int temp[27];
		int sqr1[9][9];
		int sqr2[9][9];
		int a, b, Temp;
		int* A;
		int* B;
		int* C;
		int su[81];
		int Map[81];
		int pos[9];
		int answer[9][9];
//		int zerosite[];
//		int zero;
};
