#include <iostream>
#include "SimpleMC.h"
//#include "PayOff1.h"
#include "MinMax.h"
#include "PayOff2.h"
#include "testHeader.h"
#include "Random1.h"
#include "DoubleDigital.h"
#include "SimpleMC3.h"
#include "Vanilla1.h"
//#include "Vanilla3.h"
#include "SimpleMC6.h"
#include "Parameters.h"
//#include "PayOffBridge.h"
//#include <cmath>
//#include "Random2.h"
//#include "RTest.h"
//#include "ArraysMJ2.h"
//#include  "ParkMiller.h"
//#include "AntiThetic.h"
//#include "ArrayIA.h"
//#include "ArrayDD.h"
#include "Array.h"
//#include "ParkMiller.h"
#include "AntiThetic2.h"
#include "Normals2.h"
#include "ParkMiller2.h"
#include "Random22.h"
#include "ConvergenceTable.h"
#include "SimpleMC8.h"
#include <vector>
#include "PathDependent.h"
#include "ExoticEngine.h"
#include "ExoticBSEngine.h"
#include "PathDependentAsian2.h"
#include "PayOffBridge2.h"
#include "Vanilla3.h"
#include "TreeProduct.h"
#include "TreeAmerican.h"
#include "TreeEuropean.h"
#include "BinomialTree.h"
#include "BSFormula.h"
#include "BSCallClass.h"
#include "Bisection.h"
#include "NewtonRhapson.h"
#include "BSCallTwo.h"
#include "PayOffFactory.h"
#include "PayOffConstructible.h"

//using namespace std;

double normalCFD(double value)
{
	return 0.5 * erfc(-value /sqrt(2));
}

double BSCallPricer(
	double spot,
	double strike,
	double expiry,
	double vol,
	double r
) 
{
	double d1 = (log(spot / strike) + (r + vol*vol / 2.0)*expiry) / (vol*sqrt(expiry));
	double d2 = d1 - vol*sqrt(expiry);
	double price = normalCFD(d1)*spot - normalCFD(d2)*strike*exp(-r*expiry);
	return price;

}


/*
void testMCcall() {
	double expiry = 5.0;
	double strike = 120.0;
	double spot = 100.0;
	double vol = 0.20;
	double r = 0.0;
	unsigned long numberOfPaths = 1000000.0;

	PayOff callPayOff(strike, PayOff::call);
	double s = callPayOff(150.0);
	double maxs = max(3, 5);
	//double rnds = GetOneGaussianByBoxMuller();
	//RandomGen rndGen = RandomGen();
	double r2 = GetOneGaussianBySummation();
	//rndGen.GetmyG();
	int hd = getN();
	double rnd = GetOneGaussianByBoxMuller();

	double x = 2.0*(double)rand() / (double)(RAND_MAX)-1;

	double result = 0;

	for (unsigned long j = 0; j < 12; j++)
		result += (double)rand();// / static_cast<double>(RAND_MAX);

	result -= 6.0;

	//return result;
	//*PayOff call = &callPayOff;
	
	double priceCall = SimpleMonteCarlo2(callPayOff,
		expiry,
		spot,
		vol,
		r,
		numberOfPaths);

	double priceCallBS = BSCallPricer(
		spot,
		strike,
		expiry,
		vol,
		r
	);

	cout << "price call " << priceCall;
	cin.get();
	cout << "price call BS " << priceCallBS;
	cin.get();
	
	cout << "payoff \n" << s;
	cout << "max \n" << maxs;
	cout << "rand is \n" << x;
	cout << "res is \n" << result;
	cout << "arg is \n" << rnd;
	cout << "getN is \n" << hd;
	cin.get();

}
*/

void testMCCall2() {
	double expiry = 5.0;
	double strike = 120.0;
	double spot = 100.0;
	double vol = 0.20;
	double r = 0.0;
	unsigned long numberOfPaths = 1000000.0;

	PayOffCall PayOffCall(strike);

	double priceCall = SimpleMonteCarlo2(PayOffCall,
		expiry,
		spot,
		vol,
		r,
		numberOfPaths);

	double priceCallBS = BSCallPricer(
		spot,
		strike,
		expiry,
		vol,
		r
	);

	std::cout << "price call " << priceCall;
	std::cin.get();
	std::cout << "price call BS " << priceCallBS;
	std::cin.get();

}

