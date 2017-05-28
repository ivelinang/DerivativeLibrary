#pragma once
#ifndef ARRAY_H
#define ARRAY_H

class MJArray
{
public:
	MJArray(unsigned long size);
	MJArray(const MJArray& original);
	~MJArray();

	MJArray& operator=(const MJArray& original);
	MJArray& operator=(const double& val);

	MJArray& operator+=(const MJArray& operand);
	//MJArray& operator+=(const double& operand);

	double operator[](unsigned long i) const;
	//inline double& operator[](unsigned long i);
	void setValue(unsigned long i, double val);
	
	inline unsigned long MJArray::getSize() const;

	void resize(unsigned long newSize);

	void append(double val);

	double sum() const;
	double min() const;
	double max() const;

private:
	double* ValuesPtr;	double* EndPtr;	unsigned long Size;	unsigned long Capacity;
};

inline unsigned long MJArray::getSize() const
{
	return Size;
}

#endif // !ARRAY_H
