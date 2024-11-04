#ifndef SIGN_H
#define SIGN_H

#include <string>

using namespace std;

/**
 * @brief Represents a generic sign with a message and type.
 *
 * The Sign class keeps track of the total number of signs created and
 * assigns a unique ID to each instance.
 */
class Sign {
protected:
    string message; ///< The message displayed on the sign.
    string type;    ///< The type of the sign.
    static int numSigns; ///< Static variable to count the number of signs created.
    int ID; ///< Unique identifier for each sign instance.

public:
    /**
     * @brief Constructs a Sign object with a specified message.
     *
     * This constructor initializes the sign's message and increments the
     * total sign count, assigning a unique ID to this sign.
     *
     * @param message The message to be displayed on the sign.
     */
    Sign(const string& message);

    /**
     * @brief Virtual destructor for the Sign class.
     *
     * Allows derived classes to properly clean up resources.
     */
    virtual ~Sign() = default;

    /**
     * @brief Retrieves the unique identifier of the sign.
     *
     * @return The ID of the sign.
     */
    int getID() const;

    /**
     * @brief Retrieves the message displayed on the sign.
     *
     * @return The message associated with the sign.
     */
    string getMessage() const;

    /**
     * @brief Retrieves the type of the sign.
     *
     * @return The type of the sign.
     */
    string getType() const;

    /**
     * @brief Compares two Sign objects for equality based on their IDs.
     *
     * @param other The other Sign object to compare against.
     * @return True if both Sign objects have the same ID, otherwise false.
     */
    bool operator==(const Sign& other) const {
        return this->ID == other.ID;
    }
};

#endif // SIGN_H
