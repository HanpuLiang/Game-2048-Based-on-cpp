
#include <cstdlib>

double Rand021() {
	return rand() / double(RAND_MAX);
}

int RandA2B(int A, int B) {
	double tA = double(A);
	double tB = double(B);
	return int(Rand021() * (tB-tA) + tA);
}
