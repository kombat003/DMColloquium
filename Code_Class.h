#include <iostream>
#include <vector>

class Polynomal
{
    private:
        std::vector<FullNum> Coof_;
	public:
	Polynomal()
	{
	}
	
	~Polynomal()
	{
	}
};

class RatNum
{
    private: 
        std::vector<FullNum> Num_;
        std::vector<NatNum> NatNum_;
};

class NatNum //I completely don't like this way of inheritance, we need an abstract class, anyway.
{
    protected:             
        std::vector<int> Num;
};

class FullNum: public NatNum
{
    private:
        int sign;
};