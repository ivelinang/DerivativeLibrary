#pragma once
#ifndef BSFORMULA_H
#define BSFORMULA_H

double BlackScholesCall(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry);

double BlackScholesPut(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry);

double BlackScholesDigitalCall(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry);

double BlackScholesCallVega(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry);

double BlackScholesCallVega2(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry);

#endif // !BSFORMULA_H
