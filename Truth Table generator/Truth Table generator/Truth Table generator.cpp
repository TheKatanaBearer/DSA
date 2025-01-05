#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int anD(int, int);
int oR(int, int);
int noT(int);
int imply(int, int);
int biCondition(int, int);
void finalPrint(int a[8], int b[8], int c[8], int res[8], int fin[8]);
const int len = 8;
int main()
{
	int p[len] = { 1,1,1,1,0,0,0,0 };
	int q[len] = { 1,1,0,0,1,1,0,0 };
	int r[len] = { 1,0,1,0,1,0,1,0 };
	int ParenthesisResult[8] = {};
	int FINALRESULT[8] = {};
	int P[8] = {};
	int Q[8] = {};
	int R[8] = {};
	cout << "ENTER ! for Negation " << endl;
	cout << "ENTER & for AND " << endl;
	cout << "ENTER => for IMPLICATION " << endl;
	cout << "ENTER | for OR " << endl;
	cout << "ENTER <=> for BICONDITION " << endl;
	string propostion;
	cout << "Enter Proposition : ";
	getline(cin, propostion);
	int bracket1, bracket2;
	// FINDING WHETHER THERE IS NOT IN THE STRING 
	for (int i = 0; i < propostion.length(); i++) {

		if (propostion[i] == '!' && propostion[i + 1] == 'p') {
			for (int j = 0; j < 8; j++) {
				P[j] = noT(p[j]);
			}

		}
		else if (propostion[i] != '!' && propostion[i + 1] == 'p') {
			for (int j = 0; j < 8; j++) {
				P[j] = p[j];
			}
		}
	}

	for (int i = 0; i < propostion.length(); i++) {

		if (propostion[i] == '!' && propostion[i + 1] == 'q') {
			for (int j = 0; j < 8; j++) {
				Q[j] = noT(q[j]);
			}

		}
		else if (propostion[i] != '!' && propostion[i + 1] == 'q') {
			for (int j = 0; j < 8; j++) {
				Q[j] = q[j];
			}
		}
	}

	for (int i = 0; i < propostion.length(); i++) {

		if (propostion[i] == '!' && propostion[i + 1] == 'r') {
			for (int j = 0; j < 8; j++) {
				R[j] = noT(r[j]);
			}

		}
		else if (propostion[i] != '!' && propostion[i + 1] == 'r') {
			for (int j = 0; j < 8; j++) {
				R[j] = r[j];
			}
		}

	}

	/////                        FINDING INDEX OF BRACKETS
	for (int i = 0; i < propostion.length(); i++) {
		if (propostion[i] == '(') {
			for (int j = i; j < propostion.length(); j++) {
				if (propostion[j] == ')') {
					bracket1 = i;
					bracket2 = j;
				}
			}
		}
	}
	///                      TO CHECK WHICH VARIABLES ARE IN THE PROPOSITION 
	int index1, index2;
	char var1, var2;
	for (int i = bracket1; i < bracket2; i++) {
		if (propostion[i] == 'p') {
			for (int j = i + 1; j < bracket2; j++) {
				if (propostion[j] == 'q') {
					index1 = i;
					index2 = j;
					var1 = 'p';
					var2 = 'q';
				}
			}
		}

		else if (propostion[i] == 'q') {
			for (int j = i; j < bracket2; j++) {
				if (propostion[j] == 'r') {
					index1 = i;
					index2 = j;
					var1 = 'q';
					var2 = 'r';
				}
			}
		}
		else if (propostion[i] == 'p') {
			for (int j = i; j < bracket2; j++) {
				if (propostion[j] == 'r') {
					index1 = i;
					index2 = j;
					var1 = 'p';
					var2 = 'r';
				}
			}
		}
		else if (propostion[i] == 'q') {
			for (int j = i; j < bracket2; j++) {
				if (propostion[j] == 'p') {
					index1 = i;
					index2 = j;
					var1 = 'p';
					var2 = 'q';
				}
			}
		}
		else if (propostion[i] == 'r') {
			for (int j = i; j < bracket2; j++) {
				if (propostion[j] == 'q') {
					index1 = i;
					index2 = j;
					var1 = 'q';
					var2 = 'r';
				}
			}
		}
		else if (propostion[i] == 'r') {
			for (int j = i; j < bracket2; j++) {
				if (propostion[j] == 'p') {
					index1 = i;
					index2 = j;
					var1 = 'p';
					var2 = 'r';
				}
			}
		}
	}
	for (int i = index1; i < index2; i++) {
		// FOR AND
		if (propostion[i] == 'p' && propostion[i + 1] == '&' && (propostion[i + 2] == 'q' || propostion[i + 3] == 'q')) {
			for (int j = 0; j < 8; j++) {
				ParenthesisResult[j] = anD(P[j], Q[j]);
			}
		}
		else if (propostion[i] == 'q' && propostion[i + 1] == '&' && (propostion[i + 2] == 'r' || propostion[i + 3] == 'r')) {
			for (int j = 0; j < 8; j++) {
				ParenthesisResult[j] = anD(Q[j], R[j]);
			}
		}
		else if (propostion[i] == 'p' && propostion[i + 1] == '&' && (propostion[i + 2] == 'r' || propostion[i + 3] == 'r')) {
			for (int j = 0; j < 8; j++) {
				ParenthesisResult[j] = anD(P[j], R[j]);
			}
		}
		// FOR OR
		if (propostion[i] == 'p' && propostion[i + 1] == '|' && (propostion[i + 2] == 'q' || propostion[i + 3] == 'q')) {
			for (int j = 0; j < 8; j++) {
				ParenthesisResult[j] = oR(P[j], Q[j]);
			}
		}
		else if (propostion[i] == 'q' && propostion[i + 1] == '|' && (propostion[i + 2] == 'r' || propostion[i + 3] == 'r')) {
			for (int j = 0; j < 8; j++) {
				ParenthesisResult[j] = oR(Q[j], R[j]);
			}
		}
		else if (propostion[i] == 'p' && propostion[i + 1] == '|' && (propostion[i + 2] == 'r' || propostion[i + 3] == 'r')) {
			for (int j = 0; j < 8; j++) {
				ParenthesisResult[j] = oR(P[j], R[j]);
			}
		}
		// FOR IMPLIES 
		if (propostion[i] == 'p' && propostion[i + 1] == '=' && propostion[i + 2] == '>' && (propostion[i + 3] == 'q' || propostion[i + 4] == 'q')) {
			for (int j = 0; j < 8; j++) {
				ParenthesisResult[j] = imply(P[j], Q[j]);
			}
		}
		else if (propostion[i] == 'q' && propostion[i + 1] == '=' && propostion[i + 2] == '>' && (propostion[i + 3] == 'r' || propostion[i + 4] == 'r')) {
			for (int j = 0; j < 8; j++) {
				ParenthesisResult[j] = imply(Q[j], R[j]);
			}
		}
		else if (propostion[i] == 'p' && propostion[i + 1] == '=' && propostion[i + 2] == '>' && (propostion[i + 3] == 'r' || propostion[i + 4] == 'r')) {
			for (int j = 0; j < 8; j++) {
				ParenthesisResult[j] = imply(P[j], R[j]);
			}
		}
		// FOR BICONDITION 
		if (propostion[i] == 'p' && propostion[i + 1] == '<' && propostion[i + 2] == '=' && propostion[i + 3] == '>' && (propostion[i + 4] == 'q' || propostion[i + 5] == 'q')) {
			for (int j = 0; j < 8; j++) {
				ParenthesisResult[j] = biCondition(P[j], Q[j]);
			}
		}
		else if (propostion[i] == 'q' && propostion[i + 1] == '<' && propostion[i + 2] == '=' && propostion[i + 3] == '>' && (propostion[i + 4] == 'r' || propostion[i + 5] == 'r')) {
			for (int j = 0; j < 8; j++) {
				ParenthesisResult[j] = biCondition(Q[j], R[j]);
			}
		}
		else if (propostion[i] == 'p' && propostion[i + 1] == '<' && propostion[i + 2] == '=' && propostion[i + 3] == '>' && (propostion[i + 4] == 'r' || propostion[i + 5] == 'r')) {
			for (int j = 0; j < 8; j++) {
				ParenthesisResult[j] = biCondition(P[j], R[j]);
			}
		}

	}


	for (int i = index2; i < propostion.length(); i++) {
		if (propostion[i] == '&') {
			for (int j = i; j < propostion.length(); j++) {
				if (propostion[j] == 'r') {
					for (int k = 0; k < 8; k++) {
						FINALRESULT[k] = anD(ParenthesisResult[k], R[k]);
					}
				}
				else if (propostion[j] == 'q') {
					for (int k = 0; k < 8; k++) {
						FINALRESULT[k] = anD(ParenthesisResult[k], Q[k]);
					}
				}
				else if (propostion[j] == 'p') {
					for (int k = 0; k < 8; k++) {
						FINALRESULT[k] = anD(ParenthesisResult[k], P[k]);
					}
				}

			}

		}
		else if (propostion[i] == '|') {
			for (int j = i; j < propostion.length(); j++) {
				if (propostion[j] == 'r') {
					for (int k = 0; k < 8; k++) {
						FINALRESULT[k] = oR(ParenthesisResult[k], R[k]);
					}
				}
				else if (propostion[j] == 'q') {
					for (int k = 0; k < 8; k++) {
						FINALRESULT[k] = oR(ParenthesisResult[k], Q[k]);
					}
				}
				else if (propostion[j] == 'p') {
					for (int k = 0; k < 8; k++) {
						FINALRESULT[k] = oR(ParenthesisResult[k], P[k]);
					}
				}
			}
		}

		else if (propostion[i] == '=' && propostion[i + 1] == '>') {
			for (int j = i; j < propostion.length(); j++) {
				if (propostion[j] == 'r') {
					for (int k = 0; k < 8; k++) {
						FINALRESULT[k] = imply(ParenthesisResult[k], R[k]);
					}
				}
				else if (propostion[j] == 'q') {
					for (int k = 0; k < 8; k++) {
						FINALRESULT[k] = imply(ParenthesisResult[k], Q[k]);
					}
				}
				else if (propostion[j] == 'p') {
					for (int k = 0; k < 8; k++) {
						FINALRESULT[k] = imply(ParenthesisResult[k], P[k]);
					}
				}
			}
		}

		else if (propostion[i] == '<' && propostion[i + 1] == '=' && propostion[i + 2] == '>') {
			for (int j = i; j < propostion.length(); j++) {
				if (propostion[j] == 'r') {
					for (int k = 0; k < 8; k++) {
						FINALRESULT[k] = biCondition(ParenthesisResult[k], R[k]);
					}
				}
				else if (propostion[j] == 'q') {
					for (int k = 0; k < 8; k++) {
						FINALRESULT[k] = biCondition(ParenthesisResult[k], Q[k]);
					}
				}
				else if (propostion[j] == 'p') {
					for (int k = 0; k < 8; k++) {
						FINALRESULT[k] = biCondition(ParenthesisResult[k], P[k]);
					}
				}
			}
		}
	}
	finalPrint(p, q, r, ParenthesisResult, FINALRESULT);


	return 0;
}

