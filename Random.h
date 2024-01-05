#include <algorithm> // for sort()
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <set> // for set
#include <vector> // for vector

void Random(long int *a, int n, int b, int c){
    srand(time(0));
    std::set<int> s; 
    while (s.size() < n) {
        s.insert(b + rand() % (c - b + 1));
    }
    std::vector<int> v(s.begin(), s.end());

    std::sort(v.begin(), v.end());
	for(int i = 0; i < n; i++){
		a[i] = v.at(i);
	}
}
