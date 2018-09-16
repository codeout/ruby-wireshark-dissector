FROM ubuntu:latest

WORKDIR /tmp/wireshark

RUN apt-get update && \
  apt-get upgrade -y && \
  DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential pkg-config libglib2.0-dev \
    ruby ruby-dev \
    wireshark libwireshark-dev libwiretap-dev \
    less vim git && \
  apt-get autoremove
