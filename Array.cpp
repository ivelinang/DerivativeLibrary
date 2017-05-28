#include "Array.h"

MJArray::MJArray(unsigned long size) : Size(size), Capacity(size)
{
	if (Size > 0)
	{
		ValuesPtr = new double[size];
		EndPtr = ValuesPtr;
		EndPtr += size;
	}
	else
	{
		ValuesPtr = 0;
		EndPtr = 0;
	}
}

MJArray::MJArray(const MJArray& original) : Size(original.Size), Capacity(original.Capacity)
{
	if (Size > 0)
	{
		ValuesPtr = new double[Size];
		EndPtr = ValuesPtr;
		EndPtr += Size;
		//std::copy(original.ValuesPtr, original.EndPtr, ValuesPtr);
		for (int i = 0; i != Size; i++)
			ValuesPtr[i] = original.ValuesPtr[i];
	}
	else
	{
		ValuesPtr = EndPtr = 0;
	}
}

MJArray& MJArray::operator=(const MJArray& original)
{
	if (&original == this)
		return *this;
	if (original.Size > Capacity)
	{
		if (Capacity > 0)
			delete[] ValuesPtr;
		ValuesPtr = new double[original.Size];
		Capacity = original.Capacity;
	}

	//else continue
	Size = original.Size;
	EndPtr = ValuesPtr;
	EndPtr += Size;

	for (int i = 0; i != Size; i++)
		ValuesPtr[i] = original.ValuesPtr[i];

	return *this;
}

MJArray& MJArray::operator=(const double& val)
{
	for (unsigned long i = 0; i < Size; i++)
		ValuesPtr[i] = val;

	return *this;
}



void MJArray::resize(unsigned long newSize)
{
	if (newSize > Capacity)
	{
		if (Capacity > 0)
			delete[] ValuesPtr;
		ValuesPtr = new double[newSize];
		Capacity = newSize;
	}
	//else
	Size = newSize;
	EndPtr = ValuesPtr + Size;
}


MJArray::~MJArray()
{
	if (ValuesPtr > 0)
		delete[] ValuesPtr;
}

double MJArray::sum() const
{
	double sm = 0;
	for (int i = 0; i != Size; i++)
		sm += ValuesPtr[i];
	return sm;
}

double MJArray::max() const
{
	if (Size == 0)
	{
		throw("array is zero length");
	}
	double mx = ValuesPtr[0];
	for(int i=0; i!=Size; i++)
		if (ValuesPtr[i] > mx)
		{
			mx = ValuesPtr[i];
		}

	return mx;

}

double MJArray::min() const
{
	if (Size == 0)
	{
		throw("array is zero length");
	}

	double mn = ValuesPtr[0];
	for (int i = 0; i != Size; i++)
		if (ValuesPtr[i] < mn)
			mn = ValuesPtr[i];

	return mn;
}

MJArray& MJArray::operator+=(const MJArray& operand)
{
#ifdef RANGE_CHECKING
	if (Size != operand.getSize())
	{
		throw("to apply += two arrays must be of same size")
	}
#endif
	for (unsigned long i = 0; i < Size; i++)
		ValuesPtr[i] += operand.ValuesPtr[i];

	return *this;
}



double MJArray::operator[](unsigned long i) const
{
	if (i > Size)
		throw("out of limit");
	return ValuesPtr[i];
}
/*
inline double& MJArray::operator[](unsigned long i)
{
	if (i > Size)
		throw("out of limit");
	return ValuesPtr[i];
}
*/
void MJArray::setValue(unsigned long i, double val)
{
	if (i > Size)
		throw("out of limit");
	ValuesPtr[i] = val;
}

void MJArray::append(double val)
{
	double* newPointer = new double[Size + 1];
	for (int i = 0; i != Size; i++)
		newPointer[i] = ValuesPtr[i];
	newPointer[Size] = val;
	//now can delete old valuePtr
	delete[] ValuesPtr;
	ValuesPtr = newPointer;
	Size = Size + 1;
	
}