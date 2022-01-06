// 18/02/04 = Sun

// Exercise 5.6: Rewrite your grading program to use the conditional operator (§ 4.7, p. 151) in place of the if–else statement.

// Letter scheme:
// 100		A++
// 97-99	A+	93-96	A	90-92	A-
// 87-89	B+	83-86	B	80-82	B-
// 77-79	C+	73-76	C	70-72	C-
// 67-69	D+	63-66	D	60-62	D-
// 0-59		F

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string letter(int n)
{
	const string A = "ABCDF";
	const int N = A.size();
	string a;
	a =  n < 60		? A[N-1]:
		 n >= 100	? A[0] 	: A[(99-n)/10];
	a += n >= 100 	? "++" 	:
		 n < 60 	? ""	:
		 n % 10 < 3	? "-" 	:
		 n % 10 > 6 ? "+" 	: "";
	return a;
}

int main()
{
	for (int score = 100; score >= 0; --score)
		cout << score << " " << letter(score) << (score % 10 ? '\t' : '\n');
	return 0;
}
