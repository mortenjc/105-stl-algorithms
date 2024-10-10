
#include <algorithm>
#include <utils.h>


void setdifference(std::vector<int> a, std::vector<int> b, std::vector<int> expect) {
  std::vector<int> diff;

  std::set_difference(a.begin(), a.end(), b.begin(), b.end(),
                      std::back_inserter(diff));

  mexpect(diff, expect);
  printvec("difference: ", diff);
}


void setintersection(std::vector<int> a, std::vector<int> b, std::vector<int> expect) {
  std::vector<int> diff;

  std::set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                        std::back_inserter(diff));

  mexpect(diff, expect);
  printvec("intersect : ", diff);
}


void setunion(std::vector<int> a, std::vector<int> b, std::vector<int> expect) {
  std::vector<int> diff;

  std::set_union(a.begin(), a.end(), b.begin(), b.end(),
                 std::back_inserter(diff));

  mexpect(diff, expect);
  printvec("union     : ", diff);
}


void setsymmdiff(std::vector<int> a, std::vector<int> b, std::vector<int> expect) {
  std::vector<int> diff;

  std::set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(),
                                std::back_inserter(diff));

  mexpect(diff, expect);
  printvec("symm diff : ", diff);
}


bool setincludes(std::vector<int> a, std::vector<int> c) {
  return std::includes(a.begin(), a.end(), c.begin(), c.end());
}


void setmerge(std::vector<int> a, std::vector<int> b, std::vector<int> expect) {
  std::vector<int> diff;

  std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(diff));

  mexpect(diff, expect);
  printvec("merge     : ", diff);
}


int main(int  argc, char * argv[]) {
  std::vector<int> a{1, 2, 3, 4, 5, 9};
  std::vector<int> b{2, 4, 7, 42, 99};

  printf("Set construction and manipulation from the two vectors\n");
  printvec("a         : ", a);
  printvec("b         : ", b);

  if (not std::is_sorted(a.begin(), a.end()) or not std::is_sorted(b.begin(), b.end())) {
    printf("vectors a and b must be sorted\n");
    exit(0);
  }

  setintersection(a, b, std::vector<int>{2, 4});
  setdifference(a, b, std::vector<int>{1, 3, 5, 9});
  setsymmdiff(a, b, std::vector<int>{1, 3, 5, 7, 9, 42, 99});
  setunion(a, b, std::vector<int>{1, 2, 3, 4, 5, 7, 9, 42, 99});
  setmerge(a, b, std::vector<int>{1, 2, 2, 3, 4, 4, 5, 7, 9, 42, 99});

  massert_true(setincludes(a, std::vector<int>{3, 9}));
  printf("vector a contains {3, 9} - passed\n");
}
