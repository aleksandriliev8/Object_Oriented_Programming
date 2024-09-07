#pragma once

class Nvector {
private:
	int* values;
	size_t size;

	void copyFrom(const Nvector&);
	void free();

public:
	Nvector();
	Nvector(size_t);
	Nvector(const Nvector&);
	Nvector& operator=(const Nvector&);
	~Nvector();

	void print() const;
	int operator[](size_t index) const;

	size_t getSize() const;
	int* getValues() const;

	void setSize(size_t size);
	void setValues(int* _values);

	friend bool arePerpendicular(const Nvector&, const Nvector&);
};

Nvector operator+(const Nvector&, const Nvector&);
Nvector operator-(const Nvector&, const Nvector&);
Nvector operator*(const Nvector&, int);
Nvector operator*(int, const Nvector&);
bool operator||(const Nvector&, const Nvector&);