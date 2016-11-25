#ifndef _H_RAND_H_
#define _H_RAND_H_


class RandomGenerator {
	//pg 354
	//https://books.google.co.uk/books?id=-OHpBwAAQBAJ&pg=PA354&lpg=PA354&dq=mlcg+avoiding+overflow&source=bl&ots=jPeTqMm2gu&sig=OHvID6qxD5e9qF26vqeXvZqFkJU&hl=en&sa=X&ved=0ahUKEwiTn6uJ_KnKAhXIXB4KHfyVCfgQ6AEIHzAA#v=onepage&q=mlcg%20avoiding%20overflow&f=false
	//http://www.eternallyconfuzzled.com/tuts/algorithms/jsw_tut_rand.aspx
public:
	RandomGenerator() {
		_m = 2147483647;
		_a = 16807;
		_q = _m / _a;
		_r = _m%_a;
		_initialSeed = 4;
		_ni = _initialSeed;
	}
	RandomGenerator(int initialSeed) :_initialSeed(initialSeed), _ni(initialSeed) {
		_m = 2147483647;
		_a = 16807;
		_q = _m / _a;
		_r = _m%_a;
	}
	double getRand() {
		_ni = _a*(_ni%_q) - _r*(_ni / _q);
		if (_ni <= 0) {
			_ni += _m;
		}
		return _ni / (double)_m;
	}
	int getInitialSeed() {
		return _initialSeed;
	}
private:
	int _initialSeed;
	int _ni;
	int _m;
	int _a;
	int _q;
	int _r;
};


#endif