void testMCDigital() {

	double expiry = 5.0;
	double strike = 120.0;
	double spot = 100.0;
	double vol = 0.20;
	double r = 0.0;
	double lowerBand = 80;
	double upperBand = 130;

	unsigned long numberOfPaths = 1000.0;

	PayOff *payDigital = new PayOffDoubleDigital(lowerBand, upperBand);
	PayOffDoubleDigital payDD(lowerBand, upperBand);

	double priceCall = SimpleMonteCarlo2(*payDigital,
		expiry,
		spot,
		vol,
		r,
		numberOfPaths);
	
	delete payDigital;

	std::cout << "price call Digital " << priceCall;
	std::cin.get();

}
///*
void testMCv3() {

	double expiry = 5.0;
	double strike = 120.0;
	double spot = 100.0;
	double vol = 0.20;
	double r = 0.0;
	double lowerBand = 80;
	double upperBand = 130;

	unsigned long numberOfPaths = 1000.0;

	PayOff *payDigital = new PayOffDoubleDigital(lowerBand, upperBand);
	PayOffDoubleDigital ThePayOff(lowerBand, upperBand);
	VanillaOption *TheOption = new VanillaOption(*payDigital, strike);
	VanillaOption Option(ThePayOff, expiry);	

	double price = SimpleMonteCarlo3(*TheOption,
		spot,
		vol,
		r,
		numberOfPaths);

	//another way to construct VanillaOption
	VanillaOption secondOption(Option);
	double price2 = SimpleMonteCarlo3(secondOption,
		spot,
		vol,
		r,
		numberOfPaths);

	//third way
	PayOffPut putPay(strike);
	VanillaOption thirdOption(putPay, expiry);
	Option = thirdOption;

	double price3 = SimpleMonteCarlo3(Option,
		spot,
		vol,
		r,
		numberOfPaths);

	
	delete payDigital;
	delete TheOption;

	std::cout << "price call Digital v1 " << price << "\n";
	std::cout << "price call Digital v2 " << price2 << "\n";
	std::cout << "price call Digital v3 " << price3 << "\n";
	std::cin.get();

}
//*/


void testMCv4() {
	double expiry = 5.0;
	double strike = 120.0;
	double spot = 100.0;
	double vol = 0.20;
	double r = 0.0;
	double lowerBand = 80;
	double upperBand = 130;
	unsigned long numberOfPaths = 1000.0;
	PayOffCall thePayOff(strike);
	VanillaOption theOption(thePayOff, expiry);
	
	//ParametersConstant vp(vol);
	ParametersConstant vp(vol);
	ParametersConstant rp(r);

	double price = SimpleMonteCarlo4(theOption, spot, vp, rp, numberOfPaths);
	

	std::cout << "price mC4 " << price;
	std::cin.get();


}

void testMJArray() {
	MJArray r(3);
	//MJArray r2 = MJArray(4);
	r.setValue(1, 4.5);
	r.setValue(0, 3);
	r.setValue(2, 2);
	//double x = r[1];
	std::cout << " element 1 is " << r[1];
	std::cout << " element 0 is " << r[0];
	std::cout << " element 2 is " << r[2];
	std::cin.get();
	std::cout << " sum " << r.sum();
	std::cin.get();
	r.append(4);
	std::cout << " sum2 " << r.sum();
	std::cin.get();
	//MJArray2 r(3);
	//unsigned long s = 3;
	//MJArray2 arr(s);
	//cout << "ret " << arr.size();
	//cin.get();
}

void testParkMiller()
{
	
	RandomParkMiller rpm(9);
	//Wrapper<RandomParkMiller> w();
	AntiThetic a(rpm);
	//long dim=rpm.GetDimensionality();
	//std::cout << "dimensions " << dim;
	//std::cin.get();

	NormalDistribution nma;
	double x = nma.getPi();
	double y = nma.NormalDensity(3.3);
	double z = nma.CumulativeNormal(3.5);
	double d = nma.InverseCumulativeNormal(0.025);
	double g = nma.NormalCDFInverse(0.025);
	//double y = nma.CumulativeNormal2(3.3);
	//double x = tryDD(1.1);
	std::cout << "normal cum " << x<<y<<z<<d<<g;
	std::cin.get();
}

