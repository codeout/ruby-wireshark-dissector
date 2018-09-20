require 'wireshark'

Wireshark.load

raw = File.read(File.expand_path('../raw_frame', __FILE__))
puts Wireshark.dissect(raw)

Wireshark.unload
