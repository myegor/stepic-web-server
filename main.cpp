//
// main.cpp
// ~~~~~~~~
//
// Copyright (c) 2003-2015 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include "server.hpp"
#include <unistd.h>
#include <thread>


std::string addr;
std::string port;
std::string root;

int main(int argc, char* argv[])
{
  daemon(1,1);
  try
  {

    int opt = getopt( argc, argv, "h:p:d:" );

    while( opt != -1 ) {
        switch( opt ) {
            case 'h':
              addr = optarg;
                break;
                
            case 'p':
                port = optarg;
                break;
                
            case 'd':
                root = optarg;
                break;                
            default:
        break;
        }
        
        opt = getopt( argc, argv, "h:p:d:" );
    }


    // Initialise the server.
    http::server3::server s(addr, port, root, std::thread::hardware_concurrency());

    //daemon(1,1);

    // Run the server until stopped.
    s.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "exception: " << e.what() << "\n";
  }

  return 0;
}
