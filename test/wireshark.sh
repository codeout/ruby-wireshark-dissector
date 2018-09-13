#!/bin/sh

ruby extconf.rb && make && \
  ruby -I. $(dirname $0)/wireshark.rb
