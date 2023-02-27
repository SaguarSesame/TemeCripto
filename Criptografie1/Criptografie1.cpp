#include <iostream>
using namespace std;

struct x {
	long long u, v;
};
struct divisor {
	x uv;
	unsigned long long d;
};

divisor CMMDC(unsigned long long a, unsigned long long b) {
	unsigned long long r, q;
	long long aux;
	x xa = { 1,0 }, xb = { 0,1 };
	divisor cmmdc;
	do
	{
		r = a % b;
		q = a / b;
		aux = xb.u;
		xb.u = xa.u - q * xb.u;
		xa.u = aux;
		aux = xb.v;
		xb.v = xa.v - q * xb.v;
		xa.v = aux;
		cout << xa.u << " " << xa.v << endl;
		a = b; b = r;
	} while (r != 0);
	cmmdc.d = a;
	cmmdc.uv.u = xa.u;
	cmmdc.uv.v = xa.v;
	return cmmdc;
}

unsigned cmmdc(unsigned a, unsigned b)
{
	if (a == 0 || b == 0)
		return a + b;
	unsigned r;
	do {
		r = a % b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}

int modulo(int a, int n) {
	if (a >= 0)
		return a % n;
	else
		return n + a % n;
}
int invers(int a, int n) {
	divisor X = CMMDC(a,n);
	if (cmmdc(a, n) != 1)
		return -1;
	else
	{
		return X.uv.u;
	}
}

int main()
{
	cout << invers(10, 9);
}
