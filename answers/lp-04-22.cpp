// 18/02/03 = Sat

// Exercise 4.22: Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more if statements. Which version do you think is easier to understand and why?

// The version with more if statements, because nested conditional operators may heavily reduce readability.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void final_grade_1(int grade)
{
	cout << (grade >= 90 ? "high pass" : 
			grade > 75 ? "pass" :
			grade >= 60 ? "low pass" : "fail") << endl;
}

void final_grade_2(int grade)
{
	if (grade >= 90)
		cout << "high pass";
	else if (grade > 75)
		cout << "pass";
	else if (grade >= 60)
		cout << "low pass";
	else
		cout << "fail";
	cout << endl;
}

int main()
{
	void (*pgrade)(int);
	pgrade = final_grade_2;
	for (int grade; cin >> grade; pgrade(grade))
		;
	return 0;
}

