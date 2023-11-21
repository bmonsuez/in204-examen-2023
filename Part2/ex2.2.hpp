#pragma once

class interval
{
private:
    int lowerBound;
    int upperBound;

public:
    interval(): lowerBound(0), upperBound(0)
    {}
    interval(int theLowerBound, int theUpperBound): 
        lowerBound(theLowerBound), upperBound(theUpperBound)
    {}
    interval(const interval& anotherInterval):
        lowerBound(anotherInterval.lowerBound),
        upperBound(anotherInterval.upperBound)
    {}

    int getLowerBound() const { return lowerBound; }
    int getUpperBound() const { return upperBound; }
    
};

