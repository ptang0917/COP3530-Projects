#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <sstream>
#include <array>
using namespace std;

bool isOperator(string input) {
	string mathop[] = { "+", "-", "*", "-" };
	for (int i = 0; i < 4; i++) {
		if (input == mathop[i]) {
			return true;
		}
		else {
			return false;
		}

	}
}

void calculating(string s, stack<double> calculator) {
	double lval, rval, result;
	rval = calculator.top();
	calculator.pop();

	lval = calculator.top();
	calculator.pop();

	if (s == "+") {
		result = lval + rval;
	}
	else if (s == "-")
		result = lval - rval;
	else if (s == "*") {
		result = lval * rval;
	}
	else if (s == "/") {
		result = lval / rval;
	}
	cout << result << endl;
	calculator.push(result);
}

int main() {
	stack<double> calculator;
	string s;
	string c;
	double num;
	cout << "Enter Operation " << endl;
	while (true) {
		cin >> s;
		if (istringstream(s) >> num) {
			calculator.push(num);
		}
		else if (isOperator(s)) {
			calculating(s, calculator);
		}

	}


	/*for (int i = 0; i < s.size(); i++) {
		if (isdigit(s.at(i))) {
			
			num = (int)s.at(i);
			num = calculator.top();
			calculator.pop();

		}
		else if (s.at(i) == '+' || s.at(i) == '-' || s.at(i) == '*' || s.at(i) == '/') {
			calculator.push(s.at(i));
		}

	}*/
	return 0;
}
