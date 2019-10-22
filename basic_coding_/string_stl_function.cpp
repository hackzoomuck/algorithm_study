//요약

    //isupper : 문자가 대문자 A~Z 사이에 속하는지 검사

	//islower : 문자가 소문자 a~z 사이에 속하는지 검사

	//isalpha : 문자가 대소문자 A~Z, a~z에 속하는지 검사


if (!stricmp(cache[i].c_str(), data.c_str())) { // 대소문자를 구분하지 않고 문자열 비교


//함수 원형 및 설명

int isupper(int c);
//c : 검사할 문자 또는 아스키 값
//반환값 : 문자가 A~Z 사이에 속하면 true, 아니면 false

int islower(int c);
//c : 검사할 문자 또는 아스키 값
//반환값 : 문자가 a~z 사이에 속하면 true, 아니면 false

int isalpha(int c);
//c : 검사할 문자 또는 아스키 값
//반환값 : 문자가 A~Z나 a~z 사이에 속하면 true, 아니면 false


//※예제

#include <stdio.h>
#include <ctype.h>

int main()
{
	bool bCheck = false;
	char strTemp[] = "2T3y4J";

	//isupper
	bCheck = isupper('3');
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = isupper(97);		//97은 문자로 'a'
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = isupper(strTemp[1]);
	printf("%s\n", bCheck ? "True" : "False");

	//islower
	bCheck = islower('3');
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = islower(97);		//97은 문자로 'a'
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = islower(strTemp[1]);
	printf("%s\n", bCheck ? "True" : "False");

	//isalpha
	bCheck = isalpha('3');
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = isalpha(97);		//97은 문자로 'a'
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = isalpha(strTemp[1]);
	printf("%s\n", bCheck ? "True" : "False");

	return 0;
}