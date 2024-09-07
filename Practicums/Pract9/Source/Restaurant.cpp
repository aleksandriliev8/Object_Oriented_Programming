#include "../Pract9_1/Restaurant.h"
#pragma warning (disable : 4996)

Restaurant::Restaurant() {
	productsCapacity = 8;
	products = new Product[productsCapacity];
}

Restaurant::Restaurant(const char* restaurantName, size_t capacity) {
	strcpy(this->name, strlen(restaurantName) <= MAX_NAME_RESTAURANT ? restaurantName : "");
	this->productsCapacity = capacity;
	this->products = new Product[productsCapacity];
}

Restaurant::Restaurant(const Restaurant& other) {
	copyFrom(other);
}

void Restaurant::free() {
	delete[] this->products;
	this->productsCapacity = 0;
	this->productsCount = 0;

}

void Restaurant::copyFrom(const Restaurant& other) {
	this->products = new Product[other.productsCapacity];
	this->productsCount = other.productsCount;
	this->productsCapacity = other.productsCapacity;
	for (size_t i = 0; i < productsCount; i++)
	{
		this->products[i] = other.products[i];
	}
	strcpy(this->name, other.name);
}

Restaurant& Restaurant::operator=(const Restaurant& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Restaurant::Restaurant(Restaurant&& other) noexcept {
	MoveFrom(std::move(other));
}

void Restaurant::MoveFrom(Restaurant&& other) {
	this->productsCount = other.productsCount;
	this->productsCapacity = other.productsCapacity;
	this->products = other.products;
	strcpy(name, other.name);

	other.products = nullptr;
	other.productsCapacity = 0;
	other.productsCount = 0;
}

Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
	if (this != &other) {
		free();
		MoveFrom(std::move(other));
	}

	return *this;
}

Restaurant::~Restaurant() {
	free();
}

void Restaurant::addProduct(const MyString& productName) {
	if (this->productsCount == this->productsCapacity) {
		resize();
	}
	Product newProduct(productName);
	products[productsCount++] = newProduct;
}

void Restaurant::resize() {
	this->productsCapacity *= 2;
	Product* temp = this->products;

	this->products = new Product[productsCapacity];
	for (size_t i = 0; i < productsCount; i++)
	{
		this->products[i] = temp[i];
	}

	delete[] temp;
}

const char* Restaurant::getRestaurantName() const {
	return this->name;
}