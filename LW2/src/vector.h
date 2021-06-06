#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename type>
class Vector {
private:
	Sequence<type> coordinates_;
public:
	Vector();
  Vector(int size);

  void setSize(int size);

  Vector<type> normalise(Vector<types>& vector);
  
  Vector<type>& operator + (Vector<type> vector1, Vector<type> vector2);
  Vector<type>& operator - (Vector<type> vector1, Vector<type> vector2);
  
  type operator * (Vector<type> vector1, Vector<type> vector2);
  
  Vector<type> operator * (Vector<type> vector, type value);
  Vector<type> operator * (type value, Vector<type> vector);

  friend Vector<type> Vector<type>::operator + (Vector<type> vector1, Vector<type> vector2);
  friend type Vector<type>::operator * (Vector<type> vector1, Vector<type> vector2);
  
  friend Vector<type> Vector<type>::operator * (Vector<type> vector, type value);
  friend Vector<type> Vector<type>::operator * (type value, Vector<type> vector);

  type operator [] ();
};

#endif