#pragma once
#include <random>
#include <memory>

class Randgen {
public:
	Randgen();
	Randgen(uint64_t seed, uint64_t discard_time = 0);
	~Randgen();

	std::unique_ptr<Randgen> copy();

	inline uint64_t getSeed() const;
	inline uint64_t getGenTime() const;

	inline uint64_t rand();
	
	// min_value <= rand <= max_value
	template<typename T>
	T rand(T min_value, T max_value, bool include_max_value = true);

private:
	uint64_t seed;
	std::mt19937_64 mt_engine;
	uint64_t gen_time;
};

Randgen::Randgen() :
	gen_time(0) {
	std::random_device seed_generator;
	this->seed = seed_generator();
	this->mt_engine.seed(this->seed);
}

Randgen::Randgen(uint64_t seed, uint64_t discard_time) :
	gen_time(0),
	seed(seed) {
	this->mt_engine.seed(this->seed);
	this->mt_engine.discard(discard_time);
}

Randgen::~Randgen() {
}

std::unique_ptr<Randgen> Randgen::copy() {
	return std::make_unique<Randgen>(this->seed, this->gen_time);
}

inline uint64_t Randgen::getSeed() const {
	return this->seed;
}

inline uint64_t Randgen::getGenTime() const {
	return this->gen_time;
}

inline uint64_t Randgen::rand() {
	++gen_time;
	return mt_engine();
}

template<typename T>
inline T Randgen::rand(T min_value, T max_value, bool include_max_value) {
	return T();
}

template<>
inline int8_t Randgen::rand(int8_t min_value, int8_t max_value, bool include_max_value) {
	if (min_value > max_value)
		std::swap(min_value, max_value);
	uint8_t diff = max_value-min_value;
	if (include_max_value) {
		if (diff >= UINT8_MAX) {
			return this->rand()%UINT8_MAX+min_value;
		} else {
			++diff;
		}
	}
	return this->rand()%diff+min_value;
}

template<>
inline int16_t Randgen::rand(int16_t min_value, int16_t max_value, bool include_max_value) {
	if (min_value > max_value)
		std::swap(min_value, max_value);
	uint16_t diff = max_value-min_value;
	if (include_max_value) {
		if (diff >= UINT16_MAX) {
			return this->rand()%UINT16_MAX+min_value;
		} else {
			++diff;
		}
	}
	return this->rand()%diff+min_value;
}

template<>
inline int32_t Randgen::rand(int32_t min_value, int32_t max_value, bool include_max_value) {
	if (min_value > max_value)
		std::swap(min_value, max_value);
	uint32_t diff = max_value-min_value;
	if (include_max_value) {
		if (diff >= UINT32_MAX) {
			return this->rand()%UINT32_MAX+min_value;
		} else {
			++diff;
		}
	}
	return this->rand()%diff+min_value;
}

template<>
inline int64_t Randgen::rand(int64_t min_value, int64_t max_value, bool include_max_value) {
	if (min_value > max_value)
		std::swap(min_value, max_value);
	uint64_t diff = max_value-min_value;
	if (include_max_value) {
		if (diff >= UINT64_MAX) {
			return this->rand()%UINT64_MAX+min_value;
		} else {
			++diff;
		}
	}
	return this->rand()%diff+min_value;
}

template<>
inline uint8_t Randgen::rand(uint8_t min_value, uint8_t max_value, bool include_max_value) {
	if (min_value > max_value)
		std::swap(min_value, max_value);
	uint8_t diff = max_value-min_value;
	if (include_max_value) {
		if (diff >= UINT8_MAX) {
			return this->rand()%UINT8_MAX+min_value;
		} else {
			++diff;
		}
	}
	return this->rand()%diff+min_value;
}

template<>
inline uint16_t Randgen::rand(uint16_t min_value, uint16_t max_value, bool include_max_value) {
	if (min_value > max_value)
		std::swap(min_value, max_value);
	uint16_t diff = max_value-min_value;
	if (include_max_value) {
		if (diff >= UINT16_MAX) {
			return this->rand()%UINT16_MAX+min_value;
		} else {
			++diff;
		}
	}
	return this->rand()%diff+min_value;
}

template<>
inline uint32_t Randgen::rand(uint32_t min_value, uint32_t max_value, bool include_max_value) {
	if (min_value > max_value)
		std::swap(min_value, max_value);
	uint32_t diff = max_value-min_value;
	if (include_max_value) {
		if (diff >= UINT32_MAX) {
			return this->rand()%UINT32_MAX+min_value;
		} else {
			++diff;
		}
	}
	return this->rand()%diff+min_value;
}

template<>
inline uint64_t Randgen::rand(uint64_t min_value, uint64_t max_value, bool include_max_value) {
	if (min_value > max_value)
		std::swap(min_value, max_value);
	uint64_t diff = max_value-min_value;
	if (include_max_value) {
		if (diff >= UINT64_MAX) {
			return this->rand()%UINT64_MAX+min_value;
		} else {
			++diff;
		}
	}
	return this->rand()%diff+min_value;
}

template<>
inline float Randgen::rand(float min_value, float max_value, bool include_max_value) {
	if (min_value > max_value)
		std::swap(min_value, max_value);
	float diff = max_value-min_value;
	float rand_value = static_cast<float>(this->rand())/this->mt_engine.max();
	return rand_value*diff+min_value;
}

template<>
inline double Randgen::rand(double min_value, double max_value, bool include_max_value) {
	if (min_value > max_value)
		std::swap(min_value, max_value);
	double diff = max_value-min_value;
	double rand_value = static_cast<double>(this->rand())/this->mt_engine.max();
	return rand_value*diff+min_value;
}