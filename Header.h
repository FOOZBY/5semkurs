#include <string>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

char is_operation(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string inf_to_post(string str)//inf to post
{
	string res = "";
	stack<char> stck;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			stck.push(str[i]);
		}
		if (str[i] == ')')
		{
			while (!stck.empty() && stck.top() != '(')
			{
				res.push_back(stck.top());
				res.push_back(' ');
				stck.pop();
			}
			stck.pop();
		}
		if (str[i] == '^')
		{
			while (!stck.empty() && stck.top() == '^')
			{
				res.push_back(stck.top());
				res.push_back(' ');
				stck.pop();
			}
			stck.push(str[i]);
		}
		if (str[i] == '*' || str[i] == '/')
		{
			while (!stck.empty() && (stck.top() == '^' || stck.top() == '*' || stck.top() == '/'))
			{
				res.push_back(stck.top());
				res.push_back(' ');
				stck.pop();
			}
			stck.push(str[i]);
		}
		if (str[i] == '+' || str[i] == '-')
		{
			stck.push(str[i]);
		}
		if (isdigit(str[i]) || str[i] == ',')
		{
			while (isdigit(str[i]) || str[i] == ',')
			{
				res.push_back(str[i]);
				i++;
			}
			res.push_back(' ');
			i--;
		}
	}
	while (!stck.empty())
	{
		res.push_back(stck.top());
		res.push_back(' ');
		stck.pop();
	}
	return res;
}

string pre_to_post(string str)
{
	stack<string> s;
	stack<char> digit;
	// length of expression
	int length = str.length();
	string temp1;

	// reading from right to left
	for (int i = length - 1; i >= 0; i--)
	{
		// check if symbol is operator
		if (is_operation(str[i]))
		{
			// pop two operands from stack
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();

			// concat the operands and operator
			string temp = op1 + ' ' + op2 + ' ' + str[i];

			// Push string temp back to stack
			s.push(temp);
		}

		// if symbol is an operand
		else if (isdigit(str[i]) || str[i] == ',')
		{
			while (isdigit(str[i]) || str[i] == ',')
			{
				digit.push(str[i]);
				i--;
			}
			while (!digit.empty())
			{
				temp1 += digit.top();
				digit.pop();
			}
			i++;
			// push the operand to the stack
			s.push(temp1);
			temp1 = "";
		}
	}

	// stack contains only the Postfix expression
     return s.top();
}

string post_to_post(string str)
{
	return str;
}

float calc(float op1, float op2, char oper)
{
	switch (oper)
	{
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '^':
		return pow(op1,op2);
	}
}

void count_post(string str)
{
	stack<float> stck;
	string temp;
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) || str[i] == ',')
		{
			while (isdigit(str[i]) || str[i] == ',')
			{
				temp.push_back(str[i]);
				i++;
			}
			i--;
			stck.push(stof(temp));
		}
		if (is_operation(str[i]))
		{
			float op2 = stck.top();
			stck.pop();
			float op1 = stck.top();
			stck.pop();
			float res = calc(op1, op2, str[i]);
			stck.push(res);
		}
		temp = "";
	}
	cout << "Result = " << stck.top() << endl;
}