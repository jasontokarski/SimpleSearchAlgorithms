#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

const int DATA_RANGE = 100;
const int DATA_SIZE = 100;
const int DATA_SEED = 7;
const int SEARCH_SEED = 9;

/****************************************************************
FUNCTION:    linear_search()

ARGUMENTS: A reference to a constant vector of integers, a constant int value
of another integer vector, and the number of comparisons make in the search.

RETURNS:     A bool representing whether the search value was found.

NOTES:         The x value will be compared against elements in the inputVec
vector.
****************************************************************/
bool linear_search(const std::vector<int>& inputVec, const int x, int& comparisons) {
	//Create iterators that point to the beginning and end of the vector.
	std::vector<int>::const_iterator itBegin = inputVec.begin();
	std::vector<int>::const_iterator itEnd = inputVec.end();
	
	//Reset comparison count each time this function is called.
	comparisons = 0;
	
	//Iterate through the input vector and look for a match between x and
	//the current element, if the end is reached then return false.
	for (size_t i = 0; i < inputVec.size(); itBegin++, i++)
	{
		comparisons++;
		if (x == *itBegin)
		{
			return true;
		}
		if (*itBegin == *(itEnd-1))
		{
			return false;
		}
	}
}

/****************************************************************
FUNCTION:    binary_search()

ARGUMENTS: A reference to a constant vector of integers, a constant int value
of another integer vector, and the number of comparisons make in the search.

RETURNS:     A bool representing whether the search value was found.

NOTES:         The x value will be compared against elements in the inputVec
vector.
****************************************************************/
bool binary_search(const std::vector<int>& inputVec, const int x, int& comparisons) {
	//Create variables for the beginning, middle, and end indices.
	size_t mid = 0, vecBeg = 0;
	size_t vecEnd = inputVec.size();
	
	//Reset comparison count each time this function is called.
	comparisons = 0;
	
	//Loop through the vector until vecBeg and vecEnd values reach
	//each other. Increment comparisons on each loop. If the current
	//x value is less than middle inputvec value, move the end position
	//to the current middle index, otherwise move the beginning position
	//to the current middle index.
	while (vecBeg < vecEnd)
	{
		comparisons++;
		mid = (int)((vecBeg + vecEnd) / 2);
		if (x < inputVec[mid])
		{
			vecEnd = mid;
		}
		else if ( x > inputVec[mid])
		{
			vecBeg = mid + 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

/****************************************************************
FUNCTION:    print_vec()

ARGUMENTS: A reference to a constant vector of integers.

RETURNS:     Nothing

NOTES:         Prints a formatted list of elements within a vector.
****************************************************************/
void print_vec(const std::vector<int>& vec) {
	//Vector iterator pointing to beginning of vector, a variable to check when
	//a newline is needed and initial formatting.
	std::vector<int>::const_iterator itBegin = vec.begin();
	int newLine = 0;
	std::cout << std::setw(9);
	
	//Loop through the vector and check the number of digits in the integer
	//accordingly, then format depending on the number of digits.
	//After 10 iterations add a newline.
	for (size_t i = 0; i < vec.size(); itBegin++, i++)
	{
		if ((*itBegin / 10) < 1)
		{
			std::cout << *itBegin << "   ";
		}
		else if((*itBegin / 10) == 10)
		{
			std::cout << *itBegin << " ";
		}
		else
		{
			std::cout << *itBegin << "  ";
		}
		if (++newLine == 10)
		{
			newLine = 0;
			std::cout << std::endl;
			std::cout << std::setw(9);
		}
	}
}

void average_comparisons(const std::vector<int>& inputVec, const std::vector<int>& searchVec, bool(*search)(const std::vector<int>&, const int, int&)) {
	int i, comparison = 0, sum = 0, found = 0;
	bool res;
	for (i = 0; i<(int)searchVec.size(); i++) {
		res = search(inputVec, searchVec[i], comparison); //search() will be replaced by linear or binary search functions
		sum += comparison;
		if (res)
			found++;
	}
	std::cout << found << " numbers are found. The average number of comparisons in each search: " << (double)sum / (double)searchVec.size() << std::endl << std::endl;
}

int random_number() {
	return rand() % DATA_RANGE + 1;
}

int main() {

	// -------- create unique random numbers ------------------//
	std::vector<int> inputVec(DATA_SIZE);
	srand(DATA_SEED);
	generate(inputVec.begin(), inputVec.end(), random_number);
	sort(inputVec.begin(), inputVec.end());
	std::vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
	inputVec.resize(it - inputVec.begin());
	random_shuffle(inputVec.begin(), inputVec.end());

	std::cout << "------ Data source: " << inputVec.size() << " unique random numbers ------" << std::endl;
	print_vec(inputVec);
	std::cout << std::endl;

	// -------- create random numbers to be searched ---------//
	std::vector<int> searchVec(DATA_SIZE / 2);
	srand(SEARCH_SEED);
	generate(searchVec.begin(), searchVec.end(), random_number);

	std::cout << "------ " << searchVec.size() << " random numbers to be searched: ------" << std::endl;
	print_vec(searchVec);
	std::cout << std::endl;

	std::cout << "Linear search: ";
	average_comparisons(inputVec, searchVec, linear_search);
	std::cout << "Binary search: ";
	average_comparisons(inputVec, searchVec, binary_search);

	sort(inputVec.begin(), inputVec.end());
	std::cout << "------- numbers in data source are now sorted ---------" << std::endl << std::endl;
	std::cout << "Linear search: ";
	average_comparisons(inputVec, searchVec, linear_search);
	std::cout << "Binary search: ";
	average_comparisons(inputVec, searchVec, binary_search);

	return 0;
}