#pragma once
#include <cstdint>

struct Unique
{
private:
	static uint64_t ID;

public:
	const uint64_t id;
	Unique();
	Unique(Unique& unique);
};