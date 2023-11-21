#pragma once

#include<algorithm>
#include<concepts>
#include<iostream>

template<class T>
    requires std::integral<T> || std::floating_point<T>
class interval
{
private:
    T lowerBound;
    T upperBound;

public:
    typedef T value_type;

    interval(): 
        lowerBound((value_type)1), 
        upperBound((value_type)0)
    {}

    interval(
        value_type theLowerBound, 
        value_type theUpperBound): 
        lowerBound(theLowerBound), upperBound(theUpperBound)
    {
        if(upperBound < lowerBound)
        {
            lowerBound = 1; 
            upperBound = 0;
        }
    }

    interval(const interval<T>& anotherInterval):
        lowerBound(anotherInterval.lowerBound),
        upperBound(anotherInterval.upperBound)
    {}

    value_type getLowerBound() const { return lowerBound; }
    value_type getUpperBound() const { return upperBound; }

    static interval create(value_type theLowerBound, value_type theLength)    
    {
        return interval(theLowerBound, theLowerBound + theLength);
    }

    bool is_empty() const { return upperBound < lowerBound; }


    bool operator == (const interval<T>& anotherInterval) const
    {
        return anotherInterval.lowerBound == lowerBound
            && anotherInterval.upperBound == upperBound;
    }

    bool operator <= (const interval<T>& anotherInterval) const
    {
        return is_empty() ||
            (lowerBound >= anotherInterval.lowerBound 
                && upperBound <= anotherInterval.upperBound);
    }

    bool operator >= (const interval<T>& anotherInterval) const
    {
        return is_empty() ||
            (lowerBound <= anotherInterval.lowerBound 
                && upperBound >= anotherInterval.upperBound);
    }

    bool operator != (const interval<T>& anotherInterval) const
    {
        return !(*this == anotherInterval);
    }

    bool operator < (const interval<T>& anotherInterval) const
    {
        return *this <= anotherInterval && *this != anotherInterval;
    }

    bool operator > (const interval<T>& anotherInterval) const
    {
        return *this >= anotherInterval && *this != anotherInterval;
    }

    interval operator & (const interval<T>& anotherInterval) const
    {
        return interval(
            std::max(lowerBound, anotherInterval.lowerBound),
            std::min(upperBound, anotherInterval.upperBound));
    }

    interval operator | (const interval<T>& anotherInterval) const
    {
        return interval(
            std::min(lowerBound, anotherInterval.lowerBound),
            std::max(upperBound, anotherInterval.upperBound));
    }

};

template<
    typename T, 
    typename charT, typename traits>
std::basic_ostream<charT, traits>&
    operator << (std::basic_ostream<charT, traits>& aStream,
        const interval<T>& theInterval)
{
    aStream << "[";
    if(!theInterval.is_empty())
        aStream << theInterval.getLowerBound() 
            << ", " 
            << theInterval.getUpperBound();
    aStream << "]";
    return aStream;
}

