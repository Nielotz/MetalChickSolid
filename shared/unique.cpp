#include "..\headers\unique.hpp"

uint64_t Unique::ID = 0;

Unique::Unique() 
	:id(ID++)
{
}

Unique::Unique(Unique& unique)
	:id(ID++)
{
}
