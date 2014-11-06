#ifndef _uVECTOR_H_
#define _uVECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum _uVECTOR_TYPE
{
	uVECTOR_TYPE_INT		  = 1,
	uVECTOR_TYPE_CHAR		  = 2,
	uVECTOR_TYPE_FLOAT		  = 3,
	uVECTOR_TYPE_DOUBLE	  	  = 4
};
typedef enum _uVECTOR_TYPE uVectorType;

struct _uVector
{
/***********************
*member variable       *
***********************/
	void *container;
	size_t elem_size;
	
	size_t max_num_elem;
	size_t num_elem;
	
	size_t max_size_vec;
	size_t size_vec;
	
	uVectorType Type;
	
/***********************
*member function       *
***********************/
	
	/*Capacity*/
	size_t (*size)(struct _uVector*);	// point to _getSize, Returns the number of elements in the vector.
	size_t (*max_size)(struct _uVector*); // point to _getMaxSize, Returns the maximum number of elements that the vector can hold.
	void (*resize)(struct _uVector* ,size_t); // point to _resize, Resizes the container.
	//size_t (*capacity)(struct _uVector*); // point to _capacity, Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
	bool (*empty)(struct _uVector*); // point to _empty, test whether the vector is empty if it is empty returm true
	void (*push_back)(struct _uVector*, void*); // point to _pushBack, Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
	void* (*at)(struct _vector*, size_t);
	/*Modification*/

};
typedef struct _uVector uVector;


uVector *newv(uVectorType ,size_t );

/***********************************************************
*  < member function in struct _uVector >		   *
*  note : start with '_' means it will                     *
*  be pointed by another function has different name       *
***********************************************************/
size_t _getSize(struct _uVector*);
size_t _getMaxSize(struct _uVector*);
void _resize(struct _uVector* ,size_t);
bool _empty(struct _uVector*);
void _pushBack(struct _uVector*, void*);
void _at(struct _vector*, size_t);
#endif
