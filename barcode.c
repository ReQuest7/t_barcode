#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_barcode(int barcode[13]) {
    int odd_sum = 0, even_sum = 0;

    // 홀수 및 짝수 자리 합 계산
    for (int i = 0; i < 12; i++) {
        if (i % 2 == 0) {
            odd_sum += barcode[i];
        }
        else {
            even_sum += barcode[i];
        }
    }

    even_sum *= 3; // 짝수 자리 합을 3배
    int total_sum = odd_sum + even_sum + barcode[12]; // 총합에 검증 숫자 더함

    // 총합이 10의 배수이면 유효
    return (total_sum % 10 == 0);
}

int main() {
    char barcode_str[14];  // 13자리 숫자 + null 종료
    int barcode[13];

    printf("13자리 바코드를 입력하세요: ");

    // 13자리 숫자를 문자열로 받음
    fscanf_s(stdin, "%13s", barcode_str, (unsigned)sizeof(barcode_str));    

    // 문자열을 정수 배열로 변환
    for (int i = 0; i < 13; i++) {
        if (!isdigit(barcode_str[i])) {
            printf("잘못된 입력입니다. 숫자만 입력하세요.\n");
            return 1;
        }
        barcode[i] = barcode_str[i] - '0';  // 문자형 숫자를 정수로 변환
    }

    // 바코드 유효성 검사
    if (is_valid_barcode(barcode)) {
        printf("유효한 바코드입니다.\n");
    }
    else {
        printf("유효하지 않은 바코드입니다.\n");
    }

    return 0;
}
