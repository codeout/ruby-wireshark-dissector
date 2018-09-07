#include "ruby.h"

void rawshark_process_packet();

VALUE wrap_rawshark_process_packet(self, data) VALUE self, data;
{
    uint8_t *raw;

    raw = (uint8_t *)StringValuePtr(data);
    rawshark_process_packet(raw);
    return Qnil;
}

void Init_wireshark() {
    VALUE module;

    module = rb_define_module("Wireshark");
    rb_define_module_function(module, "dissect", wrap_rawshark_process_packet, 1);
}