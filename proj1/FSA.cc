//
//  FSA.cc
//  Project1
//
//  Created by Joshua Choi on 02/10/2020.
//  Copyright © 2020 Nanogram, Inc. All rights reserved.
//

#include "FSA.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>



using namespace std;


/**
 MARK: - Init
 @param ifs An ifstream reference
 */
FSA::FSA(ifstream &ifs) {
    /// Initialized String value casted to sigma vector
    string char_states;
    // Read
    ifs >> char_states;
    // Iterate through the character states and append it to the vector
    for (char ch: char_states) {
        sigma.push_back(ch);
    }
    // Get the number of states
    ifs >> num_states;
    // Gett the start state
    ifs >> start_state;
    
    /**
     (1) )Get how many accept states there are; (2) read the accept states through temp; (3) append them to ```accept_states```
     */
    int num_accepts;
    int temp;
    
    ifs >> num_accepts;
    for (int i = 0; i < num_accepts; i++) {
        ifs >> temp;
        accept_states.push_back(temp);
    }
    
    // Get the state table
    get_state_table(ifs);
}



/**
 Describes and logs the number of states, start state, accept states, etc. of the FSA.
 */
void FSA::describe() {
    cout << "• Alphabet: " << sigma << "\n";
    cout << "• Start state: " << start_state << "\n";
    cout << "• Number of states: " << num_states << "\n";
    cout << "• Number of accept states: " << accept_states.size() << "\n";
    cout << "• Accept state(s): ";
    // Iterate through the accept states
    for (unsigned long int i = 0; i < accept_states.size(); i++) {
        // Log the accept state separated by a comma (excluding last)
        cout << accept_states[i];
        std::cout << (i == accept_states.size() - 1 ? "." : ", ");
    }
    
    cout << "\n\n• State Table:\n";
    cout << "    a    b \n";
    // Iterate through the number of states
    for (int i = 0; i < num_states; i++) {
        cout << i++ << "|";
        for(unsigned long int j = 0; j < sigma.length(); j++) {
            cout << "    " << state_table[i][j];
        }
        cout<<endl;
    }
}

/**
 Update the table with data-entries from the input file. This method returns nothing and only iterates through each row/column in the input file (delimiter = whitespaces)
 @param ifs An ifstream input
 */
void FSA::get_state_table(ifstream &ifs) {
    /// Initialized Int vector of the table filled with 0s. Useful to preventing NULL values
    vector<int> row(sigma.size());
    
    // Index the table with a row of 0s
    state_table.push_back(row);
    
    /**
     Here, we read through the contents of the table
     */
    // Iterate through the row
    for (int r = 0; r < num_states; r++) {
        // Iterate through the columns
        for (unsigned int c = 0; c < sigma.size(); c++) {
            // Update the row
            ifs >> row[c];
        }
        // Update the table
        state_table.push_back(row);
    }
}



/**
 Traces the op of the finite state automotan by reading its state
 @param in_string A String reference-value representing the input
 */
void FSA::trace(const string& in_string) {
    /// Initialized Int vector representing the operations of the FSA
    vector<int> trace;
    
    /// Store the ```start_state``` in the current state
    int currentState = start_state;
    
    // Append the current state
    trace.push_back(currentState);
    
    // Cast sigma as a vector of characters to prepare to find the character's index from the input
    const std::vector<char> characterVector(in_string.begin(), in_string.end());
    
    // Iterate through the parameter's input string
    for (char character: in_string) {
        /// Get the index of the character in the sigma from the input string
        int i = indexOf(characterVector, character);

        // If the input is valid...
        if (i >= 0) {
            // Update the ```currentState``` variable with the approriate value
            currentState = state_table[currentState][i];
            // And append the current state to the trace vector
            trace.push_back(currentState);
        } else {
            cout << "Error: " << character << "is an invalid input.\n";
            exit(1);
        }
    }
    
    /**
     Here, we log the state of the trace
     */
    cout << "State Trace: ";
    // Iterate through the elements
    for (int state: trace) {
        // Log whether the state is accepted or not
        cout << "State: " << state << "\n";
        cout << ((indexOf(accept_states, currentState) >= 0) ? "Accepted.\n" : "Not Accepted.\n");
    }
}



/**
 Method used to get the index, i, of any element, e in a vector, v.
 @param list Dynamic type vector (make sure to cast it as a const for runtime)
 @param element Dynamic element value
 */
template <typename T> int FSA::indexOf(const vector<T> list, const T element) {
    // MARK: - Algorithm
    auto i = std::find(list.begin(), list.end(), element);
    return i == list.end() ? -1 : int(i - list.begin());
}
