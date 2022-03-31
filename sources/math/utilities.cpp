#include "math/utilities.h"


int gcd(int first, int second) {
	if (second == 0)
		return first;
	return gcd(second, first % second);
}