# bufferblink
protobuf with cmake example.

## build
```bash
# if you do need protoc.
cmake . -B build -D protobuf_BUILD_TESTS=off

# if you dont need protoc.
cmake . -B build -D protobuf_BUILD_TESTS=off -D protobuf_BUILD_PROTOC_BINARIES=OFF

# if you wanna build protobuf from source
cmake . -B build -D protobuf_BUILD_TESTS=off -D USE_PROTOBUF_FROM_SOURCE=ON
```

## TODO

- [x] ship protoc in project.
- [x] move generated file to a separate project for reuse by multi projects.
- [x] add switch to use protobuf build from source or vise versa.
- [ ] add protoc linux support.
