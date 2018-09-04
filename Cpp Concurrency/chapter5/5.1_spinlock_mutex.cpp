#include <atomic>
#include <mutex>
#include <iostream>

using namespace std;

class SpinLockMutex {
private:
	atomic_flag flag;

public:
	SpinLockMutex() : flag(ATOMIC_FLAG_INIT) {}

	void lock() {
		while(flag.test_and_set(memory_order_acquire));
	}

	void unlock() {
		flag.clear(memory_order_release);
	}
};

int main() {
	int a = 0;
	SpinLockMutex mutex;
	mutex.lock();
	a = 1;
	cout << a << endl;
	mutex.unlock();
	return 0;
}