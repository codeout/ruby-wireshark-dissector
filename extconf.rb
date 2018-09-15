require 'mkmf'

WIRESHARK_VERSION = '2.4.5'

# $CFLAGS += ' -g -O3'
$CFLAGS += ' ' + `pkg-config --cflags glib-2.0`.strip
$CFLAGS += " -I./wireshark-#{WIRESHARK_VERSION}"
$LDFLAGS += ' -lwireshark -lwiretap -lwsutil -lglib-2.0'

create_header('config.h')
File.open('config.h', 'ab') do |f|
  f.puts "#define WS_NORETURN __attribute((noreturn))"
  f.puts "#define _U_ __attribute__((unused))"
end

create_makefile('wireshark')
