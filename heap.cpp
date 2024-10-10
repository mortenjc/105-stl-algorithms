
#include <algorithm>
#include <utils.h>


// Create heap by construction, one element at a time
void pushheap(std::vector<int> v) {
  std::vector<int> w;
  for (int & elt : v) {
    w.push_back(elt);
    std::push_heap(w.begin(), w.end());
  }
  printvec(w);
}

// Create heap by initialisation
void makeheap(std::vector<int> v) {
  std::make_heap(v.begin(), v.end());
  printvec(v);
}

// Get sorted array from max heap
void popheap(std::vector<int> v) {
  std::make_heap(v.begin(), v.end());
  int len = v.size();
  std::vector<int> w;
  for (int i = 0; i < len; i++) {
    std::pop_heap(v.begin(), v.end());
    w.push_back(v.back());
    v.pop_back();
    printvec(v);
  }
  printvec(w);
}


// Create heap by initialisation
void sortheap(std::vector<int> v) {
  std::make_heap(v.begin(), v.end());
  std::sort_heap(v.begin(), v.end());
  printvec(v);
}


int main(int  argc, char * argv[]) {
  printf("Heap construction and manipulation from \n");
  std::vector<int> v{3, 2, 4, 1, 5, 9};
  printvec("push_heap\n", v);
  pushheap(v);

  printf("make_heap\n");
  makeheap(v);

  printf("pop_heap\n");
  popheap(v);

  printf("sort_heap\n");
  sortheap(v);
}
