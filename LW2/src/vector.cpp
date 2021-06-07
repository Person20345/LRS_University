#include "vector.h"



template <typename type>
Vector<type>::Vector() {
  index_ = 0;
}



template <typename type>
Vector<type>::Vector(int TYPE) {
  this->setSequence(TYPE);
  index_ = 0;
}



template <typename type>
Vector<type>::Vector(int TYPE, int size) {
  this->setSequence(TYPE);
  this->setSize(size);
  index_ = 0;
}



template <typename type>
void Vector<type>::setSequence(int TYPE) {
  sequence_type_ = TYPE;

  if (TYPE == DYNAMICARRAY_TYPE)
    coordinates_ = (DynamicArraySequence<type>*) new DynamicArraySequence<type>;
  else if (TYPE == LINKEDLIST_TYPE)
    coordinates_ = (LinkedListSequence<type>*) new LinkedListSequence<type>;
}



template <typename type>
void Vector<type>::setIndex(int index) {
  index_ = index;
}



template <typename type>
int Vector<type>::getIndex() {
  return index_;
}



template <typename type>
void Vector<type>::setSize(int size) {
  if (this->dimensions() == 0) {
    type newValue;
    for (int i = 0; i < size; i++)
      coordinates_->addBack(newValue);
  }
}



template <typename type>
type Vector<type>::norm() {
  type ret;

  for (int i = 0 ; i < this->dimensions(); i++)
    ret = ret + (*this)[i] * (*this)[i];

  return (type)sqrt(ret);
}



template <typename type>
type Vector<type>::m_norm() {
  type ret;

  if (this->dimensions() > 0)
    ret = (*this)[0];
  for (int i = 1; i < this->dimensions(); i++)
    if (ret < (*this)[i])
      ret = (*this)[i];

  return ret;
}



template <typename type>
type Vector<type>::l_norm() {
  type ret;

  if (this->dimensions() > 0)
    ret = (*this)[0];
  for (int i = 1; i < this->dimensions(); i++)
    ret = ret + (*this)[i];

  return ret;
}



template <typename type>
int Vector<type>::dimensions() {
  return coordinates_->length();
}


template <typename type>
int Vector<type>::sequenceType() {
  return sequence_type_;
}



template <typename type>
Vector<type> Vector<type>::operator + (Vector<type>& vector) {
  try {
    if (vector.dimensions() != this->dimensions())
      throw "different dimensions of vectors";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

  Vector<type> ret(this->sequence_type_, this->dimensions());

  for (int i = 0 ; i < this->dimensions(); i++)
    ret[i] = (*this)[i] + vector[i];

  return ret;
}



template <typename type>
Vector<type> Vector<type>::operator - (Vector<type>& vector) {
  try {
    if (vector.dimensions() != this->dimensions())
      throw "different dimensions of vectors";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

  Vector<type> ret(this->sequence_type_, this->dimensions());

  for (int i = 0 ; i < this->dimensions(); i++)
    ret[i] = (*this)[i] - vector[i];

  return ret;
}



template <typename type>
type Vector<type>::operator * (Vector<type>& vector) {
  try {
    if (vector.dimensions() != this->dimensions())
      throw "different dimensions of vectors";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

  type ret;
  ret = 0;

  for (int i = 0; i < this->dimensions(); i++)
    ret += (*this)[i] * vector[i];

  return ret;
}



template <typename type>
Vector<type> Vector<type>::operator * (type value) {
  Vector<type> ret(this->sequence_type_, this->dimensions());

  for (int i = 0 ; i < this->dimensions(); i++)
    ret[i] = (*this)[i] * value;

  return ret;
}



template <typename type>
type& Vector<type>::operator [] (int index) {
  return (*coordinates_)[index];
}



template <typename type>
void Vector<type>::operator = (Vector<type> vector) {
  try {
    if (vector.dimensions() != this->dimensions())
      throw "different dimensions of vectors";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

  for (int i = 0 ; i < this->dimensions(); i++)
    (*this)[i] = vector[i];
}



template <typename type>
Vector<type>::~Vector() {
  delete coordinates_;
}