#include <iostream>



class A {
private:
	int a_;
public:
	A(int a) {
		a_ = a;
	}

	int get() {
		return a_;
	}
};



class B {
private:
	A a_;
public:
	B(int a) : a_(a) {}

	int get() {
		return a_.get();
	}
};



int main() {
	B b(123);

	std::cout << b.get() << std::endl;

	return 0;
}