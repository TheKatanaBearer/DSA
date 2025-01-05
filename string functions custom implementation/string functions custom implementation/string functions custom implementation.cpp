


#include<iostream>
using namespace std;


//str length



//int main() {
//    const char* str = "Hello, World!";              //const is necessary here
//    std::cout << "Length: " << strlen(str) << std::endl;
//    return 0;
//}


//its custom implemetation


//size_t my_strlen(const char* hamza) {
//	size_t length = 0;
//
//	while (hamza[length] != '\0') {
//		length++;
//	}
//
//	return length;
//}
//
//
//int main() {
//	const char* str = "Hello, World!";
//	std::cout << "Length: " << my_strlen(str) << std::endl;
//	return 0;
//}











//str cpy
//
//int main() {
//	char hamza[] = "abdullah is a good boy ";
//
//	char abdullah[50];
//
//	strcpy(abdullah, hamza);
//
//	cout << "the copied string is " << abdullah;
//}


//now this is the custom implementation of it

//
//char* my_Strcpy(char* dest, const char* src) {
//	char* start = dest;
//
//
//	while ((*dest++ = *src++) != '\0') {
//		return start;
//	}
//}
//
//int main() {
//	char src[] = "my name is hamza khan ";
//
//	char dest[50];
//
//	my_Strcpy(dest, src);
//
//	cout << dest;
//}



//strncpy
//
//int main() {
//
//	char src[] = "hello world";
//
//	char dest[20];
//
//	strncpy_s(dest, src, 5);
//
//
//	cout << dest;
//
//
//}



//now this is the custom implementation of it

//char* my_strncpy(char* dest, const char* src, size_t n) {
//	size_t i;
//	for ( i = 0; src[i] != '\0'; i++) {
//		dest[i] = src[i];
//	}
//
//
//	for (; i < n; i++) {
//		dest[i] = '\0';
//	}
//
//	return dest;
//}
//
//
//int main() {
//	const char src[] = "Hello, World!";
//	char dest[20];
//	my_strncpy(dest, src, 5);
//	std::cout << "Copied String: " << dest << std::endl;
//	return 0;
//}



// this is the useage of strcat()


//int main() {
//	char dest[50] = "hello ";
//	char src[] = "world! ";
//
//	strcat(dest, src);
//	cout << dest;
//}



//this is the custom implementation of strcmp()

//
//char* my_Strcat(char* dest, const char* source) {
//	char* start = dest;
//
//	while (*dest) {
//		dest++;
//	}
//
//	while ((*dest++ = *source++) != '\0');
//
//	return start;
//
//
//
//}
//
//int main() {
//	char dest[50] = "hello!";
//
//	char src[] = "world ";
//
//	my_Strcat(dest, src);
//
//	cout << dest;
//}





//this is for the strncat

//
//char* my_strncat(char* dest, const char* src, size_t n) {
//	char* start = dest;
//
//	while (*dest) {
//		dest++;
//
//	}
//	while (n-- && (*dest++ = *src++) != '\0');
//
//	if (n == 0) {
//
//		*dest = '\0';
//	}
//
//	return start;
//
//}
//
//int main() {
//	char dest[50] = "Hello, ";
//	char src[] = "World!";
//	my_strncat(dest, src, 3);
//	std::cout << "Concatenated String: " << dest << std::endl;
//	return 0;
//}










//this is the usage of str cmp

//int main() {
//	const char* str1 = "hello ";
//	const char* str2 = "world ";
//
//	int result = strcmp(str1, str2);
//
//	if (result < 0) {
//
//		cout << str1 << "is less than " << str2 << endl;
//	}
//
//	else if (result == 0) {
//		cout << str1 << "is equal to " << str2;
//	}
//
//	else {
//		cout << str1 << "is greater than " << str2 << endl;
//	}
//
//	return 0;
//
//
//}



//this is the custom implementation of strcmp

int strcmp(const char* s1, const char* s2)
{
	for (; *s1 == *s2; s1++,s2++) {

	}if (*s1 == '\0') {
		return 0;
	}

	return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
}