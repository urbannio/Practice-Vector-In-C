#include "VectorInC.h"

uVector *newv(uVectorType uvectortype,size_t max_num_elem)
{	
	uVector *uvector = (uVector*)malloc(sizeof(uVector));
	
	uvector->Type = uvectortype;
	uvector->max_num_elem = max_num_elem;
	uvector->max_size = &_getMaxSize;
	uvector->num_elem = 0;
	
	switch(uvectortype)
	{
		case uVECTOR_TYPE_INT:
			
			uvector->max_size_vec = max_num_elem*sizeof(int);
			uvector->container = malloc(uvector->max_size_vec);
			uvector->elem_size = sizeof(int);
			return uvector;
		break;
		
		case uVECTOR_TYPE_CHAR:
			
			uvector->max_size_vec = max_num_elem*sizeof(char);
			uvector->container = malloc(uvector->max_size_vec);
			uvector->elem_size = sizeof(char);
			return uvector;
		break;
		
		case uVECTOR_TYPE_FLOAT:
			
			uvector->max_size_vec = max_num_elem*sizeof(float);
			uvector->container = malloc(uvector->max_size_vec);
			uvector->elem_size = sizeof(float);
			return uvector;
		break;
		
		case uVECTOR_TYPE_DOUBLE:
			
			uvector->max_size_vec = max_num_elem*sizeof(double);
			uvector->container = malloc(uvector->max_size_vec);
			uvector->elem_size = sizeof(double);
			return uvector;
		break;
	}
}
size_t _getSize(struct _uVector *uvector)
{
	return uvector->num_elem;
}

size_t _getMaxSize(struct _uVector *uvector)
{
	return uvector->max_size_vec;
}

void _pushBack(struct _uVector* uvector, void* newelem)
{
	uvector->container[uvector->num_elem] = newelem;
}
