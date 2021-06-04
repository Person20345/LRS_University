#include "vector.h"




template <typename type>
Vector() {}




template <typename type>
Vector(int size) {
  this->setSize(size);
}




template <typename type>
void setSize(int size) {
  type newItem;
  for (int i = 0; i < size; i++)
    coordinates_.addBack(newItem);
}



template <typename type>
Vector<type> normalise(Vector<types>& vector) {
  coordinates_[];
}



template <typename type>
Vector<type> operator + (Vector<type> vector1, Vector<type> vector2) {

}



template <typename type>
type operator * (Vector<type> vector1, Vector<type> vector2) {

}



template <typename type>
Vector<type> operator * (Vector<type> vector, type value) {

}



template <typename type>
Vector<type> operator * (type value, Vector<type> vector) {

}