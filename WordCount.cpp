#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) {
	int ch, count = 1;
	FILE* fp;
	if ((fp = fopen(argv[2], "r")) == NULL) {
		printf("�ļ� %s ��ʧ�ܣ������ļ����Ƿ�������ȷ��", argv[2]);
		exit(1);
	}
	if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-C") == 0) {
		count = 0;
		while ((ch = getc(fp)) != EOF) {
			count++;
		}
		printf("�ַ��� ����%d��\n", count);
	}
	else if (strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "-W") == 0) {
		while ((ch = getc(fp)) != EOF) {
			if ((ch == ' ') || (ch == ',')) {
				count++;
			}
		}
		printf("������ ����%d��\n", count);
	}
	else {
		printf("��������Ч�����");
	}
	fclose(fp);
	return 0;
}
