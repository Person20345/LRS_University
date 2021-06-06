#include "vector.h"



template <typename type>
Vector() {}



template <typename type>
Vector(int size) {
  this->setSize(size);
}



template <typename type>
void setSize(int size) {4
  type newItem;
  for (int i = 0; i < size; i++)
    coordinates_.addBack(newItem);
}



template <typename type>
Vector<type> norm=(Vector<types>& vector) {
  coordinates_[];
}



template <typename type>
Vector<type>& operator + (Vector<type>& vector1, Vector<type>& vector2) const {
  try {
    if (vector1.length() != vector2.length())
      throw "vectors of different dimensions";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

  Vector<type> ret;
  ret.setSize(vector1.length());

  for (int i = 0; i < vector1.length(); i++)
    ret.coordinates_[i] = vector2.coordinates_[i] + vector1.coordinates_[i];

  return ret;
}



template <typename type>
Vector<type>& operator - (Vector<type>& vector1, Vector<type>& vector2) const {
  try {
    if (vector1.length() != vector2.length())
      throw "vectors of different dimensions";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

  Vector<type> ret;
  ret.setSize(vector1.length());

  for (int i = 0; i < vector1.length(); i++)
    ret.coordinates_[i] = vector1.coordinates_[i] - vector2.coordinates_[i];

  return ret;
}



template <typename type>
type operator * (Vector<type>& vector1, Vector<type>& vector2) {

}



template <typename type>
Vector<type> operator * (Vector<type>& vector, type value) {

}



template <typename type>
Vector<type> operator * (type value, Vector<type>& vector) {

}