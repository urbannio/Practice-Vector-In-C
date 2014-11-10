#include "VectorInC.h"

uVector *newv(uVectorType uvectortype)
{	
	
	uVector *uvector = (uVector*)malloc(sizeof(uVector));
	
	uvector->Type = uvectortype;
	uvector->num_elem = 0;
	uvector->size_vec = 0;  

	uvector->push_back  = &_pushBack;
	uvector->at 		= &_at;
	uvector->pop_back   = &_popBack;
	uvector->resize     = &_resize;
	uvector->empty      = &_empty;
	uvector->clear      = &_clear;
	uvector->front      = &_front;
	
	switch(uvectortype)
	{
		case uVECTOR_TYPE_INT:
			uvector->elem_size = sizeof(int);
		break;
		
		case uVECTOR_TYPE_CHAR:
			uvector->elem_size = sizeof(char);
		break;
		
		case uVECTOR_TYPE_FLOAT:
			uvector->elem_size = sizeof(float);
		break;
		
		case uVECTOR_TYPE_DOUBLE:
			uvector->elem_size = sizeof(double);
		break;
	}
	
	return uvector;
}

size_t _size(struct _uVector *uvector)
{
	return uvector->num_elem;
}

void _pushBack(struct _uVector* uvector, void* newelem)
{
	uvector->resize(uvector,uvector->num_elem+1);
	memcpy(uvector->container+uvector->num_elem*uvector->elem_size, newelem, uvector->elem_size);
	uvector->num_elem++;
	_debug(uvector);
}

void* _at(struct _uVector* uvector, int offset)
{
	if(offset>uvector->num_elem)return NULL;
	return uvector->container+offset*uvector->elem_size;
}

void _resize(struct _uVector* uvector,size_t nsize)
{	
	
	if(nsize==0)
	{
		uvector->clear(uvector);
		return;
	}
	
	if(uvector->size_vec==0)
	{
		uvector->container = malloc(nsize*uvector->Type);
		uvector->size_vec = nsize*uvector->Type;
		return;
	}
	if(nsize==uvector->num_elem)return;
	
	void *tmp = malloc(nsize*uvector->elem_size);
	if(nsize<uvector->num_elem)
	{
		memcpy(tmp, uvector->container, nsize*uvector->elem_size);
		uvector->num_elem = nsize;
	}
	else
	{
		memcpy(tmp, uvector->container, uvector->elem_size*uvector->num_elem);
	}
	
	free(uvector->container);
	uvector->container = malloc(nsize*uvector->elem_size);
	memcpy(uvector->container, tmp, uvector->elem_size*nsize);
	free(tmp);
	uvector->size_vec=nsize*uvector->elem_size;
	_debug(uvector);
}

void _clear(struct _uVector* uvector)
{
	free(uvector->container);
	uvector->num_elem = 0;
	uvector->size_vec = 0;
}

void _popBack(struct _uVector* uvector)
{
	_resize(uvector,uvector->num_elem-1);
	uvector->num_elem--;
}

int _empty(struct _uVector* uvector)
{
	_debug(uvector);
	if(uvector->num_elem>0)
		return 0;
	else 
		return 1;
}



extern void _debug(struct _uVector* uvector)
{
	printf("elem_size    = %d\n",uvector->elem_size);
	printf("num_elem     = %d\n",uvector->num_elem);
	printf("size_vec     = %d\n\n",uvector->size_vec);
}