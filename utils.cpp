
#include <utils.h>


void printvec(std::string text, std::vector<int> v) {
  printf("%s", text.c_str());
  printvec(v);
}


void printvec(std::vector<int> v) {
  for (auto & elt : v) {
    printf("%d ", elt);
  }
  printf("\n");
}


void mexpect(std::vector<int> res, std::vector<int> expect) {
  if (not std::equal(res.begin(), res.end(), expect.begin(), expect.end())) {
    printvec("error: expected ", expect);
    printvec("but result was  ", res);
    exit(0);
  }
}


void massert_true(bool result) {
  if (result != true) {
    printf("assert error: expected true\n");
    exit(0);
  }
}
