/*
 * CISC 4090 (Theory of Computation)
 * Spring, 2020
 *
 * Project 1: A Deterministic Finite-State Automaton
 *
 * Header file for FSA class
 *
 * Author: A. G. Werschulz
 * Date:   28 Jan 2020
 */



#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>



/**
 Abstract: Finite State Automaton
 */
class FSA {
public:
    FSA(std::ifstream &ifs);
    /// Disallow 0-param ctor
    FSA() = delete;
    void describe();
    void trace(const std::string& in_string);
    /**
     Modified by Josh Choi
     */
    template <typename T> int indexOf(const std::vector<T> list, const T element);
private:
    /// Alphabet
    std::string sigma;
    /// Number of states
    int num_states;
    int start_state;
    std::vector<int> accept_states;
    std::vector< std::vector<int> > state_table;
    void get_state_table(std::ifstream &ifs);
};

