#include "ruby.h"

void rawshark_init();
void rawshark_clean();
void rawshark_process_packet(uint8_t *data, int len, FILE *file);

VALUE rb_rawshark_init() {
    rawshark_init();
    return Qnil;
}

VALUE rb_rawshark_clean() {
    rawshark_clean();
    return Qnil;
}

VALUE rb_rawshark_process_packet(VALUE self, VALUE data) {
    uint8_t *raw = (uint8_t *) StringValuePtr(data);
    int rawlen = (int) RSTRING_LEN(data);
    VALUE json;

    char *buf = NULL;
    size_t buflen = 0;
    FILE *out = open_memstream(&buf, &buflen);

    rawshark_process_packet(raw, rawlen, out);
    fclose(out);

    if (buflen > 4) {
        // NOTE: Truncate leading "  ,\n"
        json = rb_str_new2(buf + 4 * sizeof(char));
    }

    free(buf);
    return json;
}

void Init_wireshark() {
    VALUE module = rb_define_module("Wireshark");

    rb_define_module_function(module, "load", rb_rawshark_init, 0);
    rb_define_module_function(module, "unload", rb_rawshark_clean, 0);
    rb_define_module_function(module, "dissect", rb_rawshark_process_packet, 1);
}
