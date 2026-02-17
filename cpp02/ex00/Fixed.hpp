// Orthodox Canonical Form
// 1. Default constructor
// 2. Parameterized constructor
// 3. Copy constructor (takes in another instance of the class and creates a copy)
// 4. Assignment operator (copies values from an object to this alread-existing object)
/*
    Human &operator=(const Human &other) {
        if (this != &other) {
            _name = other._name;
            _age = other._age;
        }
        std::cout << "Human Assignment Operator Called!" << std::endl;
      
        return (*this); //Required for chaining
    }
	// This helps you do human1 = human2
*/
// Create a class in Orthodox Canonical Form that represents a fixed-point number:
// • Private members:
// ◦ An integer to store the fixed-point number value.
// ◦ A static constant integer to store the number of fractional bits. Its value
// will always be the integer literal 8.
// • Public members:
// ◦ A default constructor that initializes the fixed-point number value to 0.
// ◦ A copy constructor.
// ◦ A copy assignment operator overload.
// ◦ A destructor.
// ◦ A member function int getRawBits( void ) const;
// that returns the raw value of the fixed-point value.
// ◦ A member function void setRawBits( int const raw );
// that sets the raw value of the fixed-point number.

class Fixed
{
	private:
		int _value;
		static const int _width;

	public:
		Fixed();
		Fixed(Fixed& other);
		Fixed&	operator=(Fixed& other);
		~Fixed();
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};