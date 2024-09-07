#pragma once
#include "../Pract9_1/Product.h"

const unsigned int MAX_NAME_RESTAURANT = 25;

class Restaurant {
private:
	Product* products;
	char name[MAX_NAME_RESTAURANT + 1];
	size_t productsCount = 0;
	size_t productsCapacity = 0;

public:
	Restaurant();
	Restaurant(const char* restaurantName, size_t capacity);
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);

	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(Restaurant&& other) noexcept;

	~Restaurant();

	void addProduct(const MyString& productName);
	//void receiveOrder(const Order& order);

	const char* getRestaurantName() const;

private:
	void copyFrom(const Restaurant& other);
	void free();
	void MoveFrom(Restaurant&& other);
	void resize();
};