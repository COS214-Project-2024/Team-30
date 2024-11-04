#include "Sign.h"
#include <iostream>
using namespace std;

/**
 * @brief Static member variable to keep track of the number of sign instances created.
 */
int Sign::numSigns = 0;

/**
 * @brief Constructs a Sign object with a specified message.
 *
 * The constructor initializes the message and assigns a unique ID to the sign.
 * It also sets the type of the sign to "Generic sign".
 *
 * @param message The message to be displayed on the sign.
 */
Sign::Sign(const string& message) : message(message), ID(++numSigns)
{
    this->type = "Generic sign";
}

/**
 * @brief Retrieves the unique identifier of the sign.
 *
 * @return The ID of the sign.
 */
int Sign::getID() const
{
    return ID;
}

/**
 * @brief Retrieves the message displayed on the sign.
 *
 * @return The message associated with the sign.
 */
string Sign::getMessage() const
{
    return message;
}

/**
 * @brief Retrieves the type of the sign.
 *
 * @return The type of the sign.
 */
string Sign::getType() const
{
    return type;
}

