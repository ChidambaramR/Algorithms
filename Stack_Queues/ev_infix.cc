#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <stack>
#include <cassert>


using namespace std;

class Expr{
	string infix;
	string postfix;
	list<string> token;
public:
	Expr(string s);
	void eval_infix();
	int alu(int op1, int op2, char op);
	bool is_num(char c);
	int precedence(char c);
};

int
Expr::precedence(char c)
{
	switch(c) {
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		default: return -99;
	}

	return 0;
}

bool
Expr::is_num(char c)
{
	if (c == '(' || c == ')' || c == '+' || c == '-'
		|| c == '*' || c == '/')
		return false;
	else
		return true;
}

Expr::Expr(string s)
{
	infix = s;
}

int
Expr::alu(int op1, int op2, char op)
{
	switch(op) {
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		default: assert(0);
	}

	return 0;
}

void
Expr::eval_infix()
{
	char inp_arr[1000];
	strncpy(inp_arr, infix.c_str(), infix.length());
	int i;
	int op1, op2;
	char op;
	stack<char> ops;
	stack<int> val;

	for (i = 0; i < infix.length(); i++) {
		//cout << inp_arr[i] << endl;
		if (inp_arr[i] == ' ')
			continue;

		if (is_num(inp_arr[i])) {
			string tmp;
			while (inp_arr[i] >= '0' && inp_arr[i] <= '9') {
				tmp.push_back(inp_arr[i]);
				i++;
			}
			i--;
			val.push(atoi(tmp.c_str()));
			//cout << val.top() << endl;
		} else if (inp_arr[i] == '(') {
			//cout << "(" << endl;
			ops.push(inp_arr[i]);
		} else if (inp_arr[i] == ')') {
			//cout << ")" << endl;
			while (!ops.empty() && ops.top() != '(') {
				op1 = val.top(); val.pop();
				op2 = val.top(); val.pop();
				op = ops.top(); ops.pop();
				val.push(alu(op2, op1, op));
				//cout << val.top() << endl;
			}
			ops.pop();
		} else if (!is_num(inp_arr[i])) {
			//cout << inp_arr[i] << endl;
			if (ops.empty() || ops.top() == '(') {
				ops.push(inp_arr[i]);
			} else {
				while(!ops.empty() && (precedence(inp_arr[i]) <= precedence(ops.top()))) {
					op1 = val.top(); val.pop();
					op2 = val.top(); val.pop();
					op = ops.top(); ops.pop();
					val.push(alu(op2, op1, op));
				}
				ops.push(inp_arr[i]);
			}
		}
	}

	while (!ops.empty()) {
		op1 = val.top(); val.pop();
		op2 = val.top(); val.pop();
		op = ops.top(); ops.pop();
		val.push(alu(op2, op1, op));
	}

	cout << "Result = " << val.top() << endl; 
}

int main()
{
	//string inp("(2-20+5*20)");
	//string inp("100 * ( 2 + 12 ) / 14");
	string inp("10 - 3 + 4");
	Expr e(inp);
	e.eval_infix();
	return 0;
}
