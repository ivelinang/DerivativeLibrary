#pragma once
#ifndef PAYOFF2_H
#define PAYOFF2_H

class PayOff
{
public:
	PayOff() {};
	virtual double operator()(double Spot) const = 0;
	virtual ~PayOff() {};
	virtual PayOff* clone() const = 0;
private:

};		

class PayOffCall :public PayOff
{
public:
	PayOffCall(double Strike_0);
	virtual double operator()(double Spot) const;
	virtual ~PayOffCall() {};
	virtual PayOff* clone() const;
private:
	double Strike;
};

class PayOffPut : public PayOff
{
public:
	PayOffPut(double Strike);
	virtual double operator()(double Spot) const;
	virtual ~PayOffPut() {};
	virtual PayOff* clone() const;
private:
	double Strike;

};

#endif // !PAYOFF2_H
