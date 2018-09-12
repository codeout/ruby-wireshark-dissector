```
docker build . -t wireshark
docker run --rm -it -v `pwd`:/tmp/wireshark wireshark bash
```