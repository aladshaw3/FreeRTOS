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

#include "port_template.h"

int Test_Port()
{
 int success = 0;

 Port<int> int_port;
 int_port.initializePort(0);

 int_port.setState(1);
 int_port.setState(2);
 int_port.setState(3);

 Port<double> d_port(5);

 d_port.initializePort(2.1);

 d_port.setState(3.1);

 return success;
}
