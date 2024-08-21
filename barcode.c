#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_barcode(int barcode[13]) {
    int odd_sum = 0, even_sum = 0;

    // Ȧ�� �� ¦�� �ڸ� �� ���
    for (int i = 0; i < 12; i++) {
        if (i % 2 == 0) {
            odd_sum += barcode[i];
        }
        else {
            even_sum += barcode[i];
        }
    }

    even_sum *= 3; // ¦�� �ڸ� ���� 3��
    int total_sum = odd_sum + even_sum + barcode[12]; // ���տ� ���� ���� ����

    // ������ 10�� ����̸� ��ȿ
    return (total_sum % 10 == 0);
}

int main() {
    char barcode_str[14];  // 13�ڸ� ���� + null ����
    int barcode[13];

    printf("13�ڸ� ���ڵ带 �Է��ϼ���: ");

    // 13�ڸ� ���ڸ� ���ڿ��� ���� (fscanf_s�� ������ �Է��� ����)
    fscanf_s(stdin, "%13s", barcode_str, (unsigned)sizeof(barcode_str));    

    // ���ڿ��� ���� �迭�� ��ȯ
    for (int i = 0; i < 13; i++) {
        if (!isdigit(barcode_str[i])) {
            printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
            return 1;
        }
        barcode[i] = barcode_str[i] - '0';  // ������ ���ڸ� ������ ��ȯ
    }

    // ���ڵ� ��ȿ�� �˻�
    if (is_valid_barcode(barcode)) {
        printf("��ȿ�� ���ڵ��Դϴ�.\n");
    }
    else {
        printf("��ȿ���� ���� ���ڵ��Դϴ�.\n");
    }

    return 0;
}
