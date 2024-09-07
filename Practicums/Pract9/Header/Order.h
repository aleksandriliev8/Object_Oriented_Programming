#pragma once
#include "Product.h"

class Order {
private:
	Product* productsOrder = nullptr;
	MyString nameRestaurant;
	size_t numberOfProducts = 0;
	size_t capacityProducts = 0;

public:
	Order() = default;
	Order(size_t _capacityProducts, const char* _nameRestaurant);
	Order(const Order& other);
	Order& operator=(const Order& other);

	Order(Order&& other) noexcept;
	Order& operator=(Order&& other) noexcept;

	~Order();

private:
	void copyFrom(const Order& other);
	void free();
	void moveFrom(Order&& other);
};