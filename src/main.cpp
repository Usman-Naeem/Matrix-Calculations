//In this script, Basic Operations on Matrices can be performed by the user like Addition, Subtraction, Multiplication
//Finding Idempotent, Transverse, Power, and Scalar of Matrix.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int menu();
int check(int min, int max, string input);
vector<vector<int>> size();
int mid(int row);
void Addition();
void Subtraction();
void Multiplication();
void Idempotent();
void Transverse();
void Power();
void Scalar();

int main() {
	while (true) {
		int ch = menu();
		if (ch == 1) {
			Addition();
		}
		else if (ch == 2) {
			Subtraction();
		}
		else if (ch == 3) {
			Multiplication();
		}
		else if (ch == 4) {
			Idempotent();
		}
		else if (ch == 5) {
			Transverse();
		}
		else if (ch == 6) {
			Power();
		}
		else if (ch == 7) {
			Scalar();
		}
		else {
			break;
		}
	}
	return 0;
}

int menu() {
	string choice = "";
	int ch = 0;
	cout << "\n----------------------------\n"
		<<"1. Two Matrices Addition" << endl
		<< "2. Two Matrices Subtraction" << endl
		<< "3. Two Matrices Multiplication" << endl
		<< "4. Check Matrix Idempotent" << endl
		<< "5. Find Matrix Transverse" << endl
		<< "6. Find Matrix Power (Upto 6)" << endl
		<< "7. Matrix Scalar" << endl
		<< "0. Quit\n => ";
	cin >> choice;
	ch = check(0, 7, choice);
	if(ch == -111){
		cout << "Enter an Integer !" << endl << endl;
		menu();
	}
	if (ch == -222) {
		cout << "Enter Between 0 and 7 !" << endl << endl;
		menu();
	}
	else {
		return ch;
	}
}

int check(int min, int max, string input) {
	int ch = 0;
	try {
		ch = stoi(input);
	}
	catch (invalid_argument e) {
		return -111;
	}
	if (ch < min || ch > max) {
		return -222;
	}
	return ch;
}

vector<vector<int>> size() {
	string row, column;
	int r, c;
	cout << "Select the Number of Rows 'm'\n"
		<< "1, 2, 3, 4, or 5   : ";
	cin >> row;
	r = check(1, 5, row);
	if (r == -111) {
		cout << "Enter an Integer !" << endl << endl;
		size();
	}
	if (r == -222) {
		cout << "Enter Between 1 and 5 !" << endl << endl;
		size();
	}
	cout << "Select the Number of Columns 'n'\n"
		<< "1, 2, 3, 4, or 5   : ";
	cin >> column;
	c = check(1, 5, column);
	if (c == -111) {
		cout << "Enter an Integer !" << endl << endl;
		size();
	}
	if (c == -222) {
		cout << "Enter Between 1 and 5 !" << endl << endl;
		size();
	}
	vector<vector<int>> vec(r, vector<int>(c, 0));
	return vec;
}

int Mid(int r) {
	int M = 0;
	if (r == 1) {
		M = 1;
	}
	else if (r == 2) {
		M = 1;
	}
	else if (r == 3) {
		M = 2;
	}
	else if (r == 4) {
		M = 2;
	}
	else {
		M = 3;
	}
	return M;
}


