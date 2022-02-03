//
//  std_io.cpp
//  std_io
//
//  Created by Oded Streigold on 4/18/20.
//

#include "std_io.h"

#include <iostream>
#include <queue>



int STD_IO::start_process(String path_godot_str)
{
    std::wstring path_wstring = path_godot_str.c_str();
    std::string path_string( path_wstring.begin(), path_wstring.end() );
    
    if(this->process != nullptr)
    {
        stop_process();
    }
    
    this->process = new Process(path_string, "",
        [this](const char *bytes, size_t n)
        {
            //cout << "Output from stdout: " << string(bytes, n);
            string output_str(bytes, n);
        
            String output_godot_str( output_str.c_str() );
            Variant v(output_godot_str);
        
            Variant** args = new Variant*[1];
            args[0] = {&v};
        
            Variant::CallError err;
            this->godot_output_callback->call_func( (const Variant**)args, 1, err);
        
            delete[] args;
        },
        [this](const char *bytes, size_t n)
        {
            //cout << "Output from stderr: " << string(bytes, n);
        }, true);
    
    return 0;
}

void STD_IO::set_stdout_callback(Ref<FuncRef> callback )
{
      this->godot_output_callback = callback ;
}


std::string STD_IO::godot_string_std_string(String godot_string)
{
    std::wstring std_wstring = godot_string.c_str();
    std::string std_string( std_wstring.begin(), std_wstring.end() );
    return std_string;
}


int STD_IO::send_command(String command){
    if(this->process == nullptr)
        return -1;
    std::string std_str_command = godot_string_std_string(command);
    this->process->write(std_str_command + "\n");
    return 0;
    
}

int STD_IO::stop_process(){
    if(this->process == nullptr)
        return -1;
    this->process->kill();
    delete(this->process);
    this->process = nullptr;
    return 0;
}

void STD_IO::_bind_methods() {
    
    ClassDB::bind_method(D_METHOD("set_stdout_callback", "callback"), &STD_IO::set_stdout_callback);
    ClassDB::bind_method(D_METHOD("start_process", "path_godot_str"), &STD_IO::start_process);
    ClassDB::bind_method(D_METHOD("send_command", "command"), &STD_IO::send_command);
    ClassDB::bind_method(D_METHOD("stop_process"), &STD_IO::stop_process);
}

STD_IO::STD_IO() {
}
