#ifndef SERIALIZE_H
# define SERIALIZE_H

#include <cstdint>
#include "Data.hpp"

class Serializer {
	public:
		uintptr_t serialize(Data* ptr);
		//takes a pointer and converts it to the unsigned integer type uintptr_t.
		
		Data* deserialize(uintptr_t raw);
		//takes an unsigned integer parameter and converts it to a pointer to Data

	private: 
		Serializer();
		Serializer(Serializer const& rhs);
		Serializer& operator=(Serializer const& rhs);
		~Serializer();
};

#endif
