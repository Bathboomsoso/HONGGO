#include <iostream>
#include <string>
#include <algorithm>

template <typename D>

class SimpleVector {
private:
	D* data;
	int CurrPoint = 0;
	int CurrSize = 0;

public:
	SimpleVector(int Size) { // 생성자
		if (Size == 0) {
			Size = 10;

		}
		CurrSize = Size;
		std::cout << "배열 크기가 " << Size << "인 배열이 선언 되었습니다." << std::endl;
		data = nullptr;
		data = new D[CurrSize];
	}

	~SimpleVector() { // 소멸자
		std::cout << "배열이 해제되었습니다." << std::endl;
		delete[] data;
		data = nullptr;
	}

	void Push_Back(D value) { // 푸시백 함수
		std::cout << value << "를 배열 마지막에 추가했습니다." << std::endl;
		data[CurrPoint] = value;
		CurrPoint++;
	}

	void Pop_Back() { // 팝 백 함수
		CurrPoint--;
		if (CurrPoint == -1) {
			std::cout << "배열에 아직 아무것도 없습니다." << std::endl;
			CurrPoint++;
		}
		else {
			std::cout << "배열의 마지막 값을 제외했습니다." << std::endl;
		}
		
	}

	void Size() { // 원수 갯수 출력
		std::cout << "현재 원소의 개수는" << CurrPoint << "개입니다." << std::endl;
	}

	void Capacity() { // 배열 크기 출력
		std::cout << "현재 배열의 크기는" << CurrSize << " 입니다" << std::endl;
	}

	void Display() { // 배열 출력
		std::cout << "현재 배열의 내용 : ";
		for (int i = 0; i < CurrPoint; i++) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}

	void Input() { // 배열 입력
		D input;
		std::cout << "-------------------------" << std::endl;
		std::cout << "입력할 내용을 타이핑" << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cin >> input;
		if (CurrPoint < CurrSize) {
			Push_Back(input);
		}
		else { // 배열 사이즈 확장
			std::cout << "배열이 가득찼습니다. 배열을 5늘린후 PushBack 합니다." << std::endl;
			
			int old = CurrSize;
			CurrSize += 5;
			D* new_data = new D[CurrSize]; // 복사용 배열 생성

			for (int i = 0; i < old; ++i) { // 기존 값 새로운 배열에 추가
				new_data[i] = data[i];
			}
			delete[] data; // 기존 메모리 해제
			data = new_data; // 새로운 메모리 주소 삽입
			new_data = nullptr; // 복사용 포인터 초기화
			Push_Back(input); // 입력받은 값 추가
		}
	}
	void Resize() { // 리사이징 함수
		int val;
		std::cout << "새로운 배열 크기를 입력하세요 : ";
		std::cin >> val;

		if (val < CurrPoint) {
			std::cout << "(" << val << ")가 현재 원소 개수(" << CurrPoint << ")보다 작습니다. 변경하지 않습니다." << std::endl; 
			return;
		}

		D* new_data = new D[val]; // 새 메모리 할당
		new_data = data;
		for (int i = 0; i < CurrSize; ++i) {
			new_data[i] = data[i];
		}

		delete[] data; // 이전 메모리 해제
		data = new_data; // 새로운 메모리 가리키도록 업데이트
		new_data = nullptr; // 복사용 포인터 초기화
		CurrSize = val; // 새로운 크기 반영

		std::cout << "배열 크기가 " << CurrSize << "(으)로 재설정되었습니다." << std::endl;
	}

	void Dosort() { // 정렬 함수
		std::cout << "배열을 정렬합니다." << std::endl;
		std::sort(data, data+CurrPoint);
	}
};
int main() {
	int Size = 0;
	int menu = 0;

	std::cout << "배열의 크기를 지정하세요. (입력값이 없거나 0일경우 10으로 지정됩니다.)" << std::endl;
	std::cin >> Size;

	/* 타입 변환 */
	SimpleVector<int> intvector(Size); // 인티저
	//SimpleVector<double> intvector(Size); // 더블 
	//SimpleVector<std::string> intvector(Size); // 스트링

	while (1) {
		std::cout << "-------------------------" << std::endl;
		std::cout << "1. 값입력 [맨뒤에 추가]" << std::endl;
		std::cout << "2. 값삭제 [맨뒤원소 삭제]" << std::endl;
		std::cout << "3. 모든 값 출력" << std::endl;
		std::cout << "4. 현재 원소 개수" << std::endl;
		std::cout << "5. 현재 배열 크기" << std::endl;
		std::cout << "6. 배열의 크기 리사이징" << std::endl;
		std::cout << "7. 배열 오름차순 정렬" << std::endl;
		std::cout << "8. 프로그램 종료" << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cout << "입력 : ";
		std::cin >> menu;

		switch (menu) {
		case 1:
			intvector.Input();
			std::cout << std::endl;
			break;
		case 2:
			intvector.Pop_Back();
			std::cout << std::endl;
			break;
		case 3:
			intvector.Display();
			std::cout << std::endl;
			break;
		case 4:
			intvector.Size();
			std::cout << std::endl;
			break;
		case 5:
			intvector.Capacity();
			std::cout << std::endl;
			break;
		case 6:
			intvector.Resize();
			std::cout << std::endl;
			break;
		case 7:
			intvector.Dosort();
			break;
		case 8:
			return 0;
			break;
		}
		
	}
}