void testParkM2()
{	
	ParkMiller pm(2);
	pm.SetSeed(0);
	RandomParkMiller rpm(2, 3);
	rpm.ResetDimensionality(4);
	//RandomParkMiller rp(2, 2);
	//ParkMiller pm(2);
}

void testMC8()
{
	double expiry = 5.0;
	double strike = 120.0;
	double spot = 100.0;
	double vol = 0.20;
	double r = 0.0;
	double lowerBand = 80;
	double upperBand = 130;
	unsigned long numberOfPaths = 1000.0;
	PayOffCall thePayOff(strike);
	VanillaOption theOption(thePayOff, expiry);

	//ParametersConstant vp(vol);
	ParametersConstant vp(vol);
	ParametersConstant rp(r);

	//stats
	StatisticsMean gatherer;
	ConvergenceTable gathererTwo(gatherer);

	RandomParkMiller generator(1);
	AntiThetic genTwo(generator);

	SimpleMonteCarlo6(theOption, spot, vp, rp, numberOfPaths, gathererTwo, genTwo);

	std::vector<std::vector<double>> results = gathererTwo.GetResultsSoFar();
	std::vector<std::vector<double>> prices = gatherer.GetResultsSoFar();

	std::cout << "\n for the call price the res are \n";
	for (unsigned long i = 0; i < results.size(); i++)
	{
		for (unsigned long j = 0; j < results[i].size(); j++)
		{
			std::cout << results[i][j];
			
		}


		std::cout << "\n";
	}

	std::cin.get();

	std::cout << "size is " << prices.size();

	/*
	std::cout << "\n for the call price the prices are \n";
	for (unsigned long i = 0; i < prices.size(); i++)
	{
		for (unsigned long j = 0; j < prices[i].size(); j++)
		{
			std::cout << prices[i][j];

		}


		std::cout << "\n";
	}

	std::cin.get();
	*/

}

void EquityFX()
{
	double expiry = 5.0;
	double strike = 120.0;
	double spot = 100.0;
	double vol = 0.20;
	double r = 0.0;
	double d = 0.0;
	double lowerBand = 80;
	double upperBand = 130;
	unsigned long numberOfPaths = 1000.0;
	unsigned long numberOfDates = 10;

	PayOffCall thePayOff(strike);

	MJArray times(numberOfDates);

	for (unsigned long i = 0; i < numberOfDates; i++)
		times.setValue(i, (i + 1.0)*expiry / numberOfDates);

	ParametersConstant VolParam(vol);
	ParametersConstant rParam(r);
	ParametersConstant dParam(d);

	PathDependentAsian2 theOption(times, expiry, thePayOff);

	StatisticsMean gatherer;
	ConvergenceTable gathererTwo(gatherer);

	RandomParkMiller generator(numberOfDates);
	AntiThetic genTwo(generator);

	ExoticBSEngine theEngine(theOption, rParam, dParam, VolParam, genTwo, spot);

	theEngine.DoSimulation(gathererTwo, numberOfPaths);

	std::vector<std::vector<double>> results = gathererTwo.GetResultsSoFar();

	std::cout << "\n for the Asian call price the res are \n";
	for (unsigned long i = 0; i < results.size(); i++)
	{
		for (unsigned long j = 0; j < results[i].size(); j++)
		{
			std::cout << results[i][j];

		}


		std::cout << "\n";
	}

	std::cin.get();

}

void testPayOffBridge()
{
	double expiry = 5.0;
	double strike = 120.0;
	double spot = 100.0;
	double vol = 0.20;
	double r = 0.0;
	double d = 0.0;
	double lowerBand = 80;
	double upperBand = 130;
	unsigned long numberOfPaths = 1000.0;
	unsigned long numberOfDates = 10;

	PayOffPut thePayOff(strike);
	PayOffBridge thePayOffBridge(thePayOff);
	double v = thePayOffBridge(spot);

	VanillaOption2 theOption(thePayOffBridge, expiry);
	double o = theOption.OptionPayOff(spot);

	std::cout << "payoff bridge value " << v << " and " << o;
	std::cin.get();
}

