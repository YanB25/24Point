#include <iostream>
#include <string>

using namespace std;

int Number = 4;
int Target_sum = 24;
bool solvable_lock = false;
int number_of_possibility = 0;
class Twenty_four
{
	float not_decided[5];
	string expression[5];
	friend void plus_(class Twenty_four,int i,int j);
	friend void minus_(class Twenty_four,int i, int j);
	friend void multiply(class Twenty_four, int i, int j);
	friend void divide(class Twenty_four, int i, int j);
	friend void Rminus(class Twenty_four, int i, int j);
	friend void Rdivide(class Twenty_four, int i, int j);
	void rearrange();
public:
	Twenty_four();
	void input();
	bool is_twenty_four();
	int print(bool);
	friend int six_operation(class Twenty_four);
	void analysis(float calendate,int i);
}twenty_four;

int length(float a[])
{
	int length = 0;
	int i = 0;
	while (a[i] != 0 )
	{
		length++;
		i++;
	}
	return length;
}

Twenty_four::Twenty_four()
{
	for (int i = 0; i <= Number; i++)
	{
		not_decided[i] = 0;
		expression[i] = "\0";
	}
}

void Twenty_four::analysis(float calendate,int i)//
{
	i--;
	do 
	{
		if (calendate != int(calendate))
		{
			cout << "错误，数字必须为整数，请重新输入：\n";
			cin >> calendate;
			continue;
		}
		if (calendate <= 0)
		{
			cout << "错误，数字必须整数且大于零，请重新输入：\n";
			cin >> calendate;
			continue;
		}
		if (calendate > 13)
		{
			cout << "错误，数字必须整数且小于十三，请重新输入：\n";
			cin >> calendate;
			continue;
		}
		break;
	} while (true);
	not_decided[i] = calendate;
	char temp[3];
	sprintf(temp, "%d", int(calendate));
	expression[i] = temp;
	
}
void Twenty_four::rearrange()
{
	int array_length = Number;
	for(int i=0;i<=array_length-2;i++)
		for (int j = i + 1; j <= array_length - 1; j++)
		{
			if (not_decided[i] == 0)
			{
				float temp = not_decided[i];
				not_decided[i] = not_decided[j];
				not_decided[j] = temp;

				string stemp = expression[i];
				expression[i] = expression[j];
				expression[j] = stemp;
			}
		}
}

void Twenty_four::input()
{
	/*not_decided[0] = 2;
	not_decided[1] = 5;
	not_decided[2] = 5;
	not_decided[3] = 1;
	expression[0] = "2";
	expression[1] = "5";
	expression[2] = "5";
	expression[3] = "1";*/
	cout << "请输入目标数字：\n";
	cin >> Target_sum;
	cout << "请输入备选数目:\n";
	cin >> Number;
	for (int i = 1; i <= Number; i++)
	{
		cout << "请输入第" << i << "个数字\n";
		float candidate;
		cin >> candidate;
		analysis(candidate,i);
	}
	cout << "\n";
}

bool Twenty_four::is_twenty_four()
{
	if(length(not_decided)==1)
		if(not_decided[0]==Target_sum)
			return true;
	return false;
}

int Twenty_four::print(bool a)
{
	if (a == 0)
		return 0;
	solvable_lock = true;
	number_of_possibility++;
	cout << "第"<<number_of_possibility<<"个结果为\t" << expression[0] << "\n";
	return 0;
}



void plus_(class Twenty_four twenty_four, int i,int j)
{
	class Twenty_four new_twenty_four = twenty_four;
	new_twenty_four.not_decided[i] = new_twenty_four.not_decided[i] + new_twenty_four.not_decided[j];
	new_twenty_four.not_decided[j] = 0;
	new_twenty_four.expression[i] = "("+new_twenty_four.expression[i] + "+" + new_twenty_four.expression[j]+")";
	new_twenty_four.expression[j] = "\0";
	new_twenty_four.rearrange();
	six_operation(new_twenty_four);
}