void Addition() {
	vector<vector<int>> A = size();
	int r = A.size(), c = A[0].size();
	vector<vector<int>> B(r, vector<int>(c, 0));
	string temp = "";
	A1:	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "Enter Value of A[" << i + 1 << "][" << j + 1 << "] : ";
			cin >> temp;
			A[i][j] = check(-99999999, 99999999, temp);
			if (A[i][j] == -111) {
				cout << "Enter Integers only !!! Try Again";
				goto A1;
			}
		}
	}
	cout << endl;
	B1:	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "Enter Value of B[" << i + 1 << "][" << j + 1 << "] : ";
			cin >> temp;
			B[i][j] = check(-99999999, 99999999, temp);
			if (B[i][j] == -111) {
				cout << "Enter Integers only !!! Try Again";
				goto B1;
			}
		}
	}
	cout << endl << "Your Entered Matrices A and B : \n";
	int mid = Mid(r);
	for (int i = 0; i < r; i++) {
		if (i != mid - 1) {
			cout << "  | ";
		}
		else {
			cout << "A | ";
		}
		for (int j = 0; j < c; j++) {
			cout << A[i][j] << " ";
		}
		if (i != mid - 1) {
			cout << "|    | ";
		}
		else {
			cout << "|  B | ";
		}
		for (int j = 0; j < c; j++) {
			cout << B[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "\nA + B : \n";
	for (int i = 0; i < r; i++) {
		cout << " | ";
		for (int j = 0; j < c; j++) {
			cout << A[i][j] + B[i][j] << " ";
		}
		cout << "|\n";
	}
}

void Subtraction() {
	cout << "\nNote : Here (A-B), B will be Subtracted from A.\n\n";
	vector<vector<int>> A = size();
	int r = A.size(), c = A[0].size();
	vector<vector<int>> B(r, vector<int>(c, 0));
	string temp = "";
	A1:	for (int i = 0; i < r; i++) {
	for (int j = 0; j < c; j++) {
		cout << "Enter Value of A[" << i + 1 << "][" << j + 1 << "] : ";
		cin >> temp;
		A[i][j] = check(-99999999, 99999999, temp);
		if (A[i][j] == -111) {
			cout << "Enter Integers only !!! Try Again";
			goto A1;
		}
	}
}
	cout << endl;
	B1:	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "Enter Value of B[" << i + 1 << "][" << j + 1 << "] : ";
			cin >> temp;
			B[i][j] = check(-99999999, 99999999, temp);
			if (B[i][j] == -111) {
				cout << "Enter Integers only !!! Try Again";
				goto B1;
			}
		}
	}
	cout << endl << "Your Entered Matrices A and B : \n";
	int mid = Mid(r);
	for (int i = 0; i < r; i++) {
		if (i != mid - 1) {
			cout << "  | ";
		}
		else {
			cout << "A | ";
		}
		for (int j = 0; j < c; j++) {
			cout << A[i][j] << " ";
		}
		if (i != mid - 1) {
			cout << "|    | ";
		}
		else {
			cout << "|  B | ";
		}
		for (int j = 0; j < c; j++) {
			cout << B[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "\nA - B : \n";
	for (int i = 0; i < r; i++) {
		cout << " | ";
		for (int j = 0; j < c; j++) {
			cout << A[i][j] - B[i][j] << " ";
		}
		cout << "|\n";
	}
}

void Multiplication() {
	cout << "\nNote : Here (AxB), Columns of A 'n' and rows of B 'm' Must be equal.\n\n For 'A' :\n";
	vector<vector<int>> A = size();
	int Ar = A.size(), Ac = A[0].size();
	cout << " For 'B' \n";
	vector<vector<int>> B = size();
	int Br = B.size(), Bc = B[0].size();
	if (Ac != Br) {
		cout << "The Column of A (" << Ar << "x" << Ac << "), and Row of B(" << Br << "x" << Bc << ") are not equal, Thus AB is not defined.";
		Multiplication();
	}
	string temp = "";
	A1:	for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				cout << "Enter Value of A[" << i + 1 << "][" << j + 1 << "] : ";
				cin >> temp;
				A[i][j] = check(-99999999, 99999999, temp);
				if (A[i][j] == -111) {
					cout << "Enter Integers only !!! Try Again";
					goto A1;
				}
			}
	}
	cout << endl;
	B1:	for (int i = 0; i < Br; i++) {
			for (int j = 0; j < Bc; j++) {
				cout << "Enter Value of B[" << i + 1 << "][" << j + 1 << "] : ";
				cin >> temp;
				B[i][j] = check(-99999999, 99999999, temp);
				if (B[i][j] == -111) {
					cout << "Enter Integers only !!! Try Again";
					goto B1;
				}
			}
	}
	cout << endl << "A : \n";
	int mid = Mid(Ar);
	for (int i = 0; i < Ar; i++) {
		cout << " | ";
		for (int j = 0; j < Ac; j++) {
			cout << A[i][j] << " ";
		}
		cout << "|\n";
	}
	cout << "B : \n";
	mid = Mid(Br);
	for (int i = 0; i < Br; i++) {
		cout << " | ";
		for (int j = 0; j < Bc; j++) {
			cout << B[i][j] << " ";
		}
		cout << "|\n";
	}
	cout << "\nA x B : \n";
	int ab = 0;
	for (int i = 0; i < Ar; i++) {
		cout << " | ";
		for (int j = 0; j < Bc; j++) {
			ab = 0;
			for (int k = 0; k < Ac; k++) {
				ab += A[i][k] * B[k][j];
			}
			cout << ab << " ";
		}
		cout << "|\n";
	}
}

void Idempotent() {
	vector<vector<int>> A = size();
	int Ar = A.size(), Ac = A[0].size();
	if (Ac != Ar) {
		cout << "The Rows and Columns of A (" << Ar << "x" << Ac << ") are not equal, Thus A^2 is not defined.";
		Idempotent();
	}
	vector<vector<int>> A2(Ar, vector<int>(Ac, 0));
	string temp = "";
	A1:	for (int i = 0; i < Ar; i++) {
		for (int j = 0; j < Ac; j++) {
			cout << "Enter Value of A[" << i + 1 << "][" << j + 1 << "] : ";
			cin >> temp;
			A[i][j] = check(-99999999, 99999999, temp);
			if (A[i][j] == -111) {
				cout << "Enter Integers only !!! Try Again";
				goto A1;
			}
		}
	}
	cout << endl << "A : \n";
	int mid = Mid(Ar);
	for (int i = 0; i < Ar; i++) {
		cout << " | ";
		for (int j = 0; j < Ac; j++) {
			cout << A[i][j] << " ";
		}
		cout << "|\n";
	}
	cout << "A^2 : \n";
	int ab = 0;
	for (int i = 0; i < Ar; i++) {
		cout << " | ";
		for (int j = 0; j < Ac; j++) {
			ab = 0;
			for (int k = 0; k < Ac; k++) {
				ab += A[i][k] * A[k][j];
			}
			A2[i][j] = ab;
			cout << ab << " ";
		}
		cout << "|\n";
	}
	bool same = true;
	for (int i = 0; i < Ar; i++) {
		for (int j = 0; j < Ac; j++) {
			if (A[i][j] != A2[i][j]) {
				same = false;
				cout << "\nAs A and A^2 are not equal, The Matrix A is not Idempotent.\n";
				return;
			}
		}
	}
	cout << "\nThe Matrix A is Idempotent.\n";
}

void Transverse() {
	vector<vector<int>> A = size();
	int Ar = A.size(), Ac = A[0].size();
	vector<vector<int>> AT(Ac, vector<int>(Ar, 0));
	string temp = "";
	A1:	for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				cout << "Enter Value of A[" << i + 1 << "][" << j + 1 << "] : ";
				cin >> temp;
				A[i][j] = check(-99999999, 99999999, temp);
				if (A[i][j] == -111) {
					cout << "Enter Integers only !!! Try Again";
					goto A1;
				}
			}
	}
	cout << endl << "A : \n";
	int mid = Mid(Ar);
	for (int i = 0; i < Ar; i++) {
		cout << " | ";
		for (int j = 0; j < Ac; j++) {
			AT[j][i] = A[i][j];
			cout << A[i][j] << " ";
		}
		cout << "|\n";
	}
	cout << endl << "A(T) : \n";
	for (int i = 0; i < Ac; i++) {
		cout << " | ";
		for (int j = 0; j < Ar; j++) {
			cout << AT[i][j] << " ";
		}
		cout << "|\n";
	}
}

