#pragma once

class interval
{
private:
    int lowerBound;
    int upperBound;

public:
    interval(): lowerBound(1), upperBound(0)
    {}

    interval(int theLowerBound, int theUpperBound): 
        lowerBound(theLowerBound), upperBound(theUpperBound)
    {
        if(upperBound < lowerBound)
        {
            lowerBound = 1; 
            upperBound = 0;
        }
    }

    interval(const interval& anotherInterval):
        lowerBound(anotherInterval.lowerBound),
        upperBound(anotherInterval.upperBound)
    {}

    int getLowerBound() const { return lowerBound; }
    int getUpperBound() const { return upperBound; }

    static interval create(int theLowerBound, int theLength)    
    {
        return interval(theLowerBound, theLowerBound + theLength);
    }

    bool is_empty() const { return upperBound < lowerBound; }


    bool operator == (const interval& anotherInterval) const
    {
        return anotherInterval.lowerBound == lowerBound
            && anotherInterval.upperBound == upperBound;
    }

    bool operator <= (const interval& anotherInterval) const
    {
        return is_empty() ||
            (lowerBound >= anotherInterval.lowerBound 
                && upperBound <= anotherInterval.upperBound);
    }

    bool operator >= (const interval& anotherInterval) const
    {
        return is_empty() ||
            (lowerBound <= anotherInterval.lowerBound 
                && upperBound >= anotherInterval.upperBound);
    }

    bool operator != (const interval& anotherInterval) const
    {
        return !(*this == anotherInterval);
    }

    bool operator < (const interval& anotherInterval) const
    {
        return *this <= anotherInterval && *this != anotherInterval;
    }

    bool operator > (const interval& anotherInterval) const
    {
        return *this >= anotherInterval && *this != anotherInterval;
    }

};

