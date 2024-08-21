def is_valid_barcode(barcode):
    # 바코드는 문자열이어야 하며 길이는 13자리여야 함
    if len(barcode) != 13 or not barcode.isdigit():
        return False

    # 홀수번째 자리 숫자 합 계산
    odd_sum = sum(int(barcode[i]) for i in range(0, 12, 2))
    
    # 짝수번째 자리 숫자 합 계산 (마지막 자리는 제외)
    even_sum = sum(int(barcode[i]) for i in range(1, 12, 2)) * 3

    # 총합 계산 (검증 숫자 포함)
    total_sum = odd_sum + even_sum + int(barcode[-1])

    # 총합이 10의 배수이면 유효한 바코드
    return total_sum % 10 == 0


barcode = input("코드를 입력하세요: ")
if is_valid_barcode(barcode):
    print("유효한 바코드입니다.")
else:
    print("유효하지 않은 바코드입니다.")
