Practice-Vector-In-C
====================

It's a practice about dynamic memory access with implement a vector like api  in c

/******************
*    demo code    *
******************/
int *a,*b;
	int ele1 = 1;
	int ele2 = 2;
	int ele3 = 3;
	int ele4 = 4;
	int ele5 = 5;
	uVectorType type;
	type = uVECTOR_TYPE_INT;
	uVector *vector = newv(type);
	vector->push_back(vector,&ele1);
	vector->push_back(vector,&ele2);
	vector->push_back(vector,&ele3);
	vector->push_back(vector,&ele4);
	vector->push_back(vector,&ele5);
	
	
	a=vector->at(vector,0);
	printf("%d\n",*a);
	a=vector->at(vector,3);
	printf("%d\n",*a);
	a=vector->at(vector,1);
	printf("%d\n",*a);
	a=vector->at(vector,2);
	printf("%d\n",*a);
	a=vector->at(vector,4);
	*a=7;
	printf("%d\n",*a);
	
	
	b=vector->at(vector,5);
	printf("%d\n",*b);
	
	
	// test resize 
	vector->resize(vector,2);
	
	a=vector->at(vector,2);
	printf("%d\n",*a);
	a=vector->at(vector,0);
	printf("%d\n",*a);
	a=vector->at(vector,1);
	printf("%d\n",*a);
	
	
	//test pop back
	vector->pop_back(vector);
	a=vector->at(vector,0);
	printf("%d\n",*a);
