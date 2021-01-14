#include "..\headers\unique.hpp"

uint64_t Unique::ID = 0;

Unique::Unique() 
	:id(ID++)
{
}

Unique::Unique(const Unique& unique)
	:id(ID++)
{
}
