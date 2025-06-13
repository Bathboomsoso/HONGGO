#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
using namespace std;

vector<int> InputNum() { // 사용자 입력 작동
	vector<int> Num;
	int in = 0;
	for (int i = 0; i < 5; ++i) {
		cout << "입력 : ";
		cin >> in;
		Num.push_back(in);
	}
	return Num;
}

int Sum(vector<int>& Num) { // 모든 배열의 합계
	return accumulate(Num.begin(), Num.end(), 0LL);
}

int Avg(int Sum) { // 모든 배열의 평균 값
	return Sum / 5;
}

vector<int> ValSort(vector<int>& Num) { // sort 함수의 오름차순 
	sort(Num.begin(), Num.end());
	return Num;
}

vector<int> ReversSort(vector<int>& Num) { // sort 함수의 내림차순
	sort(Num.begin(), Num.end(), greater<int>());
	return Num;
}


void ManualSort(vector<int>& Num) {
	int n = Num.size();

	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (Num[j] > Num[j + 1]) {
				swap(Num[j], Num[j + 1]);
			}
		}
	}
	cout << "[ 수동 ]원소의 올림차순 : ";
	Num = ValSort(Num);
	for (int i = 0; i < 5; ++i) {
		cout << Num[i] << " ";
	}
	cout << endl;

	cout << "[ 수동 ]원소의 내림차순 : ";
	Num = ReversSort(Num);
	for (int i = 0; i < 5; ++i) {
		cout << Num[i] << " ";
	}
	cout << endl;
}



void PrintDefualt(vector<int>& Numbers) { // 기본 출력 로직
	cout << "모든 원소의 합 : " << Sum(Numbers) << endl;
	cout << "모든 원소의 평균 : " << Avg(Sum(Numbers)) << endl;
}

void PrintSorts(vector<int>& Numbers) { // 추가 출력로직
	cout << "원소의 올림차순 : ";
	Numbers = ValSort(Numbers);
	for (int i = 0; i < 5; ++i) {
		cout << Numbers[i] << " ";
	}
	cout << endl;

	cout << "원소의 내림차순 : ";
	Numbers = ReversSort(Numbers);
	for (int i = 0; i < 5; ++i) {
		cout << Numbers[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> Numbers;
	Numbers = InputNum();

	PrintDefualt(Numbers); // 기본 출력값 ( 합계, 평균 출력 )
	PrintSorts(Numbers); // 추가 출력값 ( 오름차순, 내림차순 출력 )
	ManualSort(Numbers);
}
