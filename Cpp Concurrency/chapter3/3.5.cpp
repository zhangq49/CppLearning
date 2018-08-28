// 线程安全的stack的实现
#include <stack>
#include <memory>
#include <mutex>
#include <exception>
#include <string>
#include <iostream>

// pop操作时，若stack为空，则抛出该类型异常
struct empty_stack: std::exception {
	const char* what() const throw() {
		return "empty stack!";
	}
};

// 线程安全的stack类定义
template <typename T>
class threadsafe_stack {
public:
	threadsafe_stack(): data(std::stack<T>()) {}
	threadsafe_stack(const threadsafe_stack& other) {
		std::lock_guard<std::mutex> lock(other.m);
		data = other.data;
	}
	threadsafe_stack& operator=(const threadsafe_stack& other) = delete;

	void push(T value) {
		std::lock_guard<std::mutex> lock(m);
		data.push(value);
	}

	std::shared_ptr<T> pop() {
		std::lock_guard<std::mutex> lock(m);
		if (data.empty()) throw empty_stack();
		const std::shared_ptr<T> sp = std::make_shared<T>(data.top());
		data.pop();
		return sp;
	}

	void pop(T& value) {
		std::lock_guard<std::mutex> lock(m);
		if (data.empty()) return throw empty_stack();
		value = data.top();
		data.pop();
	}

	bool empty() const {
		std::lock_guard<std::mutex> lock(m);
		return data.empty();
	}

private:
	std::stack<T> data;
	mutable std::mutex m;
};

int main() {
	threadsafe_stack<std::string> st;
	st.push("first");
	auto sp = st.pop();
	std::cout << *sp << std::endl;

	return 0;
}