//
//  std_io.h
//  std_io
//
//  Created by Oded Streigold on 4/18/20.
//

#ifndef std_io_h
#define std_io_h

#include "core/reference.h"
#include "core/func_ref.h"
#include "process.hpp"

using namespace std;
using namespace TinyProcessLib;

class STD_IO : public Reference {
    GDCLASS(STD_IO, Reference);

    int count;
    Process* process = nullptr;
    Ref<FuncRef> godot_output_callback;


protected:
    static void _bind_methods();
    
    

public:
    
    std::string godot_string_std_string(String godot_string);

    STD_IO();
    
    int start_process(String path);
    int stop_process();
    int send_command(String command);
    void set_stdout_callback(Ref<FuncRef> callback );

};


#endif /* std_io_h */
