// getMyString.c
#include <stdio.h>

#define MAX_CH 20

int getMyString(char buffer[], int limit);

int main(void)
{
	char input_string[MAX_CH];
	int state;	// 사용자에게 최대 MAX_CH까지만 입력받겠다고 제한함

	state = getMyString(input_string, MAX_CH);

	if (state)
		printf("input: %s\n", input_string);
	else
		printf("input: %s -> out of range\n", input_string);

	return 0;
}


int getMyString(char buffer[], int limit)
{
	int i;
	for (i = 0; i < limit; i++)
	{
		buffer[i] = getchar();
		if (buffer[i] == '\n')
		{
			buffer[i] = 0; // [ENTER] 키 위치에 0을 넣어서 문자열을 완성함
			return 1; // 정상적으로 입력이 완료됨
		}
	}
	buffer[i] = 0;
	rewind(stdin);
	return 0; // 입력 초과 현상이 발생했음을 알림
}