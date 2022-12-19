// g++ -o thread thread.cpp -lpthread
#include <iostream>
#include <thread>

using namespace std;

//스레드에 의해 호출되는 함수
void call_from_thread(int tid) {
	cout << "스레드 실행: " << tid << endl;
	std::this_thread::sleep_for(std::chrono::nanoseconds(tid*20));
}

int main(){
	thread t[10];

	//10개의 스레드 시작
	thread(call_from_thread, 0).detach();
	for(int i = 1; i<10; ++i) {
		t[i] = thread(call_from_thread, i);
	}
	cout << "메인 함수 시작" << endl;

	//스레드가 종료될때 까지 대시
	for(int i=1; i<10; ++i) {
		if(t[i].joinable())
			t[i].join();
	}
	return 0;
}

