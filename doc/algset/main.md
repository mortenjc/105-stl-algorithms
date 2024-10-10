# Glorious county of Algos on Sets
Note that all these algorithms expects sets to be sorted. See example code
in **sets.cpp**.

The following algorithms are tested

    set_difference
    set_intersection
    set_union
    set_symmetric_difference
    includes
    merge

Based on vectors a and b

    std::vector<int> a{1, 2, 3, 4, 5, 9};
    std::vector<int> b{2, 4, 7, 42, 99};

We expect the following outcomes

    setintersection(a, b, std::vector<int>{2, 4});
    setdifference(a, b, std::vector<int>{1, 3, 5, 9});
    setsymmdiff(a, b, std::vector<int>{1, 3, 5, 7, 9, 42, 99});
    setunion(a, b, std::vector<int>{1, 2, 3, 4, 5, 7, 9, 42, 99});
    setmerge(a, b, std::vector<int>{1, 2, 2, 3, 4, 4, 5, 7, 9, 42, 99});
