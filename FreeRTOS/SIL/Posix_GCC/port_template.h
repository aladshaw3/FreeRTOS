/*!
 *  \file port_template.h port_template.cpp
 *  \brief C++ Port Object
 *  \details This file creates a Port object that can be of any type. The Ports
 *          can be any inlet or outlet signal from a C Function block in the SIL
 *          environment. A Block should contain some number of Ports of specific
 *          types to accomodate the needs for that block.
 *
 *  \author Austin Ladshaw
 *  \date 11/07/2022
 *  \copyright This software was designed and built at SPAN by Austin Ladshaw
 *             for Software-in-the-Loop simulations. Copyright (c) 2022, all
 *             rights reserved.
 *
 */

#pragma once
#ifndef _PORT_TEMPLATE_
#define _PORT_TEMPLATE_

#include <vector>

/// Port templated class
/** This object is for the creation of a templated Port object. This Port can
    be any inlet or outlet signal from a C Function block in the SIL environment.
    Hysteresis of the port is tracked using a vector of the state. The size of
    that vector is up to the user of the port. Default size is 3. */
template <typename T>
class Port
{
  public:
      /// Default Constructor
      Port();

      /// Constructor by state size
      Port(unsigned int size);

      /// Default Destructor
      ~Port();

      /// Function to resize the Port states
      void resizeState(unsigned int size);

      /// Return the size of the state object
      unsigned int getStateSize();

      /// Function to initialize the values of states to a given value
      void initializePort(T ival);

      /// Function to set current state
      void setState(T ival);

      /// Function to get the current state
      /** NOTE: The `0` state is treated as current*/
      T getState();

      /// Function to get a specific state
      /** If `i` is out-of-bounds, returns oldest state.*/
      T getState(unsigned int i);

  private:
      std::vector<T> state;
};

template <typename T>
Port<T>::Port()
{
  this->state.resize(3);
}

template <typename T>
Port<T>::Port(unsigned int size)
{
  this->state.resize(size);
}

template <typename T>
Port<T>::~Port()
{
  this->state.clear();
}

template <typename T>
void Port<T>::resizeState(unsigned int size)
{
  this->state.resize(size);
}

template <typename T>
unsigned int Port<T>::getStateSize()
{
  return this->state.size();
}

template <typename T>
void Port<T>::initializePort(T ival)
{
  for (unsigned int i=0; i<this->state.size(); i++)
  {
    this->state[i] = ival;
  }
}

/// Function to set current state
/** This function will take in the given state `ival` and apply that state
    to the Port current state (position 0 in the vector). Each older state
    is then updated to reflect the moving window of states.*/
template <typename T>
void Port<T>::setState(T ival)
{
  for (unsigned int i=this->state.size()-1; i>0; i--)
  {
    this->state[i] = this->state[i-1];
  }
  this->state[0] = ival;
}

template <typename T>
T Port<T>::getState()
{
  return this->state[0];
}

template <typename T>
T Port<T>::getState(unsigned int i)
{
  if (i < this->state.size())
    return this->state[i];
  else
    return this->state[this->state.size()-1];
}


/// Function to run tests on the Port object
int Test_Port();

#endif