void finalPrint(int a[8], int b[8], int c[8], int res[8], int fin[8])
{
	int columnWidth = 15;
	cout << left << setw(columnWidth) << "p" << setw(columnWidth) << "q" << setw(columnWidth) << "r" << setw(columnWidth) << "Before R" << setw(columnWidth) << "R" << endl;
	cout << string(5 * columnWidth, '-') << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << setw(columnWidth) << a[i] << setw(columnWidth) << b[i] << setw(columnWidth) << c[i] << setw(columnWidth) << res[i] << setw(columnWidth) << fin[i] << endl;
	}
	cout << string(5 * columnWidth, '-') << endl;
}
int anD(int a, int b) {
	int c;
	if (a == 1 && b == 1) {
		c = 1;
	}
	else {
		c = 0;
	}
	return c;

}
int oR(int a, int b) {
	int c;
	if (a == 0 && b == 0) {
		c = 0;
	}
	else {
		c = 1;
	}
	return c;

}
int XoR(int a, int b) {
	if (a == b) {
		return 0;
	}
	return 1;

}
int noT(int a) {
	int b;
	if (a == 1) {
		b = 0;
	}
	else {
		b = 1;
	}
	return b;
}
int imply(int a, int b) {
	int c = 1;
	if (a == 1 && b == 0) {
		c = 0;
	}
	else {
		c = 1;
	}
	return c;
}
int biCondition(int a, int b) {
	int c = 0;
	if (a == 1 && b == 1) {
		c = 1;
	}
	else if (a == 0 && b == 0) {
		c = 1;
	}
	else {
		c = 0;
	}
	return c;
}