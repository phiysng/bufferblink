# bufferblink
protobuf with cmake example.

## build
```bash
# if you do need protoc.
cmake . -B build -D protobuf_BUILD_TESTS=off

# if you dont need protoc.
cmake . -B build -D protobuf_BUILD_TESTS=off -D protobuf_BUILD_PROTOC_BINARIES=OFF
```

## TODO

- [ ] C++ compiler is not gonna compile if use old version protoc(3.6.1 in Ubuntu 20.04)
- [ ] move generated file to a separate project for reuse by multi projects.
