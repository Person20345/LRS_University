#include <iostream>



class A {
private:
	int value_;
public:
	void setValue(int value) {
		value_ = value;
	}


	int value() { return value_; }
};



int main() {
	A a;
	a.setValue(32544);

	printf("%d\n", a.value());
	return 0;
}