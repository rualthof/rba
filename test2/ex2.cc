#include "ex2.h"
#include <string.h>

const char * MyString::CloneCString(const char * c){
	if(c==NULL) return NULL;
	const size_t len = strlen(c);
	char * const clone = new char[len+1];
	memcpy(clone, c, len+1);
	return clone;
}

void MyString::Set(const char * c){
	const char * temp = MyString::CloneCString(c);
	delete [] c_string_;
	c_string_ = temp;
}

