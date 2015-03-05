// This program defines a simplified complex class
// + and cout is overloaded
// supports sum of complex numbers or complex number and standard type 

#include <iostream>

using namespace std;

template<class _Ty> class Complex
{
  public:
    Complex();       // constructors
	Complex(_Ty r);
	Complex(_Ty r, _Ty i);
	Complex operator+ (const Complex &);  //two complex number sum
	Complex operator+ (const _Ty &);     // complex+scalar
	template <typename _Tx>
	friend Complex<_Tx> operator+ (const _Tx &, const Complex<_Tx> &); //scalr+complex
	template <typename _Tz>
	friend ostream & operator<< (ostream &, const Complex<_Tz> &);  //overload cout
  private:
     _Ty real;
	 _Ty imag;
};

// definition of constructors 
template <class _Ty>
Complex <_Ty>::Complex() {real=(_Ty)0; imag=(_Ty)0;}

template <class _Ty>
Complex <_Ty>::Complex(_Ty r) {real=r;imag=(_Ty)0;}

template <class _Ty>
Complex <_Ty>::Complex(_Ty r, _Ty i):real (r), imag (i) {}

// definition of operator overloading
template<class _Ty> 
Complex <_Ty> Complex <_Ty>::operator+(const Complex <_Ty> &c2)
{
   return Complex<_Ty> (real+c2.real, imag+c2.imag);
}

template<class _Ty>
Complex<_Ty> Complex<_Ty>::operator+(const _Ty &i)
{
  return Complex<_Ty>(real+i,imag);
}


template<class _Tx>
Complex<_Tx> operator+ (const _Tx &i, const Complex<_Tx> &c)
{
   return Complex<_Tx>(i+c.real, c.imag);
}

template <class _Tz>
ostream & operator<< (ostream &out, const Complex<_Tz> &c)
{
  if (c.imag>=0)
     out<<c.real<<'+'<<c.imag<<'i'<<endl;
	 else
	   out<<c.real<<c.imag<<'i'<<endl;
  return out;
}


int main()
{
  int real1=5,real2=7;
  float real3=2.3,real4=2.6;
  int imag1=3, imag2=4;
  float imag3=3.2, imag4=7.2;
  Complex <int> c1(real1,imag1), c2(real2, imag2),c3;
  cout<<(c3=c1+c2)<<endl; // two complex number with integer parts
  Complex <float> c4(real3, imag3), c5(real4, imag4),c6;
  cout<<(c6=c4+c5)<<endl; // two complex number with float parts
  Complex <int> c7(real1, imag1),c8;
  cout<<(c8=c7+real1)<<endl; // a integer complex number+integer
  Complex <float> c9 (real3, imag3),c10;
  cout<<(c10=c9+real3)<<endl; // a float complex number+float
  Complex <float> c11 (real4, imag4), c12;
  cout<<(c12=real4+c11)<<endl; // a float number+float complex
  
  return 0;

  return 0;
}