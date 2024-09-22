
#include <algorithm>
#include <vector>



void printvec(std::vector<int> v) {

  for (auto & elt : v) {
    printf("%d ", elt);
  }
  printf("\n");
}


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


int main(int  argc, char * argv[]) {
  printf("Heap construction and manipulation from \n");
  std::vector<int> v{3, 2, 4, 1, 5, 9};
  printvec(v);
  printf("push_heap\n");
  pushheap(v);
  printf("make_heap\n");
  makeheap(v);
}
