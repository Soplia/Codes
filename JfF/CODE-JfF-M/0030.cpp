
#include <bolt/cl/sort.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> a (8192);
	generate(a.begin(),a.end(),rand);
	bolt::cl::sort(a.begin(),a.end());
	
	return 0;
}
