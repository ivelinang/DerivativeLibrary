#pragma once
#ifndef MINMAX_H
#define MINMAX_H

template<class T> const T& max(const T& a, const T& b)
{
	return (a > b) ? a : b;
};

template<class T> const T& min(const T& a, const T& b)
{
	return (a < b) ? b : a;
}
#endif // !MINMAX_H
