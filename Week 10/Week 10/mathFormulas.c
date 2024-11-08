// mathFormulas.c
#include <stdio.h>
#include <stdlib.h> // atoi() 함수
#include <ctype.h>	// isdigit() 함수

int numCheck(char ch)
{
	return ch >= '0' && ch <= '9'; // 1이나 0반환
}

int checkOp(char op)
{
	return op == '+' || op == '-' || op == '*' || op == '/';
}

int arrayToint(char str[])
{
	int i = 0,
		num = 0;

	// 문자열에 반복하고 모든 문자가 숫자로 변경하기
	while (str[i] != '\0')
	{
		// 숫자인지 확인하기
		if (numCheck(str[i]))
			num = num * 10 + (str[i] - '0');
		else
			break;

		i++; // 다음 문자로 이동하기
	}

	return num;
}

int main(void)
{
	char input[100],
		numStr1[50], numStr2[50],
		operator = '\0'; // 연산자를 NULL로 초기화하기
	int i = 0, // 원래 입력한 문자열의 index 
		j = 0; // 받고 싶은 숫자의 index

	// 사용자한테 수학함수 받기 (예: "12+34")
	printf("Enter a simple math formula (12+34):\n");
	fgets(input, sizeof(input), stdin);

	// #1: 첫 번째 숫자를 추출하기
	while (input[i] != '\0' && numCheck(input[i]))
	{
		numStr1[j++] = input[i++];
	}
	numStr1[j] = '\0';

	// #2: 수학 연산자를 찾기
	if (checkOp(input[i]))
	{
		operator = input[i++];
	}
	else
	{
		printf("Error: Invalidoperator!\n");
		return 1;
	}

	j = 0; // 두 번째 숫자를 받기 위해 초기화하기
	
	// #3: 두 번째 숫자를 추출하기
	while (input[i] != '\0' && numCheck(input[i]))
	{
		numStr2[j++] = input[i++];
	}
	numStr2[j] = '\0';

	/*
	예:
	input = "123+456"
	numStr1 = "123"
	operator = '+'
	numStr2 = "456"
	*/

	// 두 numStr을 숫자로 변경하기
	int num1 = arrayToint(numStr1);
	int num2 = arrayToint(numStr2);
	int result = 0;

	// 계산하기
	switch (operator)
	{
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		if (num2 != 0)
			result = num1 / num2;	// x/0하면 안됩니다..
		else
		{
			printf("Error: division by 0!\n");
			return 1; // 오류 발생!
		}
		break;
	default:
		printf("Error: Invalid operator. Use +, -, *, /.\n");
		return 1; // 오류 발생!
	}

	printf("Result: %d %c %d = %d\n", num1, operator, num2, result);

	return 0;
}