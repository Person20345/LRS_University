#include <iostream>

class B {
private:
	int a;
public:
	~B() {
		std::cout << "B-Destructor\n";
	}
};

class A {
private:
	int size_;
	int* array_;
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
			std::cerr << "Error 'set'\n";
			exit(1);
		}

		array_[index] = value;
	}

	int get(int index) const {
		if (index > size_&& index < 0) {
			std::cerr << "Error 'get'\n";
			exit(1);
		}

		return array_[index];
	}

	A operator + (const A& a) {
		if (this->length() != a.length()) {
			std::cerr << "Error '+'\n";
			exit(1);
		}

		A ret(this->length());

		B test;

		for(int i = 0; i < this->length(); i++)
			ret.set(i, this->get(i) + a.get(i));

		return ret;
	}

	void operator = (const A& a) {
		if (this->length() != a.length()) {
			std::cerr << "Error '='\n";
			exit(1);
		}

		std::cout << " =\n";
		
		for (int i = 0; i < this->length(); i++)
			this->set(i, a.get(i));
	}

	~A() {
		std::cout << "Destructor" << "\n";
		delete[] array_;
	}
};



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

	array3 = array1 + array2 + array2 + array2 + array2;

	print(&array3);

	return 0;
}