void Power() {
	string input = "";
	vector<vector<int>> A = size();
	int Ar = A.size(), Ac = A[0].size();
	if (Ac != Ar) {
		cout << "The Rows and Columns of A (" << Ar << "x" << Ac << ") are not equal, Thus Power cannot be defined.";
		Power();
	}
	vector<vector<int>> A2(Ar, vector<int>(Ac, 0));
	vector<vector<int>> A3(Ar, vector<int>(Ac, 0));
	vector<vector<int>> A4(Ar, vector<int>(Ac, 0));
	vector<vector<int>> A5(Ar, vector<int>(Ac, 0));
	A1:	for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				cout << "Enter Value of A[" << i + 1 << "][" << j + 1 << "] : ";
				cin >> input;
				A[i][j] = check(-99999999, 99999999, input);
				if (A[i][j] == -111) {
					cout << "Enter Integers only !!! Try Again";
					goto A1;
				}
			}
	}
	A2: cout << "\nEnter Power 2, 3, 4, 5, or 6: ";
	cin >> input;
	int pow = check(2, 6, input);
	if (pow == -111) {
		cout << "\nEnter Integers only !!! Try Again\n";
		goto A2;
	}
	else if (pow == -222) {
		cout << "\nEnter Between 2 and 6 !\n";
		goto A2;
	}
	cout << endl << "A : \n";
	int mid = Mid(Ar);
	for (int i = 0; i < Ar; i++) {
		cout << " | ";
		for (int j = 0; j < Ac; j++) {
			cout << A[i][j] << " ";
		}
		cout << "|\n";
	}
	cout << "\nA^" << pow << " : ";
	int ab = 0;
	if (pow == 2) {
		for (int i = 0; i < Ar; i++) {
			cout << " | ";
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A[i][k] * A[k][j];
				}
				cout << ab << " ";
			}
			cout << "|\n";
		}
	}
	else if (pow == 3) {
		for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A[i][k] * A[k][j];
				}
				A2[i][j] = ab;
			}
		}
		for (int i = 0; i < Ar; i++) {
			cout << " | ";
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A2[i][k] * A[k][j];
				}
				cout << ab << " ";
			}
			cout << "|\n";
		}
	}
	else if (pow == 4) {
		for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A[i][k] * A[k][j];
				}
				A2[i][j] = ab;
			}
		}
		for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A2[i][k] * A[k][j];
				}
				A3[i][j] = ab;
			}
		}
		for (int i = 0; i < Ar; i++) {
			cout << " | ";
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A3[i][k] * A[k][j];
				}
				cout << ab << " ";
			}
			cout << "|\n";
		}
	}
	else if (pow == 5) {
		for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A[i][k] * A[k][j];
				}
				A2[i][j] = ab;
			}
		}
		for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A2[i][k] * A[k][j];
				}
				A3[i][j] = ab;
			}
		}
		for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A3[i][k] * A[k][j];
				}
				A4[i][j] = ab;
			}
		}
		for (int i = 0; i < Ar; i++) {
			cout << " | ";
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A4[i][k] * A[k][j];
				}
				cout << ab << " ";
			}
			cout << "|\n";
		}
	}
	else {
		for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A[i][k] * A[k][j];
				}
				A2[i][j] = ab;
			}
		}
		for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A2[i][k] * A[k][j];
				}
				A3[i][j] = ab;
			}
		}
		for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A3[i][k] * A[k][j];
				}
				A4[i][j] = ab;
			}
		}
		for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A4[i][k] * A[k][j];
				}
				A5[i][j] = ab;
			}
		}
		for (int i = 0; i < Ar; i++) {
			cout << " | ";
			for (int j = 0; j < Ac; j++) {
				ab = 0;
				for (int k = 0; k < Ac; k++) {
					ab += A5[i][k] * A[k][j];
				}
				cout << ab << " ";
			}
			cout << "|\n";
		}
	}
}

