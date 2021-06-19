//
//  register_types.cpp
//  std_io
//
//  Created by Oded Streigold on 4/18/20.
//

#include "register_types.h"

#include "core/object/class_db.h"
#include "std_io.h"




void register_std_io_types() {
    ClassDB::register_class<STD_IO>();
}

void unregister_std_io_types() {
   // Nothing to do here in this example.
}
