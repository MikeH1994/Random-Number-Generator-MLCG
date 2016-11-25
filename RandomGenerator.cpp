#include"RandomGenerator.h"

RandomGenerator::RandomGenerator() {
		_m = 2147483647;
		_a = 16807;
		_q = _m / _a;
		_r = _m%_a;
		_initialSeed = 4;
		_ni = _initialSeed;
}
RandomGenerator::RandomGenerator(int initialSeed) :_initialSeed(initialSeed), _ni(initialSeed) {
	_m = 2147483647;
	_a = 16807;
	_q = _m / _a;
	_r = _m%_a;
}
double RandomGenerator::getRand() {
	_ni = _a*(_ni%_q) - _r*(_ni / _q);
	if (_ni <= 0) {
		_ni += _m;
	}
	return _ni / (double)_m;
}
int RandomGenerator::getInitialSeed() {
	return _initialSeed;
}

