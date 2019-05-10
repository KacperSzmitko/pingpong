#include "pch.h"
#include "ObjectsVector.h"
#include "Wall.h"
#include "Racket.h"
#include "Ball.h"
#include "UpdateObject.h"

template <typename T> void ObjectsVector<T>::_add(T obj) {
	vec.push_back(obj);
}

template <typename T> void ObjectsVector<T>::_delete(T obj) {
	for (i = vec.begin(); i != vec.end(); i++) {
		if (*i == obj) {
			vec.erase(i);
			break;
		}
	}
}

template <typename T> void ObjectsVector<T>::clear() {
	forEach([](T &obj) {
		delete obj;
	});
	vec.clear();
}

template <typename T> void ObjectsVector<T>::forEach(std::function<void(T &obj)> f) {
	std::for_each(vec.begin(), vec.end(), f);
}

template <typename T> std::vector<T>& ObjectsVector<T>::get() {
	return vec;
}

template <typename T> ObjectsVector<T>::~ObjectsVector() {
	forEach([](T &obj) {
		delete obj;
	});
}

template class ObjectsVector<Racket*>;
template class ObjectsVector<Ball*>;
template class ObjectsVector<Wall*>;
template class ObjectsVector<UpdateObject*>;
template class ObjectsVector<sf::Drawable*>;