#pragma once
template <typename T> class ObjectsVector {
private:
	std::vector<T> vec;
	typename std::vector<T>::iterator i;

public:
	void _add(T object);
	void _delete(T object);
	void forEach(std::function<void(T &object)> _function);
	std::vector<T>& get();
	~ObjectsVector();
};

