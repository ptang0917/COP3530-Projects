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
#include <unordered_map>
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
	return false;
}



double EvaluateExpression(vector<string> outputqueue, unordered_map<string, double> &vars) {
	stack<double> calculator;
	stack<double> resultstack;
	double lVal;
	double rVal;
	double result;
	double answer;
	int start = 0;
	int end = outputqueue.size();
	string place;

	for (int i = 0; i < outputqueue.size(); i++) {
		if (isNum(outputqueue.at(i))) {
			double n = stod(outputqueue.at(i));
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
				result = pow(rVal, lVal);
				calculator.push(result);
			}
			else {
				unordered_map<string, double>::const_iterator findvar = vars.find(outputqueue.at(i));
				if(findvar == vars.end()){
					cout << "Variable undeclared" << endl;
					exit(0);
				
				}
				else {
					double n = vars.at(outputqueue.at(i));
					calculator.push(n);
				}
				
			}

		}


	}
	answer = calculator.top();
	resultstack.push(answer);
	calculator.pop();
	return resultstack.top();
}


vector<string> InFixToPreFix(vector<string> &object) {

	vector<string> outputqueue;
	stack<string> opstack;

	for (int i = 0; i < object.size(); i++) {  //Go thourgh the vector of output stack
		if (isNum(object.at(i))) {
			outputqueue.push_back(object.at(i));
		}
		else {
			if (object.at(i) == "(") {
				opstack.push(object.at(i));
			}
			else if (object.at(i) == ")") {
				while (!opstack.empty() && opstack.top() != "(") {
					outputqueue.push_back(opstack.top());  //any other operator is being placed to the outputvector instead of '('
					opstack.pop();
				}
				opstack.pop();
			}
			else if (isOperator(object.at(i)) == true) {
				while (!opstack.empty() && Priority(opstack.top()) >= Priority(object.at(i))) {
					outputqueue.push_back(opstack.top());
					opstack.pop();
				}
				opstack.push(object.at(i));
			}
			else { // we have a variable!
				outputqueue.push_back(object.at(i));
			}
		}

	}

	while (opstack.empty() == false) {
		outputqueue.push_back(opstack.top());
		opstack.pop();
	}

	// uncomment this section for debugging the prefix
	//    for (int i = 0; i < outputqueue.size(); i++) {
	//        cout << outputqueue.at(i);
	//    }
	return outputqueue;
}

int main() {
	
	unordered_map<string, double> variables_table;
	while (1) { //the while(1) is to prevent visual studios from closing terminal
		string infix;//our infix expression
		vector<string> line;
		getline(cin, infix);
		istringstream iss(infix);

		while (iss) { //reads the entire string 
			string s; 
			iss >> s;
			if (s != "") {
				line.push_back(s); //add the string to the vector
			}
		}
		if (line.at(0) == "let") { // here is where we execute the let statement
			vector<string> let_line;
			string name = line.at(1);
			for (int i = 3; i < line.size(); i++) { // we start from 3 because object[2] is "="
				let_line.push_back(line.at(i));
			}
			vector<string> prefix_line = InFixToPreFix(let_line);
			variables_table[name] = EvaluateExpression(prefix_line, variables_table);
		}
		else if (line.at(0) == "quit" || line.at(0) == "Quit") {
			exit(0);
		}
		else {
			vector<string> prefix_line = InFixToPreFix(line);
			cout << EvaluateExpression(prefix_line, variables_table) << endl;
		}
	}
	return 0;
}
