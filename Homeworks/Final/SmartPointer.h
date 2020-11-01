// SmartPointer.h
#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <typename T>
class SmartPointer {
  T* data;
public:
  SmartPointer(const T&);
  T& operator*(); // gets value held
  const T& operator*() const; // gets value held .... i dont know how this part is supposed to work
  SmartPointer<T>& operator=(const T& data); // assigns value
  


  // Add Your declarations here



  ~SmartPointer() // destructor smart pointer
  SmartPointer(const SmartPointer& new_Data); // copy const
  SmartPointer& operator=(const SmartPointer& new_Data); // copy assignment

};

template <typename T>
SmartPointer<T>::SmartPointer(const T& data) {
  this->data = new T(data); 
  // allocate on heap for T (regardless of size)
  data = NULL;
}

template <typename T>
T& SmartPointer<T>::operator() { 
  // get value held in smart pointer
  return data;
}

template <typename T>
const T& SmartPointer<T>::operator() const { 
  // get value held in smart pointer
  return data;
}

// note: this is not copy assignmewnt
template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const T& data) { 
  // assign value to smart pointer
  *(this->data) = data;
  return *this;
}

// Add your definitions here

// copy const
template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer& new_Data) {
	data = new int;
	*data = *(new_Data.data);
}

// destructor

SmartPointer<T>::~SmartPointer() {
    delete data;
}

// copy assignment
template <typename T>
SmartPointer<T>::SmartPointer& operator=(const SmartPointer& new_Data) {
	delete data;
	data = new int;
	*data = *(new_Data.data);	
}

#endif