#ifndef _uVECTOR_H_
#define _uVECTOR_H_

#include <stdio.h>
#include <stdlib.h>



enum _uVECTOR_TYPE
{
	uVECTOR_TYPE_INT		= 1,
	uVECTOR_TYPE_CHAR		= 2,
	uVECTOR_TYPE_FLOAT		= 3,
	uVECTOR_TYPE_DOUBLE		= 4
};
typedef enum _uVECTOR_TYPE uVectorType;

struct _uVector
{
	/***********************
	*	member variable    *
    ***********************/
	void *container;
	
	size_t elem_size;   // size of one element
	size_t num_elem;    // number of element in the vector
	size_t size_vec;    // (number of element in the vector) * (size of one element)
	
	
	uVectorType Type; 
	
	/***********************
	*	member function    *
    ***********************/
	
	/*Capacity*/
	size_t   (*size)      (struct _uVector*);	                     // point to _getSize, Returns the number of elements in the vector.
	void     (*resize)    (struct _uVector*, size_t);                // point to _resize, Resizes the container.
	size_t   (*capacity)  (struct _uVector*);                        // point to _capacity, Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
	int      (*empty)     (struct _uVector*);                        // point to _empty, test whether the vector is empty if it is empty returm true
	void     (*push_back) (struct _uVector*, void*);                 // point to _pushBack, Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
	void*    (*at)        (struct _uVector*, int);
	void     (*pop_back)  (struct _uVector*);                        // point to _popBack, Removes the last element in the vector
	void     (*clear)     (struct _uVector*);
	void*    (*front)     (struct _uVector*);
	/*Modification*/

};
typedef	struct _uVector uVector;

/*******************************
*	< non-member function >    *	
*******************************/
uVector *newv(uVectorType);
void _debug(struct _uVector*);


/***********************************************************
*  < member function in struct _uVector >				   *
*  note : start with '_' means it will                     *
*  be pointed by another function has different name       *
***********************************************************/
size_t  _size      (struct _uVector*);
void    _resize    (struct _uVector*, size_t);
void    _capacity  (struct _uVector*);
int     _empty     (struct _uVector*);
void    _pushBack  (struct _uVector*, void*);
void*   _at        (struct _uVector*, int);
void    _popBack   (struct _uVector*);
void    _clear     (struct _uVector*);
void*   _front     (struct _uVector*);
#endif
