#pragma once
#ifndef WRAPPER_H
#define WRAPPER_H

template <class T>
class Wrapper
{
public:
	Wrapper() { Dataptr = 0; }

	Wrapper(const T& inner)
	{
		Dataptr = inner.clone();
	}

	
	Wrapper(T* DataPtr_)
	{
		Dataptr = Dataptr_;
	}

	~Wrapper()
	{
		if (Dataptr != 0)
			delete Dataptr;
	}

	Wrapper(const Wrapper<T>& original)
	{
		if (original.Dataptr != 0)
			Dataptr = original.Dataptr->clone();
		else
			Dataptr = 0;
	}

	Wrapper& operator=(const Wrapper<T>& original)
	{
		if (this != &original)
		{
			if (Dataptr != 0)
				delete Dataptr;

			Dataptr = (original.Dataptr != 0) ? original.Dataptr->clone() : 0;
			
		}

		return *this;
	}

	
	Wrapper& equals(const Wrapper<T>& original)
	{
		if (this != &original)
		{
			T* newPtr = (original.Dataptr != 0) ? original.Dataptr->clone() : 0;

			if (Dataptr != 0)
				delete Dataptr;

			Dataptr = newPtr;
		}

		return *this;
	}


	T& operator*()
	{
		return *Dataptr;
	}

	const T& operator*() const
	{
		return *Dataptr;
	}

	const T* const operator->() const
	{
		return Dataptr;
	}

	T* operator->()
	{
		return Dataptr;
	}


private:
	T* Dataptr;

};
#endif // !WRAPPER_H