void Scalar() {
	string input = "";
	vector<vector<int>> A = size();
	int Ar = A.size(), Ac = A[0].size();
	A1:	for (int i = 0; i < Ar; i++) {
			for (int j = 0; j < Ac; j++) {
				cout << "Enter Value of A[" << i + 1 << "][" << j + 1 << "] : ";
				cin >> input;
				A[i][j] = check(-99999999, 99999999, input);
				if (A[i][j] == -111) {
					cout << "Enter Integers only !!! Try Again";
					goto A1;
				}
			}
	}
	A2: cout << "\nEnter Scalar 'r' : ";
	cin >> input;
	int s = check(-9999999, 9999999, input);
	if (s == -111) {
		cout << "\nEnter Integers only !!! Try Again\n";
		goto A2;
	}
	cout << endl << "A : \n";
	for (int i = 0; i < Ar; i++) {
		cout << " | ";
		for (int j = 0; j < Ac; j++) {
			cout << A[i][j] << " ";
		}
		cout << "|\n";
	}
	cout << "\nr(A) = " << s << "(A) : \n";
	for (int i = 0; i < Ar; i++) {
		cout << " | ";
		for (int j = 0; j < Ac; j++) {
			cout << s * A[i][j] << " ";
		}
		cout << "|\n";
	}
}


