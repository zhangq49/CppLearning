// Conclusion:
//    The parallel quick sort version doesn't perform better than general quick sort version.

#include <list>
#include <future>
#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
list<T> parallel_quick_sort(list<T> input_list) {
	if (input_list.empty())
		return input_list;

	list<T> result_list;
	result_list.splice(result_list.begin(), input_list, input_list.begin());
	const T& pivot = *result_list.begin();

	auto divide_index = partition(input_list.begin(), input_list.end(),
								  [&](const T& t) { return t < pivot; });

	list<T> left_part;
	left_part.splice(left_part.begin(), input_list, input_list.begin(), divide_index);

	future<list<T>> new_left_part(async(&parallel_quick_sort<T>, move(left_part)));
	auto new_right_part(parallel_quick_sort(move(input_list)));

	result_list.splice(result_list.end(), new_right_part);
	result_list.splice(result_list.begin(), new_left_part.get());

	return result_list;
}

template<typename T>
list<T> quick_sort(list<T> input_list) {
	if (input_list.empty()) return input_list;

	list<T> result_list;
	result_list.splice(result_list.begin(), input_list, input_list.begin());

	const T& pivot = *result_list.begin();
	auto divide_index = partition(input_list.begin(), input_list.end(),
								  [&](const T& t) { return t < pivot; });
	
	list<T> left_part;
	left_part.splice(left_part.end(), input_list, input_list.begin(), divide_index);

	list<T> new_left_part(quick_sort(move(left_part)));
	list<T> new_right_part(quick_sort(move(input_list)));

	result_list.splice(result_list.end(), new_right_part);
	result_list.splice(result_list.begin(), new_left_part);

	return result_list;
}

int main() {
	list<int> list_tmp = {
					    1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92, 
					    1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92,
					    1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92,
					    1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92,
					    1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92,
					    1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92, 
					    1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92,
					    1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92
					  };

	clock_t start_time, end_time;
	// parallel_quick_sort version
	start_time = clock();

	list<int> list1 = list_tmp;

	// for (int elem : list1)
	// 	cout << elem << ' ';
	// cout << endl;

	list<int> list2 = parallel_quick_sort(list1);

	// for (int elem : list2)
	// 	cout << elem << ' ';
	// cout << endl;

	end_time = clock();
	cout << "The run time of parallel_quick_sort is " << (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

	// quick_sort version
	start_time = clock();

	list<int> list3 = list_tmp;

	// for (int elem : list3)
	// 	cout << elem << ' ';
	// cout << endl;

	list<int> list4 = quick_sort(list3);

	// for (int elem : list4)
	// 	cout << elem << ' ';
	// cout << endl;

	end_time = clock();
	cout << "The run time of quick_sort is " << (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

	return 0;
}