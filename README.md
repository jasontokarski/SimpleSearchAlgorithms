<h2>Search Algorithms</h2>

This program includes an implemention of a C++ program that generates random integers and compares the result to another set of integers using two basic search methods. (*linear search and binary search*) The number of matching integers is then displayed.
 
In this file, there are four main routines. They include the following:

* `void average_comparisons(const std::vector<int>& inputVec, const std::vector<int>& searchVec, bool(*search)(const std::vector<int>&, const int, int&))` A function with an input vector (*inputVec*) of random integers. The second parameter is a search vector (*searchVec*) whose values will be searched for inside of the input vector. Finally a `pointer function` is included, which will have either the linear or binary search passed into it.

* `bool linear_search(const vector<int>& inputVec, const int x, int& comparisons)`  A linear search algorithm, where `x` is the searched item in vector `inputVec`. It simply starts searching for x from the beginning of vector to the end, but it stops searching when there is a match. If the search is successful, it returns `true`; otherwise, it returns `false`. The number of comparisons (between `x` and a vector element) conducted in this search in the parameter are saved in `comparisons`.

* `int binary_search(const vector < int >& inputVec, const int x, int& comparisons)` A binary search algorithm, where `x` is the searched item in vector `inputVec`. If the search is successful, it returns `true`; otherwise, it returns `false`. The number of comparisons in the parameter `comparisons` are saved.

* `void print_vec (const vector < int >& vec)` This routine displays the contents of vector `vec` on standard output, printing `NO_ITEMS` on a single line. The sorted numbers are aligned in the output. For each printed number, `ITEM_W` spaces are allocated in standard output.

**Notes:**
 
* I/O functions from the C library such as `scanf` or `printf`, have not been used. Instead, I/O from the C++ library, such as `cin` or `cout` have been used.

* To compile the source file using GCC, execute `g++ -Wall SimpleSearchAlgorithms.cc –o search.exe`.  This will create the executable file `search.exe`. To test your program, execute `./search.exe &> search_results.out`, which will put the output (including any error messages) in file `search_results.out`. You can find the correct output of this program in file `results.out`.

* Added documentation to source file (e.g. https://google.github.io/styleguide/cppguide.html#Comments).

* Makefile has been included for easy compilation. Just run the command make (on a linux or unix environment), otherwise I recommend compiling in Visual Studio or NetBeans
