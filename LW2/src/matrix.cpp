#include "matrix.h"



template <typename type>
Matrix<type>::Matrix() {}



template <typename type>
Matrix<type>::Matrix(int TYPE) {
	this->setSequence(TYPE);
}



template <typename type>
Matrix<type>::Matrix(int TYPE, int strings_num, int colums_num) {
	this->setSequence(TYPE);
	this->setSize(strings_num, colums_num);
}



template <typename type>
void Matrix<type>::setSequence(int TYPE) {
	sequence_type_ = TYPE;
}



template <typename type>
void Matrix<type>::setSize(int strings_num, int colums_num) {
	colums_num_ = colums_num;
	strings_num_ = strings_num;
	if (sequence_type_ == LINKEDLIST_TYPE)
		values_ = (Sequence<Sequence<type> >*) new
		          LinkedListSequence<LinkedListSequence<type> >;
	else if (sequence_type_ == DYNAMICARRAY_TYPE)
		values_ = (Sequence<Sequence<type> >*) new
		          DynamicArraySequence<DynamicArraySequence<type> >;

	values_->resize(strings_num_);
	for(int i = 0; i < strings_num_; i++)
		(*values_)[i].resize(colums_num_);
}



template <typename type>
int Matrix<type>::columsNum() {
	return colums_num_;
}



template <typename type>
int Matrix<type>::stringsNum() {
	return strings_num_;
}



template <typename type>
int Matrix<type>::sequenceType() {
	return sequence_type_;
}



template <typename type>
Matrix<type> Matrix<type>::operator + (Matrix<type>& mat) {
	try {
    if (this->columsNum() != mat.columsNum() || this->stringsNum() != mat.stringsNum())
      throw "different dimensions of matrixes";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

	Matrix<type> ret(this->sequenceType(), this->stringsNum(), this->columsNum());

	for (int i = 0; i < this->stringsNum(); i++)
		for (int j = 0; j < this->columsNum(); j++)
			(*ret[i])[j] = (*(*this)[i])[j] + (*mat[i])[j];

	return ret;
}



template <typename type>
Matrix<type> Matrix<type>::operator - (Matrix<type>& mat) {
	try {
    if (this->columsNum() != mat.columsNum() || this->stringsNum() != mat.stringsNum())
      throw "different dimensions of matrixes";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

	Matrix<type> ret(this->sequenceType(), this->stringsNum(), this->columsNum());

	for (int i = 0; i < this->stringsNum(); i++)
		for (int j = 0; j < this->columsNum(); j++)
			(*ret[i])[j] = (*(*this)[i])[j] - (*mat[i])[j];

	return ret;
}



template <typename type>
Matrix<type> Matrix<type>::operator * (Matrix<type>& mat) {
	try {
    if (this->columsNum() != mat.stringsNum())
      throw "different dimensions of matrixes";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

	Matrix<type> ret(this->sequenceType(), this->stringsNum(), mat.columsNum());

	for (int i = 0; i < ret.stringsNum(); i++)
		for (int j = 0; j < ret.columsNum(); j++) {
			(*ret[i])[j] = 0;
			for (int k = 0; k < this->columsNum(); k++)
				(*ret[i])[j] += (*(*this)[i])[k] * (*mat[k])[j]; 
		}


	return ret;
}



template <typename type>
Matrix<type> Matrix<type>::operator * (type value) {
	Matrix<type> ret(this->sequenceType(), this->stringsNum(), this->columsNum());

	for (int i = 0; i < this->stringsNum(); i++)
		for (int j = 0; j < this->columsNum(); j++)
			(*ret[i])[j] = (*(*this)[i])[j] * value;

	return ret;
}



template <typename type>
Matrix<type> Matrix<type>::operator / (type value) {
	Matrix<type> ret(this->sequenceType(), this->stringsNum(), this->columsNum());

	for (int i = 0; i < this->stringsNum(); i++)
		for (int j = 0; j < this->columsNum(); j++)
			(*ret[i])[j] = (*(*this)[i])[j] * value;

	return ret;
}



template <typename type>
void Matrix<type>::operator = (Matrix<type> mat) {
	try {
    if (this->columsNum() != mat.columsNum() || this->stringsNum() != mat.stringsNum())
      throw "different dimensions of matrixes";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

  for (int i = 0; i < this->stringsNum(); i++)
		for (int j = 0; j < this->columsNum(); j++)
			(*(*this)[i])[j] = (*mat[i])[j];
}



template <typename type>
Sequence<type>* Matrix<type>::operator [] (int index) {
	return &(*values_)[index];
}



template <typename type>
int Matrix<type>::addStr(int indexTo, int indexThis) {
	for(int i = 0; i < this->columsNum(); i++)
		(*(*this)[indexTo])[i] = (*(*this)[indexTo])[i] + (*(*this)[indexThis])[i];

	return indexTo;
}



template <typename type>
int Matrix<type>::subtractStr(int indexFrom, int indexThis) {
	for(int i = 0; i < this->columsNum(); i++)
		(*(*this)[indexFrom])[i] = (*(*this)[indexFrom])[i] - (*(*this)[indexThis])[i];

	return indexFrom;
}



template <typename type>
int Matrix<type>::multiplyStr(int indexThis, type value) {
	for(int i = 0; i < this->columsNum(); i++)
		(*(*this)[indexThis])[i] = (*(*this)[indexThis])[i] * value;

	return indexThis;
}



template <typename type>
int Matrix<type>::divideStr(int indexThis, type value) {
	for(int i = 0; i < this->columsNum(); i++)
		(*(*this)[indexThis])[i] = (*(*this)[indexThis])[i] / value;

	return indexThis;
}



template <typename type>
int Matrix<type>::addClm(int indexTo, int indexThis) {
	for(int i = 0; i < this->stringsNum(); i++)
		(*(*this)[i])[indexTo] = (*(*this)[i])[indexTo] + (*(*this)[i])[indexThis];

	return indexTo;
}



template <typename type>
int Matrix<type>::subtractClm(int indexFrom, int indexThis) {
	for(int i = 0; i < this->stringsNum(); i++)
		(*(*this)[i])[indexFrom] = (*(*this)[i])[indexFrom] - (*(*this)[i])[indexThis];

	return indexFrom;
}



template <typename type>
int Matrix<type>::multiplyClm(int indexThis, type value) {
	for(int i = 0; i < this->stringsNum(); i++)
		(*(*this)[i])[indexThis] = (*(*this)[i])[indexThis] * value;

	return indexThis;
}



template <typename type>
int Matrix<type>::divideClm(int indexThis, type value) {
	for(int i = 0; i < this->stringsNum(); i++)
		(*(*this)[i])[indexThis] = (*(*this)[i])[indexThis] / value;

	return indexThis;
}



template <typename type>
type Matrix<type>::norm(int p) {
	type ret;

	for (int i = 0; i < this->stringsNum(); i++)
		for (int j = 0; j < this->columsNum(); j++) {
			type ap = sqrt((*(*this)[i])[j] * (*(*this)[i])[j]);
			for (int k = 1; k < p; k++)
				ap = ap * ap;
			ret = ret + ap;
		}
	return pow(ret, (double)1/(double)p);
}
