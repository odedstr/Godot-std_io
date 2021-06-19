//
//  std_io.h
//  std_io
//
//  Created by Oded Streigold on 4/18/20.
//

#ifndef std_io_h
#define std_io_h

#include "core/object/ref_counted.h"

class STD_IO : public RefCounted {
    GDCLASS(STD_IO, RefCounted);

    int count;

protected:
    static void _bind_methods();

public:
    void add(int p_value);
    void reset();
    int get_total() const;

    STD_IO();
};


#endif /* std_io_h */
