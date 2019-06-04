#include "pch.h"
#include "ObjectsVector.h"
#include "Wall.h"
#include "Racket.h"
#include "Ball.h"
#include "UpdateObject.h"
#include "SimObject.h"
#include "Table.h"

template <typename T> ObjectsVector<T>::ObjectsVector() {
	this->forEachReset = false;
}

template <typename T> void ObjectsVector<T>::_add(T obj) {
	vec.push_back(obj);
	forEachReset = true;
}

template <typename T> void ObjectsVector<T>::_delete(T obj) {
	for (auto i = vec.begin(); i != vec.end(); i++) {
		if (*i == obj) {
			vec.erase(i);
			forEachReset = true;
			break;
		}
	}
}

template <typename T> void ObjectsVector<T>::clear() {
	forEach([](T &obj) {
		delete obj;
	});
	vec.clear();
	forEachReset = true;
}

template <typename T> void ObjectsVector<T>::forEach(std::function<void(T &obj)> f) {
	forEachReset = false;
	for (auto i = vec.begin(); i != vec.end(); i++) {
		f(*i);
		if (forEachReset) break;
	}
}

template <typename T> std::vector<T>& ObjectsVector<T>::get() {
	return vec;
}

template <typename T> ObjectsVector<T>::~ObjectsVector() {
	
}

template class ObjectsVector<Table*>;
template class ObjectsVector<Racket*>;
template class ObjectsVector<Ball*>;
template class ObjectsVector<Wall*>;
template class ObjectsVector<UpdateObject*>;
template class ObjectsVector<SimObject*>;
template class ObjectsVector<sf::Drawable*>;