void minus_(class Twenty_four twenty_four,int i, int j)
{
	class Twenty_four new_twenty_four = twenty_four;
	new_twenty_four.not_decided[i] = new_twenty_four.not_decided[i] - new_twenty_four.not_decided[j];
	new_twenty_four.not_decided[j] = 0;
	new_twenty_four.expression[i] ="(" + new_twenty_four.expression[i] + "-" + new_twenty_four.expression[j] + ")";
	new_twenty_four.expression[j] = "\0";
	new_twenty_four.rearrange();
	six_operation(new_twenty_four);
}

void multiply(class Twenty_four twenty_four, int i, int j)
{
	class Twenty_four new_twenty_four = twenty_four;
	new_twenty_four.not_decided[i] = new_twenty_four.not_decided[i] * new_twenty_four.not_decided[j];
	new_twenty_four.not_decided[j] = 0;
	new_twenty_four.expression[i] = new_twenty_four.expression[i] + "*" + new_twenty_four.expression[j];
	new_twenty_four.expression[j] = "\0";
	new_twenty_four.rearrange();
	six_operation(new_twenty_four);
}

void divide(class Twenty_four twenty_four, int i, int j)
{
	class Twenty_four new_twenty_four = twenty_four;
	new_twenty_four.not_decided[i] = new_twenty_four.not_decided[i] / new_twenty_four.not_decided[j];
	new_twenty_four.not_decided[j] = 0;
	new_twenty_four.expression[i] = new_twenty_four.expression[i] + "/" + new_twenty_four.expression[j];
	new_twenty_four.expression[j] = "\0";
	new_twenty_four.rearrange();
	six_operation(new_twenty_four);
}

void Rminus(class Twenty_four twenty_four, int i, int j)
{
	class Twenty_four new_twenty_four = twenty_four;
	new_twenty_four.not_decided[i] = new_twenty_four.not_decided[j] - new_twenty_four.not_decided[i];
	new_twenty_four.not_decided[j] = 0;
	new_twenty_four.expression[i] = "(" + new_twenty_four.expression[j] + "-" + new_twenty_four.expression[i] + ")";
	new_twenty_four.expression[j] = "\0";
	new_twenty_four.rearrange();
	six_operation(new_twenty_four);
}

void Rdivide(class Twenty_four twenty_four, int i, int j)
{
	class Twenty_four new_twenty_four = twenty_four;
	new_twenty_four.not_decided[i] = new_twenty_four.not_decided[j] / new_twenty_four.not_decided[i];
	new_twenty_four.not_decided[j] = 0;
	new_twenty_four.expression[i] = new_twenty_four.expression[j] + "/" + new_twenty_four.expression[i];
	new_twenty_four.expression[j] = "\0";
	new_twenty_four.rearrange();
	six_operation(new_twenty_four);
}

int six_operation(class Twenty_four twenty_four)
{
	int array_length = length(twenty_four.not_decided);
	if (array_length == 1)
	{ 
		bool is_twenty_four = twenty_four.is_twenty_four();
		if(is_twenty_four)
			twenty_four.print(true);
		return 0;
	}
	for(int i=0;i<=array_length -2;i++)
		for (int j = i + 1; j <= array_length - 1; j++)
		{
			plus_(twenty_four, i, j);
			minus_(twenty_four, i, j);
			multiply(twenty_four, i, j);
			divide(twenty_four, i, j);
			Rminus(twenty_four, i, j);
			Rdivide(twenty_four, i, j);
		}
	return 0;
}


int main()
{
	int a;
	do 
	{
		class Twenty_four twenty_four;
		twenty_four.input();
		cout << "求解开始：\n";
		six_operation(twenty_four);
		if (solvable_lock == false)
			cout << "\n此题无解";
		else
			cout << "\n求解完毕\n\n\n";

	} while (true);
	return 0;
}