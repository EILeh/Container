/* Container
 *
 * Description
 *
 * Program asks the user to input the amount of integer and then the integers.
 * Program checks if all the input are the same, are their order from smaller to
 * bigger, are they in arithmetic order, are they in geometric order and triples
 * all integers.
 *
 * Writer of the program
 *
 * Name: EILeh
 */

#include <cstdlib>
#include <iostream>
#include <vector>


// Prints the elements in the parameter vector ints.
void print_integers(const std::vector< int >& ints)
{
    for(auto elem : ints) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Reads as many integers as the parameter count indicates
// and stores them into the parameter vector ints.
void read_integers(std::vector< int >& ints, int count)
{
    int new_integer = 0;
    for(int i = 0; i < count; ++i) {
        std::cin >> new_integer;
        ints.push_back(new_integer);
    }
}

// Checks if the vector members are the same by comparing other members to the
// first member. If some of the memeber is not the same as the first member, re-
// turns false, otherwise true.
bool same_values(std::vector< int >& ints)
{
    int first_member = ints.front();

    for ( int vector_member : ints )
    {
        if ( vector_member != first_member )
        {
            return false;
        }
    }

    return true;
}

// Checks if the members are from smaller to bigger by comparing them to the
// member in index zero. If the member in index zero is smaller than the member
// that is being checked, current member's value is stored to the variable
// member_at_index_zero and then the next member is being compared to this. If
// some member is smaller than member_at_zero_index, function return false, ot-
// herwise true.
bool is_ordered_non_strict_ascending(std::vector< int >& ints)
{
    int member_at_index_zero = ints.front();

    for ( int vector_member : ints )
    {
        if ( vector_member < member_at_index_zero )
        {
            return false;
        }
        member_at_index_zero = vector_member;
    }

    return true;
}

// Checks if the members in vector create a arithmetic series by counting the
// difference between the member at index one and member at index zero. Goes
// through the members in the vector and reducing from the current number's va-
// lue the value that previous member had and comparing the difference to the
// first difference. If the difference is not the same, function return false,
// otherwise true.
bool is_arithmetic_series(std::vector< int >& ints)
{
    int difference = ints.at(1) - ints.at(0);

    for ( unsigned long long int vector_member = 2; vector_member < ints.size();
          ++vector_member )
    {
        if ( ( ints.at(vector_member) - ints.at(vector_member - 1) ) !=
             difference )
        {
            return false;
        }
    }

    return true;
}

// Checks if the members in vector create a geometric series. First function
// checks that first two members are not zeros because division by zero is not
// possible. Then counts the ratio that is compared to other members in the vec-
// tor. Ratio is determined by dividing the member's value in index one by mem-
// ber's value in index zero. By going through the vector's members and dividing
// current member by perivous member and comparing it to the first ratio. If the
// first two members are zero or ratio is not same at every member, function re-
// turns false, otherwise true.
bool is_geometric_series(std::vector< int >& ints)
{
    if ( ( ints.at(0) == 0 ) and ( ints.at(1) == 0 ) )
    {
        return false;
    }

    int difference = ints.at(1) / ints.at(0);

    for ( unsigned long long int vector_member = 2; vector_member < ints.size();
          ++vector_member )
    {

        if ( ( ints.at(vector_member) / ints.at(vector_member - 1) ) !=
             difference )
        {
            return false;
        }
    }

    return true;
}

// Goes through the vector's members and multiplies each member by three.
void triple_integers(std::vector< int >& ints)
{

    for ( int& vector_member : ints )
    {
        vector_member = vector_member * 3;
    }
}

int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    if(how_many <= 0) {
        return EXIT_FAILURE;
    }

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers)) {
        std::cout << "All the integers are the same" << std::endl;
    } else {
        std::cout << "All the integers are not the same" << std::endl;
    }

    if(is_ordered_non_strict_ascending(integers)) {
        std::cout << "The integers are in a non-strict ascending order" <<
                     std::endl;
    } else {
        std::cout << "The integers are not in a non-strict ascending order" <<
                     std::endl;
    }

    if(is_arithmetic_series(integers)) {
        std::cout << "The integers form an arithmetic series" << std::endl;
    } else {
        std::cout << "The integers do not form an arithmetic series" <<
                     std::endl;
    }

    if(is_geometric_series(integers)) {
        std::cout << "The integers form a geometric series" << std::endl;
    } else {
        std::cout << "The integers do not form a geometric series" << std::endl;
    }

    triple_integers(integers);
    std::cout << "Tripled values: ";
    print_integers(integers);

    return EXIT_SUCCESS;
}

