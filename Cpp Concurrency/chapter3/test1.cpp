#include <string>
#include <cstdio>

std::string FetchFormat(){
	return "%d\n";
}
 
 
int main(){
	printf(FetchFormat().c_str(), 100);

	return 0;
}
