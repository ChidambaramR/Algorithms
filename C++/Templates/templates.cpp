#include <iostream>
using namespace std;

template<class T>
double GetAverage(T tArray[], int nElements)
{
    /*
    This is nothing but calling the constructor. If int is passed,
	this is equivalent to int tSum = int(); It will initialize 
	tSum to 0. We are doing this because, we cannot simply initialize
	tSum to 0 because we dont know if this is an integer or not. So we
	have to call the constructor.
    */
    T tSum = T(); // tSum = 0

    for (int nIndex = 0; nIndex < nElements; ++nIndex)
    {
	/*
	This will work fine for an integer. But in real time we would not
	know if += can be applied to tArray. If the passed input is a string
	then the compiler will identify it and throw an error.
	*/
        tSum += tArray[nIndex];
    }

    // Whatever type of T is, convert to double
    return double(tSum) / nElements;
}
  

int main()
{
    int  IntArray[5] = {100, 200, 400, 500, 1000};
    float FloatArray[3] = { 1.55f, 5.44f, 12.36f};

    cout << GetAverage(IntArray, 5);
    cout << GetAverage(FloatArray, 3);
}
