//���

    //isupper : ���ڰ� �빮�� A~Z ���̿� ���ϴ��� �˻�

	//islower : ���ڰ� �ҹ��� a~z ���̿� ���ϴ��� �˻�

	//isalpha : ���ڰ� ��ҹ��� A~Z, a~z�� ���ϴ��� �˻�


if (!stricmp(cache[i].c_str(), data.c_str())) { // ��ҹ��ڸ� �������� �ʰ� ���ڿ� ��


//�Լ� ���� �� ����

int isupper(int c);
//c : �˻��� ���� �Ǵ� �ƽ�Ű ��
//��ȯ�� : ���ڰ� A~Z ���̿� ���ϸ� true, �ƴϸ� false

int islower(int c);
//c : �˻��� ���� �Ǵ� �ƽ�Ű ��
//��ȯ�� : ���ڰ� a~z ���̿� ���ϸ� true, �ƴϸ� false

int isalpha(int c);
//c : �˻��� ���� �Ǵ� �ƽ�Ű ��
//��ȯ�� : ���ڰ� A~Z�� a~z ���̿� ���ϸ� true, �ƴϸ� false


//�ؿ���

#include <stdio.h>
#include <ctype.h>

int main()
{
	bool bCheck = false;
	char strTemp[] = "2T3y4J";

	//isupper
	bCheck = isupper('3');
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = isupper(97);		//97�� ���ڷ� 'a'
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = isupper(strTemp[1]);
	printf("%s\n", bCheck ? "True" : "False");

	//islower
	bCheck = islower('3');
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = islower(97);		//97�� ���ڷ� 'a'
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = islower(strTemp[1]);
	printf("%s\n", bCheck ? "True" : "False");

	//isalpha
	bCheck = isalpha('3');
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = isalpha(97);		//97�� ���ڷ� 'a'
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = isalpha(strTemp[1]);
	printf("%s\n", bCheck ? "True" : "False");

	return 0;
}