void testTrees()
{
	double expiry = 5.0;
	double strike = 120.0;
	double spot = 100.0;
	double vol = 0.20;
	double r = 0.0;
	double d = 0.0;
	ParametersConstant VolParam(vol);
	ParametersConstant rParam(r);
	ParametersConstant dParam(d);

	unsigned long numberOfPaths = 1000.0;
	unsigned long numberOfDates = 10;

	PayOffPut thePayOff(strike);

	TreeAmerican tAm(expiry, thePayOff);
	TreeEuropean tEu(expiry, thePayOff);

	double fVAm = tAm.PreFinalValue(spot, expiry, 100.0);
	double fVEu = tEu.PreFinalValue(spot, expiry, 100.0);

	std::cout << "final pay am/eu " << fVAm << " / " << fVEu;
	std::cin.get();

	unsigned long Steps = 100;
	SimpleBinomialTree bTree(spot, rParam, dParam, vol, Steps, expiry);

	double pr = bTree.getThePrice(tEu);
	std::cout << " price Binomial Tree EU " << pr;
	std::cin.get();

}

void testBSFormula()
{
	double expiry = 5.0;
	double strike = 120.0;
	double spot = 100.0;
	double vol = 0.20;
	double r = 0.0;
	double d = 0.0;

	double cPrice = BlackScholesCall(spot, strike, r, d, vol, expiry);
	std::cout << " BS call price " << cPrice;
	std::cin.get();



}

void testBisection()
{
	double expiry = 5.0;
	double strike = 120.0;
	double spot = 100.0;
	double vol = 0.20;
	double r = 0.0;
	double d = 0.0;

	BSCall theCall(r, d, expiry, spot, strike);
	double low = 0.0;
	double high = 100.0;
	double tol = 0.01;

	double cPrice = BlackScholesCall(spot, strike, r, d, vol, expiry); //target

	double targetVol = Bisection(cPrice, low, high, tol, theCall);

	std::cout << "vol is " << targetVol;
	std::cin.get();
}

void testNewton()
{
	double expiry = 5.0;
	double strike = 120.0;
	double spot = 100.0;
	double vol = 0.20;
	double r = 0.0;
	double d = 0.0;

	BSCallTwo theCall(r, d, expiry, spot, strike);

	double cPrice = BlackScholesCall(spot, strike, r, d, vol, expiry); //target

	double start = 0.10;
	double tol = 0.01;

	double volRes = NewtonRhapson<BSCallTwo, &BSCallTwo::Price, &BSCallTwo::Vega>(cPrice, start, tol, theCall);

	double volRes2 = NewtonRhapson < BSCallTwo, &BSCallTwo::Price, &BSCallTwo::Vega2>(cPrice, start, tol, theCall);

	std::cout << " newton vol is " << volRes <<"\n";
	std::cout << " newton 2 is " << volRes2;
	std::cin.get();
}

void testPayOffFactory()
{
	double Strike = 120.0;
	std::string name = "fff";

	PayOff* PayOffPtr = PayOffFactory::Instance().CreatePayOff(name, Strike);

	//check if payoff exists
	if (PayOffPtr != NULL)
	{
		double spot = 140.0;

		double payoff = PayOffPtr->operator()(spot);
		std::cout << " payoff is " << payoff;
		std::cin.get();

		//delete payoff;
		delete PayOffPtr;
	}
	else
	{
		std::cout << "such payoffdoes not exist";
		std::cin.get();
	}
}

int main() {
	//testMCCall2();
	testMCDigital();
	testMCv3();
	testMCv4();
	testMJArray();
	testParkMiller();
	testMC8();
	EquityFX();
	testPayOffBridge();
	testTrees();
	testBSFormula();
	testBisection();
	testNewton();
	testPayOffFactory();
	return 0;
}