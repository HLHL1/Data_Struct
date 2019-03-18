
#define text
 
#include<iostream>
#include<string>
#include<vector>
#include<stack>
 
 
using namespace std;
 
stack<char> CharStory;//??????
stack<long> CalculateStory;//????????
vector<string> PostFix;//???????;
 
void init()
{
	char tempc = cin.peek();
	bool IsNumCarry = false;//?????????
	while (cin.peek() != '\n')//??????
	{
		cin.get(tempc);
		switch (tempc)
		{
		case '+':case  '-'://???????????
		{
					 if (CharStory.size() > 0&&CharStory.top()!='('){
						 PostFix.push_back("");
						 PostFix[PostFix.size() - 1] +=CharStory.top();
						 CharStory.pop();
					 }
					 IsNumCarry = false;
					 CharStory.push(tempc);
		}
			break;
		case '*':case  '/'://?????????
		{
					 if (CharStory.size()<1 || CharStory.top() == '+' || CharStory.top() == '-'&&CharStory.top() != '(')//?????????????????
					 {
						 IsNumCarry = false;
						 CharStory.push(tempc);
					 }
					 else{
						 if (CharStory.size() > 0){
							 PostFix.push_back("");
							 PostFix[PostFix.size() - 1] += CharStory.top();
							 CharStory.pop();
							 IsNumCarry = false;
							 CharStory.push(tempc);
						 }
					 }
		}
			break;
		case '^'://?????????
		{
					 if (CharStory.size()<1 || CharStory.top() == '+' || CharStory.top() == '-'&&CharStory.top() != '(' || CharStory.top() == '*' || CharStory.top() == '/')//?????????????????
					 {
						 IsNumCarry = false;
						 CharStory.push(tempc);
					 }
					 else{
						 if (CharStory.size() > 0){
							 PostFix.push_back("");
							 PostFix[PostFix.size() - 1] += CharStory.top();
							 CharStory.pop();
							 IsNumCarry = false;
							 CharStory.push(tempc);
						 }
					 }
		}
			break;
 
 
		case '1':case '2':case '3':case'4':case '5':case '6':case'7':case'8':case'9':case'0'://????????
		{
 
					 if (IsNumCarry)
						 PostFix[PostFix.size() - 1] += tempc;
					 else
					 {
						 PostFix.push_back("");
						 PostFix[PostFix.size() - 1] += tempc;
					 }
					 IsNumCarry = true;
		}
			break;
		case '('://(????
		{
					 IsNumCarry = false;
			CharStory.push(tempc);
		}break;
 
		case ')':{//??)??????(
					 { IsNumCarry = false;
						 while (CharStory.size()>0&&CharStory.top() != '(')
						 {
							 PostFix.push_back("");
							 PostFix[PostFix.size() - 1] += CharStory.top();
							 CharStory.pop();
						 }
						 CharStory.pop();//??(
					 }
		}
			break;
		default:
			break;
		}
	}
	while (CharStory.size() > 0)
	{
		PostFix.push_back("");
		PostFix[PostFix.size() - 1] += CharStory.top();
		CharStory.pop();
	}
#ifdef text
	for (int i = 0; i < PostFix.size(); i++)
	{
		cout << PostFix[i];
	}
#endif
 
}
 
long ChangToLongInt(string temp)
{
	long back=0;
	for (int i = 0; i < temp.size(); i++)
	{
		back << 1;
		back += temp[i] - '0';
	}
	return back;
}
void count()
{
	long temp;
	for (auto i:PostFix)
	{
		if (i != "+" &&i != "-" &&i != "*" &&i != "/" &&i != "^")
		{
			CalculateStory.push(ChangToLongInt(i));
		}
		else
		{
			if (i == "*")
			{
				temp = CalculateStory.top();
				CalculateStory.pop();
				temp *= CalculateStory.top();
				CalculateStory.pop();
			}
			if (i == "/")
			{
				temp = CalculateStory.top();
				CalculateStory.pop();
				temp /= CalculateStory.top();
				CalculateStory.pop();
			}
			if (i == "+")
			{
				temp = CalculateStory.top();
				CalculateStory.pop();
				temp += CalculateStory.top();
				CalculateStory.pop();
			}
			if (i == "-")
			{
				temp = CalculateStory.top();
				CalculateStory.pop();
				temp -= CalculateStory.top();
				CalculateStory.pop();
			}
			if (i == "^")
			{
				temp = CalculateStory.top();
				CalculateStory.pop();
				temp = pow(temp,CalculateStory.top());
				CalculateStory.pop();
			}
			CalculateStory.push(temp);
		}
	}
	cout << temp;
 
}
 
int main()
{
	cout << "Plase enter the fomulation:" << endl;
	init();
	cout << "=";
	count();
#ifdef text
	system("pause");
#endif
	return 0;
}
 
 
