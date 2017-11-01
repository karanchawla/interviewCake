#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std; 

class Temperature
{
private: 
	int currentTemperature; 

	int maxTemperature;
	int minTemperature;

	double meanTemperature;
	int numOfSamples;
	double sumOfTempratures;

	// for mode
    vector<size_t> occurrences_;
    size_t maxOccurrences_;
    int mode_;
public:
	Temperature():
	currentTemperature(0),
	maxTemperature(INT_MIN),
	minTemperature(INT_MAX),
	meanTemperature(0),
	numOfSamples(0),
	sumOfTempratures(0),
	occurrences_(111), // vector of 0s at indices 0..110
    maxOccurrences_(0),
    mode_(0),
	{

	}

	void insert(int tempValue)
	{
		size_t currentTemperatureOccurrences = ++occurrences_[tempValue];
        if (currentTemperatureOccurrences > maxOccurrences_) {
            mode_ = tempValue;
            maxOccurrences_ = currentTemperatureOccurrences;
        }

		maxTemperature = max(maxTemperature, tempValue);
		minTemperature = min(minTemperature, tempValue);

		currentTemperature = tempValue;

		numOfSamples++;
		sumOfTempratures += tempValue;
		meanTemperature = sumOfTempratures / numOfSamples;
	}

	int getMax() const
	{
		return maxTemperature;
	}

	int getMin() const
	{
		return minTemperature;
	}

	double getMean() const
	{
		return meanTemperature;
	}

	int getMode() const
	{
		return mode_;
	}
};