#include "../Pract9_1/Order.h"
#pragma warning (disable:4996)

Order::Order(size_t _capacityProducts, const char* _nameRestaurant) {
	this->capacityProducts = _capacityProducts;
	this->nameRestaurant = MyString(_nameRestaurant);
	this->productsOrder = new Product[_capacityProducts];
}

Order::Order(const Order& other) {
	copyFrom(other);
}

Order& Order::operator=(const Order& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Order::Order(Order&& other) noexcept {
	
}

Order& Order::operator=(Order&& other) noexcept {

}

Order::~Order() {

}

void Order::copyFrom(const Order& other) {
	this->capacityProducts = other.capacityProducts;
	this->numberOfProducts = other.numberOfProducts;
	this->nameRestaurant = other.nameRestaurant;
	this->productsOrder = new Product[other.capacityProducts];

	for (size_t i = 0; i < numberOfProducts; i++)
	{
		this->productsOrder[i] = other.productsOrder[i];
	}
}

void Order::moveFrom(Order&& other) {
	this->capacityProducts = other.capacityProducts;
	this->numberOfProducts = other.numberOfProducts;
	this->nameRestaurant = other.nameRestaurant;
	this->productsOrder = other.productsOrder;

	other.capacityProducts = 0;
	other.numberOfProducts = 0;
	other.nameRestaurant = nullptr;
	delete[] other.productsOrder;
	other.productsOrder = nullptr;
}
