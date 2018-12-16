#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int iPreviousMove = -1;
static int iUpCount = 0;
static int iDownCount = 0;
static int iRightCount = 0;
static int iLeftCount = 0;

void FindEscape(string* strArrayMaze, int* iPosEscape) {
	for (int i = 0; i<3; i++) {
		string strTemp = strArrayMaze[i];
		if (strTemp.find("e") != strTemp.npos) {
			iPosEscape[0] = i;
			iPosEscape[1] = (int)strTemp.find("e");
			return;
		}
	}
	return;
}

string FindRightMove(int* iPosEscape) {
	int x = iPosEscape[0];
	int y = iPosEscape[1];
	if (y>1) {
		iPreviousMove = 2;
		iRightCount++;
		return "RIGHT";
	}
	if (y<1) {
		iPreviousMove = 1;
		iLeftCount++;
		return "LEFT";
	}
	if (x>1) {
		iPreviousMove = 0;
		iUpCount++;
		return "UP";
	}
	if (x<1) {
		iPreviousMove = 3;
		iDownCount++;
		return "DOWN";
	}
	return "UP";//This is of no significance
}

string MakeMove(int iValue) {
	if (iValue == 1) {
		iPreviousMove = 0;
		iUpCount++;
		return "UP";
	}
	if (iValue == 10) {
		iPreviousMove = 1;
		iLeftCount++;
		return "LEFT";
	}
	if (iValue == 100) {
		iPreviousMove = 2;
		iRightCount++;
		return "RIGHT";
	}
	if (iValue == 1000) {
		iPreviousMove = 3;
		iDownCount++;
		return "DOWN";
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (iValue == 11) {
		if (iPreviousMove == 3) {
			iPreviousMove = 1;
			iLeftCount++;
			return "LEFT";
		}
		iPreviousMove = 0;
		iUpCount++;
		return "UP";
	}
	if (iValue == 101) {
		if (iPreviousMove == 3) {
			iPreviousMove = 2;
			iRightCount++;
			return "RIGHT";
		}
		iPreviousMove = 0;
		iUpCount++;
		return "UP";
	}
	if (iValue == 1001) {
		if (iPreviousMove == 3) {
			iPreviousMove = 3;
			iDownCount++;
			return "DOWN";
		}
		iPreviousMove = 0;
		iUpCount++;
		return "UP";
	}
	if (iValue == 1010) {
		if (iPreviousMove == 0) {
			iPreviousMove = 1;
			iLeftCount++;
			return "LEFT";
		}
		iPreviousMove = 3;
		iDownCount++;
		return "DOWN";
	}
	if (iValue == 110) {
		if (iPreviousMove == 2) {
			iPreviousMove = 2;
			iRightCount++;
			return "RIGHT";
		}
		iPreviousMove = 1;
		iLeftCount++;
		return "LEFT";
	}
	if (iValue == 1100) {
		if (iPreviousMove == 0) {
			iPreviousMove = 2;
			iRightCount++;
			return "RIGHT";
		}
		iPreviousMove = 3;
		iDownCount++;
		return "DOWN";
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (iValue == 111) {
		if (iPreviousMove == 1 || iPreviousMove == 2) {
			iPreviousMove = 0;
			iUpCount++;
			return "UP";
		}
		if (iLeftCount>iRightCount) {
			iPreviousMove = 1;
			iLeftCount++;
			return "LEFT";
		}
		iPreviousMove = 2;
		iRightCount++;
		return "RIGHT";
	}
	if (iValue == 1011) {
		if (iPreviousMove == 0 || iPreviousMove == 3) {
			iPreviousMove = 1;
			iLeftCount++;
			return "LEFT";
		}
		if (iUpCount>iDownCount) {
			iPreviousMove = 0;
			iUpCount++;
			return "UP";
		}
		iPreviousMove = 3;
		iDownCount++;
		return "DOWN";
	}
	if (iValue == 1101) {
		if (iPreviousMove == 0 || iPreviousMove == 3) {
			iPreviousMove = 2;
			iRightCount++;
			return "RIGHT";
		}
		if (iUpCount>iDownCount) {
			iPreviousMove = 0;
			iUpCount++;
			return "UP";
		}
		iPreviousMove = 3;
		iDownCount++;
		return "DOWN";
	}
	if (iValue == 1110) {
		if (iPreviousMove == 1 || iPreviousMove == 2) {
			iPreviousMove = 3;
			iDownCount++;
			return "DOWN";
		}
		if (iLeftCount>iRightCount) {
			iPreviousMove = 1;
			iLeftCount++;
			return "LEFT";
		}
		iPreviousMove = 2;
		iRightCount++;
		return "RIGHT";
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (iValue == 1111) {
		if (iPreviousMove == 0) {
			iUpCount++;
			return "UP";
		}
		if (iPreviousMove == 1) {
			iLeftCount++;
			return "LEFT";
		}
		if (iPreviousMove == 2) {
			iRightCount++;
			return "RIGHT";
		}
		if (iPreviousMove == 3) {
			iDownCount++;
			return "DOWN";
		}
	}
	return "UP";//This is of no significance
}

string FindRightMoveWithoutEscape(string* strArrayMaze) {
	char* pCStrLine1 = (char*)strArrayMaze[0].c_str();
	char* pCStrLine2 = (char*)strArrayMaze[1].c_str();
	char* pCStrLine3 = (char*)strArrayMaze[2].c_str();
	int iValue = 0;
	if (pCStrLine1[1] == '-') {
		if (iPreviousMove == -1) {
			iPreviousMove = 0;
			iUpCount++;
			return "UP";
		}
		iValue += 1;
	}
	if (pCStrLine2[0] == '-') {
		if (iPreviousMove == -1) {
			iPreviousMove = 1;
			iLeftCount++;
			return "LEFT";
		}
		iValue += 10;
	}
	if (pCStrLine2[2] == '-') {
		if (iPreviousMove == -1) {
			iPreviousMove = 2;
			iRightCount++;
			return "RIGHT";
		}
		iValue += 100;
	}
	if (pCStrLine3[1] == '-') {
		if (iPreviousMove == -1) {
			iPreviousMove = 3;
			iDownCount++;
			return "DOWN";
		}
		iValue += 1000;
	}
	return MakeMove(iValue);
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string strID;
	string strArrayMaze[3];
	cin >> strID;
	for (int i = 0; i<3; i++) {
		cin >> strArrayMaze[i];
	}
	int iPosEscape[2] = { -1,-1 };
	FindEscape(strArrayMaze, iPosEscape);
	if (iPosEscape[0]>-1) {
		string strMove = "";
		strMove = FindRightMove(iPosEscape);
		cout << strMove << endl;
		return 0;
	}
	string strMove = "";
	strMove = FindRightMoveWithoutEscape(strArrayMaze);
	cout << strMove << endl;
	return 0;
}
