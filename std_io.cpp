//
//  std_io.cpp
//  std_io
//
//  Created by Oded Streigold on 4/18/20.
//

#include "std_io.h"

#include "process.hpp"
#include <iostream>

using namespace std;
using namespace TinyProcessLib;


void STD_IO::add(int p_value) {
    count += p_value;
    
    auto exit_status=0;
    
    cout << endl << "Example 7 - send data to cat through stdin" << endl;
     Process process7("cat", "", [](const char *bytes, size_t n) {
       cout << "Output from stdout: " << string(bytes, n);
     }, nullptr, true);
     process7.write("Hello cat\n");
     process7.close_stdin();
     exit_status=process7.get_exit_status();
     cout << "Example 7 process returned: " << exit_status << " (" << (exit_status==0?"success":"failure") << ")" << endl;
     this_thread::sleep_for(chrono::seconds(5));

}

void STD_IO::reset() {
    count = 0;
}

int STD_IO::get_total() const {
    return count;
}

void STD_IO::_bind_methods() {
    ClassDB::bind_method(D_METHOD("add", "value"), &STD_IO::add);
    ClassDB::bind_method(D_METHOD("reset"), &STD_IO::reset);
    ClassDB::bind_method(D_METHOD("get_total"), &STD_IO::get_total);
}

STD_IO::STD_IO() {
    count = 0;
}
