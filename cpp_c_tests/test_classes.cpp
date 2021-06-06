#include <iostream>

class A {
private:
	int* array_;
	int size_;
public:
	A(int size) {
		size_ = size;
		array_ = (int*) new int[size];
	}

	int length() const {
		return size_;
	}

	void set(int index, int value) {
		if (index > size_ && index < 0) {
			std::cerr << "Error\n";
			exit(1);
		}

		array_[index] = value;
	}

	int get(int index) const {
		if (index > size_&& index < 0) {
			std::cerr << "Error\n";
			exit(1);
		}

		return array_[index];
	}

	friend A operator + (A& a1, A& a2);

	~A() {
		std::cout << "Destructor" << "\n";
		delete[] array_;
	}
};

A operator + (A& a1, A& a2) {
	if (a1.length() != a2.length()) {
		std::cerr << "Error\n";
		exit(1);
	}
	
	A ret(a1.length());

	for(int i = 0; i < a1.length(); i++)
		ret.set(i, a1.get(i) + a2.get(i));

	return ret;
}



void print(const A* a) {
	for (int i = 0; i < a->length(); i++)
		std::cout << a->get(i) << "[" << i << "]  ";
	std::cout << std::endl;
}

int main() {

	int size = 3;
	A array1(size);
	A array2(size);
	A array3(size);

	for (int i = 0; i < size; i++) {
		array1.set(i, 10*i);
		array2.set(i, 100*i);
	}

	print(&array1);
	print(&array2);

	array3 = array1 + array2;

	print(&array3);

	return 0;
}