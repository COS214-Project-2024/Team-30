#ifndef TRAFFICLIGHTS_H
#define TRAFFICLIGHTS_H

using namespace std;

/**
 * @brief Represents a traffic light with a state that can change.
 *
 * The TrafficLight class manages the state of a traffic light,
 * which can be red, yellow, or green. It also provides a unique
 * identifier for each traffic light instance.
 */
class TrafficLight {
private:
    char state;            ///< Current state of the traffic light ('R', 'Y', 'G').
    static int numLights;  ///< Static counter to track the number of TrafficLight instances.
protected:
    int id;                ///< Unique identifier for the traffic light instance.
public:
    /**
     * @brief Constructs a TrafficLight object and initializes its state to 'Red'.
     *
     * This constructor assigns a unique ID to the traffic light.
     */
    TrafficLight();

    /**
     * @brief Changes the state of the traffic light.
     *
     * The traffic light cycles through the following states:
     * - Red ('R') to Green ('G')
     * - Green ('G') to Yellow ('Y')
     * - Yellow ('Y') to Red ('R')
     */
    void changeState();

    /**
     * @brief Retrieves the current state of the traffic light.
     *
     * @return The current state of the traffic light as a character ('R', 'Y', or 'G').
     */
    char getState() const;

    /**
     * @brief Retrieves the unique ID of the traffic light.
     *
     * @return The ID of the traffic light instance.
     */
    int getID() const;

    /**
     * @brief Compares two TrafficLight instances for equality based on their IDs.
     *
     * @param other The other TrafficLight instance to compare against.
     * @return True if both traffic lights have the same ID; otherwise, false.
     */
    bool operator==(const TrafficLight& other) const {
        return this->id == other.id;
    }

    /**
     * @brief Sets the state of the traffic light to the specified character.
     *
     * @param c The character representing the desired state ('R', 'Y', or 'G').
     */
    void setState(char c) {
        state = c;
    }
};

#endif // TRAFFICLIGHTS_H

