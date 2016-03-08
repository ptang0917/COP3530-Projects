#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <stack>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>

//#include <main.h>
using namespace std;

bool isNum(const string &symbol)
{
	bool Number = false;
	for (unsigned int i = 0; i < symbol.size(); i++)
	{
		if (isdigit(symbol[i])) {
			Number = true;
		}
		else {
			Number = false;
		}
	}
	return Number;
}


int Priority(const string &c) {
	int order;
	if (c == "^") {
		order = 3;
	}
	else if (c == "*" || c == "/") {
		order = 2;
	}
	else if (c == "+" || c == "-") {
		order = 1;
	}
	else {
		order = 0;
	}
	return order;
}
bool isOperator(const string &c) {
	if (c == "+" || c == "-" || c == "*" || c == "/" || c == "^") {
		return true;
	}
}



void EvaluateExpression(vector<string> outputqueue) {
	stack<double> calculator;
	stack<double> resultstack;
	double n;
	double lVal;
	double rVal;
	double result;
	double answer;
	int start = 0;
	int end = outputqueue.size();
	string place;



	for (int i = 0; i < outputqueue.size(); i++) {
		if (isNum(outputqueue.at(i))) {
			n = stod(outputqueue.at(i));
			calculator.push(n);
		}
		else {
			if (outputqueue.at(i) == "+") {
				lVal = calculator.top();
				calculator.pop();
				rVal = calculator.top();
				calculator.pop();
				result = lVal + rVal;
				calculator.push(result);
			}
			else if (outputqueue.at(i) == "-") {
				lVal = calculator.top();
				calculator.pop();
				rVal = calculator.top();
				calculator.pop();
				result = rVal - lVal;
				calculator.push(result);
			}
			else if (outputqueue.at(i) == "*") {
				lVal = calculator.top();
				calculator.pop();
				rVal = calculator.top();
				calculator.pop();
				result = rVal * lVal;
				calculator.push(result);
			}
			else if (outputqueue.at(i) == "/") {
				lVal = calculator.top();
				calculator.pop();
				rVal = calculator.top();
				calculator.pop();
				result = rVal / lVal;
				if (lVal == 0) {
					cout << "ERROR DIVISION BY ZERO " << endl;
					break;
				}
				else {
					calculator.push(result);
				}
				
			}
			else if (outputqueue.at(i) == "^") {
				lVal = calculator.top();
				calculator.pop();
				rVal = calculator.top();
				calculator.pop();
				result = pow(lVal, rVal);
				calculator.push(result);
			}

		}
		

	}
	answer = calculator.top();
	resultstack.push(answer);
	calculator.pop();
	cout << "result of expression: " << resultstack.top() << endl;
	resultstack.pop();
}


void InFixToPreFix(vector<string> &object) {

	vector<string> outputqueue;
	stack<string> opstack;

	for (int i = 0; i < object.size(); i++) {
		if (isNum(object.at(i))) {
			outputqueue.push_back(object.at(i));
		}
		else {
			if (object.at(i) == "(") {
				opstack.push(object.at(i));
			}
			if (object.at(i) == ")") {
				while (!opstack.empty() && opstack.top() != "(") {
					outputqueue.push_back(opstack.top());
					opstack.pop();
				}
				opstack.pop();
			}
			if (isOperator(object.at(i)) == true) {
				while (!opstack.empty() && Priority(opstack.top()) >= Priority(object.at(i))) {
					outputqueue.push_back(opstack.top());
					opstack.pop();
				}
				opstack.push(object.at(i));
			}
		}

	}

	while (opstack.empty() == false) {
		outputqueue.push_back(opstack.top());
		opstack.pop();
	}

	for (int i = 0; i < outputqueue.size(); i++) {
		cout << outputqueue.at(i);
	}
	EvaluateExpression(outputqueue);

}

int main() {
	string infix;//our infix expression
	vector<string> object;
	
	//infix = "3 ^ 4 + ( 4 / 2 ) * 5";
	//3 ^ 3 + ( 9 - 3 ) * 4
	while (1) {
		getline(cin, infix);
		istringstream iss(infix);

		while (iss) {
			string s;
			iss >> s;
			object.push_back(s);
		}
		InFixToPreFix(object);
	}
	return 0;
}
