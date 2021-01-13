#include "..\headers\unique.hpp"

Unique::Unique() 
	:id(ID++)
{
}

Unique::Unique(Unique& unique)
	:id(ID++)
{
}
